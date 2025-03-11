#include <stdio.h>
int main() {
    int n, i;
    printf("Entrez la valeur de n :\n");
    scanf("%d", &n);
    if (n == 0) {
        printf("Le %d-ième terme de Fibonacci est : 0\n", n);
        return 0;
    } else if (n == 1) {
        printf("Le %d-ième terme de Fibonacci est : 1\n", n);
        return 0;
    }
    int a = 0, b = 1, c; 
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    printf("Le %d-ième terme de Fibonacci est : %d\n", n, b);
    return 0;
}
