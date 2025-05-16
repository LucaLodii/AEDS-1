#include "data.h"
#include <time.h>

int calcularIdade(Data nascimento) {
    time_t t = time(NULL);
    struct tm *atual = localtime(&t);
    
    int idade = atual->tm_year + 1900 - nascimento.ano;
    
    // Ajusta se ainda não fez aniversário este ano
    if ((atual->tm_mon + 1) < nascimento.mes || 
        ((atual->tm_mon + 1) == nascimento.mes && atual->tm_mday < nascimento.dia)) {
        idade--;
    }
    
    return idade;
}