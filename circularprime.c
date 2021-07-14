#include <stdio.h>

int numberDigits(int n) {
    int digits = 0;

    while(n != 0) {
        n = n / 10;
        digits++;
    }

    return digits;
}

int pow10(int n) {
    int x = 1;
    for(int i = 0; i < n; i++) {
        x *= 10;
    }

    return x;
}

int isPrime(int n) {
    int i;

    if(n == 1) {
        return 0;
    }

    if(n == 2) {
        return 1;
    }

    if((n % 2) == 0) {
        return 0;
    }

    for(i = 3; i*i <= n; i+=2) {
        if((n % i) == 0) {
            return 0;
        }
    }
    return 1;
}

int isCircular(int n) {
    int digits = numberDigits(n);
    int temp;

    for(int i = 0; i < digits; i++) {
        temp = n / pow10(digits-1);
        n = (n % pow10(digits-1))*10 + temp;
        if(isPrime(n) == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {

    int a, b;
    scanf("%d %d", &a, &b);
    for(; a <= b; a++) {
        if(isCircular(a)) {
            printf("%d\n", a);
        }
    }
    return 0;
}
