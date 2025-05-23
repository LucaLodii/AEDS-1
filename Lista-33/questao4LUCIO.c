#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
// Na prova essa questao tinha a) Iterativa e b) Recursiva

#define TAM 0
#define maxStr 50

typedef struct
{
    char nome[50];
    int idade;
}Pessoa;

bool strIguais(char str1[], char str2[]){
    bool iguais = true;
    int i = 0;
        while(iguais && i<maxStr  && str1[i]!='\0' && str2[i]!='\0'){
            if(toupper(str1[i]) != toupper(str2[i])) iguais = false;
            i++;
        }
    return iguais;
}

void listaPessoas(Pessoa pessoas[], char* nome){
    for (int i = 0; i < TAM; i++){
        if(strIguais(pessoas[i].nome, nome)){
            escrevaPessoa(pessoas[i]);
        }
    }
}

int main(){
    Pessoa P[2] = {"RAFA",18, "DUDA",17};
    listaPessoas(P, "DUDA");
}