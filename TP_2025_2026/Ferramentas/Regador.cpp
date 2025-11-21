//
// Created by Enrique Marques on 01/11/2025.
//

#include "Regador.h"
Regador::Regador(int s, const string& p) : Ferramenta(s, p), capacidade(200) {}

string Regador::usar(Jardim &jardim) {
    return string();
}

char Regador::getSimbolo() const {
    return 0;
}

bool Regador::deveRemover() const {
    return false;
}
