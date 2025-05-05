#include <stdio.h>
// VERSÃO RECURSIVA
void qtMaiorQueX(float arr[], int size, float x){
    int countMaiorQueX = 0;
    for (int i = 0; i < size; i++){
        if(arr[i] > x) countMaiorQueX++;
    }
    printf("\nExistem %i numero(s) maior que %.2f", countMaiorQueX, x);
}

int main()
{
    float arr[] = {-1.5, 2.3, -4.7, 0.0, -3.2, 15.6};
    float x;
    int size = 6;
    printf("\nDigite um numero X para calcularamos a quantidade de numeros maior q ele presentes nesse arr: ");
    for (int i = 0; i < size; i++)
    {
        printf("\n%io: %.1f", i + 1, arr[i]);
    }
    printf("\nDigite o valor de X: ");
    scanf("%f", &x);

    qtMaiorQueX(arr, size, x);

    return 0;
}