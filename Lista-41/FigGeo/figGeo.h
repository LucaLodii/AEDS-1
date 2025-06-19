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

    void leia();
    void escreva();

    float perimetro();
    float area();
};

#endif