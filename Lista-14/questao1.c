#include <stdio.h>

void function2(int x){
    if (x <= 5){
        printf("%d ",x);
        function2(x+1);
    }
}

void function1(){
    int x = 1;
    printf("\nEsse programa so serve pra contar de 1 ate 5\n");
    function2(x);
}
int main(){
    function1();
}