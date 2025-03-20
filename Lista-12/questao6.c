#include <stdio.h>
void apresentacao(){
    printf("\nEsse programa calcula potenciacao\n");
}
float lerBase(){
    float base;
    printf("\nInforme a base: ");
    scanf("%f",&base);
    return base;
}
int lerExpoente(){
    int expoente;
    printf("\nInforme o expoente (inteiro): ");
    scanf("%d", &expoente);
    return expoente;
}
float calc(float base, int expoente){
    float resultado = 1.0;

    if (expoente > 0) {
        for (int i = 0; i < expoente; i++) {
            resultado *= base;
        }
    } else if (expoente < 0) {
        for (int i = 0; i < -expoente; i++) {
            resultado *= base;
        }
        resultado = 1.0 / resultado;
    }

    return resultado;
}
void resultado(float base){
    printf("\nO resultado da potenciacao eh: %.f",base);
}
int main(){

    apresentacao();

    float A = lerBase();
    int B = lerExpoente();
    float C = calc(A,B);

    resultado(C);

    return 0;
}