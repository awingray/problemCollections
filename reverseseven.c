#include <stdio.h>

int reverseNumber(int n) {
    int num;
    while(n != 0) {
        num = (num * 10) + n % 10;
        n /= 10;

    }
}

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    return 0;
}
