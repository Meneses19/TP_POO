//
// Created by Enrique Marques on 01/11/2025.
//

#include "ErvaDaninha.h"
#include "../Utils/Settings.h"

ErvaDaninha::ErvaDaninha(int linha, int coluna)
        : Planta(
        "ErvaDaninha",
        linha,
        coluna,
        Settings::ErvaDaninha::inicial_nutrientes,
        Settings::ErvaDaninha::inicial_agua,
        "feia",
        true,
        'e'
),
          idade(0),
          instantesDesdeMultiplicacao(0)
{
}
shared_ptr<Planta> ErvaDaninha::duplicar(int l, int c) const {
    return make_shared<ErvaDaninha>(l, c);
}
bool ErvaDaninha::deveReproduzir() const {
    return (getNutrientes() > Settings::ErvaDaninha::multiplica_nutrientes_maior) &&
           (this->instantesDesdeMultiplicacao > Settings::ErvaDaninha::multiplica_instantes);
}
void ErvaDaninha::avancaInstante(int& soloAgua, int& soloNutrientes) {

    if (!isViva()) {
        return;
    }

    this->idade++;
    this->instantesDesdeMultiplicacao++;

    if (this->idade > Settings::ErvaDaninha::morre_instantes) {
        morre();
        setNutrientes(0);
        setAgua(0);
        return;
    }

    if (soloAgua >= Settings::ErvaDaninha::absorcao_agua) {
        soloAgua -= Settings::ErvaDaninha::absorcao_agua;
        addAgua(Settings::ErvaDaninha::absorcao_agua);
    }

    if (soloNutrientes >= Settings::ErvaDaninha::absorcao_nutrientes) {
        soloNutrientes -= Settings::ErvaDaninha::absorcao_nutrientes;
        addNutrientes(Settings::ErvaDaninha::absorcao_nutrientes);
    }

}
bool ErvaDaninha::podeMultiplicar() const {
    return (getNutrientes() > Settings::ErvaDaninha::multiplica_nutrientes_maior &&
            this->instantesDesdeMultiplicacao > Settings::ErvaDaninha::multiplica_instantes);
}

void ErvaDaninha::resetCooldownMultiplicacao() {
    this->instantesDesdeMultiplicacao = 0;
}
