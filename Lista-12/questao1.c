#include <stdio.h>
#include <stdlib.h>
void apresentacao(){
    printf("\nEsse programa soma 2 inteiros\n");
}
float leiaReal(){
    float x;
    printf("\nInforme o numero: ");
    scanf("%f",&x);
    return x;
}
float soma(float x, float y){
    return x+y;
}
void resultado(float C){
    printf("\nA soma eh: %.f",C);
}
int main(){
    float A = leiaReal();
    float B = leiaReal();
    float C = soma(A,B);
    resultado (C);
    return 0;
}