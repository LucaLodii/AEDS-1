#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define MAX 5

class Quadrado
{
private:
    float lado;

public:
    void setLado(float lado)
    {
        if(lado >= 0){
            this->lado = lado;
        }
    }

    float getLado()
    {
        return lado;
    }

    float calcularPerimetro()
    {
        return lado * 4;
    }

    float calcularArea()
    {
        return lado * lado;
    }

    void leiaLado()
    {
        float lado;
        do
        {
            cout << "Digite o valor do lado (maior que 0): ";
            cin >> lado;
        } while (lado <= 0);
        setLado(lado);
    }

    void leiaQuadrado()
    {
        leiaLado();
        cout << "Perimetro: " << calcularPerimetro() << endl;
        cout << "Area: " << calcularArea() << endl;
    }

};

int main()
{
    Quadrado Q[MAX];

    for (int i = 0; i < MAX; i++)
    {
        cout << "\nQuadrado " << i + 1 << ":\n";
        Q[i].leiaQuadrado();
    }

    return 0;
}