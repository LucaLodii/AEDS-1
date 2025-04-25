#include <stdio.h>
#include <stdlib.h>

void trocaPrimeiroUltimo(float notas[], int n) {
    if (n > 0) {
        float temp = notas[0];
        notas[0] = notas[n-1];
        notas[n-1] = temp;
    }
}

int main()
{
    float notas[4];
    int n = 4;

    for (int i = 0; i < n; i++){            //Coloca as notas no array
        printf("\nDigite a nota %d: ",i+1);
        scanf("%f",&notas[i]);
    }

    printf("\nNotas originais: ");          //Fala as notas q vc digitou
    for (int i = 0; i < n; i++) {
        printf("%.1f ", notas[i]);
    }

    trocaPrimeiroUltimo(notas, n);

    printf("\nNotas apos troca: ");         //Fala as notas apos a funcao que trocaa as notas
    for (int i = 0; i < n; i++) {
        printf("%.1f ", notas[i]);
    }

    return 0;
}