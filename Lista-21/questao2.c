#include <stdio.h>
#include <stdlib.h>

void primeiraTroca(float notas[], int nota1, int nota2)
{
    float temp = notas[nota1];              //TEMP TEM Q SER FLOAT PARA DAR A RESPOSTA COM VIRGULA
    notas[nota1] = notas[nota2];
    notas[nota2] = temp;
}

int main()
{
    float notas[4];
    int n = 4;

    for (int i = 0; i < n; i++){            //Coloca as notas no array
        printf("\nDigite a nota %d: ",i+1);
        scanf("%f",&notas[i]);
    }

    printf("\nEscolha a 1a nota de 1 a 4 para trocarmos de lugar: ");
    int nota1, nota2;
    do
    {
        scanf("%i", &nota1);
    } while (nota1 < 1 || nota1 > 4);
    do
    {
        printf("\nAgora escolha a 2a: ");
        scanf("%i", &nota2);
    } while (nota2 < 1 || nota2 > 4);

    primeiraTroca(notas, nota1-1, nota2-1); //COLOCAR -1 POIS ARRAY COMEÇA EM 0


    printf("\nNotas apos troca: ");         //Fala as notas apos a funcao que trocaa as notas
    for (int i = 0; i < n; i++) {
        printf("%.1f ", notas[i]);
    }

        return 0;
}