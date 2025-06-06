#include <stdio.h>
#include <stdbool.h>
#include "data/data.h"
#include "pessoas/pessoas.h"

int main()
{
    Pessoa pessoas[MAX];
    abertura(pessoas); // Inicializa o sistema

    int opcao;
    do
    {
        printf("\nMenu de funcionalidades, escolha uma opcao: \n");
        printf("0 - Sair do Programa\n");
        printf("1 - Cadastrar pessoa\n");
        printf("2 - Listar todas as pessoas cadastradas\n");
        printf("3 - Pesquisar por nome\n");
        printf("4 - Pesquisar por CPF\n");
        printf("5 - Excluir pessoa\n");
        printf("6 - Apagar todas as pessoas cadastradas\n");
        printf("7 - EXTRA: Informar a idade media da turma\n");        // ESSA É UMA FUNÇÃO EXTRA, EU FIZ PQ QUIS
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
            pesquisaPessoaNome(pessoas);
            break;

        case 4:
        {
            pesquisaPessoaCPF(pessoas);
            break;
        }
        case 5:
            deletaPessoa(pessoas);
            break;
        case 6:
            apagarTodos(pessoas);
            break;
        case 7:
            printf("\nIdade média: %.1f anos\n", idadeMedia(pessoas));  // ESSA É UMA FUNÇÃO EXTRA, EU FIZ PQ QUIS
            break;
        default:
            printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}