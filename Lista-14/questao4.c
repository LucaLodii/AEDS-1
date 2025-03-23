#include <stdio.h>

void function2(int n){
    if(n>=0){
        printf("%d ",n);
        function2(n-1);
    }
}

void function1(){
    int n;
    printf("\nInforme um numero para contarmos dele ate 0: ");
    scanf("%d",&n);
    function2(n);
}

int main(){
    function1();

    return 0;
}