//
// Created by Enrique Marques on 01/11/2025.
//

#include "Adubo.h"

Adubo::Adubo(int s, const string &p) : Ferramenta(s, p) {

}

string Adubo::usar(Jardim &jardim) {
    return string();
}

char Adubo::getSimbolo() const {
    return 0;
}

bool Adubo::deveRemover() const {
    return false;
}
