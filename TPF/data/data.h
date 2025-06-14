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

    int diasMes() const;

    bool setData(int dia, int mes, int ano);
    Data getData();

    bool setDia(int dia);
    bool setMes(int mes);
    void setAno(int ano);

    int getDia() const;
    int getMes() const;
    int getAno() const;

    std::string mesExtenso();
    bool dataValida();
    void leiaData();
    void escreveData() const;
};

Data obterDataAtual();
int calcularIdade(const Data &nascimento);

#endif
