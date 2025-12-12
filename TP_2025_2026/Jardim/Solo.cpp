//
// Created by Enrique Marques on 30/10/2025.
//

#include "Solo.h"
#include "Settings.h" // valores iniciais
#include <cstdlib>  //rand
#include <algorithm> // max

Solo::Solo(): planta(nullptr), ferramenta(nullptr) {

    // Inicialização aleatória conforme o enunciado
    // Água: entre 80 e 100
    int minAgua = Settings::Jardim::agua_min;
    int maxAgua = Settings::Jardim::agua_max;
    this->agua = minAgua + (rand() % (maxAgua - minAgua + 1));

    // Nutrientes: entre 40 e 50
    int minNutri = Settings::Jardim::nutrientes_min;
    int maxNutri = Settings::Jardim::nutrientes_max;
    this->nutrientes = minNutri + (rand() % (maxNutri - minNutri + 1));
}

int Solo::letraParaIndice(char letra) {
    letra = tolower(letra); // aceita maiúsculas
    if (letra < 'a' || letra > 'z')
        return -1; // inválido
    return letra - 'a';
}
// gestão recursos
int Solo::getAgua() const {
    return agua;
}

int Solo::getNutrientes() const {
    return nutrientes;
}

void Solo::adicionarAgua(int quantidade) {
    this->agua += quantidade;
    if (this->agua < 0) this->agua = 0;
}

void Solo::adicionarNutrientes(int quantidade) {
    this->nutrientes += quantidade;
    if (this->nutrientes < 0) this->nutrientes = 0;
}
void Solo::retirarAgua(int quantidade) {
    this->agua -= quantidade;
    if (this->agua < 0) this->agua = 0;
}

void Solo::retirarNutrientes(int quantidade) {
    this->nutrientes -= quantidade;
    if (this->nutrientes < 0) this->nutrientes = 0;
}

// --- Gestão de Planta ---

shared_ptr<Planta> Solo::getPlanta() const {
    return planta;
}

void Solo::setPlanta(shared_ptr<Planta> p) {
    this->planta = p;
}

void Solo::removerPlanta() {
    this->planta = nullptr; // O shared_ptr trata de libertar se for o último
}

bool Solo::temPlanta() const {
    return planta != nullptr;
}

// --- Gestão de Ferramenta ---

shared_ptr<Ferramenta> Solo::getFerramenta() const {
    return ferramenta;
}

void Solo::setFerramenta(shared_ptr<Ferramenta> f) {
    this->ferramenta = f;
}

void Solo::removerFerramenta() {
    this->ferramenta = nullptr;
}

bool Solo::temFerramenta() const {
    return ferramenta != nullptr;
}
