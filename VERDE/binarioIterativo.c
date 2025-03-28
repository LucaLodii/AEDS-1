#include <stdio.h>

void binario(int num, int potencia){
    if (potencia == 0) return;

    while(potencia>0){
        if (num>=potencia){
            printf("1");
            num-=potencia;
        } else {
            printf("0");
        }
        potencia/=2;
    }
}

void pot(int num) {
    while (num < 0) {
        printf("Número negativo não suportado.\n");
        return;
    }

    int potencia = 1;
    while (potencia * 2 <= num) {
        potencia *= 2;
    }
    binario(num,potencia);
    printf("\n"); 
}

int main(){
    int num, base = 2;
    scanf("%d",&num);
    pot(num);

}