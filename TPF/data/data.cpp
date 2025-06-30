/*H******************************************************************************
* FILENAME :    data.cpp                     DESIGN REF:     TP

* DESCRIPTION :
*       Implementação da classe Data que gerencia operações relacionadas a datas.
*       Contém todas as implementações das funções declaradas no header data.hpp,
*       incluindo validação robusta de datas, cálculos de idade e manipulação
*       de anos bissextos.
*
* PUBLIC FUNCTIONS :
*       - Implementação de construtores e destrutor da classe Data
*       - Implementação de funções de validação (dataValida, setDia, setMes, setAno)
*       - Implementação de funções de acesso (getDia, getMes, getAno)
*       - Implementação de funções de manipulação (setData, mesExtenso, diasMes)
*       - Implementação de funções de entrada/saída (escreveData, leiaData)
*       - Implementação de funções utilitárias (obterDataAtual, calcularIdade)
*
* NOTES :
*       Implementação robusta com validação completa de datas, incluindo
*       verificação de anos bissextos e validação de dias por mês específico.
*       Todas as funções seguem o padrão de um único retorno sem breaks.
*       Inclui tratamento de casos extremos e validação de limites.
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
* 001     1.0     16May25   LL   Criacao inicial do arquivo data.cpp.
* 002     2.0     30Jun06   LL   Implementação de validação robusta de datas
*
*H*/

#include "data.hpp"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

// Retorna o nome do mês por extenso
string Data::mesExtenso()
{
    string mes = " ";
    string extenso[] = {"janeiro", "fevereiro", "marco", "abril",
                        "maio", "junho", "julho", "agosto",
                        "setembro", "outubro", "novembro", "dezembro"};
    if (dataValida())
        mes = extenso[(this->mes - 1)];
    return mes;
}

// Valida se a data é válida considerando dias por mês e anos bissextos
bool Data::dataValida() const
{
    bool valida = true;
    
    // Checa se o dia, mes e ano sao validos
    if (this->dia < 1 || this->mes < 1 || this->mes > 12)
    {
        valida = false;
    }
    else
    {
        // Checa se o dia é valido para o mes especifico
        int maxDias = 31; // Valor padrao de dias
        
        if (this->mes == 2)
        {
            // Logica de fevereiro
            bool bissexto = false;
            if (this->ano % 400 == 0)
            {
                bissexto = true;
            }
            else if (this->ano % 100 != 0 && this->ano % 4 == 0)
            {
                bissexto = true;
            }
            maxDias = bissexto ? 29 : 28;
        }
        else if (this->mes == 4 || this->mes == 6 || this->mes == 9 || this->mes == 11)
        {
            maxDias = 30; // Abril, Junho, Setembro, Novembro
        }
        
        if (this->dia > maxDias)
        {
            valida = false;
        }
    }
    
    return valida;
}

// Retorna o número de dias no mês atual
int Data::diasMes()
{
    int dias = 31; // Valor padrao de dias
    
    if (this->mes >= 1 && this->mes <= 12)
    {
        if (this->mes == 2)
        {
            bool bissexto = false;
            if (this->ano % 400 == 0)
            {
                bissexto = true;
            }
            else if (this->ano % 100 != 0 && this->ano % 4 == 0)
            {
                bissexto = true;
            }

            dias = bissexto ? 29 : 28;
        }
        else if (this->mes == 4 || this->mes == 6 || this->mes == 9 || this->mes == 11)
        {
            dias = 30; // Abril, Junho, Setembro, Novembro
        }
    }
    
    return dias;
}

// Define o dia se for válido para o mês atual
bool Data::setDia(int d)
{
    if (d >= 1 && d <= diasMes())
    {
        dia = d;
        return true;
    }
    return false;
}

// Define o mês se estiver no intervalo válido
bool Data::setMes(int m)
{
    if (m >= 1 && m <= 12)
    {
        mes = m;
        return true;
    }
    return false;
}

// Define o ano se estiver no intervalo válido
bool Data::setAno(int a)
{
    if (a >= 1900 && a <= 2100)
    {
        ano = a;
        return true;
    }
    return false;
}

// Getters - retornam os valores dos atributos
int Data::getDia() const
{
    return dia;
}

int Data::getMes() const
{
    return mes;
}

int Data::getAno() const
{
    return ano;
}

// Exibe a data no formato DD/MM/AAAA
void Data::escreveData()
{
    cout << dia << "/" << mes << "/" << ano;
}

// Lê uma data do usuário com validação
void Data::leiaData()
{
    int d, m, a;
    do
    {
        cout << "Dia: ";
        cin >> d;
        cout << "Mes: ";
        cin >> m;
        cout << "Ano: ";
        cin >> a;
        setAno(a); // Precisa vir antes do setDia para validar dias corretamente em fevereiro
    } while (!setMes(m) || !setDia(d));
}

// Obtém a data atual do sistema
Data obterDataAtual()
{
    Data d;
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    d.setAno(1900 + ltm->tm_year);
    d.setMes(1 + ltm->tm_mon);
    d.setDia(ltm->tm_mday);
    return d;
}

// Calcula a idade baseada na data de nascimento
int calcularIdade(const Data &nascimento)
{
    Data atual = obterDataAtual();
    int idade = atual.getAno() - nascimento.getAno();

    // Ajusta a idade se ainda não chegou o aniversário
    if (atual.getMes() < nascimento.getMes())
    {
        idade--;
    }
    else if (atual.getMes() == nascimento.getMes())
    {
        if (atual.getDia() < nascimento.getDia())
        {
            idade--;
        }
    }
    return idade;
}

// Construtores
Data::Data()
{
    setData();
}

Data::Data(int ano)
{
    setData(ano);
}

Data::Data(int dia, int mes, int ano)
{
    setData(dia, mes, ano);
}

// Define data vazia (0/0/0)
bool Data::setData() {
    dia = 0;
    mes = 0;
    ano = 0;
    return true;
}

// Define apenas o ano
bool Data::setData(int a) {
    dia = 0;
    mes = 0;
    ano = a;
    return true;
}

// Define data completa com validação
bool Data::setData(int d, int m, int a)
{
    bool yearSet = setAno(a);
    bool monthSet = setMes(m);
    bool daySet = setDia(d);
    return monthSet && daySet && yearSet;
}

// Verifica se o mês é igual ao parâmetro
bool Data::mesIgualParametro(int mes){
    bool ehIgual = false;
    if(getMes() == mes){
        ehIgual = true;
    }
    return ehIgual;
}