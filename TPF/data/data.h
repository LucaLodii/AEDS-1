#ifndef DATA_H
#define DATA_H

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

int calcularIdade(Data nascimento);
Data obterDataAtual();
void leiaData(Data *data);
void escreveData(Data data);
const char* mesExtenso(Data data);
int diasMes(Data data);

#endif