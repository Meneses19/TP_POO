//
// Created by Enrique Marques on 01/11/2025.
//

#include "TesouraDePoda.h"

TesouraDePoda::TesouraDePoda(int s, const string &p) : Ferramenta(s, p) {

}

string TesouraDePoda::usar(Jardim &jardim) {
    return string();
}

char TesouraDePoda::getSimbolo() const {
    return 0;
}

bool TesouraDePoda::deveRemover() const {
    return false;
}
