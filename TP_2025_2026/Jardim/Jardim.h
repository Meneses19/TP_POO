//
// Created by Enrique Marques on 29/10/2025.
//

#ifndef TP_2025_2026_JARDIM_H
#define TP_2025_2026_JARDIM_H
#include "Solo.h"
#include "../Jardineiro/Jardineiro.h"
#include "../Plantas/Planta.h"
#include "../Ferramentas/Ferramenta.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Jardim {
    Solo** grelha;
    int linhas;
    int colunas;

    vector<shared_ptr<Planta>> plantas;
    vector<shared_ptr<Ferramenta>> ferramentas;
    Jardineiro jardineiro;

public:
    Jardim();
    Jardim(int linhas, int colunas);
    ~Jardim();

    void Criargrelha(int l, int c);
    Solo& getSolo(int linha, int coluna);
    bool posicaoValida(char& linha, char& coluna);

    void adicionarPlanta(shared_ptr<Planta> p);
    void removerPlantaNaPosicao(const string& pos);
    shared_ptr<Planta> getPlantaNaPosicao(const string& pos) const;

    void adicionarFerramenta(shared_ptr<Ferramenta> f);
    Jardineiro& getJardineiro();
    void JardineiroEntra(const char& l, const char& c);
    void JardineiroSai();
    void getJardineiroLinCol(int& l, int& col);

    void mostrar();

    int getLinhas() const;
    int getColunas() const;
};

#endif //TP_2025_2026_JARDIM_H
