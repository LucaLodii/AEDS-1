#include <stdio.h>
#include <ctype.h>
int main (){

    char continuar = 'S';
    float salario, soma = 0;
    int salario_medio, count_salario;
    printf("\nEsse programa eh responsavel por aumentar os salarios especificos\n");
    while (continuar ==  'S') {

        printf("\nDigite seu salario: ");
        scanf("%f", &salario);
        count_salario ++;
        soma += salario;
            if(salario < 1000){
                salario *= 1,1;
            }
            else if(salario>=1000 && salario<=2000){
                salario *= 1.08;
            }
            else {salario = salario * 1.07;}

                printf("\nSlario reajustado: %.2f", salario);

                printf("\nVc deseja continuar? S para sim N para nao: ");
                scanf(" %c", &continuar);
                    continuar = toupper(continuar);
    } 

    salario_medio = (soma/count_salario);
    printf("\nO salario medio eh: %.2f",salario_medio);

    return 0;
}