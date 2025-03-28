#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idadeMonica, idadeFilhoUm, idadeFilhoDois, idadeFilhoTres;
    do
    {
        scanf("%i", &idadeMonica);
    } while (idadeMonica <= 40 || idadeMonica >= 110);

    do
    {
        scanf("%i", &idadeFilhoUm);
    } while (idadeFilhoUm <= 1 || idadeFilhoUm >= idadeMonica);

    do
    {
        scanf("%i", &idadeFilhoDois);
    } while ((idadeFilhoDois <= 1 || idadeFilhoDois >= idadeMonica) || idadeFilhoDois == idadeFilhoUm);

    idadeFilhoTres = idadeMonica - idadeFilhoUm - idadeFilhoDois;

    if(idadeFilhoUm > idadeFilhoDois && idadeFilhoUm > idadeFilhoTres){
        printf("%i\n", idadeFilhoUm);
    } else if(idadeFilhoDois > idadeFilhoUm && idadeFilhoDois > idadeFilhoTres){
        printf("%i\n", idadeFilhoDois);
    } else{
        printf("%i\n", idadeFilhoTres);
    }
}