/*H**************************************************************************************************************
 *FILENAME :    main.cpp                   DESIGN REF:    TPF
 *
 * DESCRIPTION :
 *       Este arquivo é o ponto de entrada principal do Sistema de Registro de Pessoas.
 *       Ele gerencia o fluxo de execução do programa, apresentando o menu de opções
 *       ao usuário e coordenando as chamadas para as funcionalidades de registro,
 *       listagem, pesquisa, exclusão e gestão de dados de pessoas, professores e alunos.
 *       Atua como a interface de alto nível do sistema
 *
 * NOTES :
 *       Sistema de Registro de Pessoas para o projeto final de AEDs.
 *
 * Luca L. 2025, 2025. All rights reserved.
 *
 * AUTHOR    : Luca L.                     START DATE : 16 May 25
 *
 * CHANGES :
 *
 * REF NO  VERSION   DATE    WHO                DETAIL
 *------- ------- --------- ---- -------------------------------------------
 *001       1.0    16May25   LL   Criacao inicial do arquivo main.cpp.
 *002       1.1    30Jun06   LL   Implementação de tratamento por exceção
 *
 *H*/

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
    { // menu principal
        cout << "\nMenu de funcionalidades, escolha uma opcao: \n";
        cout << "0 - Sair do Programa\n";
        cout << "1 - Cadastrar pessoa\n";
        cout << "2 - Listar todas as pessoas cadastradas\n";
        cout << "3 - Pesquisar por nome\n";
        cout << "4 - Pesquisar por CPF\n";
        cout << "5 - Excluir pessoa\n";
        cout << "6 - Apagar todas as pessoas cadastradas\n";
        cout << "7 - Aniversariantes do mes\n\n";
        cin >> opcao;
        cin.ignore();

        switch (opcao)
        {
        case 0:
            cout << "\nObrigado por usar este programa\n";
            despedida(pessoas);

            // Limpar objetos alocados
            for (int i = 0; i < Pessoa::TAM; i++)
            {
                if (pessoas[i] != nullptr)
                {
                    delete pessoas[i];
                }
            }
            break;

        case 1:
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
                if (Pessoa::TAM >= MAX)
                {
                    cout << "Limite maximo de pessoas atingido!" << endl;
                    break;
                }
                pessoas[Pessoa::TAM] = new Professor();
                try
                {
                    processarObjeto(pessoas[Pessoa::TAM]);
                }
                catch (const runtime_error &e)
                {
                    cout << e.what() << endl;
                }
                pessoas[Pessoa::TAM]->leiaPessoa();
                cout << pessoas[Pessoa::TAM]->getNome() << endl;

                Pessoa::TAM++;
                break;

            case 2:
                if (Pessoa::TAM >= MAX)
                {
                    cout << "Limite maximo de pessoas atingido!" << endl;
                    break;
                }
                pessoas[Pessoa::TAM] = new Aluno();
                try
                {
                    processarObjeto(pessoas[Pessoa::TAM]);
                }
                catch (const runtime_error &e)
                {
                    cout << e.what() << endl;
                }
                pessoas[Pessoa::TAM]->leiaPessoa();
                cout << pessoas[Pessoa::TAM]->getNome() << endl;

                Pessoa::TAM++;
                break;

            default:
                break;
            }
            break;

        case 2:
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
                listaProfessores(pessoas);
                cin.get();
                break;

            case 2:
                listaAlunos(pessoas);
                cin.get();
                break;

            default:
                break;
            }
            break;

        case 3:
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
                cout << "0 - Voltar ao menu inicial" << endl;
                cout << "1 - Informar o mes a ser pesquisado" << endl;
                cout << "2 - Listar os Professores aniversariantes do mes" << endl;
                cout << "3 - Listar os Alunos aniversariantes do mes" << endl
                     << "4 - Listar todos os aniversariantes do mes" << endl
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

                case 4:
                    listarTodosAniversariantes(pessoas, mes);
                    cin.get();
                    break;

                default:
                    break;
                }
            } while (subOpcao != 0);
            break;

        default:
            cout << "\nOpcao invalida!\n";
        }
    } while (opcao != 0);

    return 0;
}