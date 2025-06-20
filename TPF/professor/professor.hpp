#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP
#include "../pessoas/pessoas.hpp"

class Professor : public Pessoa
{
private:
    string especializacao;

public:
    void setEspecializacao(string especializacao);
    string getEspecializacao();

    Professor(
        string nome, string, int mes, int dia, int ano)
        : Pessoa(
              nome, mes, dia, ano) {};

    Professor(string especializacao);

    Professor(){};
};

#endif