//Estou fazendo as questões que estão no final da AULA-17 (depois vou fazer a lista em si)
//questao: Dada uma matriz quadrada de reais, construa uma função que calcule o maior valor presente em sua diagonal principal.
#include <stdio.h>

#define MAX_SIZE 3 //Como é quadrada só precisa de 1 valor

void maiorValorDaDiagonalPrincipalCaralho(float matriz [MAX_SIZE][MAX_SIZE]){
    float maior = matriz[0][0];
    for(int x = 0; x < MAX_SIZE; x++){
        if(matriz[x][x] > maior) maior = matriz[x][x];
    }
    printf("\nO maior valor da diagonal principal da matriz eh: %.f",maior);
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
    maiorValorDaDiagonalPrincipalCaralho(matriz);
}