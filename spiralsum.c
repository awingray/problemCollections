#include <stdio.h>

int main() {

    int n, m, sum = 0;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        sum += m;
        m = m + (2*i);
    }

    printf("%d\n", sum);
    return 0;
}
