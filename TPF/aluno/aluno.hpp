#ifndef ALUNO_HPP
#define ALUNO_HPP
#include "../pessoas/pessoas.hpp"

class Aluno : public Pessoa
{
private:
    unsigned long int matricula;

public:
    void setMatricula(unsigned long int matricula);

    unsigned long int getMatricula();

    Aluno(
        string nome, string, int mes, int dia, int ano)
        : Pessoa(
              nome, mes, dia, ano) {};

    Aluno(unsigned long int matricula);

    Aluno(){};
};

#endif