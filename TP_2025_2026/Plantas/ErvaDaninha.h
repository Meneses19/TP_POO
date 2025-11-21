//
// Created by Enrique Marques on 01/11/2025.
//

#ifndef TP_2025_2026_ERVADANINHA_H
#define TP_2025_2026_ERVADANINHA_H
#include "Planta.h"

class ErvaDaninha : public Planta {
private:
    int idade;
    int instantesDesdeMultiplicacao;

public:
    ErvaDaninha(int linha, int coluna);

    ~ErvaDaninha() override = default;

    void avancaInstante(int& soloAgua, int& soloNutrientes) override;



    // Verifica se a Erva Daninha tem condições para se multiplicar.
    // @return true se nutrientes > 30 e cooldown > 5

    bool podeMultiplicar() const;


    // Reinicia o cooldown de multiplicação.
    // Chamado pelo Jardim DEPOIS de criar a nova planta.
    void resetCooldownMultiplicacao();
};
#endif //TP_2025_2026_ERVADANINHA_H
