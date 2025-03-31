#include <stdio.h>

void ehPrimo(int numero, int divisor, int countDiv) {

    if(numero <= 1) {
        printf("\nNumero invalido");
        return;
    }
    if(divisor > numero/2) {
        if(countDiv == 0) 
            printf("\nEH primo");
        else 
            printf("\nNAO eh primo");
        return;
    }
    
    if(numero % divisor == 0)
        ehPrimo(numero, divisor+1, countDiv+1);
    else
        ehPrimo(numero, divisor+1, countDiv);
}

int main() {
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    ehPrimo(numero, 2, 0);  
    return 0;
}