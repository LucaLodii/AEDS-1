#include <stdio.h>

// Protótipos
int existe_caixa_valida(int caixas[], int N);
void processa_fila(int caixas[], int N, int K, int turno_atual);
int calcular_coleta(int frutas);

// Variáveis globais
int coletado_leticia = 0;

int main() {
    int N;  // número de caixas de frutas
    int K;  // posição de Letícia na fila
    scanf("%d %d", &N, &K);
    
    int caixas[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &caixas[i]);
    }
    
    processa_fila(caixas, N, K, 1);
    printf("%d\n", coletado_leticia);
    
    return 0;
}

void processa_fila(int caixas[], int N, int K, int turno_atual) {
    int maior = 0;
    for (int i = 1; i < N; i++) {
        if (caixas[i] > caixas[maior]) {
            maior = i;
        }
    }
    
    int frutas = caixas[maior];
    int coleta = calcular_coleta(frutas);
    
    caixas[maior] -= coleta;
    
    if (turno_atual == K) {
        coletado_leticia = coleta;
        return;
    }
    
    if (caixas[maior] > 0 || existe_caixa_valida(caixas, N)) {
        processa_fila(caixas, N, K, turno_atual + 1);
    }
}

int calcular_coleta(int frutas) {
    int produto = 1;
    int auxiliar = frutas;
    
    while (auxiliar > 0) {
        int digito = auxiliar % 10;
        if (digito % 2 != 0) {
            produto *= digito;
        }
        auxiliar /= 10;
    }
    
    if (produto == 1 && frutas % 2 == 0) {
        return 1;
    } else {
        return produto;
    }
}

int existe_caixa_valida(int caixas[], int N) {
    for (int i = 0; i < N; i++) {
        if (caixas[i] > 0) {
            return 1;
        }
    }
    return 0;
}