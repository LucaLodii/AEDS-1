#include "data.h"
#include <iostream>
#include <ctime>

using namespace std;

char *Data::mesExtenso()
{
    static char *extenso[] = {
        (char *)"janeiro", (char *)"fevereiro", (char *)"marco", (char *)"abril", (char *)"maio", (char *)"junho",
        (char *)"julho", (char *)"agosto", (char *)"setembro", (char *)"outubro", (char *)"novembro", (char *)"dezembro"};

    if (dataValida())
        return extenso[mes - 1];
    else
        return (char *)""; // Retorna string vazia se for inválido
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
        return bissexto ? 29 : 28;
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

void Data::leData()
{
    int d, m, a;
    do
    {
        cout << "Dia: ";
        cin >> d;
        cout << "Mês: ";
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
