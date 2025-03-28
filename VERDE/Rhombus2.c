#include <stdio.h>

void losango(int tamanho) {

    for(int linha = 1; linha <= tamanho; linha++) {
        for(int espaco = 1; espaco <= tamanho - linha; espaco++) {
            printf(" ");
        }
        for(int asterisco = 1; asterisco <= 2*linha - 1; asterisco++) {
            printf("*");
        }
        printf("\n");
    }
    
    for(int linha = tamanho-1; linha >= 1; linha--) {
        for(int espaco = 1; espaco <= tamanho - linha; espaco++) {
            printf(" ");
        }
        for(int asterisco = 1; asterisco <= 2*linha - 1; asterisco++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int tamanho;
    printf("Digite o tamanho do losango: ");
    scanf("%d", &tamanho);
    
    losango(tamanho);
    
    return 0;
}