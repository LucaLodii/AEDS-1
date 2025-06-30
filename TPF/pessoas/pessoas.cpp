/*H******************************************************************************
* FILENAME :    pessoas.cpp                   DESIGN REF:     TP

* DESCRIPTION :
*       Implementação da classe abstrata Pessoa e funções auxiliares do sistema.
*       Contém todas as implementações das funções declaradas no header pessoas.hpp,
*       incluindo gerenciamento de memória, persistência em arquivo e operações
*       de pesquisa e manipulação de dados.
*
* PUBLIC FUNCTIONS :
*       - Implementação da classe abstrata Pessoa
*       - Implementação de funções de inicialização (abertura, despedida)
*       - Implementação de funções de persistência (carregaPessoas, gravaPessoas)
*       - Implementação de funções de pesquisa (pesquisaPessoaNome, pesquisaPessoaCPF)
*       - Implementação de funções de manipulação (deletaPessoa, apagarTodos)
*       - Implementação de funções utilitárias (leiaCPF, tamanho)
*
* NOTES :
*       Implementação robusta com gerenciamento adequado de memória e
*       persistência em arquivos binários. Inclui tratamento de exceções
*       e validação de dados. Todas as funções seguem o padrão de um
*       único retorno sem breaks.
*
*       Parte do Sistema de Registro de Pessoas para o projeto final de AEDs.
*
*       Leonardo Stuart de A. Ramalho, 2025. All rights reserved.
*
* AUTHOR    : Leonardo Stuart de A. Ramalho                     START DATE : 24 May 25
*
* CHANGES :
*
* REF NO  VERSION DATE      WHO  DETAIL
* ------- ------- --------- ---- -------------------------------------------
* 001     1.0     16May25   LL   Criacao inicial do arquivo pessoas.cpp.
* 002     2.0     30Jun06   LL   Implementação de sistema de persistência
*
*H*/

#include "../data/data.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <string>
#include "pessoas.hpp"
#include "../professor/professor.hpp"
#include "../aluno/aluno.hpp"
using namespace std;

int Pessoa::TAM = 0; // Definição da variável global

// Inicializa o sistema e carrega dados salvos
void abertura(Pessoa *pessoas[])
{
    cout << "\nControle de Pessoas\n";
    Pessoa::TAM = tamanho("tamanhoArq.dat");
    carregaPessoas(pessoas);
}

// Lê o tamanho do arquivo ou cria se não existir
int tamanho(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    int tam;

    if (file != nullptr)
    {
        if (fread(&tam, sizeof(int), 1, file) == 1)
        {
            Pessoa::TAM = tam;
        }
        else
        {
            Pessoa::TAM = 0;
        }
        fclose(file);
    }
    else
    {
        file = fopen(filename, "wb");
        if (file != nullptr)
        {
            fwrite(&Pessoa::TAM, sizeof(int), 1, file);
            fclose(file);
        }
    }

    return Pessoa::TAM;
}

// Setters e Getters da classe Pessoa
void Pessoa::setNome(string nome)
{
    this->nome = nome;
}

string Pessoa::getNome()
{
    return nome;
}

// Valida e define o CPF no formato correto
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

// Define a data de nascimento
bool Pessoa::setNascimento(int dia, int mes, int ano)
{
    return this->nascimento.setData(dia, mes, ano);
}

Data Pessoa::getNascimento()
{
    return nascimento;
}

// Lê CPF do usuário com validação de formato
string leiaCPF()
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
    return cpf;
}

// Pesquisa pessoa por nome
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

// Pesquisa pessoa por CPF
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

// Deleta pessoa por CPF
bool deletaPessoa(Pessoa *pessoas[])
{
    string cpf;
    cout << "\nCPF para excluir (000.000.000-00): ";
    cin.ignore();
    getline(cin, cpf);

    bool apagou = false;

    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getCPF() == cpf)
        {
            for (int j = i; j < Pessoa::TAM - 1; j++)
            {
                delete pessoas[j];
                pessoas[j] = pessoas[j + 1]; // Faz o "shift"
            }
            Pessoa::TAM--;
            cout << "Pessoa excluida com sucesso!\n";
            apagou = true;
        }
    }
    if (apagou == false)
    {
        cout << "CPF não encontrado.\n";
    }
    return apagou;
}

// Construtores da classe Pessoa
Pessoa::Pessoa()
{
    nascimento.setData();
    nome = "";
}

Pessoa::Pessoa(string nome)
{
    nascimento.setData();
    setNome(nome);
}

Pessoa::Pessoa(string nome, int dia, int mes, int ano)
{
    nascimento.setData(dia, mes, ano);
    setNome(nome);
}

Pessoa::~Pessoa()
{
}

// Remove todas as pessoas da memória
void apagarTodos(Pessoa *pessoas[])
{
    // Apaga todos os objetos da memoria primeiro
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i] != nullptr)
        {
            delete pessoas[i];
            pessoas[i] = nullptr;
        }
    }
    Pessoa::TAM = 0;
    printf("Todos os cadastros foram removidos.\n");
}

// Carrega pessoas do arquivo
void carregaPessoas(Pessoa *pessoas[])
{
    FILE *arquivo = fopen("pessoas.dat", "rb");
    if (arquivo)
    {
        int loaded = 0;
        Pessoa *p;

        // O laço continua enquanto houver espaço no array (loaded < Pessoa::TAM)
        // E a função conseguir ler uma nova pessoa do arquivo.
        // A atribuição e a verificação são feitas em uma única expressão.
        while (loaded < Pessoa::TAM && (p = criarPessoaDoArquivo(arquivo)) != nullptr)
        {
            pessoas[loaded++] = p;
        }

        fclose(arquivo);
        Pessoa::TAM = loaded; // Atualiza o TAM para o número de pessoas carregadas
    }
}

// Cria objeto Pessoa a partir do arquivo baseado no tipo
Pessoa *criarPessoaDoArquivo(FILE *arquivo)
{
    int tipo;
    Pessoa *novaPessoa = nullptr;

    int itemsLidos = fread(&tipo, sizeof(int), 1, arquivo);
    if (itemsLidos != 1)
    {
        novaPessoa = nullptr;
    }

    switch (tipo)
    {
    case 1:
        novaPessoa = new Aluno();
        try
        {
            processarObjeto(novaPessoa);
        }
        catch (const runtime_error &e)
        {
            cout << e.what() << endl;
        }
        break;
    case 2:
        novaPessoa = new Professor();
        try
        {
            processarObjeto(novaPessoa);
        }
        catch (const runtime_error &e)
        {
            cout << e.what() << endl;
        }
        break;
    default:
        novaPessoa = nullptr;
    }

    if (novaPessoa != nullptr)
    {
        if (!novaPessoa->carregar(arquivo))
        {
            delete novaPessoa;
            novaPessoa = nullptr;
        }
    }

    return novaPessoa;
}

// Salva o tamanho atual no arquivo
void gravaTAM()
{
    FILE *arquivo = fopen("tamanhoArq.dat", "wb");
    if (arquivo)
    {
        fwrite(&Pessoa::TAM, sizeof(int), 1, arquivo);
        fclose(arquivo);
    }
}

// Salva todas as pessoas no arquivo
void gravaPessoas(Pessoa *pessoas[])
{
    FILE *arquivo = fopen("pessoas.dat", "wb");
    if (arquivo)
    {
        for (int i = 0; i < Pessoa::TAM; ++i)
        {
            if (pessoas[i] != nullptr)
            {
                pessoas[i]->gravar(arquivo);
            }
        }
        fclose(arquivo);
        gravaTAM();
    }
}

// Finaliza o sistema salvando dados
void despedida(Pessoa *pessoas[])
{
    gravaPessoas(pessoas);
}

// Lista aniversariantes de um mês específico
void listarTodosAniversariantes(Pessoa *pessoas[], int mes)
{
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        Data nascimento = pessoas[i]->getNascimento();
        int mesNiver = nascimento.getMes();
        if (mes == mesNiver)
        {
            pessoas[i]->escrevePessoa();
        }
    }
}

// Processa objeto com tratamento de exceção
void processarObjeto(Pessoa *pessoa)
{
    if (pessoa == nullptr)
    {
        throw runtime_error("Erro: Objeto é NULL.");
    }
    pessoa->mostrarMensagem();
}

// Mensagem de inicialização
void Pessoa::mostrarMensagem()
{
    cout << "Pessoa inicializada e funcional!" << endl;
}