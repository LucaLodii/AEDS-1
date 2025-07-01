/*H**************************************************************************************************************
*FILENAME  :    professor.cpp                   DESIGN REF:      TPF
*
* DESCRIPTION :
*       Implementação da classe 'Professor', que herda de 'Pessoa', e suas funcionalidades
*       específicas. Este arquivo contém a lógica para a criação, manipulação (getters/setters),
*       leitura e exibição de dados de professores, além de funções para pesquisa, exclusão,
*       listagem e gerenciamento de registros de professores no sistema.
*       Inclui também as rotinas para persistência de dados de Professor em arquivo binário.
*
* PUBLIC FUNCTIONS :
*       Professor::Professor(string especializacao)
*       void Professor::setEspecializacao(string especializacao)
*       string Professor::getEspecializacao()
*       void Professor::leiaPessoa() // Sobrescrito
*       void Professor::escrevePessoa() // Sobrescrito
*       void Professor::gravar(FILE *arquivo)
*       bool Professor::carregar(FILE *arquivo)
*       void pesquisaProfessorNome(Pessoa *pessoas[])
*       void pesquisaProfessorCPF(Pessoa *pessoas[])
*       bool deletaProfessor(Pessoa *pessoas[])
*       void apagarTodosProfessores(Pessoa *pessoas[])
*       void listaProfessores(Pessoa *pessoas[])
*       void listarProfessoresAniversariantes(Pessoa *pessoas[], int mes)
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
*001       1.0     16May25   LL   Criacao inicial do arquivo professor.cpp.
*002       1.1     30Jun25   LL   Implementacao de metodos da classe Professor e funcoes de gerenciamento.
*
*******************************************************************************/

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
    setCPF(leiaCPF());
    cout << "\nData de nascimento: [DD MM AAAA]";
    int dia, mes, ano;
    cin >> dia >> mes >> ano;
    setNascimento(dia, mes, ano);
    cout << "\nEspecializacao: ";
    string especializacao;
    cin >> especializacao;
    setEspecializacao(especializacao);
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
    cout << "\nEspecializacao: " << getEspecializacao() << endl;
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
            if (pessoas[i]->getCPF() == supostoCPF)
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
    bool apagou = false;

    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getTipo() == 2)
        {
            if (pessoas[i]->getCPF() == cpf)
            {
                // Apaga o objeto da memória primeiro
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

void apagarTodosProfessores(Pessoa *pessoas[])
{
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i]->getTipo() == 2)
        {
            // Apaga o objeto da memória primeiro
            delete pessoas[i];
            
            for (int j = i; j < Pessoa::TAM - 1; j++)
            {
                pessoas[j] = pessoas[j + 1]; // Faz o "shift"
            }
            Pessoa::TAM--;
            i--; // Continua no mesmo indice apos o shift foi feito
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

bool Professor::carregar(FILE *arquivo)
{
    bool carregou = true;
    int nomeLen;
    
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
    
    int especializacaoLen;
    // Leitura e validação do tamanho da especialização
    if (carregou && (fread(&especializacaoLen, sizeof(int), 1, arquivo) != 1 || especializacaoLen <= 0 || especializacaoLen > 1000))
    {
        carregou = false;
    }
    
    if (carregou)
    {
        char *espBuf = new char[especializacaoLen + 1];
        // Leitura da especialização
        if (fread(espBuf, sizeof(char), especializacaoLen, arquivo) != (size_t)especializacaoLen) 
        { 
            delete[] espBuf; 
            carregou = false; 
        }
        else
        {
            espBuf[especializacaoLen] = '\0';
            setEspecializacao(espBuf);
            delete[] espBuf;
        }
    }
    
    return carregou;
}