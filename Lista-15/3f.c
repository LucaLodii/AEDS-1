#include <stdio.h>

int lerInvertido(int num){
    int soma = 0;
    while(num>=1){
        soma += num%10;
        num/=10;
    }
    printf("\nA soma eh: %d",soma);
}

int lerNum(){
    int num;
    printf("\nDigite um numero que eu te falo a soma de seus digitos: ");
    scanf("%d",&num);
    return num;
}

int main(){
    int A = lerNum();
    lerInvertido(A);
}