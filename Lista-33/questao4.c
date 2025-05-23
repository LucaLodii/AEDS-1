#include <stdbool.h>
#include <stdbool.h>
// essa aqui eu chutei o balde, mt sono

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

bool pesquisarPorNomeRecursivo(Pessoa pessoas[], int total, int indice, const char* nomeBuscado) {
    if (indice >= total) return false; 
    if (strcmp(pessoas[indice].nome, nomeBuscado) == 0) return true; 
    return pesquisarPorNomeRecursivo(pessoas, total, indice + 1, nomeBuscado); 
}