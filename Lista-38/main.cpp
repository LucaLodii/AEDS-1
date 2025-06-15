#include <iostream>
#include <string>
using namespace std;

const int _MAX = 10; // numero máximo de candidatos

class Candidato
{
private:
    string nome;
    double nota;

public:
    // Construtor
    Candidato(string nome, double nota)
    {
        this->nome = nome;
        this->nota = nota;
    }

    void setNome(string nome)
    {
        this->nome = nome;
    }

    string getNome()
    {
        return nome;
    }

    void setNota(double nota)
    {
        this->nota = nota;
    }

    double getNota()
    {
        return nota;
    }
};

// ======== Funções auxiliares (fora da classe) ========

int qtCandidatos()
{
    int n;
    do
    {
        cout << "Digite o numero de candidatos (max " << _MAX << "): ";
        cin >> n;
    } while (n < 1 || n > _MAX);
    return n;
}

void criarCandidatos(int n, Candidato *candidatos[])
{
    string nome;
    double nota;

    for (int i = 0; i < n; i++)
    {
        cout << "\nCandidato " << i + 1 << ":\n";

        cout << "Nome: ";
        fflush(stdin);
        getline(cin, nome);

        cout << "Nota: ";
        cin >> nota;

        candidatos[i] = new Candidato(nome, nota);
    }
}

double notaMedia(int n, Candidato *candidatos[])
{
    double soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += candidatos[i]->getNota();
    }
    return soma / n; // FALTAVA RETURN
}

void listarAcimaDaMedia(int n, Candidato *candidatos[], double media)
{
    cout << "\nCandidatos com nota acima da media (" << media << "):\n";
    for (int i = 0; i < n; i++)
    {
        if (candidatos[i]->getNota() > media)
        {
            cout << candidatos[i]->getNome() << " - " << candidatos[i]->getNota() << endl;
        }
    }
}

int main()
{
    Candidato *candidatos[_MAX];

    int n = qtCandidatos();
    criarCandidatos(n, candidatos);
    double media = notaMedia(n, candidatos);
    listarAcimaDaMedia(n, candidatos, media);

    for (int i = 0; i < n; i++)
    {
        delete candidatos[i];
    }

    return 0;
}
