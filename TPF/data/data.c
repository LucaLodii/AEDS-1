#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "data.h"

Data obterDataAtual()
{
    Data hoje;
    time_t now = time(NULL);
    struct tm *lt = localtime(&now);
    hoje.dia = lt->tm_mday;
    hoje.mes = lt->tm_mon + 1;
    hoje.ano = lt->tm_year + 1900;
    return hoje;
}

void leiaData(Data *data)
{
    int tentativas = 0;
    const int max_tentativas = 3;
    int dados_lidos;
    char entrada[50];

    while (tentativas < max_tentativas)
    {
        printf("Data (DD/MM/AAAA): ");

        if (!fgets(entrada, sizeof(entrada), stdin))
        {
            clearerr(stdin);
            continue;
        }

        dados_lidos = sscanf(entrada, "%d/%d/%d",
                             &data->dia,
                             &data->mes,
                             &data->ano);

        if (dados_lidos == 3 &&
            data->dia >= 1 && data->dia <= 31 &&
            data->mes >= 1 && data->mes <= 12 &&
            data->ano > 1900)
        {
            return; // Data válida
        }

        printf("Formato inválido! Tente novamente (%d/%d tentativas)\n",
               tentativas + 1, max_tentativas);
        tentativas++;
    }

    // Se falhar todas as tentativas
    data->dia = 1;
    data->mes = 1;
    data->ano = 2000;
    printf("Usando data padrão: 01/01/2000\n");
}

int calcularIdade(Data nascimento)
{
    const Data hoje = obterDataAtual();
    return hoje.ano - nascimento.ano -
           (hoje.mes < nascimento.mes ||
            (hoje.mes == nascimento.mes && hoje.dia < nascimento.dia));
    // time_t t = time(NULL);
    // struct tm *atual = localtime(&t);

    // int idade = atual->tm_year + 1900 - nascimento.ano;

    // if ((atual->tm_mon + 1) < nascimento.mes ||
    //     ((atual->tm_mon + 1) == nascimento.mes && atual->tm_mday < nascimento.dia)) {
    //     idade--;
    // }

    // return idade;
}

void escreveData(Data data)
{
    printf("%02d/%02d/%04d", data.dia, data.mes, data.ano);
}

const char *mesExtenso(Data data)
{
    const char *meses[] = {
        "Janeiro", "Fevereiro", "Março", "Abril",
        "Maio", "Junho", "Julho", "Agosto",
        "Setembro", "Outubro", "Novembro", "Dezembro"};
    return (data.mes >= 1 && data.mes <= 12) ? meses[data.mes - 1] : "Inválido";
}

int diasMes(Data data)
{
    int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Verifica ano bissexto para fevereiro
    if (data.mes == 2 &&
        ((data.ano % 4 == 0 && data.ano % 100 != 0) || (data.ano % 400 == 0)))
    {
        return 29;
    }
    return (data.mes >= 1 && data.mes <= 12) ? dias[data.mes - 1] : 0;
}