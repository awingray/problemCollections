#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int area, i, j, k;

	scanf("%d", &area);

	for(i = 1; i <= area; i++) {
		for(j = i + 1; j < area; j++) {
		    if((i*j)/2 == area) {
                for(k = i + 2; k <= area; k++) {
                    if((i*i)+(j*j) == (k*k)) {
                        printf("%d %d %d\n", i, j, k);
                    }
                }
            }

		}
	}
	return 0;
}
