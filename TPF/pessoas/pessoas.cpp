#include "../data/data.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <string>
#include "pessoas.hpp"
using namespace std;

int Pessoa::TAM = 0; // Definição da variável global

void abertura(Pessoa *pessoas[])
{
    cout << "\nControle de Pessoas\n";
    Pessoa::TAM = tamanho((char *)"tamanhoArq.dat");
    carregaPessoas(pessoas);
}

int tamanho(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file != nullptr) {
        if (fscanf(file, "%i", &Pessoa::TAM) != 1) {
            Pessoa::TAM = 0;
        }
        fclose(file);
    } else {        
        file = fopen(filename, "w");
        if (file != nullptr) {
            fprintf(file, "%d\n", Pessoa::TAM); 
            fclose(file); 
        }
    }

    return Pessoa::TAM;
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
    return this->nascimento.setData(dia, mes, ano);
}

Data Pessoa::getNascimento()
{
    return nascimento;
}

// void cadastrePessoa(Pessoa* pessoas[])
// {
//     if (Pessoa::TAM >= MAX)
//     {
//         cout << "Limite maximo de pessoas atingido!" << endl;
//         return;
//     }

//     cin.ignore();

//     cout << "\nNome: ";
//     string nome;
//     getline(cin, nome);
//     pessoas[Pessoa::TAM]->setNome(nome);

//     Data nascimento;
//     cout << "\nData de nascimento: ";
//     nascimento.leiaData();
//     pessoas[Pessoa::TAM]->setNascimento(nascimento.getDia(), nascimento.getMes(), nascimento.getAno());

//     cin.ignore();

//     cout << "CPF: ";
//     string cpf;
//     getline(cin, cpf);
//     pessoas[Pessoa::TAM]->setCPF(cpf);

//     Pessoa::TAM++;
// }

void leiaCPF()
{
    string cpf;
    getline(cin, cpf);
    int formatoValido = 0;
    if (cpf.length() == 14 && cpf[3] == '.' && cpf[7] == '.' && cpf[11] == '-')
    {
        formatoValido = 1;
    }
    while (!formatoValido)
    {
        cout << "\nCPF (formato 000.000.000-00): ";

        getline(cin, cpf);

        if (cpf.length() == 14 && cpf[3] == '.' && cpf[7] == '.' && cpf[11] == '-')
        {
            formatoValido = 1;
        }
        else
        {
            cout << "Formato incorreto! Use: 000.000.000-00\n";
        }
    }
}

void pesquisaPessoaNome(Pessoa *pessoas[])
{
    string supostoNome;
    cout << "\nDigite o nome a ser encontrado: ";
    getline(cin, supostoNome);

    int encontradas = 0;
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getNome() == supostoNome)
        {
            pessoas[i]->escrevePessoa();
            encontradas++;
        }
    }

    if (encontradas == 0)
    {
        cout << "Nenhuma pessoa encontrada com o nome '" << supostoNome << "'.\n";
    }
}

void pesquisaPessoaCPF(Pessoa *pessoas[])
{
    string supostoCPF;
    cout << "\nDigite o CPF a ser encontrado (000.000.000-00): ";
    getline(cin, supostoCPF);

    int encontradas = 0;
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getCPF() == supostoCPF)
        {
            pessoas[i]->escrevePessoa();
            encontradas++;
        }
    }

    if (encontradas == 0)
    {
        cout << "Nenhuma pessoa encontrada com o CPF '" << supostoCPF << "'.\n";
    }
}

bool deletaPessoa(Pessoa *pessoas[])
{
    string cpf;
    cout << "\nCPF para excluir (000.000.000-00): ";
    cin.ignore();
    getline(cin, cpf);

    for (int i = 0; i < Pessoa::TAM; i++)
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
    cout << "CPF não encontrado.\n";
    return false;
}

Pessoa::Pessoa()
{
    nascimento.setData();
    nome = "";
    TAM++;
}

Pessoa::Pessoa(string nome)
{
    nascimento.setData();
    setNome(nome);
    TAM++;
}

Pessoa::Pessoa(string nome, int dia, int mes, int ano)
{
    nascimento.setData(dia, mes, ano);
    setNome(nome);
    TAM++;
}

Pessoa::~Pessoa()
{
    TAM--;
}

void apagarTodos(Pessoa *pessoas[])
{
    Pessoa::TAM = 0;
    printf("Todos os cadastros foram removidos.\n");
}

void carregaPessoas(Pessoa *pessoas[])
{
    FILE *arquivo = fopen("pessoas.dat", "rb");
    if (arquivo)
    {
        fread(pessoas, sizeof(Pessoa), Pessoa::TAM, arquivo);
        fclose(arquivo);
    }
}

void gravaTAM(){
    FILE *arquivo = fopen("tamanhoArq.dat", "wb");
    if (arquivo)
    {
        fwrite(&Pessoa::TAM, sizeof(int), 1, arquivo);
        fclose(arquivo);
    }
}
void gravaPessoas(Pessoa *pessoas[])
{
    FILE *arquivo = fopen("pessoas.dat", "wb");
    if (arquivo)
    {
        fwrite(pessoas, sizeof(Pessoa), Pessoa::TAM, arquivo);
        fclose(arquivo);
        gravaTAM();
    }
}


void despedida(Pessoa *pessoas[])
{
    gravaPessoas(pessoas);
}
