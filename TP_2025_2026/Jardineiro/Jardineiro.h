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

    vector<shared_ptr<Ferramenta>> inventario;

    int movimentosRestantes;
    int plantacoesRestantes;
    int colheitasRestantes;

public:
    Jardineiro();

    int getLinhas() const;
    int getColunas() const;

    void entra(const char& l, const char& c);
    void sai();
    bool estaNoJardim() const;

    void setPosicao(int l, int c);
    string getPosicao() const;

    void adicionarFerramenta(shared_ptr<Ferramenta> f);
    void removerFerramenta(shared_ptr<Ferramenta> f);
    shared_ptr<Ferramenta> getFerramentaNoIndice(int indice);
    int getNumFerramentas() const;

    void resetTurno();

    bool podeMover() const;
    void mover(char direcao);

    void planta();
    void colhe();

    bool podePlantar() const;
    bool podeColher() const;

    void pega(int indice);
    void larga();
};

#endif //TP_2025_2026_JARDINEIRO_H
