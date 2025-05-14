#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pessoa.h"

#define MAX 100
int TAM = 0;

int main()
{
    int choice;
    do{
        system("clear");
        printf("=============================\n");
        printf("     🧾 Gerenciar Alunos\n");
        printf("=============================\n");
        printf("1. ➕ Cadastrar Aluno\n");
        printf("2. 📋 Listar Alunos\n");
        printf("3. 🔍 Idade Média dos Alunos\n");
        printf("0. ❌ Sair\n");
        printf("-----------------------------\n");

        printf("\nWhat do you want to do? [0 to 9]: ");
        scanf("%i", &choice);
        while (getchar() != '\n' && getchar() != EOF);

        switch (choice)
        {
        case 0:
            choice = 0;
            break;

        case 1:
            cadastrar_pessoa();
            getchar();
            break;

        case 2:
            lista();
            getchar();
            break;

        case 3: 

            break;

        default:
            break;
        }
    }while(choice != 0);

    return 0;
}