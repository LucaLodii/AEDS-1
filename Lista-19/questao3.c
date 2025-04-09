#include <stdio.h>
#include <stdlib.h>

int* funcao(int *p){
    int *quadrado = malloc(sizeof(int));
    *quadrado = (*p)*(*p);
    return quadrado;

}
int main(){
    int *p = malloc(sizeof(int));
    printf("\nInforme um valor p que eu falo o quadrado dele: ");
    scanf("%d",p);
    int *quadrado = funcao(p);

    printf("\nO quadrado de %d eh: %d",*p, *quadrado);

    free(p);
    free(quadrado);

    return 0;
}