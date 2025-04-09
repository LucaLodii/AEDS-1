#include <stdio.h>
#include <stdlib.h>

int main(){
    float *A, *B;
    A = malloc(sizeof(float)); //aloca os 4 bytes e devolve o endereço do 1o
    printf("\nDigite o 1o valor: ");
    scanf("%f",A); //SEM &

    B = malloc(sizeof(float));
    printf("\nDigite o 2o valor: ");
    scanf("%f",B); //SEM &

    float *soma;
    soma = malloc(sizeof(float));
    *soma = *A + *B; 
    printf("\nA soma de %.1f e %.1f eh: %.1f",*A, *B , *soma);

    return 0;

}