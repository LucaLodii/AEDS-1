#include <stdio.h>

int ehPrimoEntreSi(int numero1,int numero2, int divisor){
        if(numero1 <= 1 || numero2 <= 1) {
        printf("\nOs numeros tem quer ser maiores que 1");
        return 0;
    }
    int maior, menor;
    if(numero1>numero2){
        maior=numero1;
        menor=numero2;
    }
    else {
        maior=numero2;
        menor=numero1;
    }
    
    while(divisor<=menor){
        if(menor%divisor==0){
            if(maior%divisor==0){
                printf("\nNAO primos entre si");
                return 1;
            }
        }
        divisor++;
    }
    printf("\nSAO sao primos entre si");

    return 0;
}

int main(){
    int numero1, numero2;
    scanf("%d",&numero1);
    scanf("%d",&numero2);
    ehPrimoEntreSi(numero1,numero2, 2);
    return 0;
}