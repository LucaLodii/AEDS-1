#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <string>
#include "data/data.hpp"
#include "pessoas/pessoas.hpp"

// Para rodar: g++ main.cpp pessoas/pessoas.cpp data/data.cpp -o main

int main()
{
    Pessoa pessoas[MAX];
    abertura(pessoas); // Inicializa o sistema

    int opcao;
    bool pessoasCadastradas = false;
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

        case 2: // For each
            for (Pessoa pessoa : pessoas)
            {
                pessoa.escrevePessoa();
                pessoasCadastradas = true;
            }
            if (!pessoasCadastradas)
            {
                cout << "Nenhuma pessoa cadastrada." << endl;
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

        default:
            printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}