#include <stdbool.h>

typedef struct {
    char nome[50];
    float salario;
} Funcionario;

float calcularMediaSalarios(Funcionario funcs[], int tamanho) {
    float soma = 0;
    for (int i = 0; i < tamanho; i++){
        soma += funcs[i].salario;
    }
    float valor = soma / tamanho;
    return valor;
}

int contarAcimaDe(Funcionario funcs[], int tamanho, float valor) {
    int contador = 0;
    for (int i = 0; i < tamanho; i++){
        if (funcs[i].salario > valor) contador++;
    }
    return contador;
}
