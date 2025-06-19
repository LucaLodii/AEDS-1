#include "quadrado.h"

using namespace std;

int quantidadeQ = 0;

Quadrado::Quadrado() : lado(0.0f)
{
    quantidadeQ++;
}

Quadrado::Quadrado(float lado)
{
    this->lado = lado;
    quantidadeQ++;
}

Quadrado::Quadrado(float lado, string cor)
{
    this->lado = lado;
    setCor(cor);
    quantidadeQ++;
}

Quadrado::~Quadrado()
{
    quantidadeQ--;
}

void Quadrado::setLado(float lado)
{
    this->lado = lado;
}

float getLado(float lado)
{
    return lado;
}

void Quadrado::leia()
{
    cout << "Digite o valor do lado do quadrado: ";
    cin >> lado;
    // setLado(lado);

    cout << "Digite a cor do quadrado: ";
    string c;
    cin >> c;
    setCor(c);
}

void Quadrado::escreva()
{
    cout << "Cor: " << getCor() << endl;
    cout << "Lado: " << lado << endl;
    cout << "Perimetro: " << perimetro() << endl;
    cout << "Área: " << area() << endl;
    cout << "Quantidade de Quadrados Cadastrados: " << getQuantidade() << endl;
}

float Quadrado::perimetro()
{
    return lado * 4;
}

float Quadrado::area()
{
    return lado * lado;
}

int Quadrado::getQuantidade()
{
    return quantidadeQ;
}
