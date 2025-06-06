#include "data.h"
#include <iostream>
#include <ctime>

using namespace std;

static const char* meses[] = {
    "Janeiro", "Fevereiro", "Março", "Abril",
    "Maio", "Junho", "Julho", "Agosto",
    "Setembro", "Outubro", "Novembro", "Dezembro"
};

bool Data::dataValida() const {
    if (ano < 1 || mes < 1 || mes > 12 || dia < 1) 
        return false;
    return dia <= diasMes();
}

const char* Data::mesExtenso() const {
    return (mes >= 1 && mes <= 12)
        ? meses[mes - 1]
        : "Inválido";
}

int Data::diasMes() const {
    if (mes == 2) {
        bool bissexto = (ano % 400 == 0) || (ano % 100 != 0 && ano % 4 == 0);
        return bissexto ? 29 : 28;
    }
    static const int diasPorMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return diasPorMes[mes - 1];
}

void Data::escreveData() const {
    cout << dia << "/" << mes << "/" << ano;
}

void Data::leiaData() {
    int d, m, a;
    do {
        cout << "Dia: ";
        cin >> d;
        cout << "Mês: ";
        cin >> m;
        cout << "Ano: ";
        cin >> a;
    } while (!setDia(d) || !setMes(m));
    setAno(a);
}

Data obterDataAtual() {
    Data d;
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);
    d.setAno(1900 + ltm->tm_year);
    d.setMes(1 + ltm->tm_mon);
    d.setDia(ltm->tm_mday);
    return d;
}

int calcularIdade(const Data& nascimento) {
    Data atual = obterDataAtual();
    int idade = atual.getAno() - nascimento.getAno();
    if ((atual.getMes() < nascimento.getMes()) ||
        (atual.getMes() == nascimento.getMes() && atual.getDia() < nascimento.getDia())) {
        idade--;
    }
    return idade;
}
