#include <stdio.h>
int main() {

    int denominador = 1, numerador = 1, x=1;  

        printf("\nCALCULADORA DO H\n");
        printf("\n 1 para continuar 0 para parar\n");

        do {
        printf("%d/", numerador);  
        printf("%d ", denominador);  
        denominador = denominador * 3;  
        scanf("%d",&x);
    } while(x != 0);
        
        printf("\nObrigado!");
        
    return 0;
}
