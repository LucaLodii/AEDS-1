//iterativo
#include <stdio.h>

int losangoPt2(int tamanho){
    int espacoExterno = tamanho-1;
    int espacoInterno = 1;
    //printf("%d",tamanho);
        while(espacoExterno>=0){
            for(int j = 1; j<=espacoInterno;j++){
                printf(" ");
                }
            for(int i = 1; i<espacoExterno*2;i++){
                printf("*");
                }
                printf("\n");
                espacoInterno++;
            espacoExterno--;
        }
        return 0;} 

int losangoPt1(int tamanho){
    int espacoExterno = tamanho-1;
    int espacoInterno = 0;

    //PRIMEIRA METADE: inicio
    while(espacoExterno>=0){
        for(int i = 1; i<=espacoExterno;i++){
            printf(" ");
        }
        printf("*");
        for(int j = 0; j<espacoInterno;j++){
            printf("*");
            printf("*");}
        espacoInterno++;
        printf("\n");
        espacoExterno--;
    }
    
//PRIMEIRA METADE: inicio
    return 0;
}

int lerTamanho(){
    int tamanho;
    printf("\nDigite o tamanho da aresta do losango: ");
    scanf("%d",&tamanho);
    return tamanho;
}

int main(){
    int A = lerTamanho();
    losangoPt1(A);
    losangoPt2(A);
}