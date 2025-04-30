#include <stdio.h>
#include <stdlib.h>
//VERSÃO RECURSIVA

void inverterArrayRecursivo(float arr[], int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }

    float temp = arr[inicio];
    arr[inicio] = arr[fim];
    arr[fim] = temp;

    inverterArrayRecursivo(arr, inicio + 1, fim - 1);
}

int main() {
    float notas[] = {1.5, 2.3, 4.7, 5.2};
    int n = sizeof(notas)/sizeof(notas[0]);
    
    inverterArrayRecursivo(notas, 0, n-1);
    
    for (int i = 0; i < n; i++) {
        printf("%.1f ", notas[i]);
    }
    
    return 0;
}