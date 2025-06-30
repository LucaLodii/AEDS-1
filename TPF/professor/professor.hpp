/*H******************************************************************************
* FILENAME :    professor.hpp                 DESIGN REF:     TP

* DESCRIPTION :
*       Header da classe Professor que herda da classe abstrata Pessoa.
*       Define a interface específica para professores no sistema, incluindo
*       funcionalidades de especialização e operações específicas de professores.
*
* PUBLIC FUNCTIONS :
*       - Classe Professor com herança de Pessoa
*       - Funções de acesso à especialização (setEspecializacao, getEspecializacao)
*       - Funções de identificação (getTipo)
*       - Funções de entrada/saída (leiaPessoa, escrevePessoa)
*       - Funções de persistência (gravar, carregar)
*       - Funções de pesquisa específicas (pesquisaProfessorNome, pesquisaProfessorCPF)
*       - Funções de manipulação (deletaProfessor, apagarTodosProfessores)
*
* NOTES :
*       Classe derivada de Pessoa que implementa funcionalidades específicas
*       para professores, incluindo gerenciamento de especialização. Implementa
*       todas as funções virtuais puras da classe base. Todas as funções seguem
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
* 001     1.0     16May25   LL   Criacao inicial do arquivo professor.hpp.
* 002     2.0     30Jun06   LL   Implementação de funcionalidades específicas
*
*H*/

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