#ifndef PESSOAS_H
#define PESSOAS_H

#include "../data/data.h"

#define MAX_STR 50
#define MAX 100

extern int TAM;

typedef struct {
    char CPF[15];           // Implementado na lista 32, 000.000.000-00
    char nome[MAX_STR];
    Data nascimento;
} Pessoa;

// Funções de inicialização/encerramento
void abertura(Pessoa pessoas[]); 
void carregaPessoas(Pessoa pessoas[]);
void despedida(Pessoa pessoas[]); 

// Não sei o nome
int tamanho(char* arq);
void gravaPessoas(Pessoa pessoas[]); 

// Funções de exibição
void escrevaEstPessoa(Pessoa pessoa);
void escrevaPessoa(Pessoa pessoas[], int i); 

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