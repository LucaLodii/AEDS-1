#include <iostream>
#include <string>
// g++ questao3/main.cpp questao1/main.hpp -o q3
using namespace std;


class Veiculo
{
    private:
    string modelo;
    int ano;
    
    public:
    static int quantidade;
    
    Veiculo()
    {
        quantidade++;
    }
    ~Veiculo() {}
    
    virtual void escreve() = 0;
    
    void setModelo(string modelo)
    {
        this->modelo = modelo;
    }
    string getModelo()
    {
        return modelo;
    }
    
    void setAno(int ano)
    {
        this->ano = ano;
    }
    int getAno()
    {
        return ano;
    }
};

int Veiculo::quantidade = 0;    // TEM QUER ESTAR DEPOIS DA CLASS VEICULO

class Carro : public Veiculo
{
private:
    string tracao;

public:
    Carro() {}
    Carro(string modelo, int ano, string tracao)
    {
        setModelo(modelo);
        setAno(ano);
        this->tracao = tracao;
    }

    void escreve()
    {
        cout << "Modelo: " << getModelo() << ", Ano: " << getAno() << ", Tracao: " << tracao << endl;
    }
    void escreve(string modelo, int ano, string tracao);
};

class Moto : public Veiculo
{
private:
    int cilindradas;

public:
    Moto() {}
    Moto(string modelo, int ano, int cilindradas)
    {
        setModelo(modelo);
        setAno(ano);
        this->cilindradas = cilindradas;
    }

    void escreve()
    {
        cout << "Modelo: " << getModelo() << ", Ano: " << getAno() << ", Tracao: " << cilindradas << endl;
    }
    void escreve(string modelo, int ano, string cilindradas);
};

int main()
{
    // ISSO FOI O MEU PROFESSOR QUE PEDIU NÃO TOQUE NA MAIN
    Veiculo *veiculo[4];
    veiculo[0] = new Carro("Gol", 2020, "dianteira");
    veiculo[1] = new Carro();
    veiculo[2] = new Moto();
    veiculo[3] = new Moto("XL125", 2019, 125);
    cout << endl
         << Veiculo::quantidade;

    cout << "\nDetalhes dos veiculos:" << endl;
    for (int i = 0; i < 4; ++i)
    {
        if (veiculo[i] != nullptr)
        {
            veiculo[i]->escreve();
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        delete veiculo[i];
        veiculo[i] = nullptr;
    }

    return 0;
}