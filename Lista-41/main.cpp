#include <iostream>
#include <string>

#include "FigGeo/figGeo.h"
#include "circulo/circulo.h"
#include "quadrado/quadrado.h"
#include "triangulo/triangulo.h"

const int MAX = 100;
FigGeo *arranjoFiguras[MAX];

int main()
{

    int opcao;
    do
    {
        cout << "\nMenu de funcionalidades, escolha uma opcao: \n";
        cout << "0 - Sair do Programa\n";
        cout << "1 - Circulos\n";
        cout << "2 - Quadrados\n";
        cout << "3 - Triangulos\n";

        cin >> opcao;

        switch (opcao)
        {
        case 0:
            cout << "\nObrigado por usar este programa\n";
            break;

        case 1:
            // Lógica para o menu de Círculos
            // Chame cadastrarFigura(1) ou listarFiguras(1) aqui
            break;

        case 2:
            // Lógica para o menu de Quadrados
            break;

        case 3:
            // Lógica para o menu de Triângulos
            break;

        default:
            cout << "\nOpcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}