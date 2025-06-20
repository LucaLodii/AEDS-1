#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <string>
#include "data/data.hpp"
#include "pessoas/pessoas.hpp"

using namespace std;

// Para rodar: g++ main.cpp pessoas/pessoas.cpp data/data.cpp -o main

int main()
{
    Pessoa pessoas[MAX];
    abertura(pessoas); // Inicializa o sistema

    int opcao, subOpcao;

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
        printf("7 - Aniversariantes do mês\n");
        cin >> opcao;
        cin.ignore();

        switch (opcao)
        {
        case 0:
            printf("\nObrigado por usar este programa\n");
            despedida(pessoas);
            break;

        case 1:
            cout << "0 - Voltar ao menu inicial" << endl;
            cout << "1 - Cadastrar Professor" << endl;
            cout << "2 - Cadastrar Aluno" << endl;
            cin >> subOpcao;
            cin.ignore();

            switch (subOpcao)
            {
            case 0:

                break;

            case 1:

                break;

            case 2:

                break;

            default:
                break;
            }

            // LOGICA DA IMPLEMENTACAO
            cadastrePessoa(pessoas);
            break;

        case 2: // For each
            cout << "0 - Voltar ao menu inicial" << endl;
            cout << "1 - Listar Professor" << endl;
            cout << "2 - Listar Aluno" << endl;
            cin >> subOpcao;
            cin.ignore();

            switch (subOpcao)
            {
            case 0:

                break;

            case 1:

                break;

            case 2:

                break;

            default:
                break;
            }

            // LOGICA DA IMPLEMENTACAO
            if (Pessoa::TAM == 0)
            {
                cout << "Nenhuma pessoa cadastrada." << endl;
            }
            else
            {
                for (int i = 0; i < Pessoa::TAM; i++)
                {
                    pessoas[i].escrevePessoa();
                }
            }
            break;

        case 3:
            cout << "0 - Voltar ao menu inicial" << endl;
            cout << "1 - Pesquisar Professores por nome" << endl;
            cout << "2 - Pesquisar Alunos por nome" << endl;
            cin >> subOpcao;
            cin.ignore();

            switch (subOpcao)
            {
            case 0:

                break;

            case 1:

                break;

            case 2:

                break;

            default:
                break;
            }

            // LOGICA DA IMPLEMENTACAO
            pesquisaPessoaNome(pessoas);
            break;

        case 4:
        {
            cout << "0 - Voltar ao menu inicial" << endl;
            cout << "1 - Pesquisar Professores por CPF" << endl;
            cout << "2 - Pesquisar Alunos por CPF" << endl;
            cin >> subOpcao;
            cin.ignore();

            switch (subOpcao)
            {
            case 0:

                break;

            case 1:

                break;

            case 2:

                break;

            default:
                break;
            }

            // LOGICA DA IMPLEMENTACAO
            pesquisaPessoaCPF(pessoas);
            break;
        }
        case 5:
            cout << "0 - Voltar ao menu inicial" << endl;
            cout << "1 - Excluir Professor (pelo CPF)" << endl;
            cout << "2 - Excluir Aluno (pelo CPF)" << endl;
            cin >> subOpcao;
            cin.ignore();

            switch (subOpcao)
            {
            case 0:

                break;

            case 1:

                break;

            case 2:

                break;

            default:
                break;
            }

            // LOGICA DA IMPLEMENTACAO
            deletaPessoa(pessoas);
            break;

        case 6:
            cout << "0 - Voltar ao menu inicial" << endl;
            cout << "1 - Excluir todos os Professores" << endl;
            cout << "2 - Excluir todos os Alunos" << endl;
            cin >> subOpcao;
            cin.ignore();

            switch (subOpcao)
            {
            case 0:

                break;

            case 1:

                break;

            case 2:

                break;

            default:
                break;
            }

            // LOGICA DA IMPLEMENTACAO
            apagarTodos(pessoas);
            break;

        case 7:
            do
            {
                cout << "0 - Voltar ao menu inicial" << endl;
                cout << "1 - Informar o mês a ser pesquisado" << endl;
                cout << "2 - Listar os Professores aniversariantes do mês" << endl;
                cout << "3 - Listar os Alunos aniversariantes do mês" << endl;
                cin >> subOpcao;
                cin.ignore();

                switch (subOpcao)
                {
                case 0:
                    break;

                case 1:

                    break;

                case 2:

                    break;

                default:
                    break;
                }
            } while (subOpcao != 0);

            // LOGICA DA IMPLEMENTACAO
            apagarTodos(pessoas);
            break;

        default:
            printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}