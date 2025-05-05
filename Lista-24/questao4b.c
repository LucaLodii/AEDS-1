#include <stdio.h>

#define EH_VOGAL(c) ((c) == 'a' || (c) == 'e' || (c) == 'i' || (c) == 'o' || (c) == 'u')

int contarVogaisRecursiva(char *str) {
    if (*str == '\0') return 0;

    int isVogal = EH_VOGAL(*str);
    return isVogal + contarVogaisRecursiva(str + 1);
}

void lerVogais(char* string[], int size) {
    for (int i = 0; i < size; i++) {
        int total = contarVogaisRecursiva(string[i]);
        printf("A palavra \"%s\" tem %d vogais.\n", string[i], total);
    }
}

int main() {
    char* string[5] = {"ciencias", "da", "computacao", "na", "puc"};
    int size = 5;

    lerVogais(string, size);

    return 0;
}
