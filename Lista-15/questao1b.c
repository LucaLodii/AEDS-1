#include <stdio.h>

void finbonacci(int termos, int t1, int t2){
    if (termos > 0) { 
        printf("%d, ",t1);
        finbonacci(termos-1, t2, t1+t2);
    }
}
void numTermos(){
    int termos;
    printf("\nInforme quantos termos fibonacci vc quer: ");
    scanf("%d",&termos);
    finbonacci(termos,1,1);
}
int main(){
    numTermos();
    
    return 0;
}