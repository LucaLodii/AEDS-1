#include <stdio.h>
#include <stdbool.h>

#define MAX 100  

typedef struct {
    char nome[50];
    int idade;
} Pessoa;


void listarRecursivo(Pessoa PESSOAS[], int contador) {  
    if(contador >= MAX) return;  
    printf("\nO nome da %do pessoa eh: %s", contador+1, PESSOAS[contador].nome);  
    listarRecursivo(PESSOAS, contador+1);  
}
