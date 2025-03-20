#include <stdio.h>
#include <stdlib.h>
void apresentacao(){
    printf("\nEsse programa vai calcular o maior entre dois valores reais\n");
}
float leiaReal(){
    float x;
    printf("\nInforme um valor: ");
    scanf("%f",&x);
    return x;
}
float maior(float x, float y){
    if (x > y) {
        return x;
    } else {
        return y;
    }
}
float menor(float x, float y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}
void resultadoMaior(float C){
    printf("\n o maior resultado eh: %.2f",C);
}
void resultadoMenor(float D){
    printf("\n o menor resultado eh: %.2f",D);
}
int main(){
    apresentacao();

    float A = leiaReal();
    float B = leiaReal();

    float C = maior(A,B);
    float D = menor(A,B);

    resultadoMaior(C);
    resultadoMenor(D);
    return 0;
}