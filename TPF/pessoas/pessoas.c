#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pessoas.h"
#include "data.h"

int TAM = 0; // Definição da variável global

void cadastrarPessoa(Pessoa pessoas[]) {
    if (TAM >= MAX) {
        printf("Limite máximo atingido!\n");
        return;
    }

    while (getchar() != '\n'); // Limpa buffer
    
    printf("\nNome: ");
    fgets(pessoas[TAM].nome, 50, stdin);
    pessoas[TAM].nome[strcspn(pessoas[TAM].nome, "\n")] = '\0';

    printf("Data de nascimento (DD MM AAAA): ");
    scanf("%d/%d/%d",
          &pessoas[TAM].nascimento.dia,
          &pessoas[TAM].nascimento.mes,
          &pessoas[TAM].nascimento.ano);

    TAM++;
    printf("Cadastro realizado!\n");
}

void listarPessoas(Pessoa pessoas[]) {
    if (TAM == 0) {
        printf("Nenhuma pessoa cadastrada!\n");
        return;
    }

    printf("\nPessoas cadastradas:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%s - %02d/%02d/%04d (%d anos)\n",
               pessoas[i].nome,
               pessoas[i].nascimento.dia,
               pessoas[i].nascimento.mes,
               pessoas[i].nascimento.ano,
               calcularIdade(pessoas[i].nascimento));
    }
}

float idade_media(Pessoa pessoas[]) {  
    if (TAM == 0) {
        printf("Nenhuma pessoa cadastrada!\n");
        return 0.0f;
    }

    int soma_idade = 0;
    Data hoje;

    time_t now = time(NULL);
    struct tm *lt = localtime(&now);
    hoje.dia = lt->tm_mday;
    hoje.mes = lt->tm_mon + 1;
    hoje.ano = lt->tm_year + 1900;

    for (int i = 0; i < TAM; i++) {
        soma_idade += calcular_idade(pessoas[i].nascimento, hoje);
    }

    return soma_idade/(float)TAM;
}

int calcular_idade(Data nascimento, Data hoje){
    int idade;
    int soma_dias = 0;

    int dias_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dias_mes_bissexto[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //calcular quantos dias ele viveu ate hoje
    for(int i = nascimento.ano; i < hoje.ano; i++){
        if((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)){
            soma_dias += 366;
        } else {
            soma_dias += 365;
        }
    }
    //subtrai dias ano nascimento
    if((nascimento.ano % 4 == 0 && nascimento.ano % 100 != 0) || (nascimento.ano % 400 == 0)){
        for(int i = 0; i < nascimento.mes-1; i++){
            soma_dias -= dias_mes_bissexto[i];
        }
    } else {
        for(int i = 0; i < nascimento.mes-1; i++){
            soma_dias -= dias_mes[i];
        }
    }
    soma_dias -= nascimento.dia;
    
    //adiciona dias ano atual
    if((hoje.ano % 4 == 0 && hoje.ano % 100 != 0) || (hoje.ano % 400 == 0)){
        for(int i = 0; i < hoje.mes-1; i++){
            soma_dias += dias_mes_bissexto[i];
        }
    } else {
        for(int i = 0; i < hoje.mes-1; i++){
            soma_dias += dias_mes[i];
        }
    }
    soma_dias += hoje.dia;

    idade = soma_dias/365;

    return idade;
}

void salvarDados(Pessoa pessoas[]) {
    FILE *arquivoTAM = fopen("tamanho.dat", "wb");
    if (arquivoTAM) {
        fwrite(&TAM, sizeof(int), 1, arquivoTAM);
        fclose(arquivoTAM);
    }

    FILE *arquivoPessoas = fopen("pessoas.dat", "wb");
    if (arquivoPessoas) {
        fwrite(pessoas, sizeof(Pessoa), TAM, arquivoPessoas);
        fclose(arquivoPessoas);
    }
}

void carregarDados(Pessoa pessoas[]) {
    FILE *arquivoTAM = fopen("tamanho.dat", "rb");
    if (arquivoTAM) {
        fread(&TAM, sizeof(int), 1, arquivoTAM);
        fclose(arquivoTAM);
    }

    FILE *arquivoPessoas = fopen("pessoas.dat", "rb");
    if (arquivoPessoas) {
        fread(pessoas, sizeof(Pessoa), TAM, arquivoPessoas);
        fclose(arquivoPessoas);
    }
}