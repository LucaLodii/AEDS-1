#include <stdio.h>

void imprimirAsteriscos(int qtd) {
    if (qtd > 0) {
        printf("*");
        imprimirAsteriscos(qtd - 1);
    }
}

void imprimirEspacos(int qtd) {
    if (qtd > 0) {
        printf(" ");
        imprimirEspacos(qtd - 1);
    }
}

void losangoSuperior(int linhas, int asteriscos) {
    if (linhas > 0) {
        imprimirEspacos(linhas - 1);  // Espaços decrescentes
        imprimirAsteriscos(asteriscos);  // Asteriscos crescentes
        printf("\n");
        losangoSuperior(linhas - 1, asteriscos + 2);  // Chama próxima linha
    }
}

int main() {
    int n;
    printf("Digite o número de linhas (parte superior): ");
    scanf("%d", &n);
    
    // Inicia com: linhas = n, asteriscos = 1 (valor inicial)
    losangoSuperior(n, 1);
    
    return 0;
}