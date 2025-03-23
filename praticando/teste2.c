#include <stdio.h>
#include <stdlib.h>


void imprimirDecrescente(int n,int j){
    if (j<=n){
        printf("%d ",j);
        imprimirDecrescente(n,j+1);
    }
}

void lerEntradaEImprimir(){
    int j = 0;
    int n;
    printf("\nContando de n ate 0\nDigite n: ");
    scanf("%d",&n);
    imprimirDecrescente(n,j);
}

int main(){
    lerEntradaEImprimir();
    return 0;
}