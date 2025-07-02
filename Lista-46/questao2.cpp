#include <iostream>

using namespace std;

const int NUM_LIN_A = 3;
const int NUM_COL_A = 2;

const int NUM_LIN_B = 2;
const int NUM_COL_B = 3;

const int NUM_LIN_C = NUM_LIN_A;
const int NUM_COL_C = NUM_COL_B;

class Matriz
{
public:
    static void leia(float M[NUM_LIN_A][NUM_COL_A])
    {
        cout << "Digite os valores da matriz A: " << endl;
        for (int i = 0; i < NUM_LIN_A; i++)
        {
            for (int j = 0; j < NUM_COL_A; j++)
            {
                cout << "A[" << i << "][" << j << "]: ";
                cin >> M[i][j];
            }
        }
    }

    static void leiaB(float M[NUM_LIN_B][NUM_COL_B])
    {
        cout << "Digite os valores da matriz B: " << endl;
        for (int i = 0; i < NUM_LIN_B; i++)
        {
            for (int j = 0; j < NUM_COL_B; j++)
            {
                cout << "B[" << i << "][" << j << "]: ";
                cin >> M[i][j];
            }
        }
    }

    static void produtoMatrizes(float A[NUM_LIN_A][NUM_COL_A], float B[NUM_LIN_B][NUM_COL_B], float C[NUM_LIN_C][NUM_COL_C])
    {
        for (int i = 0; i < NUM_LIN_C; i++)
        {
            for (int j = 0; j < NUM_COL_C; j++)
            {
                C[i][j] = 0.0;
            }
        }

        for (int i = 0; i < NUM_LIN_A; i++)
        {
            for (int j = 0; j < NUM_COL_B; j++)
            {
                for (int k = 0; k < NUM_COL_A; k++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }

    static void resultado(float M[NUM_LIN_C][NUM_COL_C])
    {
        cout << "\nMatriz Resultante:" << endl;
        for (int i = 0; i < NUM_LIN_C; i++)
        {
            for (int j = 0; j < NUM_COL_C; j++)
            {
                cout << M[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main()
{
    float matrizA[NUM_LIN_A][NUM_COL_A];
    float matrizB[NUM_LIN_B][NUM_COL_B];
    float matrizC[NUM_LIN_C][NUM_COL_C];

    Matriz::leia(matrizA);
    Matriz::leiaB(matrizB);

    Matriz::produtoMatrizes(matrizA, matrizB, matrizC);

    Matriz::resultado(matrizC);

    return 0;
}