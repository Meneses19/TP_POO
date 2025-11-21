//
// Created by Enrique Marques on 01/11/2025.
//

#include "Cacto.h"
#include "../Utils/Settings.h"

// --- Construtor ---
Cacto::Cacto(int linha, int coluna)
        : Planta( "Cacto",
                  linha,
                  coluna,
                  0,
                  0,
                  "neutra",
                  true,
                  'c'),
          instantesAguaAlta(0),
          instantesNutrientesBaixos(0)
{
}

void Cacto::avancaInstante(int& soloAgua, int& soloNutrientes) {

    if (!isViva()) {
        return;
    }
    int aguaAbsorvida = (soloAgua * Settings::Cacto::absorcao_agua_percentagem) / 100;
    soloAgua -= aguaAbsorvida;
    addAgua(aguaAbsorvida);

    int nutrientesAbsorvidos = 0;
    if (soloNutrientes >= Settings::Cacto::absorcao_nutrientes) {
        nutrientesAbsorvidos = Settings::Cacto::absorcao_nutrientes;
    } else {
        nutrientesAbsorvidos = soloNutrientes;
    }
    soloNutrientes -= nutrientesAbsorvidos;

    addNutrientes(nutrientesAbsorvidos);


    if (soloAgua > Settings::Cacto::morre_agua_solo_maior) {
        this->instantesAguaAlta++;
    } else {
        this->instantesAguaAlta = 0;
    }
    if (soloNutrientes < Settings::Cacto::morre_nutrientes_solo_menor) {
        this->instantesNutrientesBaixos++;
    } else {
        this->instantesNutrientesBaixos = 0;
    }

    if (this->instantesAguaAlta > Settings::Cacto::morre_agua_solo_instantes ||
        this->instantesNutrientesBaixos > Settings::Cacto::morre_nutrientes_solo_instantes)
    {
        morre();

        soloNutrientes += getNutrientes();

        setNutrientes(0);

        setAgua(0);
    }
}
