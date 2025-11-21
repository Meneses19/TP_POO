//
// Created by Enrique Marques on 01/11/2025.
//

#ifndef TP_2025_2026_REGADOR_H
#define TP_2025_2026_REGADOR_H

#include "Ferramenta.h"
class Jardim;

class Regador : public Ferramenta {
    int capacidade;

public:
    Regador(int s, const std::string& p);
    string usar(Jardim& jardim) override;
    char getSimbolo() const override;
    bool deveRemover() const override;
};
#endif //TP_2025_2026_REGADOR_H
