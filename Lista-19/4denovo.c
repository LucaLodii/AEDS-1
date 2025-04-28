#include <stdio.h>
#include <stdlib.h>

#define NUM_COUNT 10

int main() {
    FILE *arquivo;
    float num, soma = 0, media;
    int maiores_que_media = 0;
    int i;

    // Create/open file
    arquivo = fopen("numeros.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }

    // Read numbers, store in file, and calculate sum
    printf("Digite %d numeros reais:\n", NUM_COUNT);
    for (i = 0; i < NUM_COUNT; i++) {
        scanf("%f", &num);
        fprintf(arquivo, "%.2f\n", num);
        soma += num;
    }
    fclose(arquivo);

    media = soma / NUM_COUNT;

    // Reopen file to count numbers > average
    arquivo = fopen("numeros.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return 1;
    }

    // Count numbers greater than average
    for (i = 0; i < NUM_COUNT; i++) {
        fscanf(arquivo, "%f", &num);
        if (num > media) {
            maiores_que_media++;
        }
    }
    fclose(arquivo);

    arquivo = fopen("numeros.txt", "a");
    fprintf(arquivo, "\nMedia: %.2f\n", media);
    fprintf(arquivo, "Quantidade acima da media: %d\n", maiores_que_media);
    fclose(arquivo);

    printf("\nMedia: %.2f\n", media);
    printf("Quantidade acima da media: %d\n", maiores_que_media);

    return 0;
}