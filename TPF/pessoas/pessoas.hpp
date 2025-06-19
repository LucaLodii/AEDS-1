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

    ~Pessoa();

    void setNome(string);
    string getNome();

    void setCPF(string);
    string getCPF();

    bool setNascimento(int dia, int mes, int ano);
    Data getNascimento();

    void leiaNome();
    void escrevaNome();

    void leiaPessoa();
    void escrevePessoa();
};

// --- Funções auxiliares do sistema ---
void abertura(Pessoa pessoas[]);       // Inicializa o sistema
void carregaPessoas(Pessoa pessoas[]); // Carrega do arquivo
void despedida(Pessoa pessoas[]);      // Grava no arquivo ao encerrar

int tamanho(char *arq);              // Verifica tamanho do arquivo
void gravaPessoas(Pessoa pessoas[]); // Salva no arquivo

// --- Funções de pesquisa ---
void pesquisaPessoaNome(Pessoa pessoas[]);
void pesquisaPessoaCPF(Pessoa pessoas[]);

// --- Funções de manipulação ---
void cadastrePessoa(Pessoa pessoas[]);
void leiaCPF(char cpf[]);
bool deletaPessoa(Pessoa pessoas[]);
void apagarTodos(Pessoa pessoas[]);

#endif
