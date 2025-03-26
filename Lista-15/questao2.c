#include <stdio.h>

long int A(long int m, long int n) {
    if (m == 0) {
        return n + 1;
    }
    else if (n == 0) {
        return A(m - 1, 1);
    }
    else {
        return A(m - 1, A(m, n - 1));
    }
}

void apresentacao() {
    printf("\n----FUNCAO DE ACKERMAN----");
    long int m, n;
    do {
        printf("\nDigite M: ");
        scanf("%ld", &m);
        printf("\nDigite N: ");
        scanf("%ld", &n);
    } while (m < 0 || n < 0);
    
    long int result = A(m, n);
    printf("\nA(%ld, %ld) = %ld\n", m, n, result);
}

int main() {
    apresentacao();
    return 0;
}