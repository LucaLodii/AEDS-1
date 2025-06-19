#include "../FigGeo/figGeo.h"
#include <iostream>

using namespace std;

FigGeo::FigGeo() {
    cor = "Sem cor";
}

FigGeo::FigGeo(string cor) {
    this->cor = cor;
}

FigGeo::~FigGeo() {
    // destrutor virtual
}

void FigGeo::setCor(string cor) {
    this->cor = cor;
}

string FigGeo::getCor() {
    return cor;
}

void FigGeo::leia() {
    cout << "Digite a cor da figura: ";
    cin >> cor;
}

void FigGeo::escreva() {
    cout << "Cor: " << cor << endl;
}
