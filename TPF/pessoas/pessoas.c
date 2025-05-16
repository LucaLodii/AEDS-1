#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

float idadeMedia(Pessoa pessoas[]) {
    if (TAM == 0) {
        printf("Nenhuma pessoa cadastrada!\n");
        return 0.0f;
    }

    int soma = 0;
    for (int i = 0; i < TAM; i++) {
        soma += calcularIdade(pessoas[i].nascimento);
    }

    float media = (float)soma / TAM;
    printf("Idade media: %.1f anos\n", media);
    return media;
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