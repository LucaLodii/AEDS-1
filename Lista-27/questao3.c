#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 3 

void diagonalSecundaria(float matriz[MAX_SIZE][MAX_SIZE]){
    printf("\nListando os valores que compoe a diagonal secundaria");
    for(int i = 0, j = 2; i <= 2 && j >= 0; i++, j--){
        printf("\nPosicao [%d][%d]: %.f ",i, j, matriz[i][j]);
    }
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
    float matriz[MAX_SIZE][MAX_SIZE];
    leMatriz(matriz);

    diagonalSecundaria(matriz);


    return 0;
}