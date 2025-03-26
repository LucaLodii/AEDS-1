#include <stdio.h>

void ehPalindromo(int num) {
    int original = num;
    int invertido = 0;

    while (num > 0) {
        invertido = invertido * 10 + num % 10;
        num /= 10;
    }

    if (original == invertido) printf("\nEh Palindromo");
    else printf("\nNAO eh palindromo");
}

int lerNum() {
    int num;
    printf("\nVerifique se um dado numero eh palindromo: ");
    scanf("%d", &num);
    return num;
}

int main() {
    int A = lerNum();
    ehPalindromo(A);
    return 0;
}