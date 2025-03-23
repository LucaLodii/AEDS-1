#include <stdio.h>
#include <stdlib.h>

void apresentacao2(int A){
    if (A>=0){
        printf("%d ",A);
        apresentacao2(A-1);
    }
}

void apresentacao(){
    int n;
    printf("\nDigite um numero para este programa o subtrair ate 0: ");
    scanf("%d",&n);
        apresentacao2(n);
}

int main(){
    apresentacao();
    return 0;
}