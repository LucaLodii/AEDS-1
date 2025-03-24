#include <stdio.h>


void escreveInvertido(int n) {
    if(n==0) printf("\n0");
    while (n > 0) {
        printf("%d", n % 10);
        n = n / 10;
    } 
}

void apresentacao() {
    int n;
    printf("Informe um numero para eu inverte-lo: ");
    scanf("%d", &n);
    escreveInvertido(n);
}

int main() {
    apresentacao();
    return 0;
}