#include <stdio.h>
#include <stdbool.h>

//QUESTÃO DIFÍCIL SE GUIE PELOS COMENTÁRIOS

bool ehPrimo(int n) {
    bool primo;
    if(n < 2) primo = false;
    else {
        primo = true;
        int i = 2;
        while(primo && i <= n/2) {
            if(n % i == 0) primo = false;
            i++;
        }
    }
    return primo;
}

void teste(int n, int *b, int *k) {
    // Casos especiais
    if(n <= 1) {
        *b = n;
        *k = 1;
        return;
    }
    
    // Inicializa com o pior caso (1 × n)
    *b = 1;
    *k = n;
    
    // Procura o menor B possível (de 2 até n)
    for(int possible_b = 2; possible_b <= n; possible_b++) {
        if(n % possible_b == 0) {  // Se B divide N
            int possible_k = n / possible_b;
            
            // Verifica se possible_b é primo
            if(ehPrimo(possible_b)) {
                if(possible_b < *b || *b == 1) {
                    *b = possible_b;
                    *k = possible_k;
                }
            }
        }
    }
}

int main() {
    int n, b, k;
    printf("Digite um numero: ");
    scanf("%d", &n);
    
    teste(n, &b, &k);
    printf("b = %d, k = %d (pois %d * %d = %d)\n", b, k, b, k, n);
    
    return 0;
}