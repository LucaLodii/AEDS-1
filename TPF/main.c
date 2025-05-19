#include <stdio.h>
#include "data/data.h"
#include "pessoas/pessoas.h"

int main()
{
    Pessoa pessoas[MAX];
    abertura(); // Inicializa o sistema

    int opcao;
    do
    {
        printf("\nMenu de funcionalidades, escolha uma opcao: \n");
        printf("0 - Sair do Programa\n");
        printf("1 - Cadastrar pessoa\n");
        printf("2 - Listar todas as pessoas cadastradas\n");
        printf("3 - Informar a idade media da turma\n");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 0:
            printf("\nObrigado por usar este programa\n");
            despedida(pessoas);
            break;
        case 1:
            cadastrePessoa(pessoas);
            break;
        case 2:
            if (TAM == 0)
            {
                printf("\nNenhuma pessoa cadastrada!\n");
            }
            else
            {
                for (int i = 0; i < TAM; i++)
                {
                    escrevaPessoa(pessoas, i);
                }
            }
            break;
        case 3:
            printf("\nIdade média: %.1f anos\n", idadeMedia(pessoas));
            break;
        default:
            printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}