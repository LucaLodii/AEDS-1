#include <stdio.h>
#include <stdlib.h>

char* nomes[3] = {"Ana", "Joao", "Maria"};
int idades[3] = {25, 17, 30};

void listarNomesIterativo() {
    for (int i = 0; i < 3; i++) {
        printf("%s\n", nomes[i]);
    }
}

void listarNomesIdadesIterativo() {
    for (int i = 0; i < 3; i++) {
        printf("%s: %d anos\n", nomes[i], idades[i]);
    }
}

float calcularMediaIdadeIterativo() {
    int soma = 0;
    for (int i = 0; i < 3; i++) {
        soma += idades[i];
    }
    return (float)soma / 3;
}

int contarAcimaMediaIterativo(float media) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        if (idades[i] > media) count++;
    }
    return count;
}

int encontrarMaiorIdadeIterativo() {
    int max = idades[0];
    for (int i = 1; i < 3; i++) {
        if (idades[i] > max) max = idades[i];
    }
    return max;
}

void listarMenoresIterativo() {
    for (int i = 0; i < 3; i++) {
        if (idades[i] < 18) {
            printf("%s (menor)\n", nomes[i]);
        }
    }
}

void deslocarMenorIterativo() {
    int min_idx = 0;
    for (int i = 1; i < 3; i++) {
        if (idades[i] < idades[min_idx]) min_idx = i;
    }

    int temp_idade = idades[0];
    idades[0] = idades[min_idx];
    idades[min_idx] = temp_idade;

    char* temp_nome = nomes[0];
    nomes[0] = nomes[min_idx];
    nomes[min_idx] = temp_nome;
}

int buscarIdadeIterativo(int chave) {
    for (int i = 0; i < 3; i++) {
        if (idades[i] == chave) return i;
    }
    return -1;
}

void contarCaractereIterativo(char c) {
    for (int i = 0; i < 3; i++) {
        int count = 0;
        for (int j = 0; nomes[i][j] != '\0'; j++) {
            if (nomes[i][j] == c) count++;
        }
        printf("%s: %d ocorrencias de '%c'\n", nomes[i], count, c);
    }
}

int main() {
    printf("=== Nomes ===\n");
    listarNomesIterativo();
    
    printf("\n=== Nomes e Idades ===\n");
    listarNomesIdadesIterativo();
    
    float media = calcularMediaIdadeIterativo();
    printf("\nMedia de idade: %.1f\n", media);
    
    printf("Pessoas acima da media: %d\n", contarAcimaMediaIterativo(media));
    
    printf("Maior idade: %d\n", encontrarMaiorIdadeIterativo());
    
    printf("\n=== Menores de idade ===\n");
    listarMenoresIterativo();
    
    deslocarMenorIterativo();
    printf("\n=== Apos deslocar menor idade ===\n");
    listarNomesIdadesIterativo();
    
    int pos = buscarIdadeIterativo(25);
    printf("\nPosicao da idade 25: %d\n", pos);
    
    printf("\n=== Ocorrencias de 'a' ===\n");
    contarCaractereIterativo('a');
    
    return 0;
}