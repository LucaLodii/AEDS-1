#include <stdio.h>

void ehPrimoEntreSi(int numero1,int numero2, int divisor){
    if (numero1 <= 1 || numero2 <= 1) {
        printf("\nOs numeros devem ser maiores que 1");
        return;
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

    if (divisor > menor) {
        printf("\nSAO primos entre si");
        return;
    }
    
    if (numero1 % divisor == 0 && numero2 % divisor == 0) {
        printf("\nNAO sao primos entre si");
        return;
    }

    ehPrimoEntreSi(numero1, numero2, divisor + 1);
}

int main(){
    int numero1, numero2;
    scanf("%d %d", &numero1, &numero2);
    ehPrimoEntreSi(numero1,numero2, 2);
    return 0;
}