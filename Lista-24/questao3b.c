#include <stdio.h>
// VERSÃO RECURSIVA
int qtMaiorQueX(float arr[], float x, int j, int size) {
    if (j >= size) {
        return 0; 
    }
    if (arr[j] > x) {
        return 1 + qtMaiorQueX(arr, x, j + 1, size);
    } else {
        return 0 + qtMaiorQueX(arr, x, j + 1, size);
    }
}

int main() {
    float arr[] = {-1.5, 2.3, -4.7, 0.0, -3.2, 15.6};
    float x;
    int size = 6;
    
    printf("\nArray:");
    for (int i = 0; i < size; i++) {
        printf("\n%do: %.1f", i + 1, arr[i]);
    }
    
    printf("\nDigite o valor de X: ");
    scanf("%f", &x);
    
    int count = qtMaiorQueX(arr, x, 0, size);
    printf("\nExistem %d numero(s) maior que %.2f", count, x);
    
    return 0;
}