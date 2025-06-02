#include <stdio.h>   // se o i = j significa que está na diagonal principal
#include <stdlib.h>  // se o i < j significa que esta acima da diagonal principal
#include <stdbool.h> // se o i > j significa que esta abaixo da diagonal principal

#define MAX_COL 3
#define MAX_LIN 3 // pra ser uma matriz quadrada

float diferencaMaioresDiagonal(float matriz[MAX_LIN][MAX_COL])
{
    float maiorAcima = matriz[MAX_LIN][0];
    float maiorAbaixo = matriz[0][MAX_COL];
    for (int i = 0; i < MAX_LIN; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            if (i < j && matriz[i][j] > maiorAcima)
            {
                maiorAcima = matriz[i][j];
            }
            if (i > j && matriz[i][j] > maiorAbaixo)
            {
                maiorAbaixo = matriz[i][j];
            }
        }
    }
    printf("\nMaior acima da diagonal: %.1f", maiorAcima);
    printf("\nMaior abaixo da diagonal: %.1f", maiorAbaixo);
    if (maiorAcima >= maiorAbaixo)
        return maiorAcima - maiorAbaixo;
    else
        return maiorAbaixo - maiorAcima;
}

void leMatriz(float matriz[MAX_LIN][MAX_COL])
{
    printf("\nDigite os valores da matriz %dx%d:\n", MAX_LIN, MAX_COL);
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
    leMatriz(M1);

    float diferenca = diferencaMaioresDiagonal(M1);
    printf("\nDiferenca: %.2f\n", diferenca);

    return 0;
}