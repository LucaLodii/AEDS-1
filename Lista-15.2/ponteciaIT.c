#include <stdio.h>

void potenciacao(int base, int expoente){
    int constante = base;
    for(int i = 0; i<expoente; i++){
        printf("%d ",base);
        base*=constante;
    }
}

int main(){
    int base, expoente;
    printf("\nBase: ");
    scanf("%d",&base);
    printf("\nexpoente: ");
    scanf("%d",&expoente);
    potenciacao(base, expoente);
}