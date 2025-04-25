#include <stdio.h>
#include <stdlib.h>

int diasNoMes(int mes) {
    int dias[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (mes >= 1 && mes <= 12) {
        return dias[mes - 1]; // Ajusta para índice 0-based
    }
    return -1; // Retorno inválido se mês errado
}

int main() {
    int mes;
    printf("Digite um valor inteiro relativo a um mes do ano [1..12]: ");
    scanf("%d", &mes);
    
    int dias = diasNoMes(mes);
    if (dias != -1) {
        printf("O mes %d tem %d dias.\n", mes, dias);
    } else {
        printf("Mes invalido!\n");
    }
    
    return 0;
}