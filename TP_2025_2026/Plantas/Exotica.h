//
// Created by Enrique Marques on 01/11/2025.
//

#ifndef TP_2025_2026_EXOTICA_H
#define TP_2025_2026_EXOTICA_H

#include "Planta.h"

class Exotica : public Planta {
    int instantesCiclo;
public:
    Exotica(int linha, int coluna);
    ~Exotica() override = default;
    void avancaInstante(int& soloAgua, int& soloNutrientes) override;
};

#endif //TP_2025_2026_EXOTICA_H
