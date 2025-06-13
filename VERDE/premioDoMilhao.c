#include <stdio.h>

int numeros[50];

int numAcessos(int N, int numeros[])
{
    for (int i = 0; i < N; i++) {
        int A;
        scanf("%d", &A);
        numeros[i] = A;
    }

    int soma = 0;
    int resposta = 0;
    int i = 0;

    while (soma < 1000000 && i < N) {
        soma += numeros[i];
        i++;
        resposta++;
    }

    printf("%d", resposta);
}

int numDias()
{
    int N;
    do {
        printf("Digite o número de dias (1 a 1000): ");
        scanf("%d", &N);
    } while (N < 1 || N > 1000);
    return N;
}

int main()
{
    int N = numDias();
    numAcessos(N, numeros);
}
