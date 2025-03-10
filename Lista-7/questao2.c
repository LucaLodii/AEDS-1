#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
float base, resposta;
int expo;

    printf("\n vamos calcular uma potenciação");
    printf("\nprimeiro digite a base: ");
    scanf("%f",&base);
    printf("\nAgora digite o expoente: ");
    scanf("%i",&expo);

    do{
        resposta=base*base;
        expo--;
    }while(expo>0);
    printf("\nResultado da potenciação: %.2f\n", resposta);
    return 0;
}