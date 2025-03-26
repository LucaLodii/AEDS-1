#include <stdio.h>

void calcularFatorial(int n) {
    int fatorial = 1;
    for(int i = 1; i <= n; i++) {
        fatorial *= i;
        printf("%d! = %d\n", i, fatorial);
    }
}

int lerN() {
    int n;
    printf("\nInforme o numero que deseja saber o fatorial: ");
    scanf("%d", &n);
    return n;
}

int main() {
    int n = lerN();
    if (n >= 0) {
        calcularFatorial(n);
    } else {
        printf("Erro: Fatorial nao definido para numeros negativos.\n");
    }
    return 0;
}