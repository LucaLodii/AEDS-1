#include <stdio.h>
#include <stdlib.h>

#define MAX_COL 4

void maiorValorDeI(int linhas, float matriz[][MAX_COL]) {
    int linhaEscolida;
    printf("\nEscolha uma linha (0 a %d): ", linhas-1);
    scanf("%d", &linhaEscolida);
    
    float maior = matriz[linhaEscolida][0];
    for(int j = 1; j < MAX_COL; j++) {
        if(matriz[linhaEscolida][j] > maior) {
            maior = matriz[linhaEscolida][j];
        }
    }
    printf("O maior valor da linha %d eh: %.1f\n", linhaEscolida, maior);
}

void leMatriz(int linhas, float matriz[][MAX_COL]) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < MAX_COL; j++) {
            printf("Posicao [%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]); 
        }
    }
}

void escreveMatriz(int linhas, float matriz[][MAX_COL]) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < MAX_COL; j++) {
            printf("%.1f ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int linhas;
    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);
    
    float (*M1)[MAX_COL] = malloc(linhas * sizeof(float[MAX_COL]));
    
    printf("\nDigite os valores da matriz %dx%d:\n", linhas, MAX_COL);
    leMatriz(linhas, M1);
    
    printf("\nMatriz:\n");
    escreveMatriz(linhas, M1);
    
    maiorValorDeI(linhas, M1);
    
    free(M1);
    return 0;
}