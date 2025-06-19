#ifndef CIRUCLO_H
#define CIRCULO_H

#include "../FigGeo/figGeo.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Circulo : public FigGeo
{
    private:
        float raio;
        static int quantidadeC;
        
    public:
        Circulo();
        Circulo(float raio);
        Circulo(float raio, string cor);

        ~Circulo();

        void setRaio(float raio);
        float getRaio();

        void leia();
        void escreva();

        float perimetro();
        float area();

        string getTipo();

        static int getQuantidade();
};

#endif 