#include <stdio.h>

void calc(int num, int i, int fatorial) {
    if (i <= num) {
        printf("%d! = %d\n", i, fatorial);
        calc(num, i + 1, fatorial * (i + 1));
    }
}

void introduction(){
    int num, i = 1, fatorial = 1;
    printf("\n----CALCULADORA DE FATORIAL----\n");
        printf("\nInforme o numero que vc quer saber o fatorial: ");
        scanf("%d",&num);

        calc(num,i, fatorial);
}

int main(){
    introduction();

    return 0;
}