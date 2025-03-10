#include <stdio.h>
int main(){

    int termo1 = 0, termo2 = 1, termo=1;

    printf("\n0");
    for(int i=0; i<9; i++){
        printf("\n%d",termo);
        termo= termo1+termo2;
        termo1 = termo2;
        termo2 = termo;
    }

    return 0;
}