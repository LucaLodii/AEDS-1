#include <stdio.h>
int main(){

    float valor;

    printf("\nDescubra seu desconto aqui na loja :)\n");
        printf("\nDigite seu valor: ");
        scanf("%f",&valor);

            do {
                if(valor < 500){
                    valor *= 0.3;
                    printf("\nO valor do seu produto com desconto de 70%% eh: %.2f",valor);
                }if(valor >=500 && valor <= 3000){
                    valor *= 0.4;
                    printf("\nO valor do seu produto com desconto de 60%% eh: %.2f",valor);
                } if (valor > 3000){
                    valor *= 0.5;
                    printf("\nO valor do seu produto com desconto de 50%% eh: %.2f",valor);
                }
                    printf("\nDigite seu valor: ");
                    scanf("%f",&valor);
        } while (valor != 0);
        
        printf("Tchau!");

    return 0;
}