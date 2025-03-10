#include <stdio.h>
int main(){

    int termo = 2, razao = 3, i;

    for (i=0; i<10; i++){
        printf("\n%d",termo);
        termo += razao;
    }
    return 0;
} 