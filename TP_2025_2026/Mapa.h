//
// Created by Enrique Marques on 22/10/2025.
//
#ifndef TP_2025_2026_MAPA_H
#define TP_2025_2026_MAPA_H

#include <string>
#include <random>
#include <cstdlib>
#include <vector>
#include <memory>  // Para std::unique_ptr
#include <unordered_map>

using namespace std;

class Mapa {
private:
    int linhas, colunas; // Dimensões do mapa
    char **grid;  // Representação da grelha do deserto

    // Leitura do ficheiro de texto
    int moedas;
    static int instantes_entre_novos_itens;
    int duracao_item;
    int max_itens;
    int preco_venda_mercadoria;
    int preco_compra_mercadoria;
    int preco_caravana;
    int instantes_entre_novos_barbaros;
    int duracao_barbaros;

    unordered_map<string, int *> variaveis;

public:
    bool carregarMapa(const string& ficheiro); // Carrega o mapa de um ficheiro
    int setDuracaoItem(int duracao);

};
#endif //TP_2025_2026_MAPA_H
