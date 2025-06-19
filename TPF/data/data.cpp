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
    if (this->dia < 0 || this->dia > 31)
        valida = false;
    else if (this->mes < 0 || this->mes > 12)
        valida = false;
    return valida;
}

int Data::diasMes()
{
    if (mes == 2)
    {
        bool bissexto = false;
        if (ano % 400 == 0)
        {
            bissexto = true;
        }
        else if (ano % 100 != 0 && ano % 4 == 0)
        {
            bissexto = true;
        }

        if (bissexto)
            return 29;
        else
            return 28;
    }

    static const int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return diasPorMes[mes - 1];
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

bool Data::setData() {
    dia = 0;
    mes = 0;
    ano = 0;
    return true;
}

bool Data::setData(int a) {
    dia = 0;
    mes = 0;
    ano = a;
    return true;
}

bool Data::setData(int d, int m, int a)
{
    bool yearSet = setAno(a);
    bool monthSet = setMes(m);
    bool daySet = setDia(d);
    return monthSet && daySet && yearSet;
}
