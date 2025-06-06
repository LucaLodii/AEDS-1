#ifndef DATA_H
#define DATA_H

#include "data.h" 
#include <iostream>

class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    // Setters
    bool setDia(int d) {
        if(d >= 1 && d <= 31) {
            dia = d;
            return true;
        }
        return false;
    }

    bool setMes(int m) {
        if(m >= 1 && m <= 12) {
            mes = m;
            return true;
        }
        return false;
    }

    void setAno(int a) { ano = a; }

    // Getters
    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAno() const { return ano; }

    // Métodos
    bool dataValida() const;
    const char* mesExtenso() const;
    int diasMes() const;
    void escreveData() const;
    void leiaData();
};

// Declarações de funções livres
Data obterDataAtual();
int calcularIdade(const Data& nascimento);

#endif