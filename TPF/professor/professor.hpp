#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP
#include "../pessoas/pessoas.hpp"

class Professor : public Pessoa
{
private:
    string especializacao;
    const int tipo = 2;

public:
    void setEspecializacao(string especializacao);
    string getEspecializacao();

    int getTipo()
    {
        return tipo;
    }

    Professor(
        string nome, int mes, int dia, int ano)
        : Pessoa(
              nome, mes, dia, ano) {};

    Professor(string especializacao);

    Professor() {};

    void leiaPessoa();
    void escrevePessoa();
    void gravar(FILE* arquivo);
    bool carregar(FILE* arquivo);
};

void pesquisaProfessorNome(Pessoa *pessoas[]);
void pesquisaProfessorCPF(Pessoa* pessoas[]);
bool deletaProfessor(Pessoa *pessoas[]);
void apagarTodosProfessores(Pessoa *pessoas[]);
void listaProfessores(Pessoa *pessoas[]);
void listarProfessoresAniversariantes(Pessoa *pessoas[], int mes);


#endif