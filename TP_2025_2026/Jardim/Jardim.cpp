//
// Created by Enrique Marques on 29/10/2025.
//

#include "Jardim.h"

Jardim::Jardim() : grelha(nullptr), linhas(0), colunas(0){

}

Jardim::~Jardim() {
    for (int i = 0; i < linhas; ++i) {
        delete[] grelha[i];
    }
    delete[] grelha;
}

Solo& Jardim::getSolo(int linha, int coluna) {
    return grelha[linha][coluna];
}

bool Jardim::posicaoValida(char& linha, char& coluna) {
    char linhaChar = tolower(linha);
    char colunaChar = tolower(coluna);

    int l = linhaChar - 'a';
    int c = colunaChar - 'a';

    return l >= 0 && l < linhas && c >= 0 && c < colunas;
}

int Jardim::getLinhas() const {
    return linhas;
}

int Jardim::getColunas() const {
    return colunas;
}

void Jardim::mostrar(){
    // Exemplo simples com régua
    cout << "  ";
    for (int j = 0; j < colunas; ++j)
        cout << static_cast<char>('A' + j);
    cout << "\n";

    for (int i = 0; i < linhas; ++i) {
        cout << static_cast<char>('A' + i) << " ";
        for (int j = 0; j < colunas; ++j) {
            cout << grelha[i][j].getSimbolo(); // Assumindo que Solo tem getSimbolo()
        }
        cout << "\n";
    }
}

void Jardim::Criargrelha(int l, int c) {
    if (grelha) {
        for (int i = 0; i < linhas; ++i) {
            delete[] grelha[i];
        }
        delete[] grelha;
    }

    linhas = l;
    colunas = c;
    grelha = new Solo*[linhas];

    for (int i = 0; i < linhas; i++) {
        grelha[i] = new Solo[colunas];
    }
}

void Jardim::JardineiroEntra(const char& l, const char& c) {
    jardineiro.entra(l, c);
}

void Jardim::JardineiroSai() {
    jardineiro.sai();
}

void Jardim::getJardineiroLinCol(int &l, int &col) {
    l = jardineiro.getLinhas();
    col = jardineiro.getColunas();
}
