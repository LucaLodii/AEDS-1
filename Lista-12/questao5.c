#include <stdio.h>

void apresentacao(){
    printf("\nEsse programa calcula o fatorial de um numero\n");
}
int lerNatural(){
    int num;
    do {
        printf("\nDigite um numero NATURAL: ");
        scanf("%d", &num);
    } while (num < 0);  

    return num;
}
int calc(int num){
    int fatorial = 1;
    for (int i = 1; i <= num; i++) {
        fatorial *= i;
    }
    return fatorial;
}
void resultado(int fatorial){
    printf("\nO fatorial eh: %d",fatorial);
}
int main(){
    apresentacao();

    float A = lerNatural();
    float B = calc(A);

    resultado(B);
    
    return 0;
}