/*H**************************************************************************************************************
*FILENAME  :    pessoa.cpp                      DESIGN REF:      TPF
*
* DESCRIPTION :
*       Implementação da classe base abstrata 'Pessoa' e das funcionalidades
*       globais para gerenciamento de um array de objetos Pessoa. Define a estrutura
*       comum de dados (nome, CPF, data de nascimento) e os métodos polimórficos
*       (leiaPessoa, escrevePessoa, gravar, carregar, getTipo) que devem ser
*       implementados pelas classes derivadas (Aluno, Professor).
*       Este arquivo também contém a lógica central para inicialização do sistema,
*       manipulação de dados em memória e persistência em arquivo binário para
*       odas as entidades 'Pessoa' do sistema.
*       
* PUBLIC FUNCTIONS :
* // Membros Estáticos da Classe Pessoa:
*       static int Pessoa::TAM
*
* // Construtores da Classe Pessoa:
*       Pessoa::Pessoa()
*       Pessoa::Pessoa(string nome)
*       Pessoa::Pessoa(string nome, int dia, int mes, int ano)
*
* // Métodos Virtuais Puros (Interface para classes derivadas):
*       virtual int Pessoa::getTipo() = 0
*       virtual void Pessoa::leiaPessoa() = 0
*       virtual void Pessoa::escrevePessoa() = 0
*       virtual void Pessoa::gravar(FILE *arquivo) = 0
*       virtual bool Pessoa::carregar(FILE *arquivo) = 0
*
* // Destrutor Virtual:
*       virtual Pessoa::~Pessoa()
*
* // Métodos da Classe Pessoa:
*       void Pessoa::setNome(string nome)
*       string Pessoa::getNome()
*       void Pessoa::setCPF(string CPF)
*       string Pessoa::getCPF()
*       void Pessoa::mostrarMensagem()
*       bool Pessoa::setNascimento(int dia, int mes, int ano)
*       Data Pessoa::getNascimento()
*
* // Funções Globais do Sistema (Operando em Pessoa* array):
*       void abertura(Pessoa *pessoas[])
*       void carregaPessoas(Pessoa *pessoas[])
*       void despedida(Pessoa *pessoas[])
*       void processarObjeto(Pessoa *pessoa)
*       int tamanho(const char *filename)
*       void gravaPessoas(Pessoa *pessoas[])
*       Pessoa *criarPessoaDoArquivo(FILE *arquivo)
*       void gravaTAM()
*       void pesquisaPessoaNome(Pessoa *pessoas[])
*       void pesquisaPessoaCPF(Pessoa *pessoas[])
*       void listarTodosAniversariantes(Pessoa *pessoas[], int mes)
*       string leiaCPF() // Função auxiliar para leitura de CPF
*       bool deletaPessoa(Pessoa *pessoas[])
*       void apagarTodos(Pessoa *pessoas[])
*
* NOTES :
*       Parte do Sistema de Registro de Pessoas para o projeto final de AEDs.
*       O arquivo pessoas.cpp é crucial para o gerenciamento polimórfico das entidades.
*
* COPYRIGHT : Luca L. 2025, 2025. All rights reserved.
*
* AUTHOR    : Luca L.                     START DATE : 16 May 25
*
* CHANGES :
*
* REF NO  VERSION   DATE      WHO          DETAIL
*------- ------- --------- ---- -------------------------------------------
*001       1.0     16May25   LL   Criacao inicial do arquivo pessoas.cpp (como pessoas.cpp).
*002       1.1     30Jun25   LL   Implementacao da classe Pessoa como base abstrata e funcoes de gerenciamento polimorfico.
*
*******************************************************************************/

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

void abertura(Pessoa *pessoas[])
{
    cout << "\nControle de Pessoas\n";
    Pessoa::TAM = tamanho("tamanhoArq.dat");
    carregaPessoas(pessoas);
}

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

Pessoa *criarPessoaDoArquivo(FILE *arquivo)
{
    int tipo;
    Pessoa *novaPessoa = nullptr;

    // Tenta ler o tipo de pessoa do arquivo
    int itemsLidos = fread(&tipo, sizeof(int), 1, arquivo);
    if (itemsLidos != 1)
    {
        novaPessoa = nullptr;
    }

    // Cria objeto da classe correta (Aluno ou Professor) com base no tipo
    switch (tipo)
    {
    case 1: // Aluno
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
    case 2: // Professor
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
    default: // Tipo desconhecido
        novaPessoa = nullptr;
    }

    // Carrega dados do objeto e verifica sucesso
    if (novaPessoa != nullptr)
    {
        if (!novaPessoa->carregar(arquivo))
        {
            delete novaPessoa; // Libera memória em caso de falha no carregamento
            novaPessoa = nullptr;
        }
    }

    return novaPessoa;
}

// Grava o contador total de pessoas (Pessoa::TAM) em arquivo
void gravaTAM()
{
    FILE *arquivo = fopen("tamanhoArq.dat", "wb");
    if (arquivo)
    {
        fwrite(&Pessoa::TAM, sizeof(int), 1, arquivo);
        fclose(arquivo);
    }
}

// Grava todas as pessoas do array em arquivo
void gravaPessoas(Pessoa *pessoas[])
{
    FILE *arquivo = fopen("pessoas.dat", "wb");
    if (arquivo)
    {
        for (int i = 0; i < Pessoa::TAM; ++i)
        {
            if (pessoas[i] != nullptr)
            {
                pessoas[i]->gravar(arquivo); // Grava objeto polimorficamente
            }
        }
        fclose(arquivo);
        gravaTAM(); // Atualiza o arquivo de tamanho
    }
}

// Função de despedida: salva dados ao encerrar
void despedida(Pessoa *pessoas[])
{
    gravaPessoas(pessoas);
}

// Lista aniversariantes para um dado mês
void listarTodosAniversariantes(Pessoa *pessoas[], int mes)
{
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        Data nascimento = pessoas[i]->getNascimento();
        int mesNiver = nascimento.getMes();
        if (mes == mesNiver)
        {
            pessoas[i]->escrevePessoa(); // Exibe pessoa polimorficamente
        }
    }
}

// Processa um objeto Pessoa, com tratamento de exceção
void processarObjeto(Pessoa *pessoa)
{
    if (pessoa == nullptr)
    {
        throw runtime_error("Erro: Objeto é NULL.");
    }
    pessoa->mostrarMensagem();
}

// Exibe mensagem de inicialização da Pessoa
void Pessoa::mostrarMensagem()
{
    cout << "Pessoa inicializada e funcional!" << endl;
}