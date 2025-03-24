#include <stdio.h>


void escreveInvertido(int n) {
if(n==0) printf("\n0"); // Caso especial: o número zero
while (n > 0) {
printf("%d", n % 10); // escreve o último dígito
n = n / 10; // remove o último dígito
} // fim while(n)
}

void apresentacao() {
    int n;
    printf("Informe o numero para eu te falar quantos digitos ele tem: ");
    scanf("%d", &n);
    escreveInvertido(n);
}

int main() {
    apresentacao();
    return 0;
}