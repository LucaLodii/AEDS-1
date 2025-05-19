#ifndef DATA_H
#define DATA_H

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

Data obterDataAtual();

int calcularIdade(Data nascimento);
int diasMes(Data data);

void leiaData(Data *data);
void escreveData(Data data);
const char* mesExtenso(Data data);

#endif