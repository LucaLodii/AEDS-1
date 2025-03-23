#include <stdio.h>

void calc(int base, int expoente, int i){
    if(expoente>=1){
        printf("%d ",base);
    calc(base*i,expoente-1,i);
    }
}

void introducao(){
    int base, expoente, i;
    printf("\n----Esse programa calcula uma potenciacao----\n");
        printf("\nInforme a base: ");
        scanf("%d",&base);
        printf("\nInforme o expoente: ");
        scanf("%d",&expoente);
            i = base;
        calc(base,expoente, i);
}

int main(){
    introducao();

    return 0;
}