#include <stdio.h>

int lerInvertido(int num){
    while(num>=1){
        printf("%d",num%10);
        num/=10;
    }
}

int lerNum(){
    int num;
    printf("\nDigite um numero que eu te falo ele invertido: ");
    scanf("%d",&num);
    return num;
}

int main(){
    int A = lerNum();
    lerInvertido(A);
}