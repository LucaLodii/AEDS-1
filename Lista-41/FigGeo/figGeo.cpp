#include "figGeo/figGeo.h"

using namespace std;

FigGeo::FigGeo() {
    cor = "Sem cor";
}

FigGeo::~FigGeo()
{

}

void FigGeo::setCor(string cor)
{
    this->cor = cor;
}

string getCor(string cor)
{
    return cor;
}