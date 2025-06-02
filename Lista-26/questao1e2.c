#include <stdio.h>
#include <stdbool.h>

#define MAX_LIN 2  // Agora é uma constante REAL em tempo de compilação
#define MAX_COL 4  // Antes tava const int MAX_LIN = 2; E const int MAX_COL = 4; Porém dava problema

bool iguais(float matriz1[MAX_LIN][MAX_COL], float matriz2[MAX_LIN][MAX_COL]){
    for(int i = 0; i < MAX_LIN; i++) {
        for(int j = 0; j < MAX_COL; j++) {
            if (matriz1[i][j] != matriz2[i][j]) return false;
        }
    }
    return true;
}

void leMatriz(float matriz[MAX_LIN][MAX_COL]) 
{
    printf("\nDigite os valores da matriz %dx%d:\n", MAX_LIN, MAX_COL);
    for(int i = 0; i < MAX_LIN; i++) {
        for(int j = 0; j < MAX_COL; j++) {
            printf("Posicao [%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }
}

void escreveMatriz(float matriz[MAX_LIN][MAX_COL]) {
    for(int i = 0; i < MAX_LIN; i++) {
        for(int j = 0; j < MAX_COL; j++) {
            printf("\nPosicao [%d][%d] = %.1f ", i, j, matriz[i][j]);
        }
    }
}

int main()
{
    float M1[MAX_LIN][MAX_COL];
    leMatriz(M1);
    float M2[MAX_LIN][MAX_COL];
    leMatriz(M2);
    printf("\n\nEscrevendo a primeira Matriz :\n");
    escreveMatriz(M1);
    printf("\n\nEscrevendo a segunda Matriz :\n");
    escreveMatriz(M2);
    if (iguais(M1, M2))
    printf("\nMatrizes iguais !");
    else
    printf("\nMatrizes diferentes !");
    return 0;
}