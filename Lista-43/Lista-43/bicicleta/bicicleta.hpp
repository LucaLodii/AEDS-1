#ifndef BICICLETA_HPP
#define BICICLETA_HPP
#include <iostream>

using namespace std;

class Bicicleta : public Transporte
{
    private:

    public:
        void mover();
        Bicicleta(){};
};

#endif
