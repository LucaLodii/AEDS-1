#include <iostream> // Contem stdbool.h dentro
#include <string>
using namespace std;

class Pessoa
{
private:
    string nome;
    int idade;

public:
    static int quantidade;

    Pessoa()
    {
        quantidade++;
    }

    ~Pessoa() {}

    void setNome(string nome)
    {
        this->nome = nome;
    }
    string getNome()
    {
        return nome;
    }

    void setIdade(int idade)
    {
        this->idade = idade;
    }
    int getIdade()
    {
        return idade;
    }

    bool ehMaior()
    {
        bool maiorIdade = false;
        if (getIdade() >= 18)
            maiorIdade = true;
        return maiorIdade;
    }

    Pessoa maisVelho(Pessoa)
    {
    }
};

int Pessoa::quantidade = 0;

class Aluno : public Pessoa
{
private:
    int matricula;

public:
    Aluno() {}
    Aluno(int matricula, string nome, int idade)
    {
        setNome(nome);
        setIdade(idade);
        setMatricula(matricula);
    }

    void setMatricula(int matricula)
    {
        this->matricula = matricula;
    }

    int getMatricula()
    {
        return matricula;
    }
};

int main()
{
    Pessoa *pessoas[2];
    pessoas[0] = new Aluno(885517, "luca", 18);
    pessoas[1] = new Aluno();

    cout << "Luca eh maior de idade? " << (pessoas[0]->ehMaior() ? "Sim" : "Nao") << endl;

    delete pessoas[0];
    delete pessoas[1];

    return 0;
}