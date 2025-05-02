#include <stdio.h>
#define _n 3
// AULA DE REVISAO SOBRE ITERAÇÃO E RECURSAO USANDO ARRAYS
// SE COMEÇA COM # SIGNIFICA QUE É UMA DIRETIVA
// DEFINE = TEMPO DE COMPILAÇÃO
// CONST = TEMPO DE EXECUÇÃO
// LEMBRAR Q EM "C" NAO PODE TER FUNCOES DE MESMO NOME (SOBRECARGA) MAS O "C++" PODE!
// faltou alguns exercicios!

int qtAcimaMediaRec(int idades[], int n, float MEDIA);

int maiorIdadeRec(int idades[], int n){
    int maior, m;
        if(n == 1) maior = idades[0];
        else {
                m = maiorIdadeRec(idades, n-1);
                if(idades[n-1] > m) maior = idades[n-1];
                else maior = m;
        }
    return maior;
}

int qtAcimaMediaRec2(int idades[], int n, float MEDIA){
    int qt2 = 0, maior = 0; //o lucio chamou só de qt
    if(n > 0){
        if(idades[n-1] > MEDIA) maior = 1;
        qt2 = maior + qtAcimaMediaRec(idades, n-1, MEDIA);
    }
    return qt2;
}

int qtAcimaMediaRec(int idades[], int n, float MEDIA){
    return qtAcimaMediaRec2(idades, n, MEDIA);    //nao precisaria mudar de nome em C++
}

int qtAcimaMedia(int idades[], int n){
    float MEDIA = mediaIdadesRec(idades, n);
    int qt = 0;
    for(int i = 0; i < n; i++){
        if(idades[i] > MEDIA){
            qt++;
        }
    }
    return qt;
}

int somaIdadesRec(int idades[], int n){
    int soma = 0;
    if(n > 0){
        soma = idades[n-1] + somaIdadesRec(idades, n-1);    //tem q entender o pq de -1
    }
    return soma;
}

float mediaIdadesRec(int idades[], int n)
{
    return somaIdadesRec(idades, n) / (float)n;
}

void listaPessoasRec(char *nomes[], int idades[], int n)
{
    if (n > 0)
    {
        listaPessoasRec(nomes, idades, n - 1);
        printf("\n%s,%i", nomes[n - 1], idades[n - 1]);    //tem q entender esse n-1
    }
}

void listaPessoasIdade(char *nomes[], int idades[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n%s", nomes[i]);
        printf("\n%i", idades[i]);
    }
}

void listaPessoas(char *nomes[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n%s", nomes[i]);
    }
}

int main()
{
    printf("\nVETORES");
    char *nomes[] = {"Luiz", "Bruno", "Luca"};

    int idades[] = {18, 19, 17};

    listaPessoasIdade(nomes, idades, _n);
    listaPessoasRec(nomes, idades, _n);

    listaPessoas(nomes, _n);
    listaPessoasRec(nomes, idades, _n);
    printf("\nMEDIA = %f", mediaIdadesRec(idades, _n));
    printf("\n%i Acima da media", qtAcimaMedia(idades, _n));
    printf("\n%i Acima da media", qtAcimaMediaRec(idades, _n, mediaIdadesRec(idades, _n)));
    printf("\nMaior idade: %i", maiorIdadeRec(idades, _n));

    return 0;
}