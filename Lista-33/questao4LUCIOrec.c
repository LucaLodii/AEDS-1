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
} Pessoa;

bool strIguaisR(char str1[], char str2[])
{
    return strIguaisRec(str1, str2, 0);
}

bool strIguaisRec(char* str1, char* str2, int i)
{
    bool iguais = true;
    if (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
            iguais = false;
        else
            iguais = strIguaisR(str1, str2, i + 1);
    }
    return iguais;
}

void listaPessoas(Pessoa pessoas[], char *nome)
{
    for (int i = 0; i < TAM; i++)
    {
        if (strIguaisR(pessoas[i].nome, nome))
        {
            escrevaPessoa(pessoas[i]);
        }
    }
}

int main()
{
    Pessoa P[2] = {"RAFA", 18, "DUDA", 17};
    listaPessoas(P, "DUDA");
}
