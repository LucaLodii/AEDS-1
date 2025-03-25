#include <stdio.h>

void calc(int base, int expoente, int result) {
    if (expoente > 0) {
        calc(base, expoente-1, result*base);
    } else {
        printf("%d", result);
    }
}

void introducao(){
    int base, expoente;
    printf("\nDigite a base: ");
    scanf("%d",&base);
    printf("\nDigite o expoente: ");
    scanf("%d",&expoente);
        calc(base,expoente,1);
}

int main(){
    introducao();

    return 0;
}