#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 3 

bool contemChave(float matriz[MAX_SIZE][MAX_SIZE], float chave){
    for(int i = 0; i < MAX_SIZE; i++){
        for(int j = 0; j < MAX_SIZE; j++){
            if(matriz[i][j] == chave) return true;
        }
    }
    return false;
}

void leMatriz(float matriz[MAX_SIZE][MAX_SIZE]){
    printf("\nDigite os valores da matriz %dx%d:\n", MAX_SIZE, MAX_SIZE);
    for(int i = 0; i < MAX_SIZE; i++){
        for(int j = 0; j < MAX_SIZE; j++){
            printf("Posicao [%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }
}

int main(){
    float chave = 0;
    printf("\nO valor chave eh: %.2f", chave);

    float matriz[MAX_SIZE][MAX_SIZE];
    leMatriz(matriz);

    if(contemChave(matriz, chave)) {
        printf("\nA matriz contem zero!");
    } else {
        printf("\nA matriz NAO contem zero!");
    }

    return 0;
}