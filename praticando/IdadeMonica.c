#include <stdio.h>


    int idadeM(){
        int idadeM;
        do{
            printf("\nDigite a idade de dona monica: ");
            scanf("%d",&idadeM);
        } while (idadeM <= 40 && idadeM >=110);
        return idadeM;
    }
    int idadeFilhos(int i, int A){
        int idadeF;
        do{
            printf("\nDigite a idade do %io filho: ",i);
            scanf("%d",&idadeF);
        } while (idadeF <= 1 && idadeF < A);
        return idadeF;
    }
    int idade3oFilho(int A, int B, int C){
        return A-B-C;
    }
    void resposta(int D){
        printf("\nA idade do 3o filho eh: %d",D);
    }
    int main(){
        int A = idadeM();
        int B = idadeFilhos(1, A);
        int C;
        do {
        C = idadeFilhos(2, A);
        } while (C == B);
        int D = idade3oFilho(A,B,C);
        resposta(D);
    }