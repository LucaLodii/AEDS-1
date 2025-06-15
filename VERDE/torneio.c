#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char resultados[6];

    //RESULTADO DOS JOGOS
    for(int i = 0; i < 6; i++)
    {
        //printf("\nresultado do jogo %d eh: ",i+1);
        scanf("%s",&resultados[i]);
        resultados[i] = toupper(resultados[i]);
    }
    int countV = 0;

    for(int i = 0; i<6; i++)
    {
        if(resultados[i] == 'V') countV++;
    }

    // SEPARANDO POR GRUPO
    if(countV == 5 || countV == 6) printf("1\n");
    else if(countV == 3 || countV == 4) printf("2\n");
    else if(countV == 1 || countV == 2) printf("3\n");
    else printf("\n-1");

    return 0;
}
