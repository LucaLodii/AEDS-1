#include <stdio.h>  //IDEIA DE ATIVIDAE, PEGUE O 1o VETOR E COPIE NO 2o

int listaIdades(int idades[], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", idades[i]);
    }
    return 0;
}

int ordena(int idades[], int n) {
    for (int j = 0; j < n-1; j++) {
        int pos_maior = 0; // Resetado a cada iteração
        
        for (int i = 1; i < n-j; i++) { // n-j substitui z
            if (idades[i] > idades[pos_maior]) {
                pos_maior = i;
            }
        }
        
        // Troca com a última posição não ordenada
        int temp = idades[(n-1)-j];
        idades[(n-1)-j] = idades[pos_maior];
        idades[pos_maior] = temp;
    }
    return n;
}

int somaIdades(int idades[], int n)
{
    int soma = idades[0];
    for (int i = 1; i < n; i++)
    {
        soma += idades[i];
    }
    return soma;
}

float mediaIdades(int idades[], int n)
{
    return somaIdades(idades, n) / (float)n;
}

void listaPessoas(int idades[], char *nomes[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNome: %s", nomes[i]);
        printf(", idade: %i", idades[i]);
    }
}

int main()
{
    printf("\nVETORES\n");

    int idades[] = {18, 20, 19, 17};
    char *nomes[] = {"Tiago","Eduardo" , "Leo", "Luca"};
    int n = (sizeof(idades) / sizeof(int));

    listaPessoas(idades, nomes, n);

    printf("\nA media das idades = %.2f", mediaIdades(idades, n));

    ordena(idades, n);

    listaIdades(idades, n);

    return 0;
}