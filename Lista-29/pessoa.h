#ifndef PESSOA_H
#define PESSOA_H

#define MAX 100

typedef struct{
    int dia, mes, ano;
} Data;

typedef struct{
    char nome[50];
    Data nascimento;
} Pessoa;


#define MAX 100

void lista();
void cadastrar_pessoa();
Data cadastro_nascimento();


#endif