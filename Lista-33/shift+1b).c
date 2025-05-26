#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

int TAM = 0;

void shiftMais1(float A[], int posicao){
    shiftMais1Rec(A, posicao, TAM);
}
void shiftMais1Rec(float A[], int posicao, int frente){
    if (posicao >= 0 && posicao <= TAM && TAM < MAX && frente > 0 && frente <= TAM + 1){
        if (frente > posicao){
            A[frente] = A[frente - 1];
            shiftMais1Rec(A, posicao, frente - 1);
        }
    }
}

bool insira(float A[], float X, int posicao){
    bool sucesso = true;
    if (TAM < MAX){
        shiftMais1(A, posicao);
        A[posicao] = X;
        TAM++;
        sucesso = true;
    }

    return sucesso;
}