#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int L;
    int C;
    do{
        scanf("%d",&L);
        scanf("%d",&C);
    }while(L > 100 && C > 100);

    int tipo1 = 0;
    int tipo2 = 0;

    if(L%2 != 0){
        tipo1 =  (L*C) + ((C-1)*(L-1));
        tipo2 = (C-1)*2 + (L-1)*2;
    }

    if(L%2 == 0){
        tipo1 =  (L*C) + ((C-1)*(L-1));
        tipo2 = (C-2)*2 + (L)*2;
    }

    printf("%d\n",tipo1);
    printf("%d\n",tipo2);

    return 0;
}
