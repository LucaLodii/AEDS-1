#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

int TAM = 0;

void shiftMais1(float A[], int posicao){
    if(posicao>=0 && posicao<=TAM && TAM<MAX){
        for(int i=TAM; i>posicao; i--){
                A[i] = A[i-1];
        }
    }
}

bool insira(float A[], float X, int posicao){
    bool sucesso = true;
        if(TAM < MAX){
            shiftMais1(A, posicao);
            A[posicao] = X;
            TAM++;
            sucesso = true;
        }

    return sucesso;
}