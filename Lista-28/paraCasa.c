// ESTE PARA CASA SO TEM UMA QUESTAO E VARIAS FUNCOES!!!
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

char questao1(char*, int[]);
void questao2(char*, char*, char*);
void questao3Iterativo(char*, char*);
int questao3Recursivo(char*, char*);
int tamanhoString(char*, int);
void questao4(char*, char*);
void questao4Rec(char*, int, int ,int, char*);

int main(){
    int inteiros[5] = {0, 0, 0, 0, 0};
    char string[] = "Ola, Mundo!";

    questao1(string, inteiros);   //questao pede para contar a quatidade vogais na string

    char string1[] = "Ola, Lucio ";              // a string tem 12 bytes (tamanho) contando com o \0, mas nao precisa contar, vou declarar a 3 como 50 e FODASSE
    char string2[] = "Eu nao aguento mais!";    
    char string3[100] = {0};
    questao2(string1, string2, string3);         // concatenar(jutar) a string 1 e 2 na 3

    questao3Iterativo(string1, string2);
    questao3Recursivo(string1, string2);

    char string4[] = "ROMA";
    char inversa[50];
    questao4(string4, inversa);
    printf("\nROMA invertido = ");
    questao4Rec(string4, 0, strlen(string4), strlen(string4), inversa);
}

char questao1(char* string, int inteiros[]){
    int i = 0;
    char vogais[5] = {'a','e','i','o','u'};
    for (int i = 0; string[i] != '\0'; i++){
        for (int j = 0; j < 5; j++){
            if (tolower(string[i]) == vogais[j]) {
                inteiros[j]++;
            }
        }
    }
    for(int k = 0; k < 5; k++){
        printf("\nnumero de %c = %i",vogais[k],inteiros[k]);
    }
    return 0;
}

void questao2(char* string1, char* string2, char* string3){
    //if(strlen(string3) >= strlen(string1) + strlen(string2)){ // nao consegui fazer o if funfar
        int i = 0;
        while(string1[i] != '\0'){
            string3[i] = string1[i];
            i++;
        }
    
        int j = 0;
        while(string2[j] != '\0'){
            string3[i] = string2[j];
            i++, j++;
        }
        string3[i] = '\0';
        
        printf("\n");

        for(int k = 0; k < i; k++){
            printf("%c", string3[k]);
        }
    //}
}

void questao3Iterativo(char* string1, char* string2){
    int i = 0, j = 0, count1 = 0, count2 = 0;
    while (string1[i] != '\0'){
        count1++;
        i++;
    }
    while (string2[j] != '\0'){
        count2++;
        j++;
    }
    if(count1 != count2) printf("\nA string 1 e 2 NAO possuem o mesmo tamanho");
    else printf("\nA string 1 e 2 possuem o mesmo tamanho");
}

int questao3Recursivo(char* string1, char* string2){

    if(tamanhoString(string1, 0) != tamanhoString(string2, 0)) printf("\nA string 1 e 2 NAO possuem o mesmo tamanho");
    else printf("\nA string 1 e 2 possuem o mesmo tamanho");
}

int tamanhoString(char* string, int tamanho){
    if (string[tamanho] != '\0'){
        return tamanhoString(string, tamanho + 1);
    }
    return tamanho;
}

void questao4(char* string4, char* inversa){
    printf("\nROMA invertido = ");
    int tam = strlen(string4);
    int j = tam;
    for(int i = 0; i < tam; i++,j--){
        inversa[i] = string4[j-1];
        printf("%c",inversa[i]);
    }
    printf("\n");
}

void questao4Rec(char* string4, int i, int j, int tam, char* inversa){
    if(i < tam){
        inversa[i] = string4[j-1];
        printf("%c",inversa[i]);
        questao4Rec(string4,i+1, j-1,tam,inversa);
    }
}