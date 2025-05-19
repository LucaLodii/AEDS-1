#ifndef PESSOAS_H
#define PESSOAS_H

#include "../data/data.h"

#define MAX_STR 50
#define MAX 100

extern int TAM;

typedef struct {
    char nome[MAX_STR];
    Data nascimento;
} Pessoa;

// Funções de inicialização/encerramento
void abertura(Pessoa pessoas[]);
void carregaPessoas(Pessoa pessoas[]);
void despedida(Pessoa pessoas[]);

// Funções de persistência
int tamanho(char* arq);

// Funções de exibição
void escrevaEstPessoa(Pessoa pessoa);
void escrevaPessoa(Pessoa pessoas[], int i);

// Funções de manipulação
void cadastrePessoa(Pessoa pessoas[]);
float idadeMedia(Pessoa pessoas[]);

#endif