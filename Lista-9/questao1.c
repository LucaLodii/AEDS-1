#include <stdio.h>

int main() {
    float num, maior, menor, amplitude;

    printf("\nInforme um número real: ");
    scanf("%f", &num);
    
    maior = menor = num; 

    for (int i = 1; i < 10; i++) { 
        printf("\nInforme um número real: ");
        scanf("%f", &num);

        if (num > maior) {
            maior = num;
        }
        if (num < menor) {
            menor = num;
        }
    } 

    amplitude = maior - menor;
    printf("\nA amplitude é: %f\n", amplitude);

    return 0;
}
