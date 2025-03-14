#include <stdio.h>

int main(){

    int inteiro, divisor=2, resultado, count_nprimo=0;


    printf("\nDigite um inteiro que eu te falo se ele eh primo: ");
    scanf("%i",&inteiro);

    if(inteiro == 2)printf("eh primo");
    else{
        do{
            resultado = inteiro % divisor;

                if(resultado == 0)
                    count_nprimo++;

                    divisor++;
        }while(divisor <= inteiro/2);

        if(count_nprimo>=1) printf("\nnao eh primo");
            else printf("\neh primo");
    }
    return 0;
} 