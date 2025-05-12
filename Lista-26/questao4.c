#include <stdio.h>
#include <stdbool.h>

<<<<<<< Updated upstream
#define MAX_LIN 2
#define MAX_COL 4

void matrizTransposta(float matriz1[MAX_LIN][MAX_COL], float matriz2[MAX_COL][MAX_LIN]) {
    for(int i = 0; i < MAX_LIN; i++) {
        for(int j = 0; j < MAX_COL; j++) {
            matriz2[j][i] = matriz1[i][j];
        }
    }
}
=======
#define MAX_LIN 2  // Agora é uma constante REAL em tempo de compilação
#define MAX_COL 4  // Antes tava const int MAX_LIN = 2; E const int MAX_COL = 4; Porém dava problema
>>>>>>> Stashed changes

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

<<<<<<< Updated upstream
/* Modified to handle both matrix types */
void escreveMatriz(float *matriz, int linhas, int colunas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            printf("%.1f ", matriz[i * colunas + j]);
        }
        printf("\n");
=======
void escreveMatriz(float matriz[MAX_LIN][MAX_COL]) {
        for(int i = 0; i < MAX_LIN; i++) {
        for(int j = 0; j < MAX_COL; j++) {
            printf("\nPosicao [%d][%d] = %.1f ", i, j, matriz[i][j]);
        }
>>>>>>> Stashed changes
    }
}

int main()
{
    float M1[MAX_LIN][MAX_COL];
<<<<<<< Updated upstream
    float M2[MAX_COL][MAX_LIN];
    
    printf("\nDigite os valores da matriz %dx%d:\n", MAX_LIN, MAX_COL);
    leMatriz(M1);

    matrizTransposta(M1, M2);

    printf("\nMatriz original:\n");
    escreveMatriz((float *)M1, MAX_LIN, MAX_COL);

    printf("\nMatriz transposta:\n");
    escreveMatriz((float *)M2, MAX_COL, MAX_LIN);

=======
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
>>>>>>> Stashed changes
    return 0;
}