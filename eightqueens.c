/* file: eightqueens.c */
/* author: Awin Gray (email: a.gray@student.rug.nl) */
/* date: Tue 4th October 2016 */
/* version: 1.0 */
#include <stdio.h>

int board[8][8];

int markReach( int row, int col) {
	//printf("In markReach row = %d col = %d\n", row, col);
	int i = 0, j = 0;
	int ni, nj;
	int counter = 0;
	// mark the row
	for( i = 0; i < 8; i++ ) {
		board[row][i] = 1;
	}


	// mark the column
	for( i = 0; i < 8; i++ ) {
		board[i][col] = 1;
	}

	//printf("going to mark from queen to bottom left\n");
	// mark diagonally from queen to bottom left
	for( i = row, j = col, counter = 0; counter < 8; i++, j--, counter++) {
		ni = i%8;
		nj = j%8;
		if( i < 8 && j > 0) {
			board[ni][nj] = 1;
			//printf("marked %d %d\n", ni, nj);
		}
	}

	//printf("going to mark from queen to top right\n");
	//mark diagonally from queen to top right
	for( i = row, j = col, counter = 0; counter < 8; i--, j++, counter++) {
		ni = i%8;
		nj = j%8;
		if( i > 0 && j < 8) {
			board[ni][nj] = 1;
			//printf("marked %d %d\n", ni, nj);
		}
	}

	//printf("going to mark from queen to bottom right \n");
	// mark diagonally from queen to bottom left
	for( i = row, j = col, counter = 0; counter < 8; i++, j++, counter++) {
		ni = i%8;
		nj = j%8;
		if( i < 8 && j < 8) {
			board[ni][nj] = 1;
			//printf("marked %d %d\n", ni, nj);
		}
	}

	//printf("going to mark from queen to top left\n");
	//mark diagonally from queen to top right
	for( i = row, j = col, counter = 0; counter < 8; i--, j--, counter++) {
		ni = i%8;
		nj = j%8;
		if( i > 0 && j > 0) {
			board[ni][nj] = 1;
			//printf("marked %d %d\n", ni, nj);
		}
	}


	// unmark where this queen is placed
	board[row][col] = 0;
	return 0;
}

void printBoard() {
	int i, j;
	for( i = 0; i < 8; i++) {
		for ( j = 0; j < 8; j++) {
			printf(" %d", board[i][j]);
		}
		printf("\n");
	}

}
int main() {

	int pos[8];

	int i;
	for( i = 0; i < 8; i ++) {
		scanf("%d", &pos[i]);
		//printf("read %d\n", pos[i]);
	}

	for( i = 0; i < 8; i++) {
		int ret = markReach( 7 - i, pos[i]);
	}

	//printBoard();


	for( i = 0; i < 8; i++) {
		if(board[7-i][pos[i]]) {
			printf("invalid\n");
			return 0;
		}
	}
	printf("valid\n");
	return 0;
}
