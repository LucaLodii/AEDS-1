#include <stdio.h>
int main(){

    int divisor=1, inteiro, countd = 0, resultado;


    printf("\nBota seu inteiro ai q eu falo quantos divisores ele tem: ");
    scanf("%d",&inteiro);

        do{
            resultado = inteiro % divisor;
            if(resultado==0){
                countd++;
            }
            divisor++;

        }while(divisor <= inteiro);
    
        printf("\nnumero de divisores do inteiro %d eh: %d",inteiro,countd);

    return 0;
}