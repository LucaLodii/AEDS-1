#include <stdio.h>
#include <stdlib.h>

void lerInvertido(float arr[], int size){
    if(size-1 >= 0) {
        printf("\n%.1f",arr[size-1]);
        lerInvertido(arr, size-1);
    }
}

int main(){
    float arr[5] = {10, 8, 6, 4, 2};
    int size = 5;
    printf("\nNumeros presentes no array invertido: ");
    lerInvertido(arr, size);

    return 0;
}