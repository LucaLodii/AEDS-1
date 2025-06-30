/*H******************************************************************************
* FILENAME :    aluno.cpp                     DESIGN REF:     TP

* DESCRIPTION :
*       Implementação da classe Aluno que herda da classe abstrata Pessoa.
*       Contém todas as implementações das funções declaradas no header aluno.hpp,
*       incluindo gerenciamento de matrícula, persistência em arquivo e
*       operações específicas para alunos.
*
* PUBLIC FUNCTIONS :
*       - Implementação da classe Aluno com herança de Pessoa
*       - Implementação de funções de matrícula (setMatricula, getMatricula)
*       - Implementação de funções de identificação (getTipo)
*       - Implementação de funções de entrada/saída (leiaPessoa, escrevePessoa)
*       - Implementação de funções de persistência (gravar, carregar)
*       - Implementação de funções de pesquisa (pesquisaAlunoNome, pesquisaAlunoCPF)
*       - Implementação de funções de manipulação (deletaAluno, apagarTodosAlunos)
*
* NOTES :
*       Implementação robusta com gerenciamento adequado de memória e
*       persistência em arquivos binários. Inclui validação de dados e
*       tratamento de erros. Todas as funções seguem o padrão de um
*       único retorno sem breaks.
*
*       Parte do Sistema de Registro de Pessoas para o projeto final de AEDs.
*
*       Leonardo Stuart de A. Ramalho, 2025. All rights reserved.
*
* AUTHOR    : Leonardo Stuart de A. Ramalho                     START DATE : 24 May 25
*
* CHANGES :
*
* REF NO  VERSION DATE      WHO  DETAIL
* ------- ------- --------- ---- -------------------------------------------
* 001     1.0     16May25   LL   Criacao inicial do arquivo aluno.cpp.
* 002     2.0     30Jun06   LL   Implementação de funcionalidades específicas
*
*H*/

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
    cout << "\nMatricula: " << getMatricula() << endl;
}

void pesquisaAlunoCPF(Pessoa *pessoas[])
{
    string supostoCPF;
    cout << "\nDigite o CPF a ser encontrado (000.000.000-00): ";
    getline(cin, supostoCPF);

    int encontradas = 0;
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getTipo() == 1)
        {
            if (pessoas[i]->getCPF() == supostoCPF)
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
    bool apagou = false;
    cout << "\nCPF para excluir (000.000.000-00): ";
    getline(cin, cpf);

    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getTipo() == 1)
        {
            if (pessoas[i]->getCPF() == cpf)
            {
                // Apaga o objeto da memoria primeiro
                delete pessoas[i];
                
                for (int j = i; j < Pessoa::TAM - 1; j++)
                {
                    pessoas[j] = pessoas[j + 1]; // Faz o "shift"
                }
                Pessoa::TAM--;
                cout << "Pessoa excluida com sucesso!\n";
                apagou = true;
            }
        }
    }
    
    if (!apagou)
    {
        cout << "CPF não encontrado.\n";
    }
    
    return apagou;
}

void apagarTodosAlunos(Pessoa *pessoas[])
{
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getTipo() == 1)
        {
            // Apaga o objeto da memoria primeiro
            delete pessoas[i];
            
            for (int j = i; j < Pessoa::TAM - 1; j++)
            {
                pessoas[j] = pessoas[j + 1]; // Faz o "shift"
            }
            Pessoa::TAM--;
            i--; // Continua no mesmo indice apos o shift foi feito
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
        if (pessoas[i]->getTipo() == 1 && mes == mesNiver)
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
    bool carregou = true;
    
    if (fread(&nomeLen, sizeof(int), 1, arquivo) != 1 || nomeLen <= 0 || nomeLen > 1000) 
    {
        carregou = false;
    }
    
    if (carregou)
    {
        char *nomeBuf = new char[nomeLen + 1];
        if (fread(nomeBuf, sizeof(char), nomeLen, arquivo) != (size_t)nomeLen) 
        { 
            delete[] nomeBuf; 
            carregou = false; 
        }
        else
        {
            nomeBuf[nomeLen] = '\0';
            setNome(nomeBuf);
            delete[] nomeBuf;
        }
    }

    int cpfLen;
    if (carregou && (fread(&cpfLen, sizeof(int), 1, arquivo) != 1 || cpfLen <= 0 || cpfLen > 100))
    {
        carregou = false;
    }
    
    if (carregou)
    {
        char *cpfBuf = new char[cpfLen + 1];
        if (fread(cpfBuf, sizeof(char), cpfLen, arquivo) != (size_t)cpfLen) 
        { 
            delete[] cpfBuf; 
            carregou = false; 
        }
        else
        {
            cpfBuf[cpfLen] = '\0';
            setCPF(cpfBuf);
            delete[] cpfBuf;
        }
    }

    int dia, mes, ano;
    if (carregou && fread(&dia, sizeof(int), 1, arquivo) != 1)
    {
        carregou = false;
    }
    if (carregou && fread(&mes, sizeof(int), 1, arquivo) != 1)
    {
        carregou = false;
    }
    if (carregou && fread(&ano, sizeof(int), 1, arquivo) != 1)
    {
        carregou = false;
    }
    
    if (carregou)
    {
        setNascimento(dia, mes, ano);
    }

    unsigned long int matricula;
    if (carregou && fread(&matricula, sizeof(unsigned long int), 1, arquivo) != 1)
    {
        carregou = false;
    }
    
    if (carregou)
    {
        setMatricula(matricula);
    }
    
    return carregou;
}