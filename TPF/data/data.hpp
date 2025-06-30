/*H******************************************************************************
* FILENAME :    data.hpp                     DESIGN REF:     TP

* DESCRIPTION :
*       Header da classe Data que gerencia operações relacionadas a datas.
*       Fornece funcionalidades para validação, manipulação e formatação de datas,
*       incluindo suporte a anos bissextos e cálculos de idade.
*
* PUBLIC FUNCTIONS :
*       - Construtores e destrutor da classe Data
*       - Funções de validação de data (dataValida, setDia, setMes, setAno)
*       - Funções de acesso aos atributos (getDia, getMes, getAno)
*       - Funções de manipulação de data (setData, mesExtenso, diasMes)
*       - Funções de entrada/saída (escreveData, leiaData)
*       - Funções utilitárias (obterDataAtual, calcularIdade)
*
* NOTES :
*       Esta classe é fundamental para o sistema de registro de pessoas,
*       fornecendo validação robusta de datas e cálculos de idade.
*       Implementa lógica para anos bissextos e validação de dias por mês.
*       Todas as funções seguem o padrão de um único retorno sem breaks.
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
* 001     1.0     16May25   LL   Criacao inicial do arquivo data.hpp.
* 002     2.0     30Jun06   LL   Implementação de validação robusta de datas
*
*H*/

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

using namespace std;

class Data
{
private:
    int dia;
    int mes;
    int ano;

public:
    bool setDia(int dia);
    bool setMes(int mes);
    bool setAno(int ano);

    Data();
    ~Data(){};
    Data(int ano);
    Data(int dia, int mes, int ano);

    bool setData();
    bool setData(int ano);
    bool setData(int dia, int mes, int ano);

    int getDia() const;
    int getMes() const;
    int getAno() const;

    bool dataValida() const;

    bool mesIgualParametro(int mes);

    string mesExtenso();

    int diasMes();

    void escreveData();
    void leiaData();
};

Data obterDataAtual();
int calcularIdade(const Data &nascimento);

#endif