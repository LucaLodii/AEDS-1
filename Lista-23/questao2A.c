#include <stdio.h>
#include <stdlib.h>
// VERSÃO ITERATIVA

void inverterArrayIterativo(float arr[], int tamanho)
{
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio < fim)
    {
        float temp = arr[inicio];
        arr[inicio] = arr[fim];
        arr[fim] = temp;

        inicio++;
        fim--;
    }
}

int main()
{
    float notas[] = {1.5, 2.3, 4.7, 5.2};
    int n = sizeof(notas) / sizeof(notas[0]);

    inverterArrayIterativo(notas, n);

    for (int i = 0; i < n; i++)
    {
        printf("%.1f ", notas[i]);
    }

    return 0;
}