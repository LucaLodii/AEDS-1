#include <stdio.h>
#include <stdlib.h>
int main(){
    float *A, *B, *soma;
    A = malloc(sizeof(float));
    printf("\nDigite o 1o numero: ");
    scanf("%f",A);

    B = malloc(sizeof(float));
    printf("\nDigite o 1o numero: ");
    scanf("%f",B);

    soma = malloc(sizeof(float));

    *soma = *A + *B;

    printf("\nA soma de %.1f com %.1f eh: %.1f", *A, *B, *soma);
    return 0;
}