#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void apresentacao()
{
    printf("\nSoma de dois numeros\n");
}
float leiaReal()
{
    float x;
    printf("\nDigite o primeiro numero: ");
    scanf("%f", &x);
    return x;
}
float functionSoma(float X, float Y)
{
    return X+Y;
}

void final(float C){
    printf("\nA soma eh: %.f", C);
}

int main()
{
    setlocale(LC_ALL, "");
    apresentacao();

    float A = leiaReal();
    float B = leiaReal();
    float C = functionSoma (A, B);
    final(C);
    return 0;
}