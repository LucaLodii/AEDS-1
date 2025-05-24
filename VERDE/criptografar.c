#include <stdio.h>

void converte(char entrada[], char saida[]) {
    int i = 0;
    while (entrada[i] != '\0') {
        saida[i] = entrada[i] + 3;
        i++;
    }
    saida[i] = '\0';     // Essa porra causa mais dor de cabeça doq 1 tiro na nuca
}

int main() {
    char entrada[100], saida[100];
    
    fgets(entrada, sizeof(entrada), stdin);

    converte(entrada, saida);

    printf("%s\n", saida);  // Essa aq tb
    
    return 0;
}