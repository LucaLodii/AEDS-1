#include <stdio.h>
#include <stdlib.h>

void lerInvertido(float arr[], int size){
    int i;
    printf("\nNumeros presentes no array invertido: ");
    for (i = size-1; i >= 0; i--){
        printf("\n%.1f", arr[i]);
    }
}

int main(){
    float arr[5] = {10, 8, 6, 4, 2};
    int size = 5;
    //printf("\nNumeros presentes no array");
    //for (int i = 0; i < size; i++)
    //{
    //    printf("\n%io: %.1f", i + 1, arr[i]);
   // }
    lerInvertido(arr, size);

    return 0;
}