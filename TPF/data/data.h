#ifndef DATA_H
#define DATA_H

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

// Calcula idade baseado na data atual do sistema
int calcularIdade(Data nascimento);

#endif