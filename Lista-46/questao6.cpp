#include <iostream>
#include <string>
using namespace std;

int TAM = 0;

class Cidade
{
private:
    string nomeCidade;
    int distanciaBH;

public:
    Cidade() {}
    Cidade(string nome, int distancia)
    {
        nomeCidade = nome;
        distanciaBH = distancia;
    }

    void setNome(string nome)
    {
        nomeCidade = nome;
    }

    string getNome()
    {
        return nomeCidade;
    }

    void setDistancia(int distancia)
    {
        distanciaBH = distancia;
    }

    int getDistancia()
    {
        return distanciaBH;
    }

    bool estaProxima(int chave)
    {
        return distanciaBH <= chave;
    }
};

void listarProximas(Cidade *cidades[], int limite)
{
    for (int i = 0; i < TAM; ++i)
    {
        if (cidades[i]->estaProxima(limite))
        {
            cout << cidades[i]->getNome() << endl;
        }
    }
}

void listarProximasRec(Cidade *cidades[], int limite, int i = 0)
{
    if (i >= TAM)
        return;
    if (cidades[i]->estaProxima(limite))
    {
        cout << cidades[i]->getNome() << endl;
    }
    listarProximasRec(cidades, limite, i + 1);
}

int contarDistantesRec(Cidade *cidades[], int chave, int i = 0)
{
    if (i >= TAM)
        return 0;
    if (cidades[i]->getDistancia() > chave)
        return 1 + contarDistantesRec(cidades, chave, i + 1);
    else
        return contarDistantesRec(cidades, chave, i + 1);
}
