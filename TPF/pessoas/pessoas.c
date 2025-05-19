#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pessoas.h"
#include "../data/data.h"

int TAM = 0; // Definição da variável global

void abertura(Pessoa pessoas[]){
    printf("\nControle de Pessoas\n");
    TAM = tamanho("tamanhoArq.dat");
    carregaPessoas(pessoas);
}

int tamanho(char* arq) {
    FILE* arqTamanho = fopen(arq,"r");
    if(arqTamanho != NULL) {
        fscanf(arqTamanho, "%i", &TAM);
    } else {
        arqTamanho = fopen(arq,"w");
        TAM = 0;
        fprintf(arqTamanho, "%i", TAM);
    }
    fclose(arqTamanho);
    return TAM;
}

void escrevaEstPessoa(Pessoa pessoa) {
    printf("\nNome: %s", pessoa.nome);
    printf("\nData de Nascimento: %d/%d/%d",
           pessoa.nascimento.dia,
           pessoa.nascimento.mes,
           pessoa.nascimento.ano);
}

void escrevaPessoa(Pessoa pessoas[], int i) {
    escrevaEstPessoa(pessoas[i]);
}

void cadastrePessoa(Pessoa pessoas[])
{
        if (TAM >= MAX) {
        printf("Limite máximo de pessoas atingido!\n");
        return;
    }
    printf("\nNome: ");
    fflush(stdin);
    fgets(pessoas[TAM].nome, 50, stdin);
    pessoas[TAM].nome[strcspn(pessoas[TAM].nome, "\n")] = '\0'; // Remove o '\n'
    printf("\nData de nascimento: ");
    leiaData(&pessoas[TAM].nascimento);
    TAM++;
}

float idadeMedia(Pessoa pessoas[]) {
    if (TAM == 0) {
        printf("Nenhuma pessoa cadastrada!\n");
        return 0.0f;
    }

    float soma = 0;
    for (int i = 0; i < TAM; i++) {
        soma += calcularIdade(pessoas[i].nascimento);
    }
    return soma / TAM;


    // int soma_idade = 0;
    // Data hoje;

    // time_t now = time(NULL);
    // struct tm *lt = localtime(&now);
    // hoje.dia = lt->tm_mday;
    // hoje.mes = lt->tm_mon + 1;
    // hoje.ano = lt->tm_year + 1900;

    // for (int i = 0; i < TAM; i++)
    // {
    //     soma_idade += calcularIdade(pessoas[i].nascimento, hoje);
    // }

    // return soma_idade / (float)TAM;
}


// int calcularIdade(Data nascimento, Data hoje)
// {
//     int idade;
//     int soma_dias = 0;

//     int dias_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     int dias_mes_bissexto[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     // calcular quantos dias ele viveu ate hoje
//     for (int i = nascimento.ano; i < hoje.ano; i++)
//     {
//         if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
//         {
//             soma_dias += 366;
//         }
//         else
//         {
//             soma_dias += 365;
//         }
//     }
//     // subtrai dias ano nascimento
//     if ((nascimento.ano % 4 == 0 && nascimento.ano % 100 != 0) || (nascimento.ano % 400 == 0))
//     {
//         for (int i = 0; i < nascimento.mes - 1; i++)
//         {
//             soma_dias -= dias_mes_bissexto[i];
//         }
//     }
//     else
//     {
//         for (int i = 0; i < nascimento.mes - 1; i++)
//         {
//             soma_dias -= dias_mes[i];
//         }
//     }
//     soma_dias -= nascimento.dia;

//     // adiciona dias ano atual
//     if ((hoje.ano % 4 == 0 && hoje.ano % 100 != 0) || (hoje.ano % 400 == 0))
//     {
//         for (int i = 0; i < hoje.mes - 1; i++)
//         {
//             soma_dias += dias_mes_bissexto[i];
//         }
//     }
//     else
//     {
//         for (int i = 0; i < hoje.mes - 1; i++)
//         {
//             soma_dias += dias_mes[i];
//         }
//     }
//     soma_dias += hoje.dia;

//     idade = soma_dias / 365;

//     return idade;
// }

void carregaPessoas(Pessoa pessoas[]) {
    FILE* arquivo = fopen("pessoas.dat", "rb");
    if (arquivo) {
        fread(pessoas, sizeof(Pessoa), TAM, arquivo);
        fclose(arquivo);
    }
}

void gravaPessoas(Pessoa pessoas[]) {
    FILE* arquivo = fopen("pessoas.dat", "wb");
    if (arquivo) {
        fwrite(pessoas, sizeof(Pessoa), TAM, arquivo);
        fclose(arquivo);
    }
}

void despedida(Pessoa pessoas[]){
printf("\nObrigado!\n");
gravaPessoas(pessoas);
}
