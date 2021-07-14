

#include <stdio.h>
#include <malloc.h>

int debug = 0;

struct SparseMatrix {
	int n;

};


int tokenize(char *str, int *input, int sizeInput) {
	char seps[] = " \n";
	char* token;
	int n = 1;   // starts from 1, because the first entry at [0] will contain the number of entries
	int num;

	// make all elements 0 for input
	int i;
	for( i = 0; i < sizeInput; i++)
		input[i] = 0;

	token = (char *)strtok (str, seps);
	while (token != NULL)
	{
		//printf("token = %s strlen = %d\n", token, strlen(token));
	    sscanf (token, "%d", &num);
	    //printf("In tokenize: %d\n", var);
	    input[n++] = num;

	    token = (char *)strtok (NULL, seps);
	}
	input[0] = n - 1;
	return n - 1;
}

int convertToNormalRow(int *sparseRow, int *normalRow) {
	int i, j, numZeros, numOnes, normalCounter = 0;

	if( debug) printf("sparseRow[0] = %d\n", sparseRow[0] );
	for( i = 1; i <= sparseRow[0]; i+=2) {

		numZeros = sparseRow[i];

		//if( debug) printf("numZeros = %d numOnes = %d normalCounter = %d\n", numZeros, numOnes, normalCounter);

		for( j = 0; j < numZeros; j++) {
			normalRow[normalCounter++] = 0;
		}
		if( i < sparseRow[0]) {
	  		numOnes = sparseRow[i+1];
			for( j = 0; j < numOnes; j++) {
				normalRow[normalCounter++] = 1;
			}
		}
	}
	// print the row
	for( i = 0; i < normalCounter; i++) {
		if( debug) printf("%d ", normalRow[i]);
	}
	if( debug) printf("\n");
	return normalCounter;
}

int ** readRowSparseMatrix(int n) {

	int i, j, nVals;
	char line[100];
	int *sparseRow = malloc( (n + 1) * sizeof(int));


	// the normal matrix consists of
	int **nmatrix = (int **)malloc( n * sizeof(int* ));
	for( i = 0; i < n; i++) {
		nmatrix[i] = malloc(n * sizeof(int));
		for( j = 0; j < n; j++) {
			nmatrix[i][j] = 0; // initialize them all to 0
		}
	}


	// now read n number of lines, and tokenize them into numbers
	for( i = 0; i < n; i++) {
		fgets(line, 100, stdin );
		//printf("read line: %s\n", line);

		nVals = tokenize( line, sparseRow, n);
		if( debug) printf("nVals = %d\n", nVals);
		for( j = 0; j < nVals; j++){
			if( debug) printf("%d, ", sparseRow[j]);
		}
		if( debug) printf("\n");


		nVals = convertToNormalRow( sparseRow, nmatrix[i]);
		if( debug) printf("normal row length = %d\n", nVals);

	}

	return nmatrix;
}

int convertToNormalCol(int *sparseCol, int **normalMat, int col) {
	int i, j, numZeros, numOnes, normalCounter = 0;

	if( debug) printf("sparseCol[0] = %d\n", sparseCol[0] );
	for( i = 1; i <= sparseCol[0]; i+=2) {

		numZeros = sparseCol[i];
		numOnes = sparseCol[i+1];

		if( debug) printf("numZeros = %d numOnes = %d normalCounter = %d\n", numZeros, numOnes, normalCounter);

		for( j = 0; j < numZeros; j++) {
			normalMat[normalCounter++][col] = 0;
		}
		if( i < sparseCol[0])
		for( j = 0; j < numOnes; j++) {
			normalMat[normalCounter++][col] = 1;
		}
	}
	// print the column
	for( i = 0; i < normalCounter; i++) {
		if( debug) printf("%d\n", normalMat[i][col]);
	}
	return normalCounter;
}

int ** readColSparseMatrix(int n) {

	int i, j, nVals;
	char line[100];
	int *sparseCol = malloc( (n + 1) * sizeof(int));


	// the normal matrix consists of
	int **nmatrix = (int **)malloc( n * sizeof(int* ));
	for( i = 0; i < n; i++) {
		nmatrix[i] = malloc(n * sizeof(int));
		for( j = 0; j < n; j++) {
			nmatrix[i][j] = 0; // initialize them all to 0
		}
	}


	// now read n number of lines, and tokenize them into numbers
	for( i = 0; i < n; i++) {
		fgets(line, 100, stdin );
		//printf("read line: %s\n", line);

		nVals = tokenize( line, sparseCol, n);
		if( debug) printf("nVals = %d\n", nVals);
		for( j = 0; j < nVals; j++){
			if( debug) printf("%d, ", sparseCol[j]);
		}
		if( debug) printf("\n");


		nVals = convertToNormalCol( sparseCol, nmatrix, i);
		if( debug) printf("normal col length = %d\n", nVals);

	}

	return nmatrix;
}

int sameMatrix(int **matrix1, int **matrix2, int n) {
	int i, j;
	for( i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if( matrix1[i][j] != matrix2[i][j] )
				return 0;

		}
	}
	return 1;
}

int main() {

	char line[100];
	int n;
	int **matrix1, **matrix2;

	scanf("%d", &n);
	// read the newline after the number n
	fgets(line,100, stdin);
	matrix1 = readRowSparseMatrix(n);
	// read newline in input
	fgets(line,100, stdin);
	matrix2 = readColSparseMatrix(n);



	if( sameMatrix( matrix1, matrix2, n)) {
		printf("EQUAL\n");
	} else {
		printf("DIFFERENT\n");
	}

	return 0;
}
