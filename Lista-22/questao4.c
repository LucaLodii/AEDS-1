#include <stdio.h>
#include <stdlib.h>

void trocaMaiorUltimo(float notas[], int n) {
    // Find max value and its position
    int pos_menor = 0;
    for (int i = 1; i < n; i++) {
        if (notas[i] < notas[pos_menor]) {
            pos_menor = i;
        }
    }
    // Swap with last position
    float temp = notas[n-1];
    notas[n-1] = notas[pos_menor];
    notas[pos_menor] = temp;
}

int main() {
    float notas[4];
    int n = 4;

    for (int i = 0; i < n; i++) {            //Coloca as notas no array
        printf("\nDigite a nota %d: ",i+1);
        scanf("%f",&notas[i]);
    }

    printf("\nNotas originais: ");          //Fala as notas q vc digitou
    for (int i = 0; i < n; i++) {
        printf("%.1f ", notas[i]);
    }

    trocaMaiorUltimo(notas, n);

    printf("\nNotas apos trocar o menor pelo ultimo: ");
    for (int i = 0; i < n; i++) {
        printf("%.1f ", notas[i]);
    }

    return 0;
}