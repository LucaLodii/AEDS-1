#include "data.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

std::string Data::mesExtenso()
{
    std::string mes = " ";
    std::string extenso[] = {"janeiro", "fevereiro", "marco", "abril",
                        "maio", "junho", "julho", "agosto",
                        "setembro", "outubro", "novembro", "dezembro"};
    if (dataValida())
        mes = extenso[(this->mes - 1)];
    return mes;
}

bool Data::dataValida()
{
    bool valida = true;
    if (this->dia < 0 || this->dia > 31)
        valida = false;
    else if (this->mes < 0 || this->mes > 12)
        valida = false;
    return valida;
}

int Data::diasMes() const
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

void Data::setAno(int a)
{
    ano = a;
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

void Data::escreveData() const
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

bool Data::setData(int d, int m, int a)
{
    setAno(a); // define primeiro o ano
    if (setMes(m) && setDia(d))
    {
        return true;
    }
    return false;
}

Data Data::getData()
{
    return *this; // retorna o próprio objeto (cópia)
}

