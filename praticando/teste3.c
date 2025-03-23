#include <stdio.h>

void function2(int n, int m){
    if (n<=m){
        printf("\n%d",n);
    }
    function2(n+1,m);

}

void function1(){
    int m, n;
    printf("\nEste programa soma de n ate m\nDigite n (o menor num): ");
    scanf("%d",&n);
    printf("\nAgora m: ");
    scanf("%d",&m);
        function2(n,m);
}


int main(){
    function1();
}