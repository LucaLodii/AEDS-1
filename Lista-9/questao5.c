#include <stdio.h>
int main() {

    int denominador = 10, numerador = 1;  

    for (int i = 0; i < 10; i++) {
        printf("%d/", numerador);  
        printf("%d ", denominador);  
        denominador--;  
        numerador++;  
    }

    return 0;
}
