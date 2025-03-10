#include <stdio.h>
int main(){

    int termo=2;

    for(int i=0; i<10; i++){
        printf("\n%d", termo);
        termo = termo + 3;
    }

    return 0;
}