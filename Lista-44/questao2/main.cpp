#include <iostream>
// g++ questao2/main.cpp -o q2
using namespace std;

const int MAX_LIN = 3;
const int MAX_COL = 3;

class myMatrizes
{
private:

public:
    static void leia(double M[][MAX_COL])
    {
        cout << "Digite os elementos da matriz (" << MAX_LIN << "x" << MAX_COL << "):" << endl;
        for (int i = 0; i < MAX_LIN; ++i)
        {
            for (int j = 0; j < MAX_COL; ++j)
            {
                cout << "M[" << i << "][" << j << "]: ";
                cin >> M[i][j];
            }
        }
    }

    static int min(double M[][MAX_COL]) 
    {
        double menorValor = M[0][0]; 
        int linhaMenorValor = 0;
        for (int i = 0; i < MAX_LIN; i++)
        {
            for (int j = 0; j < MAX_COL; j++)
            {
                if (menorValor < M[i][j])
                {
                    menorValor = M[i][j];
                    linhaMenorValor = i;
                }
            }
        }
        return linhaMenorValor;
    }

    static double minmax(double M[][MAX_COL]) 
    {
        int linhaDoMenor = myMatrizes::min(M);

        double maiorValorNaLinha = M[linhaDoMenor][0];

        for (int j = 0; j < MAX_COL; j++)
        {
            if (M[linhaDoMenor][j] > maiorValorNaLinha)
            {
                maiorValorNaLinha = M[linhaDoMenor][j];
            }
        }
        return maiorValorNaLinha; 
    }
};

int main()
{
    double M[MAX_LIN][MAX_COL];
    myMatrizes::leia(M);
    cout << "\nMINMAX eh igual a: " << myMatrizes::minmax(M) << endl;
    return 0;
}