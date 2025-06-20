#include <iostream>
#include "professor.hpp"

using namespace std;

Professor::Professor(string especializacao)
{
    setEspecializacao(especializacao);
}

void Professor::setEspecializacao(string especializacao)
{
    this->especializacao = especializacao;
};

string Professor::getEspecializacao()
{
    return especializacao;
};
