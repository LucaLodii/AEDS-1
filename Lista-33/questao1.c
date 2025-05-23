#include <stdbool.h>
#include <stdbool.h>

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

bool saoIguais(Pessoa a, Pessoa b) {
    if (a.idade != b.idade) return false;
    
    for (int i = 0; a.nome[i] || b.nome[i]; i++)
        if (a.nome[i] != b.nome[i]) return false;
    
    return true;
}