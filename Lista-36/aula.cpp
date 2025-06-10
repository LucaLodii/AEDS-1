// <stdlib.h> não é necessária!
#include <iostream> // substitue <stdio.h>
#include <string>
using namespace std;

class Pessoa
{
private:
    string nome;
    int idade;

public:
    void setNome(string nome)
    {
        this->nome = nome;
    }
    void setIdade(int idade)
    {
        this->idade = idade;
    }

    void escrevePessoa()
    {
        cout << endl
             << "NOME:" << nome;
        cout << endl
             << "IDADE:" << idade << endl;
    }

    void leiaPessoa()
    {
        leiaNome();
        leiaIdade();
    }

    void leiaNome()
    {
        string nome;
        cout << "NOME:";
        cin >> nome;
        setNome(nome);
    }
    void leiaIdade()
    {
        int idade;
        cout << endl
             << "IDADE:";
        cin >> idade;
        setIdade(idade);
    }
};

int main()
{
    Pessoa P[3];

    Pessoa P1;
    P[0].setNome("PEDRO");
    P[0].setIdade(18);

    Pessoa P2;
    P[1].setNome("TIAGO");
    P[1].setIdade(19);

    P[2].leiaPessoa();

    for (int i = 0; i < 3; i++)
    {
        P[i].escrevePessoa();
    }

    return 0;
}