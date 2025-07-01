/*H**************************************************************************************************************
*FILENAME  :    data.cpp                        DESIGN REF:      TPF
*
* DESCRIPTION :
*       Implementação da classe 'Data' para representação, manipulação e validação
*       de datas (dia, mês e ano). Este arquivo contém as definições dos construtores
*       sobrecarregados, getters, setters, e métodos utilitários como validação de
*       datas, cálculo de dias no mês e formatação do mês por extenso. Inclui também
*       a lógica para leitura/escrita de dados de data e funções auxiliares para
*       obter a data atual do sistema e calcular a idade a partir de uma data de nascimento.
*
* PUBLIC FUNCTIONS :
*       Data::Data()
*       Data::Data(int ano)
*       Data::Data(int dia, int mes, int ano)
*       bool Data::setDia(int dia)
*       bool Data::setMes(int mes)
*       bool Data::setAno(int ano)
*       bool Data::setData()
*       bool Data::setData(int ano)
*       bool Data::setData(int dia, int mes, int ano)
*       int Data::getDia() const
*       int Data::getMes() const
*       int Data::getAno() const
*       bool Data::dataValida() const
*       bool Data::mesIgualParametro(int mes)
*       string Data::mesExtenso()
*       int Data::diasMes()
*       void Data::escreveData()
*       void Data::leiaData()
*       Data obterDataAtual()
*       int calcularIdade(const Data &nascimento)
*
* NOTES :
*       Parte do Sistema de Registro de Pessoas para o projeto final de AEDs.
*
* COPYRIGHT : Luca L. 2025, 2025. All rights reserved.
*
* AUTHOR    : Luca L.                     START DATE : 16 May 25
*
* CHANGES :
*
* REF NO  VERSION   DATE      WHO          DETAIL
*------- ------- --------- ---- -------------------------------------------
*001       1.0     16May25   LL   Criacao inicial do arquivo data.cpp.
*002       1.1     30Jun25   LL   Implementacao de construtores e refinamento de getters/setters.
*
*******************************************************************************/

#include "data.hpp"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

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

bool Data::setDia(int d)
{
    if (d >= 1 && d <= diasMes())
    {
        dia = d;
        return true;
    }
    return false;
}

bool Data::setMes(int m)
{
    if (m >= 1 && m <= 12)
    {
        mes = m;
        return true;
    }
    return false;
}

bool Data::setAno(int a)
{
    if (a >= 1900 && a <= 2100)
    {
        ano = a;
        return true;
    }
    return false;
}

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

void Data::escreveData()
{
    cout << dia << "/" << mes << "/" << ano;
}

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

Data obterDataAtual()
{
    // Obtém a data atual do sistema
    Data d;
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    d.setAno(1900 + ltm->tm_year);
    d.setMes(1 + ltm->tm_mon);
    d.setDia(ltm->tm_mday);
    return d;
}

int calcularIdade(const Data &nascimento)
{
    // Calcula a idade com base na data de nascimento
    Data atual = obterDataAtual();
    int idade = atual.getAno() - nascimento.getAno();

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

// Construtor padrão: inicializa a data com valores zero
Data::Data()
{
    setData();
}

// Construtor: inicializa a data com o ano fornecido e dia/mês zero
Data::Data(int ano)
{
    setData(ano);
}

// Construtor: inicializa a data com dia, mês e ano fornecidos
Data::Data(int dia, int mes, int ano)
{
    setData(dia, mes, ano);
}

// Define a data para valores zero
bool Data::setData() {
    dia = 0;
    mes = 0;
    ano = 0;
    return true;
}

// Define o ano e zera dia/mês
bool Data::setData(int a) {
    dia = 0;
    mes = 0;
    ano = a;
    return true;
}

// Define dia, mês e ano, utilizando os setters individuais
bool Data::setData(int d, int m, int a)
{
    bool yearSet = setAno(a);
    bool monthSet = setMes(m);
    bool daySet = setDia(d);
    return monthSet && daySet && yearSet; // Retorna true se todos os componentes foram definidos com sucesso
}

// Verifica se o mês do objeto é igual ao mês passado como parâmetro
bool Data::mesIgualParametro(int mes){
    bool ehIgual = false;
    if(getMes() == mes){
        ehIgual = true;
    }
    return ehIgual;
}