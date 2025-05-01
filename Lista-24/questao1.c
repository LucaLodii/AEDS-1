#include <stdio.h>
#include <stdlib.h>

void opcao6(float notas[], int i)
{
    for (int j = 0; j < i - 1; j++)
    {
        int pos_maior = j;
        for (int k = j + 1; k < i; k++)
        {
            if (notas[k] > notas[pos_maior])
            {
                pos_maior = k;
            }
        }
        float temp = notas[j];
        notas[j] = notas[pos_maior];
        notas[pos_maior] = temp;
    }
}

void opcao5(float maior, float menor)
{
    printf("\nAmplitude: %.1f (Maior: %.1f, Menor: %.1f)", maior - menor, maior, menor);
}

void opcao4(float notas[], int i, float *maior, float *menor)
{
    if (i == 0)
    {
        printf("\nNenhuma nota cadastrada ainda!");
        return;
    }

    *maior = notas[0]; // tem q ser = notas[0], se for igual a 0 não funciona!!!
    *menor = notas[0];

    for (int j = 1; j < i; j++)
    {
        if (notas[j] > *maior)
        {
            *maior = notas[j];
        }
        if (notas[j] < *menor)
        {
            *menor = notas[j];
        }
    }
    printf("\nA maior nota foi: %.1f", *maior);
    printf("\nA menor nota foi: %.1f", *menor);
}

void opcao3Recursivo(float notas[], int i, int *count) {
    if (i == 0) {
        return;
    }

    if (notas[i-1] >= 60) {
        (*count)++;
    }
    
    opcao3Recursivo(notas, i-1, count);
}

//O EXERCICIO É SO ESSA FUNCAO
void opcao3(float notas[], int i) {
    if (i == 0) {
        printf("\nNenhuma nota cadastrada ainda!");
        return;
    }
    
    int countAprovados = 0;
    opcao3Recursivo(notas, i, &countAprovados);
    
    printf("\nNumero de alunos aprovados: %i", countAprovados);
}
//O EXERCICIO É SO ESSA FUNCAO"



void opcao2(float notas[], int i)
{
    if (i == 0) // Assim ele não lista lixo
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
    float notas[80], maior, menor;

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
            printf("\nInformar o numero de alunos aprovados");
            opcao3(notas, i);
            break;
        case 4:
            printf("\nInformar o valor da maior e menor nota da turma");
            opcao4(notas, i, &maior, &menor);
            break;
        case 5:
            printf("\nInformar a amplitude das notas");
            opcao5(maior, menor);
            break;
        case 6:
            printf("\nNotas ordenadas:");
            opcao6(notas, i);
            opcao2(notas, i);
            break;
        default:
            if (opcao >= 3 && opcao <= 6)
                printf("\nOpcao %d ainda nao implementada\n", opcao);
            else
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);
    return 0;
}