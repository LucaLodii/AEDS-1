#include <stdio.h>

void apresentacao(){
    printf("\nIdentificar se um numero natural eh primo ou nao\n");
}
int lerNatural(){
    int num;
        do {
            printf("\nInforme o natural: ");
            scanf("%d",&num);
        } while (num <= 1);
    return num;
}
int calc(int num){
    if (num == 2) return 1;  

    for (int divisor = 2; divisor <= num / 2; divisor++) {
        if (num % divisor == 0) {
            return 0;  
        }
    }
    return 1;  
}
void resultado(int primo){
    if (primo == 1) 
        printf("\nEh primo\n");
    else 
        printf("\nNAO eh primo\n");
}
int main(){
    apresentacao();

    int A = lerNatural();
    int B = calc(A);

    resultado(B);
    
    return 0;
}