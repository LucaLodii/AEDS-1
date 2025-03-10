#include <stdio.h>

int main(){

    int inteiro, divisor=1, resultado, count_divisores=0;


    printf("\nDigite um inteiro qualquer para saber o num de divisores: ");
    scanf("%i",&inteiro);

        do{
            resultado = inteiro % divisor;
                if(resultado == 0) {
                    count_divisores++;
                    printf("\n%d",divisor);}
            divisor++;
                    

        }while(divisor <= inteiro);

        printf("\no numero de divisores eh: %d",count_divisores);

    return 0;
} 