#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <string>
#include "data/data.hpp"
#include "pessoas/pessoas.hpp"
#include "professor/professor.hpp"
#include "aluno/aluno.hpp"

using namespace std;

// Para rodar: g++ main.cpp pessoas/pessoas.cpp data/data.cpp professor/professor.cpp aluno/aluno.cpp -o main

int main()
{
    setlocale(LC_ALL, "");
    Pessoa *pessoas[MAX];
    abertura(pessoas); // Inicializa o sistema

    int opcao, subOpcao, mes;

    do
    {
        system("cls");
        printf("\nMenu de funcionalidades, escolha uma opcao: \n");
        printf("0 - Sair do Programa\n");
        printf("1 - Cadastrar pessoa\n");
        printf("2 - Listar todas as pessoas cadastradas\n");
        printf("3 - Pesquisar por nome\n");
        printf("4 - Pesquisar por CPF\n");
        printf("5 - Excluir pessoa\n");
        printf("6 - Apagar todas as pessoas cadastradas\n");
        printf("7 - Aniversariantes do mês\n\n");
        cin >> opcao;
        cin.ignore();

        switch (opcao)
        {
        case 0:
            printf("\nObrigado por usar este programa\n");
            despedida(pessoas);
            break;

        case 1:
            system("cls");
            cout << "0 - Voltar ao menu inicial" << endl;
            cout << "1 - Cadastrar Professor" << endl;
            cout << "2 - Cadastrar Aluno" << endl
                 << endl;
            cin >> subOpcao;
            cin.ignore();

            switch (subOpcao)
            {
            case 0:
                break;

            case 1:
                pessoas[Pessoa::TAM] = new Professor();
                pessoas[Pessoa::TAM]->leiaPessoa();
                break;

            case 2:
                pessoas[Pessoa::TAM] = new Aluno();
                pessoas[Pessoa::TAM]->leiaPessoa();
                break;

            default:
                break;
            }
            break;

        case 2:
            system("cls");
            cout << "0 - Voltar ao menu inicial" << endl;
            cout << "1 - Listar Professor" << endl;
            cout << "2 - Listar Aluno" << endl
                 << endl;
            cin >> subOpcao;
            cin.ignore();

            switch (subOpcao)
            {
            case 0:
                break;

            case 1:
                listaAlunos(pessoas);
                cin.get();
                break;

            case 2:
                listaProfessores(pessoas);
                cin.get();
                break;

            default:
                break;
            }
            break;

        case 3:
            system("cls");
            cout << "0 - Voltar ao menu inicial" << endl;
            cout << "1 - Pesquisar Professores por nome" << endl;
            cout << "2 - Pesquisar Alunos por nome" << endl
                 << endl;
            cin >> subOpcao;
            cin.ignore();

            switch (subOpcao)
            {
            case 0:
                break;

            case 1:
                pesquisaProfessorNome(pessoas);
                cin.get();
                break;

            case 2:
                pesquisaAlunoNome(pessoas);
                cin.get();
                break;

            default:
                break;
            }
            break;

        case 4:
            system("cls");
            cout << "0 - Voltar ao menu inicial" << endl;
            cout << "1 - Pesquisar Professores por CPF" << endl;
            cout << "2 - Pesquisar Alunos por CPF" << endl
                 << endl;
            cin >> subOpcao;
            cin.ignore();

            switch (subOpcao)
            {
            case 0:
                break;

            case 1:
                pesquisaProfessorCPF(pessoas);
                cin.get();
                break;

            case 2:
                pesquisaAlunoCPF(pessoas);
                cin.get();
                break;

            default:
                break;
            }
            break;

        case 5:
            system("cls");
            cout << "0 - Voltar ao menu inicial" << endl;
            cout << "1 - Excluir Professor (pelo CPF)" << endl;
            cout << "2 - Excluir Aluno (pelo CPF)" << endl
                 << endl;
            cin >> subOpcao;
            cin.ignore();

            switch (subOpcao)
            {
            case 0:
                break;

            case 1:
                deletaProfessor(pessoas);
                cin.get();
                break;

            case 2:
                deletaAluno(pessoas);
                cin.get();
                break;

            default:
                break;
            }
            break;

        case 6:
            system("cls");
            cout << "0 - Voltar ao menu inicial" << endl;
            cout << "1 - Excluir todos os Professores" << endl;
            cout << "2 - Excluir todos os Alunos" << endl
                 << endl;
            cin >> subOpcao;
            cin.ignore();

            switch (subOpcao)
            {
            case 0:
                break;

            case 1:
                apagarTodosProfessores(pessoas);
                cin.get();
                break;

            case 2:
                apagarTodosAlunos(pessoas);
                cin.get();
                break;

            default:
                break;
            }
            break;

        case 7:
            do
            {
                system("cls");
                cout << "0 - Voltar ao menu inicial" << endl;
                cout << "1 - Informar o mês a ser pesquisado" << endl;
                cout << "2 - Listar os Professores aniversariantes do mês" << endl;
                cout << "3 - Listar os Alunos aniversariantes do mês" << endl
                     << endl;
                cin >> subOpcao;
                cin.ignore();

                switch (subOpcao)
                {
                case 0:
                    break;

                case 1:
                    cout << "Mes a ser pesquisado: [01 a 12]";
                    cin >> mes;
                    break;

                case 2:
                    listarProfessoresAniversariantes(pessoas, mes);
                    cin.get();
                    break;

                case 3:
                    listarAlunosAniversariantes(pessoas, mes);
                    cin.get();
                    break;

                default:
                    break;
                }
            } while (subOpcao != 0);
            break;

        default:
            printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}