#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TAM 50

typedef struct {
    int ano;
    char campeao[TAM];
} CampeonatoBrasileiro;

int contaTitulosRec(CampeonatoBrasileiro campeonatos[], char timePesquisa[], int i, int contador) {
    if(i < TAM){
        if(strcmp(campeonatos[i].campeao, timePesquisa) == 0){  // Corrigido o acesso ao array
            return contaTitulosRec(campeonatos, timePesquisa, i+1, contador+1);
        }
        return contaTitulosRec(campeonatos, timePesquisa, i+1, contador);  // Adicionado caso não encontre
    }
    return contador;
}

void contaTitulos(CampeonatoBrasileiro campeonatos[], char timePesquisa[]) {
    contaTitulosRec(campeonatos, timePesquisa, 0, 0);
}