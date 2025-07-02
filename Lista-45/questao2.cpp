#include <iostream>
#include <string>
using namespace std;

const int MAX_LIN = 3;
const int MAX_COL = 3;

class myMatrizes
{
public:
    static int posicaoMaior(double M[][MAX_COL])
    {
        int linhaMaior = -1;
        int colunaMaior = -1;
        double maiorValor = M[0][0];

        for (int i = 0; i < MAX_LIN; ++i)
        {
            for (int j = 0; j < MAX_COL; ++j)
            {
                if (M[i][j] > maiorValor)
                {
                    maiorValor = M[i][j];
                    linhaMaior = i;
                    colunaMaior = j;
                }
            }
        }

        if (linhaMaior == colunaMaior)
            return 0;
        else if (linhaMaior < colunaMaior)
            return 1;
        else
            return -1;
    }

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
};

int main()
{
    double M[MAX_LIN][MAX_COL];
    myMatrizes::leia(M);
    int posicao = myMatrizes::posicaoMaior(M);

    if (posicao == 0)
        cout << "\nMaior valor posicionado na diagonal principal";
    else if (posicao == 1)
        cout << "\nMaior valor posicionado acima da diagonal principal";
    else
        cout << "\nMaior valor posicionado abaixo da diagonal principal";

    return 0;
}