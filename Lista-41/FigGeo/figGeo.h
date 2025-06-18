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

    virtual ~FigGeo();

    virtual int getQuantidade();

    void setCor(string cor);
    string getCor();

    virtual void leia();

    virtual void escreva();

    virtual float perimetro();

    virtual float area();
};

#endif