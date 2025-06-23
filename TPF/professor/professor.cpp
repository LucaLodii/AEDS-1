#include <iostream>
#include "professor.hpp"

using namespace std;

Professor::Professor(string especializacao)
{
    setEspecializacao(especializacao);
}

void Professor::setEspecializacao(string especializacao)
{
    this->especializacao = especializacao;
};

string Professor::getEspecializacao()
{
    return especializacao;
};

void Professor::leiaPessoa()
{
    string nome;
    cout << "\nNome: ";
    getline(cin, nome);
    setNome(nome);

    cout << "\nCPF: ";
    leiaCPF();
    cout << "\nData de nascimento: [DD MM AAAA]";
    int dia, mes, ano;
    cin >> dia >> mes >> ano;
    setNascimento(dia, mes, ano);
    cout << "\nEspecializacao: ";
    string especializacao;
    cin >> especializacao;
    setEspecializacao(especializacao);
    Pessoa::TAM++;
}

void pesquisaProfessorNome(Pessoa *pessoas[])
{
    string supostoNome;
    cout << "\nDigite o nome a ser encontrado: ";
    cin.ignore();
    getline(cin, supostoNome);

    int encontradas = 0;
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getTipo() == 2)
        {
            if (pessoas[i]->getNome() == supostoNome)
            {
                pessoas[i]->escrevePessoa();
                encontradas++;
            }
        }
    }

    if (encontradas == 0)
    {
        cout << "Nenhum professor encontrado com o nome '" << supostoNome << "'.\n";
    }
}

void Professor::escrevePessoa()
{
    cout << "\nNome: " << getNome();
    cout << "\nData de Nascimento: ";
    Data nascimento = getNascimento();
    nascimento.escreveData();
    cout << "\nCPF: " << getCPF();
    cout << "\nEspecializacao: " << getEspecializacao();
}

void pesquisaProfessorCPF(Pessoa *pessoas[])
{
    string supostoCPF;
    cout << "\nDigite o CPF a ser encontrado (000.000.000-00): ";
    cin.ignore(); // evita erro caso o buffer do cin esteja sujo
    getline(cin, supostoCPF);

    int encontradas = 0;
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getTipo() == 2)
        {
            if (pessoas[i]->getNome() == supostoCPF)
            {
                pessoas[i]->escrevePessoa();
                encontradas++;
            }
        }
    }

    if (encontradas == 0)
    {
        cout << "Nenhum professor encontrado com o CPF '" << supostoCPF << "'.\n";
    }
}

bool deletaProfessor(Pessoa *pessoas[])
{
    string cpf;
    cout << "\nCPF para excluir (000.000.000-00): ";
    cin.ignore();
    getline(cin, cpf);

    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getTipo() == 1)
        {
            if (pessoas[i]->getCPF() == cpf)
            {
                for (int j = i; j < Pessoa::TAM - 1; j++)
                {
                    pessoas[j] = pessoas[j + 1]; // Faz o "shift"
                }
                Pessoa::TAM--;
                cout << "Pessoa excluida com sucesso!\n";
                return true;
            }
        }
    }
    cout << "CPF não encontrado.\n";
    return false;
}

void apagarTodosProfessores(Pessoa *pessoas[])
{
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getTipo() == 2)
        {
            for (int j = i; j < Pessoa::TAM - 1; j++)
            {
                pessoas[j] = pessoas[j + 1]; // Faz o "shift"
            }
            Pessoa::TAM--;
        }
        if (pessoas[i]->getTipo() == 2)
        {
            i--;
        }
    }
    cout << "Professores excluidos com sucesso!\n";
}

void listaProfessores(Pessoa *pessoas[])
{
    if (Pessoa::TAM == 0)
    {
        cout << "Nenhuma pessoa cadastrada." << endl;
    }
    else
    {
        for (int i = 0; i < Pessoa::TAM; i++)
        {
            if (pessoas[i]->getTipo() == 2)
            {
                pessoas[i]->escrevePessoa();
            }
        }
    }
}