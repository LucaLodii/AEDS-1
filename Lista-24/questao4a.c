#include <stdio.h>

void lerVogais(char* string[], int size) {
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; string[i][j] != '\0'; j++) {
            char c = string[i][j];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                count++;
            }
        }
        printf("A palavra \"%s\" tem %d vogais.\n", string[i], count);
    }
}

int main() {
    char* string[5] = {"ciencias", "da", "computacao", "na", "puc"};
    int size = 5;

    lerVogais(string, size);

    return 0;
}
