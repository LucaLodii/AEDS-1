#include <stdio.h>

void calc(int num, int i, int fatorial){
    if  (i <= num) {
        printf("%d ",fatorial);
        i++;
        
    }
    calc(num,i,fatorial *= i);
}

void lerNatural(){
    int num;
    int i = 1;
    int fatorial = 1;
    do {
        printf("\nDigite um numero NATURAL: ");
        scanf("%d", &num);
    } while (num < 0);  
    calc(num,i, fatorial);
}

int main(){
    lerNatural();
}