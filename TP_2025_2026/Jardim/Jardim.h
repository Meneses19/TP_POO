#ifndef TP_2025_2026_JARDIM_H
#define TP_2025_2026_JARDIM_H

#include "Solo.h"
#include "Jardineiro.h"
#include "Plantas/Planta.h"
#include "Ferramentas/Ferramenta.h"

#include <iostream>
#include <vector>
#include <memory> // shared_ptr
#include <string>

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

    // CORREÇÃO 1: O 'const' TEM de estar aqui
    bool posicaoValida(int l, int c) const; 
    bool posicaoValida(char linha, char coluna) const;

    // CORREÇÃO 2: Tem de ser 'bool', não 'void'
    bool adicionarPlanta(shared_ptr<Planta> p);
    
    void removerPlantaNaPosicao(int l, int c);
    shared_ptr<Planta> getPlantaNaPosicao(int l, int c) const;

    void adicionarFerramenta(shared_ptr<Ferramenta> f);
    void removerFerramenta(shared_ptr<Ferramenta> f);

    Jardineiro& getJardineiro();
    void JardineiroEntra(const char& l, const char& c);
    void JardineiroSai();
    void getJardineiroLinCol(int& l, int& col);

    void mostrar();

    int getLinhas() const;
    int getColunas() const;

    void avancarTempo(int instantes);

    void listarTodasPlantas() const;
    void mostrarDetalhesPlanta(int l, int c) const;
    void mostrarDetalhesSolo(int l, int c) const;
};

#endif //TP_2025_2026_JARDIM_H