//
// Created by Enrique Marques on 31/10/2025.
//

#include "Jardineiro.h"

Jardineiro::Jardineiro() :posicao("00"), dentroDoJardim(false), movimentosRestantes(0),plantacoesRestantes(0), colheitasRestantes(0), lin(-1), col(-1){

}

void Jardineiro::entra(const char& l, const char& c) {
    if(!dentroDoJardim){
        posicao = l + c;
        dentroDoJardim = true;
        lin = Solo::letraParaIndice(l);
        col  = Solo::letraParaIndice(c);
    }
}

void Jardineiro::sai() {
    if(dentroDoJardim){
        posicao = " ";
        dentroDoJardim = false;
        lin = -1;
        col = -1;
    }
}

bool Jardineiro::estaNoJardim() const {
    return dentroDoJardim;
}

int Jardineiro::getLinhas() {
    return lin;
}

int Jardineiro::getColunas() {
    return col;
}
