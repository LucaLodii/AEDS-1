#include <stdio.h>

#define LINHAS_A 2
#define COLUNAS_A 3 
#define LINHAS_B 3
#define COLUNAS_B 2

void produtoMatricial(float A[LINHAS_A][COLUNAS_A], float B[LINHAS_B][COLUNAS_B], float C[LINHAS_A][COLUNAS_B]) {
    for (int i = 0; i < LINHAS_A; i++) {
        for (int j = 0; j < COLUNAS_B; j++) {
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < LINHAS_A; i++) { // Pra linha
        for (int j = 0; j < COLUNAS_B; j++) { // Pra coluna
            for (int k = 0; k < COLUNAS_A; k++) {   //Pro produto 
                C[i][j] += A[i][k] * B[k][j];  // Soma dos produtos
            }
        }
    }
}

int main() {
    float A[LINHAS_A][COLUNAS_A] = {
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.0f, 6.0f}
    };

    float B[LINHAS_B][COLUNAS_B] = {
        {7.0f, 8.0f},
        {9.0f, 10.0f},
        {11.0f, 12.0f}
    };

    float C[LINHAS_A][COLUNAS_B];  // Matriz resultado

    produtoMatricial(A, B, C);

    printf("Matriz C (Produto A x B):\n");
    for (int i = 0; i < LINHAS_A; i++) {
        for (int j = 0; j < COLUNAS_B; j++) {
            printf("%.2f\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}