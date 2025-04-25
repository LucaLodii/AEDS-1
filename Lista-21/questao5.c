#include <stdio.h>
#include <stdlib.h>

void ordemCrescente(float arr[], int n){

    for (int i = 1; i < n; i++) {
        if (notas[i] < ) {

        }
    }

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
        printf("%.1f ", arr[i]);
    }

    return 0;
}