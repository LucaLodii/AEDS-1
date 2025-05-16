#include <stdio.h>
#include "data/data.h"
#include "pessoas/pessoas.h"

int main() {
    Pessoa pessoas[MAX];
    carregarDados(pessoas);

    int opcao;
    do {
        printf("\nMenu de funcionalidades, escolha uma opcao: \n");
        printf("0 - Sair do Programa\n");
        printf("1 - Cadastrar pessoa\n");
        printf("2 - Listar todas as pessoas cadastradas\n");
        printf("3 - Informar a idade media da turma\n");
        scanf("%i", &opcao);

        switch (opcao) {
            case 0:
                printf("\nObrigado por usar este programa");
                salvarDados(pessoas);
                break;
            case 1:
                cadastrarPessoa(pessoas);
                break;
            case 2:
                listarPessoas(pessoas);
                break;
            case 3:
                idadeMedia(pessoas);
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}