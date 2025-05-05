const int MAX_LIN = 2;
const int MAX_COL = 4;

void 

int main()
{
    float M1[MAX_LIN][MAX_COL];
    leMatriz(M1);
    float M2[MAX_LIN][MAX_COL];
    leMatriz(M2);
    printf(“\n\nEscrevendo a primeira Matriz :\n”);
    escreveMatriz(M1);
    printf(“\n\nEscrevendo a segunda Matriz :\n”);
    escreveMatriz(M2);
    if (iguais(M1, M2))
        printf(“\nMatrizes iguais !”);
    else
        printf(“\nMatrizes diferentes !”);
    return 0;
}