#ifndef ALUNO_HPP
#define ALUNO_HPP
#include "../pessoas/pessoas.hpp"

class Aluno : public Pessoa
{
private:
    unsigned long int matricula;
    const int tipo = 1;

public:
    void setMatricula(unsigned long int matricula);

    int getTipo(){
        return tipo;
    }

    unsigned long int getMatricula();

    Aluno(
        string nome, int mes, int dia, int ano)
        : Pessoa(
              nome, mes, dia, ano) {};

    Aluno(unsigned long int matricula);

    Aluno(){};

    void leiaPessoa();
    void escrevePessoa();
    void gravar(FILE* arquivo);
    void carregar(FILE* arquivo);
};

void pesquisaAlunoNome(Pessoa *pessoas[]);
void pesquisaAlunoCPF(Pessoa* pessoas[]);
bool deletaAluno(Pessoa *pessoas[]);
void apagarTodosAlunos(Pessoa *pessoas[]);
void listaAlunos(Pessoa *pessoas[]);
void listarAlunosAniversariantes(Pessoa *pessoas[], int mes);


#endif