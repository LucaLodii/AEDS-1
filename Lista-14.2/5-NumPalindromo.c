#include <stdio.h>

void escreveInvertido(int n, int palindromo) {
    int original = n;  // Store the original number
    int reversed = 0;  // To build the reversed number
    
    printf("Invertido: ");
    if (n == 0) {
        printf("0");
    }
    
    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        printf("%d", digit);
        n = n / 10;
    }
    
    if (original == reversed) {
        printf("\nEh Palindromo");
    } else {
        printf("\nNao eh palindromo");
    }
}

void apresentacao() {
    int n;
    printf("Informe um numero para eu inverte-lo: ");
    scanf("%d", &n);
    escreveInvertido(n, 1);  // Second argument not needed anymore
}

int main() {
    apresentacao();
    return 0;
}