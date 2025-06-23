#ifndef CARRO_HPP
#define CARRO_HPP
#include <iostream>
using namespace std;

class Carro : public Transporte
{
    private:

    public:
        void mover();
        Carro(){};
};

#endif
