#include <stdio.h>
#include <stdlib.h>

float* calcMedia(int *a, int *b){
    float *media = malloc(sizeof(float));
    *media = (*a + *b)/2.0f;
    return media;
}

int main(){
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));

    printf("\nInforme a: ");
    scanf("%d",a);
    printf("\nInforme b: ");
    scanf("%d",b);

    //calcMedia(a,b);
    float *media = calcMedia(a, b);

    printf("\nA media entre %d e %d eh: %.f", *a, *b, *media);

    free(a);
    free(b);
    free(media);

    return 0;
}