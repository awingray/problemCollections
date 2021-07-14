#include <stdio.h>

int main() {
    int a, b, n, x = 0;
    scanf("%d %d %d", &a, &b, &n);
    for(int i = 1; i <= n; i++) {
        if((i % a) == 0 && (i % b) == 0) {
            x += 1;
        }
    }
    printf("%d\n", x);
    return 0;
}
