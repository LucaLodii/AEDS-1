#include <stdio.h>

int fibonacci(int k){
    if (k <=2) return 1; //CASO BASE
    int t1=1, t2=2, proximo;
        for(int i = 1; i<=k; i++){
            printf("%d, ",t1);
            proximo = t1+t2;
            t1 = t2;
            t2 = proximo;
        }
        return t2;
}

int introducao(){
    int k;
    printf("\nInforme quantos termos fibonacci vc quer: ");
    scanf("%d",&k);
    return k;
}

int main(){
    int A = introducao();
    fibonacci(A);

    return 0;
}