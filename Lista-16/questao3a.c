#include <stdio.h>
int ehPrimo(int numero){
    if(numero <= 1) {
        printf("\nNAO eh primo");
        return 0;
    }
    
    if(numero == 2) { 
        printf("\nEH primo");
        return 0;
    }

    int divisor = 2, countDiv = 1;
    while(divisor<=numero/2) {
        if(numero%divisor==0) countDiv++;
        divisor++;
    }

    if(countDiv>1) printf("\nNAO eh primo");
    else printf("\nEH primo");
    return 0;
}
int main(){
    int numero;
    scanf("%d",&numero);
    ehPrimo(numero);
    return 0;
}