// EU APAGUEI COISAS INUTEIS DA QUESTAO 1 E 2
#include <stdio.h>
#include <stdbool.h>

#define MAX_LIN 2
#define MAX_COL 4

void escreveMatriz(float matriz[MAX_LIN][MAX_COL]) {
        for(int i = 0; i < MAX_LIN; i++) {
        for(int j = 0; j < MAX_COL; j++) {
            printf("\nPosicao [%d][%d] = %.1f ", i, j, matriz[i][j]);
        }
    }
}

void copiarM1emM2(float matriz1[MAX_LIN][MAX_COL], float matriz2[MAX_LIN][MAX_COL]){    //Argumentos: os endereços para duas matrizes de reais
    for(int i = 0; i < MAX_LIN; i++) {
        for(int j = 0; j < MAX_COL; j++) {
            matriz2[i][j] = matriz1[i][j]; 
        }
    }
}

void leMatriz(float matriz[MAX_LIN][MAX_COL])
{
    for (int i = 0; i < MAX_LIN; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            printf("Posicao [%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }
}

int main()
{
    float M1[MAX_LIN][MAX_COL];
    printf("\nDigite os valores da 1a matriz %dx%d:\n", MAX_LIN, MAX_COL);
    leMatriz(M1);
    float M2[MAX_LIN][MAX_COL];
    printf("\nDigite os valores da 2a matriz %dx%d:\n", MAX_LIN, MAX_COL);
    leMatriz(M2);

    copiarM1emM2(M1, M2);

    printf("\n\nEscrevendo a primeira Matriz :\n");
    escreveMatriz(M1);
    printf("\n\nEscrevendo a segunda Matriz :\n");
    escreveMatriz(M2);

    return 0;


}