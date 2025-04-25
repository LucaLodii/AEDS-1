#include <stdio.h>
#include <stdlib.h>

char* nomeMes(int mes) {
    char* meses[12] = {
        "Janeiro", "Fevereiro", "Marco", "Abril",
        "Maio", "Junho", "Julho", "Agosto",
        "Setembro", "Outubro", "Novembro", "Dezembro"
    };
    
    if (mes >= 1 && mes <= 12) {
        return meses[mes - 1];
    }
    return "Mes invalido";
}

int main() {
    int mes;
    printf("Digite um numero de mes (1-12): ");
    scanf("%d", &mes);
    
    char* nome = nomeMes(mes);
    printf("O mes correspondente e: %s\n", nome);
    
    return 0;
}