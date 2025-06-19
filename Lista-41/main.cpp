// Fiz esse programa praticamente igual ao diagrama do Lucio, mas optei por trocar algumas coisas nos .h
// Explicação do pq eu usei nullptr e não NULL
// Optei também por usar nullptr (exclusivo do C++), pois de acordo com o que pesquisei ele é mais seguro para todos casos ja que não é um inteiro em si
// e sim um ponteiro inteiro que aponto para nulo, logo ele funciona tanto para um valor nulo quanto para um ponteiro que aponta para nulo, diferente do
// do NULL.
#include <iostream>
#include <string>

#include "FigGeo/FigGeo.h"
#include "Circulo/Circulo.h"
#include "Quadrado/Quadrado.h"
#include "Triangulo/Triangulo.h"

using namespace std;

const int MAX = 100;
FigGeo *arrFiguras[MAX];

int numFigurasCadastradas = 0;

int main()
{

    for (int i = 0; i < MAX; ++i)
    {
        arrFiguras[i] = nullptr;
    }

    int opcao;

    do
    {
        cout << "\nMenu de funcionalidades, escolha uma opcao:\n";
        cout << "0 - Sair do Programa\n";
        cout << "1 - Circulos\n";
        cout << "2 - Quadrados\n";
        cout << "3 - Triangulos\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 0:
            cout << "\nObrigado por usar este programa!\n";
            break;

        case 1:
        {
            int opcaoC;
            do
            {
                cout << "\nSubmenu - Circulos\n";
                cout << "0 - Voltar ao menu anterior\n";
                cout << "1 - Cadastrar\n";
                cout << "2 - Listar\n";
                cout << "Escolha: ";
                cin >> opcaoC;

                switch (opcaoC)
                {
                case 1:
                {
                    cout << "\nCadastrar Circulo\n";
                    if (numFigurasCadastradas < MAX)
                    {
                        Circulo *novo = new Circulo();
                        novo->leia();
                        arrFiguras[numFigurasCadastradas] = novo;
                        numFigurasCadastradas++;
                        cout << "Circulo cadastrado com sucesso! Total de círculos: " << Circulo::getQuantidade() << "\n";
                    }
                    else
                    {
                        cout << "Limite de figuras atingido!\n";
                    }
                    break;
                }
                    // Para esse case 2 tive que fazer uma função getTipo visto que o arr que o Lucio pediu armazena qualquer figura e não as diferencia
                    // Isso se repete nas outras formas
                case 2:
                {
                    cout << "\nListando Círculos:\n";
                    bool encontrouCirculo = false;

                    for (int i = 0; i < Circulo::getQuantidade(); ++i)
                    {
                        if (arrFiguras[i] != NULL && arrFiguras[i]->getTipo() == "circulo")
                        {
                            arrFiguras[i]->escreva();
                            encontrouCirculo = true;
                        }
                    }

                    if (!encontrouCirculo)
                    {
                        cout << "Nenhum círculo cadastrado.\n";
                    }
                    break;
                }

                case 0:
                    cout << "Voltando...\n";
                    break;
                default:
                    cout << "Opcao invalida!\n";
                    break;
                }
            } while (opcaoC != 0);
            break;
        }

        case 2:
        {
            int opcaoQ;
            do
            {
                cout << "\nSubmenu - Quadrados\n";
                cout << "0 - Voltar ao menu anterior\n";
                cout << "1 - Cadastrar\n";
                cout << "2 - Listar\n";
                cout << "Escolha: ";
                cin >> opcaoQ;

                switch (opcaoQ)
                {
                case 1:
                {
                    cout << "\nCadastrar Quadrado\n";
                    if (numFigurasCadastradas < MAX)
                    {
                        Quadrado *novo = new Quadrado();
                        novo->leia();
                        arrFiguras[numFigurasCadastradas] = novo;
                        numFigurasCadastradas++;
                        cout << "Quadrado cadastrado com sucesso! Total de quadrados: " << Quadrado::getQuantidade() << "\n";
                    }
                    else
                    {
                        cout << "Limite de figuras atingido!\n";
                    }
                    break;
                }
                // case 2:
                // {
                //     cout << "\nListando Quadrados:\n";
                //     bool encontrouQuadrado = false;
                //     for (int i = 0; i < numFigurasCadastradas; ++i)
                //     {
                //         // Verifica se o ponteiro aponta para um objeto Quadrado
                //         Quadrado* q = dynamic_cast<Quadrado*>(arrFiguras[i]);
                //         if (q) // Se for um Quadrado
                //         {
                //             q->escreva(); // Chama o método escreva do Quadrado
                //             encontrouQuadrado = true;
                //         }
                //     }
                //     if (!encontrouQuadrado)
                //     {
                //         cout << "Nenhum quadrado cadastrado.\n";
                //     }
                //     break;
                // }
                case 0:
                    cout << "Voltando...\n";
                    break;
                default:
                    cout << "Opcao invalida!\n";
                    break;
                }
            } while (opcaoQ != 0);
            break;
        }

        case 3:
        {
            int opcaoT;
            do
            {
                cout << "\nSubmenu - Triangulos\n";
                cout << "0 - Voltar ao menu anterior\n";
                cout << "1 - Cadastrar\n";
                cout << "2 - Listar\n";
                cout << "Escolha: ";
                cin >> opcaoT;

                switch (opcaoT)
                {
                case 1:
                {
                    cout << "\nCadastrar Triangulo\n";
                    if (numFigurasCadastradas < MAX)
                    {
                        Triangulo *novo = new Triangulo();
                        novo->leia();
                        if (novo->ehValido())
                        {
                            arrFiguras[numFigurasCadastradas] = novo;
                            numFigurasCadastradas++;
                            cout << "Triângulo cadastrado com sucesso! Total de triângulos: " << Triangulo::getQuantidade() << "\n";
                        }
                        else
                        {
                            cout << "Erro: lados não formam um triângulo válido!\n";
                            delete novo;
                        }
                    }
                    else
                    {
                        cout << "Limite de figuras atingido!\n";
                    }
                    break;
                }
                // case 2:
                // {
                //     cout << "\nListando Triângulos:\n";
                //     bool encontrouTriangulo = false;
                //     for (int i = 0; i < numFigurasCadastradas; ++i)
                //     {
                //         // Verifica se o ponteiro aponta para um objeto Triangulo
                //         Triangulo* t = dynamic_cast<Triangulo*>(arrFiguras[i]);
                //         if (t) // Se for um Triangulo
                //         {
                //             t->escreva(); // Chama o método escreva do Triangulo
                //             encontrouTriangulo = true;
                //         }
                //     }
                //     if (!encontrouTriangulo)
                //     {
                //         cout << "Nenhum triângulo cadastrado.\n";
                //     }
                //     break;
                // }
                case 0:
                    cout << "Voltando...\n";
                    break;
                default:
                    cout << "Opcao invalida!\n";
                    break;
                }
            } while (opcaoT != 0);
            break;
        }

        default:
            cout << "Opcao invalida!\n";
            break;
        }

    } while (opcao != 0);

    // Esporro que eu tomei da IA:
    // ATENÇÃO: Como o destrutor de FigGeo NÃO é virtual no seu último FigGeo.h,
    // o 'delete' aqui chamará apenas o destrutor de FigGeo, e não os destrutores
    // das classes derivadas (Circulo, Quadrado, Triangulo). Isso pode causar
    // vazamentos de memória para recursos específicos dessas classes.
    // Recomenda-se fortemente que o destrutor em FigGeo.h seja 'virtual ~FigGeo();'.
    for (int i = 0; i < numFigurasCadastradas; ++i)
    {
        if (arrFiguras[i] != nullptr)
        {
            delete arrFiguras[i];
            arrFiguras[i] = nullptr;
        }
    }

    return 0;
}
