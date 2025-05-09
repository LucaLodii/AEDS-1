// Laborátorio de Sexta
//Dada uma matriz de reais, calcular sua transposta
#include <stdio.h>

#define _m 3
#define _n 2

void listaTransposta(float T[_n][_m]){
    printf("\nLista Transposta");
    for(int i = 0; i < _n; i++){
        printf("\n");
        for(int j = 0; j < _m; j++){
            printf("%.f ",T[i][j]);
        }
    }
}

void transposta(float MAT[][_n], float T[_n][_m]){
        for(int i = 0; i < _n; i++){
            for(int j = 0; j < _m; j++){
                T[i][j] = MAT[i][j];
        }
    }
}

void listaOriginal(float MAT[][_n]){
    printf("\nLista Original");
    for(int i = 0; i < _m; i++){
        printf("\n");
        for(int j = 0; j < _n; j++){
            printf("%.f ",MAT[i][j]);
        }
    }
}

int main(){
    float MAT[][_n] = {10, 20, 30, 40, 50, 60};
    float T[_n][_m];

    listaOriginal(MAT);
    transposta(MAT, T);
    listaTransposta(T);

    return 0;
}