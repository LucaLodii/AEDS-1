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
    setCPF(leiaCPF());
    cout << "\nData de nascimento: [DD MM AAAA]";
    int dia, mes, ano;
    cin >> dia >> mes >> ano;
    setNascimento(dia, mes, ano);
    cout << "\nMatricula: ";
    unsigned long int matricula;
    cin >> matricula;
    setMatricula(matricula);
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
                // Delete the object from memory first
                delete pessoas[i];
                
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
            // Delete the object from memory first
            delete pessoas[i];
            
            for (int j = i; j < Pessoa::TAM - 1; j++)
            {
                pessoas[j] = pessoas[j + 1]; // Faz o "shift"
            }
            Pessoa::TAM--;
            i--; // Stay at the same index since we shifted
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

bool Aluno::carregar(FILE *arquivo)
{
    int nomeLen;
    if (fread(&nomeLen, sizeof(int), 1, arquivo) != 1 || nomeLen <= 0 || nomeLen > 1000) return false;
    char *nomeBuf = new char[nomeLen + 1];
    if (fread(nomeBuf, sizeof(char), nomeLen, arquivo) != (size_t)nomeLen) { delete[] nomeBuf; return false; }
    nomeBuf[nomeLen] = '\0';
    setNome(nomeBuf);
    delete[] nomeBuf;

    int cpfLen;
    if (fread(&cpfLen, sizeof(int), 1, arquivo) != 1 || cpfLen <= 0 || cpfLen > 100) return false;
    char *cpfBuf = new char[cpfLen + 1];
    if (fread(cpfBuf, sizeof(char), cpfLen, arquivo) != (size_t)cpfLen) { delete[] cpfBuf; return false; }
    cpfBuf[cpfLen] = '\0';
    setCPF(cpfBuf);
    delete[] cpfBuf;

    int dia, mes, ano;
    if (fread(&dia, sizeof(int), 1, arquivo) != 1) return false;
    if (fread(&mes, sizeof(int), 1, arquivo) != 1) return false;
    if (fread(&ano, sizeof(int), 1, arquivo) != 1) return false;
    setNascimento(dia, mes, ano);

    unsigned long int matricula;
    if (fread(&matricula, sizeof(unsigned long int), 1, arquivo) != 1) return false;
    setMatricula(matricula);
    return true;
}