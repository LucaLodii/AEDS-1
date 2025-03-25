#include <stdio.h>

int qtDigitos(int n) {
    int contador;
    
    if (n < 0) {
        n = -n;
    }
    if (n < 10) {
        contador = 1;
    }
    else {
        contador = 1 + qtDigitos(n / 10);
    }
    return contador;
}

int main() {
    int numero;
    
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);
    
    int quantidade = qtDigitos(numero);
    printf("O numero %d tem %d digito(s)\n", numero, quantidade);
    
    return 0;
}