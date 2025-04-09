#include <stdio.h>

void losango(int linhas, int espaco, int linhasAntes){
    for(int i = 1; i<linhas; i++){
        printf(" ");
    }
    linhas = linhasAntes - 1;
    linhasAntes--;
    for(int j = 1; j<=espaco; j++){
        printf("*");
    }
    espaco+=2;
}

int main(){
    int linhas, espaco = 1, linhasAntes;
    scanf("%d",&linhas);
    linhasAntes = linhas;
    losango(linhas, espaco, linhasAntes);
}