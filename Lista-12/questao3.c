#include <stdio.h>

void apresentacao(){
    printf("\nEste programa calcula o perimetro de quadrados\n");
}
float lerLado(){
    float lado;
    printf("\nInforme o lado do quadrado: ");
    scanf("%f",&lado);
    return lado;
}
float calc(float lado){
    float perimetro = 0;
    perimetro = lado * 4;
    return perimetro;
}
void resultado(float perimetro){
    printf("\nO perimetro eh: %.1f",perimetro);
}
int main(){
    apresentacao();

    float A = lerLado();
    float B = calc(A);

    resultado(B);

}