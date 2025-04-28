#include <stdio.h>

void criarArquivo(char nome[100]) {
    FILE *arquivo = fopen(nome, "w");
    float valor = 1; // Inicializa com qualquer valor diferente de 0
    
    printf("Digite valores reais (0 para encerrar):\n");
    
    while(valor != 0) {
        scanf("%f", &valor);
        if(valor != 0) {
            fprintf(arquivo, "%f\n", valor);
        }
    }
    
    fclose(arquivo);
}

int main() {
    char nome[100];
    printf("Nome do arquivo: ");
    scanf("%s", nome);
    
    criarArquivo(nome);
    return 0;
}