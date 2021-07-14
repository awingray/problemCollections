/* file: additive.c */
/* author: Awin Gray (email: a.gray@student.rug.nl) */
/* date: Tue 11th October 2016 */
/* version: 1.0 */
/*

________5________
____-4_____+4____
__-3__+3_-3__+3__

*/
#include <stdio.h>

// i = iterator from starting number: n, n-1, n-2,...,1
// sum = sum of the iterators: n+(n-1)+(n-2)+...+1
// n = starting number (constant)
int getExpression(int i, int sum, int n) {

    if(i == 1) {
        return (n == sum);
    }

    return getExpression(i-1, (i-1)+sum, n) + getExpression(i-1, (i-1)-sum, n);
}


int main(int argc, char *argv[]) {
    int n;

    scanf("%d", &n);
    printf("%d\n", getExpression(n, n, n));

    return 0;
}
