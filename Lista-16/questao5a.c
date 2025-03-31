#include <stdio.h>
int somaDeNateM(int N, int M){
    int soma=0;
    while(N<=M){
        soma+=N;
        N++;
    }
    printf("\nA soma dos inteiros de N ate M eh: %d",soma);
    return 0;
}

int main(){
    int N, M;
    printf("\nDigite o menor e depois o maior numero: ");
    scanf("%d %d", &N, &M);
    somaDeNateM(N, M);
    return 0;
}