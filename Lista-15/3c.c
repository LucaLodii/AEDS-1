#include <stdio.h>

int ContagemRegressiva(int n){
    int i = 1;
    while(i<=n){
        printf("%d ",i);
        i++;
    }
}

int lerN(){
    int n;
    printf("\nInforme N para que eu possa contar de 1 ate N: ");
    scanf("%d",&n);
    return n;
}

int main(){
    int A = lerN();
    ContagemRegressiva(A);

    return 0;
}