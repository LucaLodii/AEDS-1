#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // era pra ser const mas fdc
int TAM = 0;

typedef struct 
{
    int dia;
    int mes;
    int ano;
}Data;


typedef struct
{
    char nome[50];
    Data nascimento;
} Pessoa;

// Protótipos das funções
void cadastrarPessoa(Pessoa pessoas[]);
void listarPessoas(Pessoa pessoas[]);
float idadeMedia(Pessoa pessoas[]);
void salvarDados(Pessoa pessoas[]);
void carregarDados(Pessoa pessoas[]);
int calcularIdade(Data nascimento);

int main()
{
    Pessoa pessoas[MAX];
    int opcao;
    do
    {
        printf("\nMenu de funcionalidades, escolha uma opcao: \n");
        printf("\n0 - Sair do Programa");
        printf("\n1 - Cadastar pessoa");
        printf("\n2 - Listar todas as pessoas cadastradas (nome e idade)");
        printf("\n3 - Informar a idade média da turma\n");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 0:
            printf("\nObrigado por usar este programa");
            break;
        case 1:
            printf("\nCadastar pessoa: ");
            cadastrarPessoa(pessoas);
            break;
        case 2:
            printf("\nListar todas as pessoas cadastradas (nome e idade): ");
                listarPessoas(pessoas);
            break;
        case 3:
            printf("\nInformar a idade media da turma: ");
                idadeMedia(pessoas);
            break;

        default:
            printf("\nOpcao invalida!\n");
            break;
        }
    } while (opcao != 0);
}

// Funções
void cadastrarPessoa(Pessoa pessoas[]) {
    if (TAM >= MAX) {
        printf("Limite máximo atingido!\n");
        return;
    }
    
    fflush(stdin);
    printf("\nNome: ");
    //scanf("%49s", pessoas[TAM].nome);
    fgets(pessoas[TAM].nome, sizeof(pessoas[TAM].nome), stdin);
    pessoas[TAM].nome[strcspn(pessoas[TAM].nome, "\n")] = '\0'; // pra n pular linha
    
    printf("Data de nascimento (DD MM AAAA): ");
    scanf("%d/%d/%d", 
          &pessoas[TAM].nascimento.dia, 
          &pessoas[TAM].nascimento.mes, 
          &pessoas[TAM].nascimento.ano);
    
    TAM++;
    printf("Cadastro realizado!\n");
}

void listarPessoas(Pessoa pessoas[]) {
    if (TAM == 0) {
        printf("Nenhuma pessoa cadastrada!\n");
        return;
    }
    
    printf("\nPessoas cadastradas:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%s - %02d/%02d/%d\n", 
               pessoas[i].nome,
               pessoas[i].nascimento.dia,
               pessoas[i].nascimento.mes,
               pessoas[i].nascimento.ano);
    }
}
float idadeMedia(Pessoa pessoas[]) {
    if (TAM == 0) {
        printf("Nenhuma pessoa cadastrada!\n");
        return 0.0f;
    }
    
    int soma = 0;
    for (int i = 0; i < TAM; i++) {
        soma += calcularIdade(pessoas[i].nascimento);
    }
    
    float media = (float)soma / TAM;
    printf("Idade media: %.1f anos\n", media);
    return media;
}
int calcularIdade(Data nascimento) { // essa parte foi gpt guentei nn
    //int idade = ANO_ATUAL - nascimento.ano;
    
    // Você pode adicionar aqui a lógica para verificar se já fez aniversário
    // Se quiser implementar, precisaria pedir o mês e dia atual ao usuário
    // ou manter ANO_ATUAL, MES_ATUAL e DIA_ATUAL como variáveis globais
    
    //return idade;
}

void salvarDados(Pessoa pessoas[]) {
    FILE *arquivoTAM = fopen("tamanho.dat", "wb");
    if (arquivoTAM) {
        fwrite(&TAM, sizeof(int), 1, arquivoTAM);
        fclose(arquivoTAM);
    }

    FILE *arquivoPessoas = fopen("pessoas.dat", "wb");
    if (arquivoPessoas) {
        fwrite(pessoas, sizeof(Pessoa), TAM, arquivoPessoas);
        fclose(arquivoPessoas);
    }
}
void carregarDados(Pessoa pessoas[]) {
    FILE *arquivoTAM = fopen("tamanho.dat", "rb");
    if (arquivoTAM) {
        fread(&TAM, sizeof(int), 1, arquivoTAM);
        fclose(arquivoTAM);
    }

    FILE *arquivoPessoas = fopen("pessoas.dat", "rb");
    if (arquivoPessoas) {
        fread(pessoas, sizeof(Pessoa), TAM, arquivoPessoas);
        fclose(arquivoPessoas);
    }
}