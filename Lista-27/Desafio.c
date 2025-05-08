// Desafio: Pesquisa em uma matriz bidimensional
// Implemente uma função que pesquise por um valor chave em uma matriz de reais. A função deverá gerar verdadeiro, se presente, ou falso, caso contrário.
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 3  //Optei por uma quadrada, mas não há diferença na lógica do programa

bool maiorValorDaDiagonalPrincipalCaralho(float matriz[MAX_SIZE][MAX_SIZE], float chave){
    bool ehChave = false;
    for(int i = 0; i < MAX_SIZE; i++){
        for(int j = 0; j < MAX_SIZE; j++){
            if (matriz[i][j] == chave) {
                ehChave = true;
                }
        }
    }
    if(ehChave == true) printf("\nO valor chave esta presente!");
        else printf("\nO valor chave nao esta presente!");
}

float valorChave() {
    float chave;
    printf("\nEscolha o valor chave: ");
    scanf("%f", &chave);
    return chave;
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

    float chave = valorChave();
    //printf("\nO valor chave eh: %.2f", chave);

    maiorValorDaDiagonalPrincipalCaralho(matriz, chave);
}