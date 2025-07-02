#include <iostream>
using namespace std;

const int MAX_LIN = 3;
const int MAX_COL = 3;

float minimoDosMaximos(float M[][MAX_COL])
{
    float maximosPorLinha[MAX_LIN];

    for (int i = 0; i < MAX_LIN; ++i)
    {
        float maiorDaLinha = M[i][0];
        for (int j = 1; j < MAX_COL; ++j)
        {
            if (M[i][j] > maiorDaLinha)
            {
                maiorDaLinha = M[i][j];
            }
        }
        maximosPorLinha[i] = maiorDaLinha;
    }

    float menorEntreMaximos = maximosPorLinha[0];
    for (int i = 1; i < MAX_LIN; ++i)
    {
        if (maximosPorLinha[i] < menorEntreMaximos)
        {
            menorEntreMaximos = maximosPorLinha[i];
        }
    }
    return menorEntreMaximos;
}