#ifndef QUADRADO_H
#define QUADRADO_H

#include "FigGeo.h"
#include <iostream>
#include <string>

using namespace std;

class Quadrado : public FigGeo
{
    private:
        float lado;
        static int quantidadeQ;
        
    public:
        Quadrado();
        Quadrado(float lado);
        Quadrado(float lado, string cor);

        ~Quadrado();

        void setLado(float lado);
        float getLado();

        void leia();
        void escreva();

        float perimetro();
        float area();

        int getQuantidade();
};

#endif 