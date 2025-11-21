//
// Created by Enrique Marques on 01/11/2025.
//

#ifndef TP_2025_2026_ADUBO_H
#define TP_2025_2026_ADUBO_H

#include "Ferramenta.h"

class Adubo : public Ferramenta {
    int quantidade;

public:
    Adubo(int s, const string& p);
    string usar(Jardim& jardim) override;
    char getSimbolo() const override;
    bool deveRemover() const override;
};
#endif //TP_2025_2026_ADUBO_H
