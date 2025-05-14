#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

static int TAM = 0;
static const char *TAM_FILENAME = "arquivostxt/tam.txt";

Pessoa pessoas;
Data datas;

static void load_tam(){
    FILE* tam_file = fopen(TAM_FILENAME, "r");
    if(tam_file){
        if(fscanf(tam_file, "%i", &TAM) != 1) TAM = 0;
    }
    fclose(tam_file);
}

static void save_tam(void) {
    FILE* tam_file = fopen(TAM_FILENAME, "w");
    if (!tam_file) {
        printf("Não foi possivel escrever em tam.txt\n");
        return;
    }
    fprintf(tam_file, "%d", TAM);
    fclose(tam_file);
}

void cadastrar_pessoa(){
    load_tam();

    if(TAM >= MAX){
        printf("Máximo de cadastros atingido.\n");
        return;
    }

    char name[50];
    printf("Digitar nome: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    strcpy(pessoas.nome, name);

    pessoas.nascimento = cadastro_nascimento();
    TAM++;
    printf("Foi registrado o(a) aluno(a) %s (Nascido em: %i/%i/%i) na posição %i\n", pessoas.nome, pessoas.nascimento.dia, pessoas.nascimento.mes, pessoas.nascimento.ano, TAM);

    char* pessoas_filename = "arquivostxt/pessoas.txt";
    FILE* pessoas_file = fopen(pessoas_filename, "a");
    if(!pessoas_file){
        printf("Nao foi possivel escrever em pessoas.\n");
        return;
    }
    fprintf(pessoas_file, "%s(%i/%i/%i)\n", pessoas.nome, pessoas.nascimento.dia, pessoas.nascimento.mes, pessoas.nascimento.ano);
    fclose(pessoas_file);
    save_tam();
}

Data cadastro_nascimento(){

    char date[11];    
    printf("Digite sua data de nascimento (DD/MM/YYYY): ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = '\0';
    
    int diav, mesv, anov;
    if (sscanf(date, "%d/%d/%d", &diav, &mesv, &anov) != 3 ||
        diav < 1 || diav > 31 ||
        mesv < 1 || mesv > 12 ||
        anov < 1) {
        fprintf(stderr, "Formato de data inválido; Por favor use DD/MM/YYYY.\n");
        return cadastro_nascimento();
    }

    datas.dia = diav;
    datas.mes = mesv;
    datas.ano = anov;

    return datas;
}

void lista(){
    load_tam();

    char* pessoas_filename = "arquivostxt/pessoas.txt";
    FILE* pessoas_file = fopen(pessoas_filename, "r");
    if(!pessoas_file){
        printf("Nao foi possivel ler pessoas.\n");
        return;
    }

    char nome[50];
    int dia,mes,ano,i = 0;
    char buffer[256];
    while(fgets(buffer, sizeof(buffer), pessoas_file)){
        buffer[strcspn(buffer, "\n")] = '\0';
        sscanf(buffer, "%49[^()](%i/%i/%i)", nome, &dia, &mes, &ano);
        printf("Aluno(a) %s (Nascido em: %i/%i/%i) na posição #%i\n", nome, dia, mes, ano, i);
        i++;
    }
    fclose(pessoas_file);
}