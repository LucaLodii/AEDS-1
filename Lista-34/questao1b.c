#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool ehPalindromoRec(char *str)
{
    return ehPalindromoRec2(str, 0, strlen(str) - 1);
}
bool ehPalindromoRec2(char *str, int i, int j)
{
    bool palindromo = true;
    if (i < j)
    {
        if (str[i] != str[j])
            palindromo = false;
        else
            palindromo = ehPalindromoRec2(str, i + 1, j - 1);
    }
    return palindromo;
}