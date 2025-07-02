#include <iostream>
#include <string>

bool buscaLetraIterativa(std::string texto, char letraChave) {
    for (int i = 0; i < texto.length(); ++i) {
        if (texto[i] == letraChave) {
            return true;
        }
    }
    return false;
}

bool buscaLetraRecursivaAux(std::string texto, char letraChave, int indice) {
    if (indice >= texto.length()) {
        return false;
    }
    if (texto[indice] == letraChave) {
        return true;
    }
    return buscaLetraRecursivaAux(texto, letraChave, indice + 1);
}

bool buscaLetraRecursiva(std::string texto, char letraChave) {
    return buscaLetraRecursivaAux(texto, letraChave, 0);
}