/* file: collatz.c */
/* author: Awin Gray (email: a.gray@student.rug.nl) */
/* date: Tue 11th October 2016 */
/* version: 1.0 */
#include <stdio.h>
#include <stdlib.h>

#define MAX64 9223372036854775807L /* 2ˆ63 -1 */

#define MAX_N 100000000

static int mem[MAX_N];
/* This function returns the collatz length for the number n*/
int lengthCollatz(long n) {

    if(n <= 1) {
        return 1;
    }

    if(n >= MAX_N) {
        if(n % 2 == 0) {
            return 1 +  lengthCollatz(n/2);
        } else {
            return 1 +  (lengthCollatz((3 * n) + 1));
        }
    } else {
    	if(mem[n] == 0) {
	        if(n % 2 == 0) {
	            return 1 +  (mem[n] = lengthCollatz(n/2));
	        } else {
	            return 1 +  (mem[n] = (lengthCollatz((3 * n) + 1)));
	        }
    	} else {
    		return mem[n];
    	}
    }
    return mem[n];
}

int main(int argc, char *argv[]) {

    int n, a, b, len=-1;
    scanf ("%d %d", &a, &b);
    while (a <= b) {
        int l = lengthCollatz(a);
        if (l > len) {
            n = a;
            len = l;
        }
        a++;
    }
    printf("%d\n", n);
    return 0;

}
