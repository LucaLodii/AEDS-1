#ifndef MAIN_HPP
#define MAIN_HPP
#include <iostream>
#include <string>

using namespace std;

class myString
{
private: 
        string A;
        string B;

public:
    static int tamanhoIgual(string A, string B);
    static int tamanhoIgualRec(string A, string B);
};

#endif