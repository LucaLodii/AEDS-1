#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TAM 50

typedef struct {
    int ano;
    char campeao[TAM];
} CampeonatoBrasileiro;

int contaTitulos(CampeonatoBrasileiro campeonatos[], char timePesquisa[]) {
    int contador = 0;
    
    for (int i = 0; i < TAM; i++) {
        if (campeonatos[i].campeao == timePesquisa[i]) {
            contador++;
        }
    }
    
    return contador;
}