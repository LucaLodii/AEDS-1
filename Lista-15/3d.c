#include <stdio.h>

int potenciacao(int base, int expoente, int i){
    i = base;
    while(expoente>0){
        printf("%d ",base);
        base*=i;
        expoente--;
    }
}

int lerBase(){
    int base;
    printf("\nInforma base o sua perua: ");
    scanf("%d",&base);
    return base;
}

int lerExpoente(){
    int expoente;
    printf("\nInforma expoente o sua perua: ");
    scanf("%d",&expoente);
    return expoente;
}

int main(){
    int A = lerBase();
    int B = lerExpoente();
    int i;
    potenciacao(A,B,i);

    return 0;
}