#include <iostream>
#include <string>
using namespace std;

#define _MAX 10 // número máximo de candidatos
static int TAM = 0;

class Candidato
{
    private:
        string nome;
        double nota;

    public:
        void setNome()
        {
            this->nome = nome;
        }
        string getNome()
        {
            return nome;
        }

        void setNota()
        {
            this->nota = nota;
        }
        double getNota()
        {
            return nota;
        }
        // ADICIONAR AS OUTRAS FUNÇÕES 
};

int main()
{
    // funcao que le o numero<MAX de candidatos
    // fazer um for com o numero retornado da funcao acima que contenha: New, nome e nota.
    // funcao para ler a media
    // funcao q lista os candidatos acima da nota media
}