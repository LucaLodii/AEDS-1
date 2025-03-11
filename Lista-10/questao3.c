#include <stdio.h>
int main() {

    int  numerador = 10, numerador2 = 11, denominador = 100, denominador2 = 99, x=1;  

        printf("\ncalculando os 10 primeiros termos da sequencia zeeeeee\n");

        for(int i=0; i<5; i++) {
        printf("%d/", numerador);  
        printf("%d ", denominador);  
            printf("%d/", denominador2);  
            printf("%d ", numerador2);  
                numerador += 2; denominador -= 2; 
                numerador2 += 2, denominador2 -= 2;

        }
        
        printf("\nObrigado!");
        
    return 0;
}
