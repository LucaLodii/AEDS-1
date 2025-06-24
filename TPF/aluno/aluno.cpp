#include <iostream>
#include "aluno.hpp"

using namespace std;

Aluno::Aluno(unsigned long int matricula)
{
    setMatricula(matricula);
}

void Aluno::setMatricula(unsigned long int matricula)
{
    this->matricula = matricula;
};

unsigned long int Aluno::getMatricula()
{
    return matricula;
};

void Aluno::leiaPessoa()
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
    cout << "\nMatricula: ";
    unsigned long int matricula;
    cin >> matricula;
    setMatricula(matricula);
    Pessoa::TAM++;
}

void pesquisaAlunoNome(Pessoa *pessoas[])
{
    string supostoNome;
    cout << "\nDigite o nome a ser encontrado: ";
    cin.ignore();
    getline(cin, supostoNome);

    int encontradas = 0;
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getTipo() == 1)
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
        cout << "Nenhum aluno encontrado com o nome '" << supostoNome << "'.\n";
    }
}

void Aluno::escrevePessoa()
{
    cout << "\nNome: " << getNome();
    cout << "\nData de Nascimento: ";
    Data nascimento = getNascimento();
    nascimento.escreveData();
    cout << "\nCPF: " << getCPF();
    cout << "\nMatricula: " << getMatricula();
}

void pesquisaAlunoCPF(Pessoa *pessoas[])
{
    string supostoCPF;
    cout << "\nDigite o CPF a ser encontrado (000.000.000-00): ";
    cin.ignore(); // evita erro caso o buffer do cin esteja sujo
    getline(cin, supostoCPF);

    int encontradas = 0;
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getTipo() == 1)
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
        cout << "Nenhum aluno encontrado com o CPF '" << supostoCPF << "'.\n";
    }
}

bool deletaAluno(Pessoa *pessoas[])
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

void apagarTodosAlunos(Pessoa *pessoas[])
{
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getTipo() == 1)
        {
            for (int j = i; j < Pessoa::TAM - 1; j++)
            {
                pessoas[j] = pessoas[j + 1]; // Faz o "shift"
            }
            Pessoa::TAM--;
        }
        if (pessoas[i]->getTipo() == 1)
        {
            i--;
        }
    }
    cout << "Alunos excluidos com sucesso!\n";
}

void listaAlunos(Pessoa *pessoas[])
{
    if (Pessoa::TAM == 0)
    {
        cout << "Nenhuma pessoa cadastrada." << endl;
    }
    else
    {
        for (int i = 0; i < Pessoa::TAM; i++)
        {
            if (pessoas[i]->getTipo() == 1)
            {
                pessoas[i]->escrevePessoa();
            }
        }
    }
}

void listarAlunosAniversariantes(Pessoa *pessoas[], int mes)
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
void Aluno::gravar(FILE *arquivo)
{
    // Anotar o Tipo da Classe (1 == Aluno)
    int tipo = 1;
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

    unsigned long int matricula = getMatricula();
    fwrite(&matricula, sizeof(unsigned long int), 1, arquivo);
}

void Aluno::carregar(FILE *arquivo)
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

    unsigned long int matricula;
    fread(&matricula, sizeof(unsigned long int), 1, arquivo);
    setMatricula(matricula);
}