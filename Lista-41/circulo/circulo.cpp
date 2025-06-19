#include "circulo/circulo.h"

using namespace std;

int quantidadeC = 0;

Circulo::Circulo() : raio(0.0f)
{
    quantidadeC++;
}

Circulo::Circulo(float raio)
{
    this->raio = raio;
    quantidadeC++;
}

Circulo::Circulo(float raio, string cor)
{
    this->raio = raio;
    setCor(cor);
    quantidadeC++;
}

Circulo::~Circulo()
{
    quantidadeC--;
}

void Circulo::setRaio(float raio)
{
    this->raio = raio;
}

float getraio(float raio)
{
    return raio;
}

void Circulo::leia()
{
    cout << "Digite o valor do raio do Circulo: ";
    cin >> raio;
    // setraio(raio);

    cout << "Digite a cor do Circulo: ";
    string c;
    cin >> c;
    setCor(c);
}

void Circulo::escreva()
{
    cout << "Cor: " << getCor() << endl;
    cout << "raio: " << raio << endl;
    cout << "Perimetro: " << perimetro() << endl;
    cout << "Área: " << area() << endl;
    cout << "QuantidadeCde Circulos Cadastrados: " << getQuantidade() << endl;
}

float Circulo::perimetro()
{
    return 2 * M_PI * raio;
}

float Circulo::area()
{
    return M_PI * raio * raio;
}

int Circulo::getQuantidade()
{
    return quantidadeC;
}
