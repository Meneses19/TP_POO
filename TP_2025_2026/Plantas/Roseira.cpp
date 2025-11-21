//
// Created by Enrique Marques on 01/11/2025.
//

#include "Roseira.h"
#include "../Utils/Settings.h"

// --- Construtor ---
Roseira::Roseira(int linha, int coluna)
        : Planta(
        "Roseira",
        linha,
        coluna,
        Settings::Roseira::inicial_nutrientes,
        Settings::Roseira::inicial_agua,
        "bonita",
        true,
        'r'
)
{
}

void Roseira::avancaInstante(int& soloAgua, int& soloNutrientes) {

    if (!isViva()) {
        return;
    }

    addAgua(-Settings::Roseira::perda_agua);
    addNutrientes(-Settings::Roseira::perda_nutrientes);

    int aguaAbsorvida = 0;
    if (soloAgua >= Settings::Roseira::absorcao_agua) {
        aguaAbsorvida = Settings::Roseira::absorcao_agua;
    } else {
        aguaAbsorvida = soloAgua;
    }
    soloAgua -= aguaAbsorvida;
    addAgua(aguaAbsorvida);

    int nutrientesAbsorvidos = 0;
    if (soloNutrientes >= Settings::Roseira::absorcao_nutrientes) {
        nutrientesAbsorvidos = Settings::Roseira::absorcao_nutrientes;
    } else {
        nutrientesAbsorvidos = soloNutrientes;
    }
    soloNutrientes -= nutrientesAbsorvidos;
    addNutrientes(nutrientesAbsorvidos);

    int nutrientesAtuais = getNutrientes();
    int aguaAtual = getAgua();
    bool deveMorrer = false;

    if (aguaAtual < Settings::Roseira::morre_agua_menor) {
        deveMorrer = true;
    }
    else if (nutrientesAtuais < Settings::Roseira::morre_nutrientes_menor) {
        deveMorrer = true;
    }
    else if (nutrientesAtuais > Settings::Roseira::morre_nutrientes_maior) {
        deveMorrer = true;
    }
    if (deveMorrer) {
        morre();
        soloNutrientes += nutrientesAtuais / 2;
        soloAgua += aguaAtual / 2;

        setNutrientes(0);
        setAgua(0);
    }
}
