#include <stdio.h>

void moverDisco(int origem, int destino) {
    printf("%d -> %d\n", origem, destino);
}

void hanoi(int discos, int origem, int destino, int auxiliar) {
    if (discos == 1) {
        moverDisco(origem, destino);  // No need for nested if - we already checked discos == 1
    }
    else {
        // Etapa 1: Mova (n-1) discos para o auxiliar (dica: troque destino/auxiliar nos parâmetros)
        hanoi(discos-1, origem, auxiliar, destino);

        // Etapa 2: Mova o disco maior para o destino final
        moverDisco(origem, destino);

        // Etapa 3: Mova os (n-1) discos do auxiliar para o destino (dica: troque origem/auxiliar)
        hanoi(discos-1, auxiliar, destino, origem);
    }
}

int main() {
    int num_discos;
    
    printf("Digite o número de discos: ");
    scanf("%d", &num_discos);
    
    // Pino 1 = origem, Pino 3 = destino, Pino 2 = auxiliar
    hanoi(num_discos, 1, 3, 2);
    
    return 0;
}