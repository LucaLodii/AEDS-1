#include <stdio.h>

void moverDisco(int origem, int destino) {
    printf("%d -> %d\n", origem, destino);
}

void hanoi(int discos, int origem, int destino, int auxiliar) {
    // Implemente os passos recursivos aqui depois
    // 1. Mover n-1 discos para o pino auxiliar
    // 2. Mover o disco restante para o destino
    // 3. Mover os n-1 discos do auxiliar para o destino
}

int main() {
    int num_discos;
    
    printf("Digite o número de discos: ");
    scanf("%d", &num_discos);
    
    // Pino 1 = origem, Pino 3 = destino, Pino 2 = auxiliar
    hanoi(num_discos, 1, 3, 2);
    
    return 0;
}