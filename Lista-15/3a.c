#include <stdio.h>

int ContagemRegressiva(int n){
    while(n>0){
        printf("%d ",n);
        n--;
    }
}

int lerN(){
    int n;
    printf("\nInforme N para que eu possa contar de N ate 1: ");
    scanf("%d",&n);
    return n;
}

int main(){
    int A = lerN();
    ContagemRegressiva(A);

    return 0;
}