#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
do{
    int ano;
    char opcao;
    printf("Digite um ano: ");
    scanf("%d", &ano);

    bool eh_bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);

    if (eh_bissexto) {
        printf("%d é um ano bissexto\n", ano);
    } else {
        printf("%d não é um ano bissexto\n", ano);
    }
    do{
    printf("\n Vc deseja sair? S para sim N para nao ");
    scanf(" %c",&opcao);
    opcao = toupper(opcao);

    if (opcao=='S'){
        printf("\n obrigado por utilizar este programa");
        return 1;
        }else if (opcao!='N'){
        printf("\nDigite uma opcao valida");}
    } while(opcao!='S' && opcao!='N');

} while(1);
    return 0;
}
