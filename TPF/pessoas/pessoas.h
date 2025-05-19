#ifndef PESSOAS_H
#define PESSOAS_H

#include "../data/data.h"

#define MAX 100

extern int TAM;

typedef struct {
    char nome[50];
    Data nascimento;
} Pessoa;

int calcular_idade(Data nascimento, Data hoje);
void cadastrarPessoa(Pessoa pessoas[]);
void listarPessoas(Pessoa pessoas[]);
float idadeMedia(Pessoa pessoas[]);
void salvarDados(Pessoa pessoas[]);
void carregarDados(Pessoa pessoas[]);

#endif