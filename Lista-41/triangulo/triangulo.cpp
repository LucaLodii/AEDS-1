#include "triangulo.h"
#include "../FigGeo/figGeo.h"
#include <cmath>

int Triangulo::quantidadeT = 0;

Triangulo::Triangulo()
{
    quantidadeT++;
}

Triangulo::Triangulo(float a, float b, float c)
{
    this->a = a;
    this->b = b;
    this->c = c;
    quantidadeT++;
}

Triangulo::Triangulo(float a, float b, float c, std::string cor) {
    setTriangulo(a, b, c, cor);
    quantidadeT++;
}


Triangulo::~Triangulo()
{
    quantidadeT--;
}

void Triangulo::setTriangulo(float a, float b, float c, std::string cor) {
    this->a = a;
    this->b = b;
    this->c = c;
    setCor(cor);
}

void Triangulo::leia()
{
    cout << "Digite o 1o lado: ";
    cin >> a;
    cout << "Digite o 2o lado: ";
    cin >> b;
    cout << "Digite o 3o lado: ";
    cin >> c;

    string cor;
    cout << "Digite a cor do Triângulo: ";
    cin >> cor;
    setCor(cor);
}

void Triangulo::escreva()
{
    cout << "Cor: " << getCor() << endl;
    cout << "1º lado: " << a << endl;
    cout << "2º lado: " << b << endl;
    cout << "3º lado: " << c << endl;
    cout << "Perímetro: " << perimetro() << endl;
    cout << "Área: " << area() << endl;
    cout << "Quantidade de Triângulos Cadastrados: " << getQuantidade() << endl;
}

float Triangulo::perimetro()
{
    return a + b + c;
}

float Triangulo::area() {
    float s = perimetro() / 2.0f;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}


bool Triangulo::ehValido() {
    bool ehTriangulo = (a + b > c) && (a + c > b) && (b + c > a);
    return ehTriangulo;
}

string Triangulo::getTipo()
{
    return "triangulo";
}

int Triangulo::getQuantidade()
{
    return quantidadeT;
}
