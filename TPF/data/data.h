#ifndef DATA_H
#define DATA_H

class Data
{
private:
    int dia;
    int mes;
    int ano;

public:

    int diasMes() const;

    bool setData(int dia, int mes, int ano);
    Data getData();

    bool setDia(int dia);
    bool setMes(int mes);
    void setAno(int ano);

    int getDia() const;
    int getMes() const;
    int getAno() const;

    char* mesExtenso();
    bool dataValida();
    void leData();
    void escreveData() const;
};

Data obterDataAtual();
int calcularIdade(const Data &nascimento);

#endif
