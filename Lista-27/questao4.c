#include <stdio.h>

#define TAMANHO 3

void copiarLinhaParaColuna(float matriz[TAMANHO][TAMANHO], int i, int j) {

    for (int k = 0; k < TAMANHO; k++) {
        matriz[k][j] = matriz[i][k];
    }
}

void imprimirMatriz(float matriz[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%.1f ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    float matriz[TAMANHO][TAMANHO] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    int i = 1;  // Fica mais facil do que fazer um for dentro de outro
    int j = 2;  //i para linha e j para coluna

    printf("Matriz original:\n");
    imprimirMatriz(matriz);

    copiarLinhaParaColuna(matriz, i, j);

    printf("\nMatriz apos copiar linha %d para coluna %d:\n", i, j);
    imprimirMatriz(matriz);

    return 0;
}