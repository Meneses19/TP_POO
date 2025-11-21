//
// Created by Enrique Marques on 31/10/2025.
//

#include "Ferramenta.h"

Ferramenta::Ferramenta(int s, const string& p) : numeroSerie(s), posicao(p) {}
Ferramenta::~Ferramenta() {}

std::string Ferramenta::getPosicao() const { return posicao; }
void Ferramenta::setPosicao(const std::string& novaPos) { posicao = novaPos; }
int Ferramenta::getSerie() const { return numeroSerie; }
