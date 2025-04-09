#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Main function to find nearest primes
void primo(int m, int *p1, int *p2) {
    // Base case for m < 2 (there are no primes below 2)
    if (m <= 2) {
        *p1 = -1;  // Indicates no prime less than m
        *p2 = 2;    // Smallest prime greater than m
        return;
    }
    
    // Find largest prime less than m (p1)
    *p1 = m - 1;
    while (*p1 >= 2 && is_prime(*p1) == false) {
        (*p1)--;
    }
    
    // Find smallest prime greater than m (p2)
    *p2 = m + 1;
    while (is_prime(*p2) == false) {
        (*p2)++;
    }
}

int main() {
    int m, p1, p2;
    
    printf("Digite um número inteiro: ");
    scanf("%d", &m);
    
    primo(m, &p1, &p2);
    
    if (p1 == -1) {
        printf("Não existe primo menor que %d\n", m);
    } else {
        printf("Maior primo menor que %d: %d\n", m, p1);
    }
    printf("Menor primo maior que %d: %d\n", m, p2);
    
    return 0;
}