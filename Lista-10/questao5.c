//A VERSÃO BONITA FOI PERDIDA
#include <stdio.h>

int main(){

    int inteiro, inteiro2, divisor=2, resultado, count_divisores=0;

    printf("\nEsse programa verifica se 2 inteiros sao primos entre si\n");
    do{
    printf("\nDigite primeiro inteiro: ");
    scanf("%i",&inteiro);
        if (inteiro < 0){
            printf("\nnumero invalido fale um positivo dessa vez");
        }}while(inteiro < 0);

    if(inteiro == 2)printf("eh primo");
        if (inteiro < 2) {
            printf("\nNumero invalido, deve ser maior ou igual a 2\n");
            return 0;
        }
            do{
                resultado = inteiro % divisor;

                    if(resultado == 0)
                        count_divisores++;

                        divisor++;
            }while(inteiro % divisor != 0);

                do{
                printf("\nDigite seu segundo inteiro: ");
                scanf("%d",&inteiro2);
                    if (inteiro2 < 0){
                        printf("\nnumero invalido fale um positivo dessa vez");
                    }
                } while (inteiro2 < 0);
                
                    if(inteiro2 % divisor != 0){
                        printf("\nestes 2 numeros sao primos entre si");
                    }       else printf("\nestes 2 numeros NAO sao primos entre si");
    
    return 0;
} 
//A VERSÃO BONITA FOI PERDIDA