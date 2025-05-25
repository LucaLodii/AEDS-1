#include <stdio.h>

#define MAX 50 

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

int maiorDaTurma(Pessoa alunos[], int TAM) {
    
    int maior = alunos[0].idade;
    
    for(int i = 1; i < TAM; i++) {
        if(alunos[i].idade > maior) {
            maior = alunos[i].idade;
        }
    }
    return maior;
}