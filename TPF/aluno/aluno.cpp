/*H**************************************************************************************************************
*FILENAME  :    aluno.cpp                       DESIGN REF:      TPF
*
* DESCRIPTION :
*       Implementação da classe 'Aluno', que herda de 'Pessoa', e suas funcionalidades
*       específicas. Este arquivo contém a lógica para a criação, manipulação (getters/setters),
*       leitura e exibição de dados de alunos, além de funções para pesquisa, exclusão,
*       listagem e gerenciamento de registros de alunos no sistema.
*       Inclui também as rotinas para persistência de dados de Aluno em arquivo binário.
*
* PUBLIC FUNCTIONS :
*       Aluno::Aluno(unsigned long int matricula)
*       void Aluno::setMatricula(unsigned long int matricula)
*       unsigned long int Aluno::getMatricula()
*       void Aluno::leiaPessoa() // Sobrescrito
*       void Aluno::escrevePessoa() // Sobrescrito
*       void Aluno::gravar(FILE *arquivo)
*       bool Aluno::carregar(FILE *arquivo)
*       void pesquisaAlunoNome(Pessoa *pessoas[])
*       void pesquisaAlunoCPF(Pessoa *pessoas[])
*       bool deletaAluno(Pessoa *pessoas[])
*       void apagarTodosAlunos(Pessoa *pessoas[])
*       void listaAlunos(Pessoa *pessoas[])
*       void listarAlunosAniversariantes(Pessoa *pessoas[], int mes)
*
* NOTES :
*       Parte do Sistema de Registro de Pessoas para o projeto final de AEDs.
*
* COPYRIGHT : Luca L. 2025, 2025. All rights reserved.
*
* AUTHOR    : Luca L.                     START DATE : 16 May 25
*
* CHANGES :
*
* REF NO  VERSION   DATE      WHO          DETAIL
*------- ------- --------- ---- -------------------------------------------
*001       1.0     16May25   LL   Criacao inicial do arquivo aluno.cpp.
*002       1.1     30Jun25   LL   Implementacao de metodos da classe Aluno e funcoes de gerenciamento.
*
*******************************************************************************/

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

// Sobrescreve leiaPessoa para incluir dados específicos de Aluno
void Aluno::leiaPessoa()
{
    string nome;
    cout << "\nNome: ";
    getline(cin, nome);
    setNome(nome); // Chama método da classe base Pessoa

    cout << "\nCPF: ";
    setCPF(leiaCPF()); // Assumindo leiaCPF() é uma função auxiliar
    cout << "\nData de nascimento: [DD MM AAAA]";
    int dia, mes, ano;
    cin >> dia >> mes >> ano;
    setNascimento(dia, mes, ano); // Chama método da classe base Pessoa
    cout << "\nMatricula: ";
    unsigned long int matricula;
    cin >> matricula;
    setMatricula(matricula);
}

// Pesquisa e exibe alunos por nome no array polimórfico de Pessoas
void pesquisaAlunoNome(Pessoa *pessoas[])
{
    string supostoNome;
    cout << "\nDigite o nome a ser encontrado: ";
    getline(cin, supostoNome);

    int encontradas = 0;
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getTipo() == 1) // Filtra por tipo Aluno (assumindo 1 é o tipo para Aluno)
        {
            if (pessoas[i]->getNome() == supostoNome)
            {
                pessoas[i]->escrevePessoa(); // Polimorfismo: chama escrevePessoa de Aluno
                encontradas++;
            }
        }
    }

    if (encontradas == 0)
    {
        cout << "Nenhum aluno encontrado com o nome '" << supostoNome << "'.\n";
    }
}

// Sobrescreve escrevePessoa para exibir detalhes de Aluno
void Aluno::escrevePessoa()
{
    cout << "\nNome: " << getNome();
    cout << "\nData de Nascimento: ";
    Data nascimento = getNascimento();
    nascimento.escreveData();
    cout << "\nCPF: " << getCPF();
    cout << "\nMatricula: " << getMatricula() << endl;
}

// Pesquisa e exibe alunos por CPF no array polimórfico de Pessoas
void pesquisaAlunoCPF(Pessoa *pessoas[])
{
    string supostoCPF;
    cout << "\nDigite o CPF a ser encontrado (000.000.000-00): ";
    getline(cin, supostoCPF);

    int encontradas = 0;
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getTipo() == 1) // Filtra por tipo Aluno
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
    
    // Leitura e validação do tamanho do nome
    if (fread(&nomeLen, sizeof(int), 1, arquivo) != 1 || nomeLen <= 0 || nomeLen > 1000) 
    {
        carregou = false;
    }
    
    if (carregou)
    {
        char *nomeBuf = new char[nomeLen + 1];
        // Leitura do nome
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
    // Leitura e validação do tamanho do CPF
    if (carregou && (fread(&cpfLen, sizeof(int), 1, arquivo) != 1 || cpfLen <= 0 || cpfLen > 100))
    {
        carregou = false;
    }
    
    if (carregou)
    {
        char *cpfBuf = new char[cpfLen + 1];
        // Leitura do CPF
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
    // Leitura de dia, mês e ano
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
    // Leitura da matrícula
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