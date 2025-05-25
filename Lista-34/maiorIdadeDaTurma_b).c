#include <stdio.h>

#define MAX 50 

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

int maiorDaTurmaRec(Pessoa alunos[], int TAM, int maior, int i){
    if(i < TAM){
        if(alunos[i].idade > maior) {
            maior = alunos[i].idade;
        }
        return maiorDaTurmaRec(alunos, TAM, maior, i+1);
    }
    return maior;
}

int maiorDaTurma(Pessoa alunos[], int TAM) {
    return maiorDaTurmaRec(alunos, TAM, alunos[0].idade, 1);
}