#include <stdio.h>
// VERSÃO ITERATIVA
void qtNegativo(float arr[], int size)
{
    int countNegativo = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
            countNegativo++;
    }
    printf("\nA quantidade de numeros negativos no array eh: %i", countNegativo);
}

int main()
{
    float arr[5] = {-10, 5, -27, 4, -1};
    int size = 5;
    printf("\nNumeros presentes no array");
    for (int i = 0; i < size; i++)
    {
        printf("\n%io: %.1f", i + 1, arr[i]);
    }
    qtNegativo(arr, size);

    return 0;
}
