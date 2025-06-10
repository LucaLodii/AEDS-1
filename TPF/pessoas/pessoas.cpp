#include "../data/data.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
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

void escrevaEstPessoa(Pessoa pessoa)
{
    cout << "Nome: " << pessoa.getNome() << endl;
    cout << "CPF: " << pessoa.getCPF() << endl;

    Data nasc = pessoa.getNascimento();
    cout << "Nascimento: " << nasc.getDia() << "/"
         << nasc.getMes() << "/"
         << nasc.getAno() << endl;
}

void escrevePessoa(Pessoa pessoas[], int i)
{
    escrevaEstPessoa(pessoas[i]);
}

void cadastrePessoa(Pessoa pessoas[])
{
    if (TAM >= MAX)
    {
        cout << "Limite máximo de pessoas atingido!" << endl;
        return;
    }

    string nome;
    cout << "\nNome: ";
    getline(cin >> ws, nome);
    pessoas[TAM].setNome(nome.c_str());

    Data nascimento;
    cout << "\nData de nascimento: ";
    nascimento.leData();
    pessoas[TAM].setNascimento(nascimento.getDia(), nascimento.getMes(), nascimento.getAno());

    char cpf[15];
    cout << "CPF: ";
    leiaCPF(cpf);
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

float idadeMedia(Pessoa pessoas[])
{
    if (TAM == 0)
    {
        cout << "Nenhuma pessoa cadastrada!\n";
        return 0.0f;
    }
    float soma = 0;
    for (int i = 0; i < TAM; i++)
    {
        soma += calcularIdade(pessoas[i].getNascimento());
    }
    return soma / TAM;
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
            escrevePessoa(pessoas, i);
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
            escrevePessoa(pessoas, i);
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
            cout << "Pessoa excluída com sucesso!\n";
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
