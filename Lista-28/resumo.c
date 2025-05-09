// Não prestei mt atenção nessa parte, se vc ta lendo isso pode pular esse arquivo

//     -Caracteres-

// Lembrar que é caracterE!

// char str[50]; // esse é o trem de ferro, ele vai de 0 a 49, não use mais que isso.

// se vc digitar dentro dessa str só "puc" vai ficar mais ou menos assim: str = {"puc",/0};

// se o tamanho é fixo deixa ponteiro 

// char palavra[10]; possui 9 letras

// vc pode limitar o limite de digitação para n dar problema no buffer usando printf("%49s");

// O gets(str);, ele foi descontinuado, por isso muitos compiladores não o reconhecem (por ser 1 erro 
// mt grave de sobreposição), por isso usam fgets

// fgets(A str, numero maximo[50 por exemplo], e o nome od arquivo);

// lembrar que CONCATENAR = juntar

// apartir de agora é bom usar string.h por causa do str lenght


// -Struct-

// tente faze-la globar para ela n ficar "boiando"

#include <stdio.h>

typedef struct {
    char NOME[50];
    int IDADE;
}   pessoa;

void leiaPessoa(pessoa P[]){  //1 passagem = passagem por valor; nome = referencia (passagme por memoria);
    for(int i = 0; i < 3; i++){
        fflush(stdin);        //stdin pois é a entrada do teclado
            printf("\nDigite o nome: ");
            fgets(P[0].NOME, 50, stdin);

            printf("\nDigite a idade: ");
            scanf("%i",&P[0].IDADE);
    }
}

int main(){

    pessoa arr[2];           //isso é 1 trem de ferro em q cada 1 leva um nome e idade
    int x;
    leiaPessoas(arr);
}
//exemplos de MAX elementos no slide
//exemplo de cadastrando apenas UMA pessoa
//