#include <stdio.h>
//VERSÃO ITERATIVA
void qtNegativo(int arr[]){
    int countNegativo;
    for(int i = 1; i < 5; i++){
        if(arr[i] < 0) countNegativo++;
    }
    printf("\nA quantidade de numeros negativo eh: %i",countNegativo);
}

int main(){
    int arr[5] = {10, -2, 21, 57, 1};
    qtNegativo(arr);
}