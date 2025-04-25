#include <stdio.h>
#include <stdlib.h>

int ordemCrescente(float arr[], int n){
    for(int j = 0; j < n; j++){
        int pos_maior = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[pos_maior]) {
                pos_maior = i;
            }
        }
        float temp = arr[(n-1)-j];
        arr[(n-1)-j] = arr[pos_maior];
        arr[pos_maior] = temp;
    }
    return n;
}

int main(){
    float arr[4];
    int n = 4;

    for (int i = 0; i < n; i++) {            //Coloca as valor no array
        printf("\nDigite o valor %d: ",i+1);
        scanf("%f",&arr[i]);
    }

    ordemCrescente(arr, n);

    printf("\nArranjo apos troca: ");         //Valores apos a funcao que trocaa as notas
    for (int i = 0; i < n; i++) {
        printf("%.f ", arr[i]);
    }

    return 0;
}