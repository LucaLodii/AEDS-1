#include "data.h"
#include <iostream>
#include <ctime>
#include <cstring> // Para pode usar strcpy

static const char* meses[] = {
    "Janeiro", "Fevereiro", "Março", "Abril",
    "Maio", "Junho", "Julho", "Agosto",
    "Setembro", "Outubro", "Novembro", "Dezembro"
};

bool Data::dataValida() const {
    if(ano < 1 || mes < 1 || mes > 12 || dia < 1) return false;
    return dia <= diasMes();
}

const char* Data::mesExtenso() const {
    return (mes >= 1 && mes <= 12) ? meses[mes-1] : "Inválido";
}

int Data::diasMes() const {
    if(mes == 2) {
        return (ano % 400 == 0 || (ano % 100 != 0 && ano % 4 == 0)) ? 29 : 28;
    }
    const int dias[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    return dias[mes-1];
}

void Data::escreveData() const {
    std::cout << dia << "/" << mes << "/" << ano;
}

void Data::leiaData() {
    int d, m, a;
    do {
        std::cout << "Dia: ";
        std::cin >> d;
        std::cout << "Mês: ";
        std::cin >> m;
        std::cout << "Ano: ";
        std::cin >> a;
    } while(!setDia(d) || !setMes(m));
    setAno(a);
}

Data obterDataAtual() {
    Data d;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    d.setAno(1900 + ltm->tm_year);
    d.setMes(1 + ltm->tm_mon);
    d.setDia(ltm->tm_mday);
    return d;
}

int calcularIdade(const Data& nascimento) {
    Data atual = obterDataAtual();
    int idade = atual.getAno() - nascimento.getAno();
    if(atual.getMes() < nascimento.getMes() || 
      (atual.getMes() == nascimento.getMes() && atual.getDia() < nascimento.getDia())) {
        idade--;
    }
    return idade;
}