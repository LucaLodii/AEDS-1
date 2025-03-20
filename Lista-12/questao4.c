#include <stdio.h>

void apresentacao(){
    printf("\nEste programa tem como funcao identificar se o inteiro eh par ou impar\n");
}
float lerInteiro(){
    float x;
    printf("\nDigite seu inteiro: ");
    scanf("%f",&x);
    return x;
}
int ehPar(int x) {
    return x % 2 == 0; 
}
void exibirResultado(int x) {
    if (ehPar(x)) {
        printf("\nO numero %d eh par.\n", x);
    } else {
        printf("\nO numero %d eh impar.\n", x);
    }
}
int main(){
    apresentacao();
    int A = lerInteiro();
    
    exibirResultado(A);
}