#include <stdio.h>

int main() {
    float num, maior, menor, amplitude;
    int primeiro = 1; 

    printf("\nInforme um numero real (0 para sair): ");
    scanf("%f", &num);

    if (num == 0) { 
        printf("\nNenhum numero válido foi inserido.\n");
        return 0;
    }

    maior = menor = num; 

    while (num != 0) { 
        printf("\nInforme um numero real (0 para sair): ");
        scanf("%f", &num);

        if (num != 0) { 
            if (num > maior) {
                maior = num;
            }
            if (num < menor) {
                menor = num;
            }
        }
    }

    amplitude = maior - menor;
    printf("\nA amplitude é: %f\n", amplitude);

    return 0;
}
