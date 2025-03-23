#include <stdio.h>

void calc(int num, int i, int fatorial){
    if(num>=0){
        printf("%d ",fatorial);
    }
    calc(num-1, i+1, fatorial *= i);
}

void introduction(){
    int num, i = 1, fatorial = 1;
    printf("\n----CALCULADORA DE FATORIAL----\n");
        printf("\nInforme o numero que vc quer saber o fatorial: ");
        scanf("%d",&num);

        calc(num,i, fatorial);
}

int main(){
    introduction();

    return 0;
}