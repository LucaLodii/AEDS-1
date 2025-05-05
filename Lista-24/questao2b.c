#include <stdio.h>
// VERSÃO RECURSIVA
void qtNegativo(float arr[], int size, int j, int countNegativo)
{

    if(j < size){
        if(arr[j] < 0) return qtNegativo(arr, size, j+1, countNegativo+1);
        else return qtNegativo(arr, size, j+1, countNegativo);
    }
    printf("\nA quantidade de numeros negativos no array eh: %i", countNegativo);
}

int main()
{
    float arr[5] = {-10, 5, -27, 4, -1};
    int size = 5, j = 0, countNegativo = 0;
    printf("\nNumeros presentes no array");
    for (int i = 0; i < size; i++)
    {
        printf("\n%io: %.1f", i + 1, arr[i]);
    }
    qtNegativo(arr, size, 0, 0);
    
    return 0;
}
