#ifndef PESSOAS_H
#define PESSOAS_H

#include "../data/data.h"
#include <iostream>
#include <cstring>

#define MAX_STR 50
#define MAX 100

extern int TAM;

class Pessoa {
private:
    char nome[MAX_STR];          // Nome da pessoa
    char CPF[15];                // CPF: 000.000.000-00
    Data nascimento;

public:
    // Getters e Setters
    void setNome(const char* novoNome);
    const char* getNome() const;

    void setCPF(const char* novoCPF);
    const char* getCPF() const;

    bool setNascimento(int dia, int mes, int ano);
    Data getNascimento() const;

    // Leitura e escrita de dados
    void leiaNome();
    void escrevaNome() const;

    void leiaPessoa();
    void escrevaPessoa() const;
};

// Funções auxiliares (sistema de gerenciamento)
void abertura(Pessoa pessoas[]);               // Inicializa o sistema
void carregaPessoas(Pessoa pessoas[]);         // Carrega do arquivo
void despedida(Pessoa pessoas[]);              // Grava no arquivo ao encerrar

int tamanho(char* arq);                        // Verifica tamanho do arquivo
void gravaPessoas(Pessoa pessoas[]);           // Salva no arquivo

// Funções de pesquisa
void pesquisaPessoaNome(Pessoa pessoas[]);
void pesquisaPessoaCPF(Pessoa pessoas[]);

// Funções de manipulação
void cadastrePessoa(Pessoa pessoas[]);
void leiaCPF(char cpf[]);
bool deletaPessoa(Pessoa pessoas[]);
void apagarTodos(Pessoa pessoas[]);
float idadeMedia(Pessoa pessoas[]);

#endif
