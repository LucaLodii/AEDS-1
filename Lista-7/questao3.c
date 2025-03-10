#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int nalunos, nota, soma = 0, maior = 0, menor = 100;
    float media;

    printf("\nQuantos alunos tem na turma? ");
    scanf("%d", &nalunos);
    int total_alunos = nalunos;

    while (nalunos > 0) {
        do {
            printf("\nDigite a nota [0-100] do aluno: ");
            scanf("%d", &nota);
            if (nota > 100 || nota < 0) {
                printf("\nNota inválida, digite novamente.\n");
            }
        } while (nota > 100 || nota < 0);

        if (nota >= 60) {
            printf("\nAprovado\n");
        } else {
            printf("\nReprovado\n");
        }

        if (nota > maior)
            maior = nota;
        if (nota < menor)
            menor = nota;

        soma += nota;
        nalunos--;
    }

    media = (float)soma / total_alunos;
    printf("\nA média da turma é: %.2f\n", media);
    printf("Maior nota: %d\n", maior);
    printf("Menor nota: %d\n", menor);

    return 0;
}
