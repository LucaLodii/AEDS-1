#include <stdio.h>

void function3(int x,int n){
    if (x >= n){
        printf("%d ",x);
        function3(x-1,n);
    }
}

void function2(int x, int n){
    if (x <= n){
        printf("%d ",x);
        function2(x+1,n);
    }
}

void function1(){
    int x = 1, n;
        printf("\ndigite um numero para programa contar de 1 ate ele: ");
        scanf("%d",&n);
    function2(x,n);
    function3(n,1);
}
int main(){
    function1();
    return 0;
}