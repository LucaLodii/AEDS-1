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
