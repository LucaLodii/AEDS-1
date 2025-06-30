/*H******************************************************************************
* FILENAME :    pessoas.hpp                   DESIGN REF:     TP

* DESCRIPTION :
*       Header da classe abstrata Pessoa e funções auxiliares do sistema.
*       Define a interface base para todas as pessoas no sistema (Alunos e Professores),
*       incluindo funcionalidades de cadastro, pesquisa, exclusão e persistência.
*
* PUBLIC FUNCTIONS :
*       - Classe abstrata Pessoa com funções virtuais puras
*       - Funções de inicialização do sistema (abertura, despedida)
*       - Funções de persistência (carregaPessoas, gravaPessoas, tamanho)
*       - Funções de pesquisa (pesquisaPessoaNome, pesquisaPessoaCPF)
*       - Funções de manipulação (deletaPessoa, apagarTodos)
*       - Funções utilitárias (leiaCPF, listarTodosAniversariantes)
*
* NOTES :
*       Classe base abstrata que define a interface comum para Alunos e Professores.
*       Implementa funcionalidades de persistência em arquivo e operações CRUD.
*       Todas as funções seguem o padrão de um único retorno sem breaks.
*       Sistema de arquivos binários para armazenamento de dados.
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
* 001     1.0     16May25   LL   Criacao inicial do arquivo pessoas.hpp.
* 002     2.0     30Jun06   LL   Implementação de sistema de persistência
*
*H*/

#ifndef PESSOAS_HPP
#define PESSOAS_HPP

#include "../data/data.hpp"
#include <iostream>
#include <string>

using namespace std;

#define MAX 100

class Pessoa
{
private:
    string nome; // Nome da pessoa
    string CPF;  // CPF: 000.000.000-00
    Data nascimento;

public:
    static int TAM;
    Pessoa();
    Pessoa(string nome);
    Pessoa(string nome, int dia, int mes, int ano);
    virtual int getTipo() = 0;

    virtual ~Pessoa();

    void setNome(string);
    string getNome();

    void setCPF(string);
    string getCPF();
    void mostrarMensagem();

    bool setNascimento(int dia, int mes, int ano);
    Data getNascimento();

    virtual void leiaPessoa() = 0;
    virtual void escrevePessoa() = 0;
    virtual void gravar(FILE *arquivo) = 0;
    virtual bool carregar(FILE *arquivo) = 0;
};

// --- Funções auxiliares do sistema ---
void abertura(Pessoa *pessoas[]);       // Inicializa o sistema
void carregaPessoas(Pessoa *pessoas[]); // Carrega do arquivo
void despedida(Pessoa *pessoas[]);      // Grava no arquivo ao encerrar
void processarObjeto(Pessoa *pessoa);

int tamanho(const char *filename);    // Verifica tamanho do arquivo
void gravaPessoas(Pessoa *pessoas[]); // Salva no arquivo
Pessoa *criarPessoaDoArquivo(FILE *arquivo);
void gravaTAM();

// --- Funções de pesquisa ---
void pesquisaPessoaNome(Pessoa *pessoas[]);
void pesquisaPessoaCPF(Pessoa *pessoas[]);
void listarTodosAniversariantes(Pessoa *pessoas[], int mes);

// --- Funções de manipulação ---
// void cadastrePessoa(Pessoa* pessoas[]);
string leiaCPF();
bool deletaPessoa(Pessoa *pessoas[]);
void apagarTodos(Pessoa *pessoas[]);

#endif
