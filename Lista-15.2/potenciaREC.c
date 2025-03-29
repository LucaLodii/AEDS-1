#include <stdio.h>

void potenciacao(int base, int expoente){
    int i = 1;
    if(expoente>i){
        printf("%d ",base);
    }
    potenciacao(base*=base,expoente);
}

int main(){
    int base, expoente;
    printf("\nBase: ");
    scanf("%d",&base);
    printf("\nexpoente: ");
    scanf("%d",&expoente);
    potenciacao(base, expoente);
}