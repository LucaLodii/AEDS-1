#ifndef PESSOAS_H
#define PESSOAS_H

#include "data.h"

#define MAX 100

extern int TAM; // Variável global compartilhada

typedef struct {
    char nome[50];
    Data nascimento;
} Pessoa;

// Funções de gestão de pessoas
void cadastrarPessoa(Pessoa pessoas[]);
void listarPessoas(Pessoa pessoas[]);
float idadeMedia(Pessoa pessoas[]);
void salvarDados(Pessoa pessoas[]);
void carregarDados(Pessoa pessoas[]);

#endif