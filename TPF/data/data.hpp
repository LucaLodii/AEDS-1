#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

using namespace std;

class Data
{
private:
    int dia;
    int mes;
    int ano;

public:
    bool setDia(int dia);
    bool setMes(int mes);
    bool setAno(int ano);

    Data();
    Data(int ano);
    Data(int dia, int mes, int ano);

    bool setData();
    bool setData(int ano);
    bool setData(int dia, int mes, int ano);

    int getDia() const;
    int getMes() const;
    int getAno() const;

    bool dataValida() const;

    string mesExtenso();

    int diasMes();

    void escreveData();
    void leiaData();
};

Data obterDataAtual();
int calcularIdade(const Data &nascimento);

#endif