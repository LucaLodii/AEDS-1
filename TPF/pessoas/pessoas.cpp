#include "../data/data.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <string>
#include "pessoas.h"
using namespace std;

int TAM = 0; // Definição da variável global

void abertura(Pessoa pessoas[])
{
    cout << "\nControle de Pessoas\n";
    TAM = tamanho((char *)"tamanhoArq.dat");
    carregaPessoas(pessoas);
}

int tamanho(char *arq)
{
    FILE *arqTamanho = fopen(arq, "r");
    if (arqTamanho != nullptr)
    {
        fscanf(arqTamanho, "%i", &TAM);
    }
    else
    {
        arqTamanho = fopen(arq, "w");
        TAM = 0;
        fprintf(arqTamanho, "%i", TAM);
    }
    fclose(arqTamanho);
    return TAM;
}

void Pessoa::setNome(string nome)
{
    this->nome = nome;
}

string Pessoa::getNome()
{
    return nome;
}

void Pessoa::setCPF(string CPF)
{
    if (CPF.length() == 14 && CPF[3] == '.' && CPF[7] == '.' && CPF[11] == '-')
    {
        this->CPF = CPF;
    }
}

string Pessoa::getCPF()
{
    return CPF;
}

bool Pessoa::setNascimento(int dia, int mes, int ano)
{
    Data d;
    if (d.setDia(dia) && d.setMes(mes))
    {
        d.setAno(ano);
        nascimento = d;
        return true;
    }
    return false;
}

Data Pessoa::getNascimento()
{
    return nascimento;
}

void Pessoa::leiaPessoa()
{
    fflush(stdin);

    cout << "Nome: ";
    getline(cin, nome);

    fflush(stdin);

    cout << "CPF (000.000.000-00): ";
    string cpf;
    getline(cin, cpf);
    setCPF(cpf);

    Data d;
    cout << "Data de nascimento: ";
    d.leiaData();
    nascimento = d;
}

void Pessoa::escrevePessoa()
{
    cout << "\nNome: " << nome;
    cout << "\nCPF: " << CPF;
    cout << "\nNascimento: ";
    nascimento.escreveData();
    cout << endl;
}

void cadastrePessoa(Pessoa pessoas[])
{
    if (TAM >= MAX)
    {
        cout << "Limite máximo de pessoas atingido!" << endl;
        return;
    }

    fflush(stdin);

    cout << "\nNome: ";
    string nome;
    getline(cin, nome);
    pessoas[TAM].setNome(nome);

    Data nascimento;
    cout << "\nData de nascimento: ";
    nascimento.leiaData();
    pessoas[TAM].setNascimento(nascimento.getDia(), nascimento.getMes(), nascimento.getAno());

    fflush(stdin);

    cout << "CPF: ";
    string cpf;
    getline(cin, cpf);
    pessoas[TAM].setCPF(cpf);

    TAM++;
}

void leiaCPF(char cpf[])
{
    int formatoValido = 0;
    while (!formatoValido)
    {
        cout << "\nCPF (formato 000.000.000-00): ";
        fflush(stdin);
        if (scanf("%14s", cpf) == 1)
        {
            if (strlen(cpf) == 14 && cpf[3] == '.' && cpf[7] == '.' && cpf[11] == '-')
            {
                formatoValido = 1;
            }
            else
            {
                cout << "Formato incorreto! Use: 000.000.000-00\n";
            }
        }
        else
        {
            cout << "Erro na leitura. Tente novamente.\n";
        }
    }
}

void pesquisaPessoaNome(Pessoa pessoas[])
{
    string supostoNome;
    cout << "\nDigite o nome a ser encontrado: ";
    cin.ignore();
    getline(cin, supostoNome);

    int encontradas = 0;
    for (int i = 0; i < TAM; i++)
    {
        if (pessoas[i].getNome() == supostoNome)
        {
            pessoas[i].escrevePessoa();
            encontradas++;
        }
    }

    if (encontradas == 0)
    {
        cout << "Nenhuma pessoa encontrada com o nome '" << supostoNome << "'.\n";
    }
}

void pesquisaPessoaCPF(Pessoa pessoas[])
{
    string supostoCPF;
    cout << "\nDigite o CPF a ser encontrado (000.000.000-00): ";
    cin.ignore(); // evita erro caso o buffer do cin esteja sujo
    getline(cin, supostoCPF);

    int encontradas = 0;
    for (int i = 0; i < TAM; i++)
    {
        if (pessoas[i].getCPF() == supostoCPF)
        {
            pessoas[i].escrevePessoa();
            encontradas++;
        }
    }

    if (encontradas == 0)
    {
        cout << "Nenhuma pessoa encontrada com o CPF '" << supostoCPF << "'.\n";
    }
}

bool deletaPessoa(Pessoa pessoas[])
{
    string cpf;
    cout << "\nCPF para excluir (000.000.000-00): ";
    cin.ignore();
    getline(cin, cpf);

    for (int i = 0; i < TAM; i++)
    {
        if (pessoas[i].getCPF() == cpf)
        {
            for (int j = i; j < TAM - 1; j++)
            {
                pessoas[j] = pessoas[j + 1]; // Faz o "shift"
            }
            TAM--;
            cout << "Pessoa excluida com sucesso!\n";
            return true;
        }
    }
    cout << "CPF não encontrado.\n";
    return false;
}

void apagarTodos(Pessoa pessoas[])
{
    TAM = 0;
    printf("Todos os cadastros foram removidos.\n");
}

void carregaPessoas(Pessoa pessoas[])
{
    FILE *arquivo = fopen("pessoas.dat", "rb");
    if (arquivo)
    {
        fread(pessoas, sizeof(Pessoa), TAM, arquivo);
        fclose(arquivo);
    }
}

void gravaPessoas(Pessoa pessoas[])
{
    FILE *arquivo = fopen("pessoas.dat", "wb");
    if (arquivo)
    {
        fwrite(pessoas, sizeof(Pessoa), TAM, arquivo);
        fclose(arquivo);
    }
}

void despedida(Pessoa pessoas[])
{
    printf("\nObrigado!\n");
    gravaPessoas(pessoas);
}
