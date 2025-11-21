//
// Created by Enrique Marques on 30/10/2025.
//

#include "Solo.h"

Solo::Solo(): agua(0),nutrientes(0),planta(nullptr), ferramenta(nullptr) {

}

Solo::Solo(const string &tipo): agua(0),nutrientes(0),planta(nullptr), ferramenta(nullptr) {

}

char Solo::getSimbolo() const {
    return Simbolo;
}

void Solo::setSimbolo(char c) {
    Simbolo = c;
}

int Solo::letraParaIndice(char letra) {
    letra = tolower(letra); // aceita maiúsculas
    if (letra < 'a' || letra > 'z')
        return -1; // inválido
    return letra - 'a';
}
