//
// Created by Enrique Marques on 01/11/2025.
//

#include "Exotica.h"
#include "../Utils/Settings.h"

// --- Construtor ---
Exotica::Exotica(int linha, int coluna)
        : Planta(
        "Exotica",
        linha,
        coluna,
        20,
        50,
        "bonita",
        true,
        'x'
),
          instantesCiclo(0)
{
}
shared_ptr<Planta> Exotica::duplicar(int l, int c) const {
    return make_shared<Exotica>(l, c);
}
bool Exotica::deveReproduzir() const {
    return false; // Exóticas não se reproduzem sozinhas, exeplo
}
// --- Comportamento a cada Instante ---
void Exotica::avancaInstante(int& soloAgua, int& soloNutrientes) {

    if (!isViva()) {
        return;
    }
    this->instantesCiclo++;

    int aguaAbsorvida = 0;
    if (soloAgua >= 15) {
        aguaAbsorvida = 15;
    } else {
        aguaAbsorvida = soloAgua;
    }
    soloAgua -= aguaAbsorvida;
    addAgua(aguaAbsorvida);

    if (soloNutrientes >= 1) {
        soloNutrientes -= 1;
        addNutrientes(1);
    }

    if (getAgua() < 1) {
        morre();
        // Ao morrer, devolve os nutrientes que acumulou
        soloNutrientes += getNutrientes();
        setNutrientes(0);
        return;
    }

    if (this->instantesCiclo >= 5) {
        // Se tiver pelo menos 20 de água interna
        if (getAgua() >= 20) {
            // Converte 20 de água interna em 10 nutrientes PARA O SOLO
            addAgua(-20); // Consome a sua própria água
            soloNutrientes += 10; // Adiciona nutrientes ao solo
        }
        this->instantesCiclo = 0; // Reinicia o ciclo
    }
}
