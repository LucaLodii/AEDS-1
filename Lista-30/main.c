#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // era pra ser const mas fdc
int TAM = 0;

typedef struct {
    float lado1;
    float lado2;
    float lado3;
} Triangulo;

void lerTriangulo(Triangulo triangulos[]);
int ehEquilatero(Triangulo t);
int ehIsosceles(Triangulo t);
int ehEscaleno(Triangulo t);
void contarTiposTriangulos(Triangulo triangulos[]);
void salvarDados(Triangulo triangulos[]);
void carregarDados(Triangulo triangulos[]);

int main() {
    Triangulo triangulos[MAX];
    carregarDados(triangulos);

    int opcao;
    do {
        printf("\n--- MENU TRIANGULOS ---\n");
        printf("0 - Sair do programa\n");
        printf("1 - Ler um triangulo\n");
        printf("2 - Informar numero de triangulos equilateros\n");
        printf("3 - Informar numero de triangulos isosceles\n");
        printf("4 - Informar numero de triangulos escalenos\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Saindo do programa...\n");
                salvarDados(triangulos); // Salva antes de sair
                break;
            case 1:
                lerTriangulo(triangulos);
                break;
            case 2:
                printf("Triangulos equilateros: %d\n", contarEquilateros(triangulos));
                break;
            case 3:
                printf("Triangulos isosceles: %d\n", contarIsosceles(triangulos));
                break;
            case 4:
                printf("Triangulos escalenos: %d\n", contarEscalenos(triangulos));
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}

void lerTriangulo(Triangulo triangulos[]) {
    if (TAM >= MAX) {
        printf("Limite maximo de triangulos atingido!\n");
        return;
    }
    
    printf("Digite os 3 lados do triangulo (separados por espaco): ");
    scanf("%f %f %f", &triangulos[TAM].lado1, &triangulos[TAM].lado2, &triangulos[TAM].lado3);
    
    // Verifica se é um triângulo válido
    if (triangulos[TAM].lado1 + triangulos[TAM].lado2 > triangulos[TAM].lado3 &&
        triangulos[TAM].lado1 + triangulos[TAM].lado3 > triangulos[TAM].lado2 &&
        triangulos[TAM].lado2 + triangulos[TAM].lado3 > triangulos[TAM].lado1) {
        TAM++;
        printf("Triangulo cadastrado com sucesso!\n");
    } else {
        printf("Valores invalidos para um triangulo!\n");
    }
}

int ehEquilatero(Triangulo t) {
    return (t.lado1 == t.lado2) && (t.lado2 == t.lado3);
}

int ehIsosceles(Triangulo t) {
    return (t.lado1 == t.lado2) || (t.lado1 == t.lado3) || (t.lado2 == t.lado3);
}

int ehEscaleno(Triangulo t) {
    return (t.lado1 != t.lado2) && (t.lado1 != t.lado3) && (t.lado2 != t.lado3);
}

int contarEquilateros(Triangulo triangulos[]) {
    int count = 0;
    for (int i = 0; i < TAM; i++) {
        if (ehEquilatero(triangulos[i])) {
            count++;
        }
    }
    return count;
}

int contarIsosceles(Triangulo triangulos[]) {
    int count = 0;
    for (int i = 0; i < TAM; i++) {
        if (ehIsosceles(triangulos[i])) {
            count++;
        }
    }
    return count;
}

int contarEscalenos(Triangulo triangulos[]) {
    int count = 0;
    for (int i = 0; i < TAM; i++) {
        if (ehEscaleno(triangulos[i])) {
            count++;
        }
    }
    return count;
}

void salvarDados(Triangulo triangulos[]) {
    FILE *arquivoTAM = fopen("tam_triangulos.dat", "wb");
    if (arquivoTAM) {
        fwrite(&TAM, sizeof(int), 1, arquivoTAM);
        fclose(arquivoTAM);
    }

    FILE *arquivoTriangulos = fopen("triangulos.dat", "wb");
    if (arquivoTriangulos) {
        fwrite(triangulos, sizeof(Triangulo), TAM, arquivoTriangulos);
        fclose(arquivoTriangulos);
    }
}

void carregarDados(Triangulo triangulos[]) {
    FILE *arquivoTAM = fopen("tam_triangulos.dat", "rb");
    if (arquivoTAM) {
        fread(&TAM, sizeof(int), 1, arquivoTAM);
        fclose(arquivoTAM);
    }

    FILE *arquivoTriangulos = fopen("triangulos.dat", "rb");
    if (arquivoTriangulos) {
        fread(triangulos, sizeof(Triangulo), TAM, arquivoTriangulos);
        fclose(arquivoTriangulos);
    }
}