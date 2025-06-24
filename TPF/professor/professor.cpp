#include <iostream>
#include "professor.hpp"

using namespace std;

Professor::Professor(string especializacao)
{
    setEspecializacao(especializacao);
}

void Professor::setEspecializacao(string especializacao)
{
    this->especializacao = especializacao;
};

string Professor::getEspecializacao()
{
    return especializacao;
};

void Professor::leiaPessoa()
{
    string nome;
    cout << "\nNome: ";
    getline(cin, nome);
    setNome(nome);

    cout << "\nCPF: ";
    leiaCPF();
    cout << "\nData de nascimento: [DD MM AAAA]";
    int dia, mes, ano;
    cin >> dia >> mes >> ano;
    setNascimento(dia, mes, ano);
    cout << "\nEspecializacao: ";
    string especializacao;
    cin >> especializacao;
    setEspecializacao(especializacao);
    Pessoa::TAM++;
}

void pesquisaProfessorNome(Pessoa *pessoas[])
{
    string supostoNome;
    cout << "\nDigite o nome a ser encontrado: ";
    getline(cin, supostoNome);

    int encontradas = 0;
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getTipo() == 2)
        {
            if (pessoas[i]->getNome() == supostoNome)
            {
                pessoas[i]->escrevePessoa();
                encontradas++;
            }
        }
    }

    if (encontradas == 0)
    {
        cout << "Nenhum professor encontrado com o nome '" << supostoNome << "'.\n";
    }
}

void Professor::escrevePessoa()
{
    cout << "\nNome: " << getNome();
    cout << "\nData de Nascimento: ";
    Data nascimento = getNascimento();
    nascimento.escreveData();
    cout << "\nCPF: " << getCPF();
    cout << "\nEspecializacao: " << getEspecializacao();
}

void pesquisaProfessorCPF(Pessoa *pessoas[])
{
    string supostoCPF;
    cout << "\nDigite o CPF a ser encontrado (000.000.000-00): ";
    getline(cin, supostoCPF);

    int encontradas = 0;
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getTipo() == 2)
        {
            if (pessoas[i]->getNome() == supostoCPF)
            {
                pessoas[i]->escrevePessoa();
                encontradas++;
            }
        }
    }

    if (encontradas == 0)
    {
        cout << "Nenhum professor encontrado com o CPF '" << supostoCPF << "'.\n";
    }
}

bool deletaProfessor(Pessoa *pessoas[])
{
    string cpf;
    cout << "\nCPF para excluir (000.000.000-00): ";
    getline(cin, cpf);

    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getTipo() == 1)
        {
            if (pessoas[i]->getCPF() == cpf)
            {
                for (int j = i; j < Pessoa::TAM - 1; j++)
                {
                    pessoas[j] = pessoas[j + 1]; // Faz o "shift"
                }
                Pessoa::TAM--;
                cout << "Pessoa excluida com sucesso!\n";
                return true;
            }
        }
    }
    cout << "CPF não encontrado.\n";
    return false;
}

void apagarTodosProfessores(Pessoa *pessoas[])
{
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getTipo() == 2)
        {
            for (int j = i; j < Pessoa::TAM - 1; j++)
            {
                pessoas[j] = pessoas[j + 1]; // Faz o "shift"
            }
            Pessoa::TAM--;
        }
        if (pessoas[i]->getTipo() == 2)
        {
            i--;
        }
    }
    cout << "Professores excluidos com sucesso!\n";
}

void listaProfessores(Pessoa *pessoas[])
{
    if (Pessoa::TAM == 0)
    {
        cout << "Nenhuma pessoa cadastrada." << endl;
    }
    else
    {
        for (int i = 0; i < Pessoa::TAM; i++)
        {
            if (pessoas[i]->getTipo() == 2)
            {
                pessoas[i]->escrevePessoa();
            }
        }
    }
}

void listarProfessoresAniversariantes(Pessoa *pessoas[], int mes)
{
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        Data nascimento = pessoas[i]->getNascimento();
        int mesNiver = nascimento.getMes();
        if (pessoas[i]->getTipo() == 2 && mes == mesNiver)
        {
            pessoas[i]->escrevePessoa();
        }
    }
}

// funcoes de arquivos
void Professor::gravar(FILE *arquivo)
{
    // Anotar o Tipo da Classe (2 == Professor)
    int tipo = 2;
    fwrite(&tipo, sizeof(int), 1, arquivo);

    string nome = getNome();
    
    int nomeLen = nome.length();
    fwrite(&nomeLen, sizeof(int), 1, arquivo);
    fwrite(nome.c_str(), sizeof(char), nomeLen, arquivo);
    
    string cpf = getCPF();

    int cpfLen = cpf.length();
    fwrite(&cpfLen, sizeof(int), 1, arquivo);
    fwrite(cpf.c_str(), sizeof(char), cpfLen, arquivo);

    Data nascimento = getNascimento();
    int dia = nascimento.getDia();
    int mes = nascimento.getMes();
    int ano = nascimento.getAno();

    fwrite(&dia, sizeof(int), 1, arquivo);
    fwrite(&mes, sizeof(int), 1, arquivo);
    fwrite(&ano, sizeof(int), 1, arquivo);

    string especializacao = getEspecializacao();
    int espLen = especializacao.length();
    fwrite(&espLen, sizeof(int), 1, arquivo);
    fwrite(especializacao.c_str(), sizeof(char), espLen, arquivo);    
}

void Professor::carregar(FILE *arquivo)
{
    int nomeLen;
    fread(&nomeLen, sizeof(int), 1, arquivo);
    char *nomeBuf = new char[nomeLen + 1];
    fread(nomeBuf, sizeof(char), nomeLen, arquivo);
    nomeBuf[nomeLen] = '\0';
    setNome(nomeBuf);
    delete[] nomeBuf;

    int cpfLen;
    fread(&cpfLen, sizeof(int), 1, arquivo);
    char *cpfBuf = new char[cpfLen + 1];
    fread(cpfBuf, sizeof(char), cpfLen, arquivo);
    cpfBuf[cpfLen] = '\0';
    setCPF(cpfBuf);
    delete[] cpfBuf;
    
    int dia, mes, ano;
    fread(&dia, sizeof(int), 1, arquivo);
    fread(&mes, sizeof(int), 1, arquivo);
    fread(&ano, sizeof(int), 1, arquivo);
    setNascimento(dia, mes, ano);
    
    int especializacaoLen;
    fread(&especializacaoLen, sizeof(int), 1, arquivo);
    char *espBuf = new char[especializacaoLen + 1];
    fread(espBuf, sizeof(char), especializacaoLen, arquivo);
    espBuf[especializacaoLen] = '\0';
    setEspecializacao(espBuf);
    delete[] espBuf;
}