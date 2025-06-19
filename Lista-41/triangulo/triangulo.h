#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "../FigGeo/figGeo.h"
#include <iostream>
#include <string>


using namespace std;

class Triangulo : public FigGeo
{
    private:
        float a;
        float b;
        float c;
        static int quantidadeT;
        
    public:
        Triangulo();
        Triangulo(float a, float b, float c);
        Triangulo(float a, float b, float c, string cor);

        ~Triangulo();

        void setTriangulo(float a, float b, float c, string cor);

        float getA();
        float getB();
        float getC();

        void leia();
        void escreva();

        float perimetro();
        float area();

        bool ehValido();

        static int getQuantidade();

        string getTipo();
};

#endif 