#include <stdio.h>
#define MAX_COL 7
#define MAX_LIN 7

float mediaQuadrado(float M[][MAX_COL], int linha, int coluna)
{
    float media = 0;
    if (linha >= 0 && linha < MAX_LIN && coluna >= 0 && coluna < MAX_COL)
    {
        float soma = 0;
        int c = 0;
        for (int i = linha - 1; i <= linha + 1; i++)
        {
            for (int j = coluna - 1; j <= coluna + 1; j++)
            {
                if (i >= 0 && i < MAX_LIN && j >= 0 && j < MAX_COL)
                {
                    soma = soma + M[i][j];
                    c++;
                } 
            } 
        } 
        media = soma / c;
    } 
    return media;
}