#ifndef FIGGEO_H
#define FIGGEO_H

#include <iostream>
#include <string>

using namespace std;

class FigGeo
{
private:
    string cor;

public:
    FigGeo();
    FigGeo(string cor);

    ~FigGeo();

    int getQuantidade();

    void setCor(string cor);
    string getCor();

    virtual void leia();
    virtual void escreva();

    virtual float perimetro() = 0;
    virtual float area() = 0;

    virtual string getTipo() = 0;
};

#endif