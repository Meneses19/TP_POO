//
// Created by Enrique Marques on 22/10/2025.
//

#include "Mapa.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cstdlib>
#include <vector>

int Mapa::instantes_entre_novos_itens = 0;

bool Mapa::carregarMapa(const string& ficheiro) {
    ifstream f(ficheiro);
    if(!f){
        cout << "\n Erro na leitura\n";
        return false;
    }
    string linha;

    // Ler as dimensões do mapa
    f >> linha >> linhas;  // Ex: "linhas 10"
    f >> linha >> colunas; // Ex: "colunas 20"
    f.ignore(numeric_limits<streamsize>::max(), '\n');
    // Validar que as dimensões lidas são válidas
    if (linhas <= 0 || colunas <= 0) {
        throw runtime_error("Dimensoes do mapa inválidas.");
    }

    // Inicializar a grid com as dimensões
    //this->redimensionarGrid(linhas, colunas, '.'); // Define um grid com '.'
    // Ler o layout do mapa linha por linha
    for (int i = 0; i < linhas; ++i) {
        getline(f, linha); // Ler a linha inteira
        // Se a linha for maior que o esperado, cortar para o tamanho certo (remover espaços extras)
        if (linha.size() > static_cast<size_t>(colunas)) {
            linha = linha.substr(0, colunas);  // Pega apenas os primeiros 'colunas' caracteres
        }
        for (int j = 0; j < colunas; ++j) {
            grid[i][j] = linha[j]; // Preencher o mapa
        }
    }
    cout << "\n Aqui esta na posicao 0,8 o carcter :" << grid[4][8];

    // Ler configuração de moedas
    while (getline(f, linha)) {
        istringstream ss(linha);
        string chave;
        int valor;

        if (ss >> chave >> valor) {
            // Procura a chave no mapa e atualiza a variável associada
            auto it = variaveis.find(chave);
            if (it != variaveis.end()) {
                *(it->second) = valor;
            }
        }
    }
    f.close();

    // Exibindo os valores lidos
    cout << "\n moedas: " << moedas;
    cout << "\n instantes_entre_novos_itens: " << instantes_entre_novos_itens;
    cout << "\n duracao_item: " << duracao_item;
    cout << "\n max_itens: " << max_itens;
    cout << "\n preco_venda_mercadoria: " << preco_venda_mercadoria;
    cout << "\n preco_compra_mercadoria: " << preco_compra_mercadoria;
    cout << "\n preco_caravana: " << preco_caravana;
    cout << "\n instantes_entre_novos_barbaros: " << instantes_entre_novos_barbaros;
    cout << "\n duracao_barbaros: " << duracao_barbaros;

    return true;
}