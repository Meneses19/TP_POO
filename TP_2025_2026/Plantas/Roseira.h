//
// Created by Enrique Marques on 01/11/2025.
//

#ifndef TP_2025_2026_ROSEIRA_H
#define TP_2025_2026_ROSEIRA_H
#include "Planta.h"

class Roseira : public Planta {
public:
    // Construtor: Só precisa da posição
    Roseira(int linha, int coluna);

    // Destrutor (boa prática)
    ~Roseira() override = default;

    // Implementação do "contrato" virtual de Planta
    void avancaInstante(int& soloAgua, int& soloNutrientes) override;
};

#endif //TP_2025_2026_ROSEIRA_H
