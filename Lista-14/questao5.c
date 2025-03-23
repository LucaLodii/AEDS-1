#include <stdio.h>

void function2(int n, int m){
    if(n<=m){
        printf("%d ",n);
        function2(n+1,m);
    }
}

void function1(){
    int n, m;
    printf("\nEsse programa soma de N ate M");
        printf("\nInforme N: ");
        scanf("%d",&n);
        printf("\nInforme M: ");
        scanf("%d",&m);
            
        function2(n,m);
}

int main(){
    function1();

    return 0;
}