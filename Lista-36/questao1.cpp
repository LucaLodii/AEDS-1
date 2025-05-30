#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Quadrado
{
private:
    float lado;
    float teclado;

public:
    void setLado(float lado)
    {
        this->lado = lado;
    }
    void setTeclado(float teclado)
    {
        this->teclado = teclado;
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

    float calcularPerimetro()
    {
        return lado*4;
    }

    float calcularArea()
    {
        return lado*lado;
    }

    void leiaTeclado()
    {
        float teclado;
        cout << "SEGUNDO LADO: ";
        cin >> teclado;
        setTeclado(teclado);
    }
};

int main()
{
    Quadrado Q;

    Quadrado Q1;
    Q.leiaQuadrado();
    Q.leiaTeclado();

    return 0;
}