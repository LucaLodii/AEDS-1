#include <stdio.h>

void function3(int x){
    if (x >= 1){
        printf("%d ",x);
        function3(x-1);
    }
}

void function2(int x){
    if (x <= 5){
        printf("%d ",x);
        function2(x+1);
    }
}

void function1(){
    int x = 1;
    printf("\nEsse programa so serve pra contar de 1 ate 5, e depois de 5 ate 1\n");
    function2(x);
    function3(5);
}
int main(){
    function1();
    return 0;
}