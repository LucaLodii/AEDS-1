#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void apresentacao(){
    printf("\nSoma de dois numeros\n");
}
float leiaReal(){
    float x;
    printf("\nDigite o numero: ");
    scanf("%f", &x);
    return x;
}
float soma(float X, float Y){
    return X+Y;
}
void resultado(float C){
    printf("\nO resultado eh: %.f", C);
}

    int main(){
        apresentacao();
        float A = leiaReal();
        float B = leiaReal();
        float C = soma(A, B);
        resultado (C);
        return 0;
    }
