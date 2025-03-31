#include <stdio.h>

int resultado = 0;

void somaRecursiva(int N, int M, int soma) {
    if (N > M) {
        somaRecursiva(M, N, soma);
        return;
    }
    
    if (N == M) {
        resultado = soma + M;
        return;
    }
    
    somaRecursiva(N + 1, M, soma + N); 
}

int main() {
    int N, M;
    resultado = 0;
    
    printf("Digite dois numeros (menor e maior): ");
    scanf("%d %d", &N, &M);
    
    somaRecursiva(N, M, 0);
    printf("Soma total = %d", resultado);
    
    return 0;
}