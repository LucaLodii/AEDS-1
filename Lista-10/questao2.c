#include <stdio.h>
#include <locale.h>
int main(){

    int valores, num;

    printf("\nOla, digite quantos nameros deseja ler: ");
    scanf("%d",&valores);


        for(valores>0; valores--;){
            printf("\nFale um numero que eu falo se eh par ou impar ZE: ");
            scanf("%d",&num);

                if(num<0) {
                    printf("\ntem q ser positivo");
                    valores++;
                continue; // Pula para a próxima iteração do loop
                }

                if(num % 2 == 0) printf("%d eh par zzzzzz\n",num);
                else printf("%d eh impar zezezezeze\n",num);
    }
    printf("\nFalou zeeee");
return 0;
}