#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>

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

    bool setData();
    bool setData(int ano);
    bool setData(int dia, int mes, int ano);

    int getDia() const;
    int getMes() const;
    int getAno() const;

    bool dataValida() const;

    string mesExtenso() const;

    int diasMes();

    void escreveData();
    void leiaData();
};

Data obterDataAtual();
int calcularIdade(const Data &nascimento);

#endif
