#include <stdio.h>
int main(){

    int mercadorias, valor, maior_valor, menor_valor;
        printf("\nNumero de conjunto de mercadorias: ");
        scanf("%d",&mercadorias);
            printf("\nDigite o valor deste conjunto: ");
            scanf("%d",&valor);

                menor_valor = maior_valor = valor;

            while (valor>2000){



                if(valor>2000){
                    maior_valor = valor;
                }else  {
                    menor_valor = valor;
                }

                    printf("\nDigite o valor deste conjunto: ");
                    scanf("%d",&valor); 
            }
            printf("\nO maior valor eh: %d",maior_valor);
            printf("\nO menor valor eh: %d",menor_valor);
        

    return 0;
}