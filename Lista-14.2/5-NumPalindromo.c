#include <stdio.h>

int ehPalindromo(int invertido, int numOriginal) {
    if(invertido == numOriginal) {
        printf("\nEh palindromo!");
    } else {
        printf("\nNAO eh palindromo!");
    }
    return 0;
}

int numInvertido(int num) {
    int invertido = 0;
    while(num > 0) {
        invertido = invertido * 10 + num % 10;
        num /= 10;
    }
    return invertido;
}

int main() {
    int num, numOriginal;
    
    printf("Digite um numero: ");
    scanf("%d", &num);
    
    numOriginal = num;
    int invertido = numInvertido(num);
    ehPalindromo(invertido, numOriginal);
    
    return 0;
}