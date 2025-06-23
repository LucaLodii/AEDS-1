#include "transporte/transporte.hpp"
#include "aviao/aviao.hpp"
#include "bicicleta/bicicleta.hpp"
#include "carro/carro.hpp"

#include <iostream>

int main()
{
    Transporte *transporte[3];
    transporte[0] = new Aviao();
    transporte[1] = new Bicicleta();
    transporte[2] = new Carro();

    for(Transporte *contador: transporte){
        contador->mover();
    }

    return 0;
}