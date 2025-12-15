//
// Created by Enrique Marques on 28/10/2025.
//

#include "Planta.h"
#include <string>
#include <sstream>

using namespace std;

Planta::Planta(const string& tipo, int linha, int coluna, int nutrientes, int agua, const string& beleza, bool estado, char displayChar)
        : tipo(tipo),
          linha(linha),
          coluna(coluna),
          nutrientes(nutrientes),
          agua(agua),
          beleza(beleza),
          estado(estado),
          displayChar(displayChar)
{
}
string Planta::getDescricao() const {
    stringstream ss;
    ss << "[" << displayChar << "] " << tipo
       << " (" << (char)('a' + linha) << (char)('a' + coluna) << ")"
       << " | Saude(Agua/Nutri): " << agua << "/" << nutrientes
       << " | Beleza: " << beleza
       << " | Estado: " << (estado ? "Viva" : "Morta");
    return ss.str();
}
string Planta::getNome() const {
    return tipo;
}
string Planta::getTipo() const {
    return tipo;
}

int Planta::getLinha() const{
    return linha;
}

int Planta::getColuna() const {
    return coluna;
}

int Planta::getNutrientes() const {
    return nutrientes;
}

int Planta::getAgua() const {
    return agua;
}

string Planta::getBeleza() const {
    return beleza;
}

char Planta::getDisplayChar() const {
    return displayChar;
}


void Planta::setPosicao(int l, int c) {
    linha = l;
    coluna = c;
}

void Planta::addAgua(int quantidade) {
    this->agua += quantidade;
}

void Planta::addNutrientes(int quantidade) {
    this->nutrientes += quantidade;
}

void Planta::setAgua(int valor) {
    this->agua = valor;
}

void Planta::setNutrientes(int valor) {
    this->nutrientes = valor;
}

void Planta::morre() {
    this->estado = false;
}

bool Planta::isViva() const {
    return estado;
}
