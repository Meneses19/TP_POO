//
// Created by Enrique Marques on 01/11/2025.
//

#ifndef TP_2025_2026_CACTO_H
#define TP_2025_2026_CACTO_H
#include "Planta.h"
class Cacto : public Planta {
private:
    int instantesAguaAlta;
    int instantesNutrientesBaixos;

public:
    // Construtor
    Cacto(int linha, int coluna);
    // Destrutor
    ~Cacto() override = default;
    shared_ptr<Planta> duplicar(int l, int c) const override;
    bool deveReproduzir() const override;
    void avancaInstante(int& soloAgua, int& soloNutrientes) override;
};
#endif //TP_2025_2026_CACTO_H
