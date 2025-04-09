#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void pesoM(int* altura, int* pesoIdeal) {
    *pesoIdeal = (*altura - 100) - ((*altura - 150) / 4);  
}

void pesoF(int* altura, int* pesoIdeal) {
    *pesoIdeal = (*altura - 100) - ((*altura - 150) / 2); 
}

int main() {
    char *gen = malloc(sizeof(char));
    int *altura = malloc(sizeof(int));
    int *pesoIdeal = malloc(sizeof(int));
    
    printf("Informe seu genero [M ou F] por favor: ");
    scanf(" %c", gen);
    *gen = toupper(*gen);

    while (*gen != 'M' && *gen != 'F') {
        printf("Genero invalido! Digite M ou F: ");
        scanf(" %c", gen);
        *gen = toupper(*gen);
    }

    printf("Informe sua altura (em cm): ");
    scanf("%d", altura);

    if (*gen == 'M') {
        pesoM(altura, pesoIdeal);
    } else {
        pesoF(altura, pesoIdeal);
    }

    printf("Seu peso ideal eh: %d kg\n", *pesoIdeal);

    free(gen);
    free(altura);
    free(pesoIdeal);
    return 0;
}