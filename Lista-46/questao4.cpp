#include <iostream>

using namespace std;

const int MAX_DIM = 100;

bool verificaDominancia(float M[][MAX_DIM], int dimensao, int linha, int coluna) {
    if (linha < 0 || linha >= dimensao || coluna < 0 || coluna >= dimensao) {
        cout << "Erro: Linha ou coluna fora dos limites da matriz." << endl;
        return false;
    }

    for (int k = 0; k < dimensao; ++k) {
        if (M[linha][k] <= M[k][coluna]) {
            return false;
        }
    }

    return true;
}