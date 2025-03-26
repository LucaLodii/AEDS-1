#include <stdio.h>

void verificarPotenciaDe2(int num) {
    if (num <= 0) {
        printf("%d NAO eh potencia de 2\n", num);
        return;
    }

    int original = num;
    while (num > 1) {
        if (num % 2 != 0) {
            printf("%d NAO eh potencia de 2\n", original);
            return;
        }
        num /= 2;
    }
    printf("%d EH potencia de 2\n", original);
}

int lerNum() {
    int num;
    printf("Digite um numero natural: ");
    scanf("%d", &num);
    return num;
}

int main() {
    int numero = lerNum();
    verificarPotenciaDe2(numero);
    return 0;
}