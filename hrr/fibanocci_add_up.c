#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int term1 = 0, term2 = 1;

    if (n == 1) {
        printf("%d\n", term1);
    } else if (n == 2) {
        printf("%d\n", term2);
    } else {
        for (int i = 3; i <= n; i++) {
            int nextTerm = term1 + term2;
            term1 = term2;
            term2 = nextTerm;
        }
        printf("%d\n", term2);
    }

    return 0;
}