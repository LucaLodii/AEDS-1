#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void qt_vogal(char* string, int vogais[]);
void concatenar(char* string1, char* string2, char concatenada[]);
int tamanho_rec(char* string, int length);

int main() {
    char string1[] = "Ola";
    char string2[] = "Mundo";
    char string3[100] = {0};  // Increased size for concatenation
    concatenar(string1, string2, string3);
    printf("%i\n", tamanho_rec(string2, 0));

    int vogais[5] = {0};  // Initialize array for counting vowels
    qt_vogal(string1, vogais);
    printf("Vowels counts: a=%d, e=%d, i=%d, o=%d, u=%d\n", vogais[0], vogais[1], vogais[2], vogais[3], vogais[4]);
}

void concatenar(char* string1, char* string2, char concatenada[]) {
    int length_con = 0;
    while (string1[length_con] != '\0') {
        concatenada[length_con] = string1[length_con];
        length_con++;
    }
    
    int length_str2 = 0;
    while (string2[length_str2] != '\0') {
        concatenada[length_con] = string2[length_str2];
        length_str2++;
        length_con++;
    }
    concatenada[length_con] = '\0';
    printf("Concatenated String: %s\n", concatenada);
}

int tamanho_rec(char* string, int length) {
    if (string[length] != '\0') {
        return tamanho_rec(string, length + 1);
    }
    return length;
}

void qt_vogal(char* string, int vogais[]) {
    int length = 0;
    while (string[length] != '\0') {
        char ch = string[length];
        if (ch == 'a' || ch == 'A') {
            vogais[0]++;
        } else if (ch == 'e' || ch == 'E') {
            vogais[1]++;
        } else if (ch == 'i' || ch == 'I') {
            vogais[2]++;
        } else if (ch == 'o' || ch == 'O') {
            vogais[3]++;
        } else if (ch == 'u' || ch == 'U') {
            vogais[4]++;
        }
        length++;
    }
}
