#include <stdio.h>
void calc(int n, int m){
    if(n<=m){
        printf("%d ",n);
        calc(n+1,m);
    }
}
void introducao(){
    int n, m;
    printf("\nDigite N: ");
    scanf("%d",&n);
    printf("\nDigite M: ");
    scanf("%d",&m);
        calc(n,m);
}
int main(){
    introducao();

    return 0;
}