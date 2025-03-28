#include <stdio.h>

void binario(int num, int potencia) {
    if (potencia == 0) return; 
    
    if (num >= potencia) {
        printf("1");
        binario(num - potencia, potencia / 2);
    } else {
        printf("0");
        binario(num, potencia / 2);
    }
}

void pot(int num) {
    if (num < 0) {
        printf("Número negativo não suportado.\n");
        return;
    }

    int potencia = 1;
    while (potencia * 2 <= num) {
        potencia *= 2;
    }
    
    binario(num, potencia);
    printf("\n"); 
}

int main(){
    int num, potencia = 2;
    scanf("%d",&num);
    pot(num);
    return 0;
}