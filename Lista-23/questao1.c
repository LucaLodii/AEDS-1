#include <stdio.h>
#include <stdlib.h>

float opcao5(float notas[], int i, int *maior, int *menor){
    float amplitude = *maior - *menor;
    printf("\nA amplitude eh: %.f",amplitude);
}

float opcao4(float notas[], int i){
    *maior = notas[0], *menor = notas[0]; //tem q ser = notas[0], se for igual a 0 não funciona!!!
    maior = malloc(sizeof(float));
    menor = malloc(sizeof(float));
    for(int j = 0; j < i; j++){
        if(notas[j] > *maior){
            *maior = notas[j];
        }
        else if (notas[j] < *menor) {
            *maior = notas[j];
        }
    }
    printf("\nA maior nota foi: %.f",*maior);
    printf("\nA menor nota foi: %.f",*menor);
    return *maior, *menor;
}

void opcao3(float notas[], int i)
{
    int countAprovados = 0;
    for(int j = 0; j < i; j++){
        if(notas[j] >= 60) countAprovados++;
    //printf("\nNumero de notas cadastradas: %i", i);
    }
    printf("\nNumero de alunos aprovados: %i", countAprovados);
}

void opcao2(float notas[], int i)
{
    if (i == 0) //Assim ele não lista lixo
    {
        printf("\nNenhuma nota cadastrada ainda!"); 
        return;
    }
    printf("\nNotas cadastradas:");
    for (int j = 0; j < i; j++)
    {
        printf("\nNota%i %.1f", j + 1, notas[j]);
    }
}

int opcao1(float notas[], int i)
{
    float nota = 1; // Inicializa com valor diferente de 0
    printf("\nCadastre sua nota, 0 para sair\n");
    do
    {
        printf("\nNota %d: ", i + 1);
        scanf("%f", &nota);

        if (nota < 0 || nota > 100)
        {
            printf("Nota invalida! Digite de 0 a 100.\n");
        }
        else if (nota != 0)
        { // Só armazena se for válida e não for 0
            notas[i] = nota;
            i++;
        }
    } while (nota != 0 && i < 80);

    return i;
}

int main()
{
    int opcao, i = 0;
    float notas[80];

    do
    {
        printf("\nMenu de funcionalidades, escolha uma opcao: \n");
        printf("\n0 - Sair do Programa");
        printf("\n1 - Cadastrar uma nota");
        printf("\n2 - Listar todas as notas");
        printf("\n3 - Informar o numero de alunos aprovados");
        printf("\n4 - Informar o valor da maior e menor nota da turma");
        printf("\n5 - Informar a amplitude das notas");
        printf("\n6 - Ordenar notas em ordem decrescente.\n");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 0:
            printf("\nObrigado por usar este programa");
            break;
        case 1:
            printf("\nCadastrar uma nota");
            i = opcao1(notas, i);
            break;
        case 2:
            printf("\nListar todas as notas");
            opcao2(notas, i);
            break;
        case 3:
            printf("\nInformar o número de alunos aprovados");
            opcao3(notas, i);
            break;
        case 4:
            printf("\nInformar o valor da maior e menor nota da turma");
            opcao4(notas, i);
            break;
        case 5:
            printf("\nInformar a amplitude das notas");
            //opcao5(notas, i);
            break;
        // ... outros casos ...
        default:
            if (opcao >= 3 && opcao <= 6)
                printf("\nOpcao %d ainda nao implementada\n", opcao);
            else
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);
    return 0;
}