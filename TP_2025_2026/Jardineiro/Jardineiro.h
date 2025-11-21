//
// Created by Enrique Marques on 31/10/2025.
//

#ifndef TP_2025_2026_JARDINEIRO_H
#define TP_2025_2026_JARDINEIRO_H

#include "../Ferramentas/Ferramenta.h"
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Jardineiro {
    string posicao;
    int lin,col;
    bool dentroDoJardim;

    Ferramenta* ferramentas[3]; // array fixo

    int movimentosRestantes;
    int plantacoesRestantes;
    int colheitasRestantes;

public:
    Jardineiro();

    int getLinhas();
    int getColunas();

    void entra(const char& l, const char& c);
    void sai();
    bool estaNoJardim() const;
    string getPosicao() const;

    void mover(char direcao);
    void resetTurno();

    void planta();
    void colhe();

    bool podePlantar() const;
    bool podeColher() const;
    bool podeMover() const;

    void pega(int indice);
    void larga();

    void adicionarFerramenta(Ferramenta* f);
    Ferramenta* getFerramentaNaMao() const;
};

#endif //TP_2025_2026_JARDINEIRO_H
