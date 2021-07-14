#include <stdio.h>

int sumSquare(int n) {
    int sum = 0;
    int digit;

    while(n != 0) {
        digit = n % 10;
        sum += (digit * digit);
        n = n / 10;
    }
    return sum;
}

int checkSquare(int n) {
    do {
        n = sumSquare(n);
        if(n == 1) {
            return 1;
        }
    } while(n != 89);

    return 89;
}

int main() {

    int n, cnt = 0;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        if(checkSquare(i) == 89) {
            cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}
