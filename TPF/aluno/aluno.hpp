/*H******************************************************************************
* FILENAME :    aluno.hpp                     DESIGN REF:     TP

* DESCRIPTION :
*       Header da classe Aluno que herda da classe abstrata Pessoa.
*       Define a interface específica para alunos no sistema, incluindo
*       funcionalidades de matrícula e operações específicas de alunos.
*
* PUBLIC FUNCTIONS :
*       - Classe Aluno com herança de Pessoa
*       - Funções de acesso à matrícula (setMatricula, getMatricula)
*       - Funções de identificação (getTipo)
*       - Funções de entrada/saída (leiaPessoa, escrevePessoa)
*       - Funções de persistência (gravar, carregar)
*       - Funções de pesquisa específicas (pesquisaAlunoNome, pesquisaAlunoCPF)
*       - Funções de manipulação (deletaAluno, apagarTodosAlunos)
*
* NOTES :
*       Classe derivada de Pessoa que implementa funcionalidades específicas
*       para alunos, incluindo gerenciamento de matrícula. Implementa todas
*       as funções virtuais puras da classe base. Todas as funções seguem
*       o padrão de um único retorno sem breaks.
*
*       Parte do Sistema de Registro de Pessoas para o projeto final de AEDs.
*
*       Leonardo Stuart de A. Ramalho, 2025. All rights reserved.
*
* AUTHOR    : Leonardo Stuart de A. Ramalho                     START DATE : 24 May 25
*
* CHANGES :
*
* REF NO  VERSION DATE      WHO  DETAIL
* ------- ------- --------- ---- -------------------------------------------
* 001     1.0     16May25   LL   Criacao inicial do arquivo aluno.hpp.
* 002     2.0     30Jun06   LL   Implementação de funcionalidades específicas
*
*H*/

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
    bool carregar(FILE* arquivo);
};

void pesquisaAlunoNome(Pessoa *pessoas[]);
void pesquisaAlunoCPF(Pessoa* pessoas[]);
bool deletaAluno(Pessoa *pessoas[]);
void apagarTodosAlunos(Pessoa *pessoas[]);
void listaAlunos(Pessoa *pessoas[]);
void listarAlunosAniversariantes(Pessoa *pessoas[], int mes);


#endif