#include <stdlib.h>
#include <stdio.h>

void maiorEmenor(int turma[], int n){
    int maior = turma[0], menor = turma[0];
        for(int i = 0; i < n; i++){
        if (turma[i] >= menor) maior = turma[i];
        else if (turma[i] <= maior) menor = turma[i];
    }
    printf("\nA maior nota foi %i",maior);
    printf("\nA menor nota foi %i",menor);
}

void mediaNotas(int turma[], int n, int soma)
{
    float media = (float)soma / n;
    int countAcima = 0;
    printf("\nA media das notas eh: %.1f", media);              //AQUI FALA A MEDIA
    for(int i = 0; i < n; i++){
        if (turma[i] >= media) countAcima++;
    }
    printf("\n%i alunos foram acima da media!", countAcima);    //AQUI FALA QUANTOS FORAM ACIMA DA MEDIA
}

int lerNotas(int turma[], int n)
{
    int soma = 0;
    printf("\nInsira todas as notas da sua turma\n");
    for (int i = 0; i < n; i++)
    {
        printf("Nota %d: ", i + 1);
        scanf("%d", &turma[i]);
        soma += turma[i];
    }
    return soma;
}

int main()
{
    int n = 0, soma = 0;
    printf("\nInsira quantos alunos tem em sua turma: ");
    scanf("%i", &n);
    int *turma = (int *)malloc(n * sizeof(int));                // tamanho turma

    soma = lerNotas(turma, n);
    mediaNotas(turma, n, soma);
    maiorEmenor(turma, n);

    free(turma);
    return 0;
}