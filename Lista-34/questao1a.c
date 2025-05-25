#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool ehPalindromo(char* str) {
    bool palindromo = true;
    int i = 0;
    int j = strlen(str) - 1;
    
    while(palindromo && i < j) {
        if(str[i] != str[j]) palindromo = false;
        i++; 
        j--; 
    }
    return palindromo;
}