//
// Created by Enrique Marques on 31/10/2025.
//

#include "Jardineiro.h"
#include "Jardim/Solo.h"
#include "Utils/Settings.h"

Jardineiro::Jardineiro()
    :posicao(" "),
    dentroDoJardim(false),
    movimentosRestantes(0),
    plantacoesRestantes(0),
    colheitasRestantes(0),
    lin(-1),
    col(-1){
}

void Jardineiro::entra(const char& l, const char& c) {
    if(!dentroDoJardim){
        lin = Solo::letraParaIndice(l);
        col = Solo::letraParaIndice(c);

        posicao = "";
        posicao += l;
        posicao += c;

        dentroDoJardim = true;
        resetTurno();
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

int Jardineiro::getLinhas() const{
    return lin;
}

int Jardineiro::getColunas() const{
    return col;
}
string Jardineiro::getPosicao() const {
    return posicao;
}
void Jardineiro::setPosicao(int l, int c) {
    this->lin = l;
    this->col = c;
}
void Jardineiro::adicionarFerramenta(shared_ptr<Ferramenta> f) {
    if (f) {
        inventario.push_back(f);
    }
}
void Jardineiro::removerFerramenta(shared_ptr<Ferramenta> f) {
    for (auto it = inventario.begin(); it != inventario.end(); ) {
        if (*it == f) {
            it = inventario.erase(it);
        } else {
            ++it;
        }
    }
}
shared_ptr<Ferramenta> Jardineiro::getFerramentaNoIndice(int indice) {
    if (indice >= 0 && indice < inventario.size()) {
        return inventario[indice];
    }
    return nullptr;
}
int Jardineiro::getNumFerramentas() const {
    return inventario.size();
}
void Jardineiro::resetTurno() {
    movimentosRestantes = Settings::Jardineiro::max_movimentos;
    plantacoesRestantes = Settings::Jardineiro::max_plantacoes;
    colheitasRestantes = Settings::Jardineiro::max_colheitas;
}
bool Jardineiro::podeMover() const {
    return movimentosRestantes > 0;
}

void Jardineiro::mover(char direcao) {
    if (movimentosRestantes > 0) {
        movimentosRestantes--;
    }
}

bool Jardineiro::podePlantar() const {
    return plantacoesRestantes > 0;
}

void Jardineiro::planta() {
    if (plantacoesRestantes > 0) {
        plantacoesRestantes--;
    }
}

bool Jardineiro::podeColher() const {
    return colheitasRestantes > 0;
}

void Jardineiro::colhe() {
    if (colheitasRestantes > 0) {
        colheitasRestantes--;
    }
}

void Jardineiro::pega(int indice) {

}

void Jardineiro::larga() {

}
