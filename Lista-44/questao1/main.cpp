#include "main.hpp"
#include <iostream>
#include <string>

// g++ questao1/main.cpp -o q1

using namespace std;

int myString::tamanhoIgual(string A, string B)
{
    int count = 0;
    int minLength = min(A.length(), B.length());

    for (int i = 0; i < minLength; ++i)
    {
        if (A[i] == B[i])
        {
            count++;
        }
    }
    return count;
}

int rec2(string A, string B, int i, int minLength)
{
    if (i >= minLength)
        return 0;

    if (A[i] == B[i])
        return 1 + rec2(A, B, i + 1, minLength);

    return rec2(A, B, i + 1, minLength);
}

int myString::tamanhoIgualRec(string A, string B)
{
    int minLength = min(A.length(), B.length());
    return rec2(A, B, 0, minLength);
}

int main()
{
    cout << "\nDigite as duas strings : ";
    string A, B;
    cin >> A >> B;
    cout << "\nCaracteres iguais desde o inicio(iterativo)" << myString::tamanhoIgual(A, B);
    cout << "\nCaracteres iguais desde o inicio(recursivo)" << myString::tamanhoIgualRec(A, B);

    return 0;
}