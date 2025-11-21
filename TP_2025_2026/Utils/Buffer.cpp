//
// Created by Enrique Marques on 29/10/2025.
//

#include "Buffer.h"

// Aloca memória para a matriz
void Buffer::alocaMatriz() {
    if(linhas > 0) {
        matriz = new char *[linhas];
        for (int i = 0; i < linhas; ++i) {
            matriz[i] = new char[colunas];
        }
        return;
    }
    matriz = nullptr;
}

// Libera memória da matriz
void Buffer::desalocaMatriz() {
    if (matriz) {
        for (int i = 0; i < linhas; ++i) {
            delete[] matriz[i];
        }
        delete[] matriz;
        matriz = nullptr;
    }
}

// Construtor
Buffer::Buffer(int linhas, int colunas)
        : linhas(linhas), colunas(colunas) {
    alocaMatriz();
    clear(); // Inicializa com espaços
}

// Destrutor
Buffer::~Buffer() {
    desalocaMatriz(); // Libera a memória
}

// Limpa o buffer
void Buffer::clear() {

}

// Escreve um caractere no buffer
void Buffer::write(char c) {

}

// Escreve uma string no buffer
void Buffer::write(const string& str) {
    for (char c : str) {
        write(c); // Escreve cada caractere
    }
}

// Escreve um inteiro no buffer
void Buffer::write(int valor) {
    write(to_string(valor)); // Converte para string e escreve
}

// Exibe o conteúdo do buffer na consola
void Buffer::display() {

    matriz[0][0] = 'A';
    matriz[0][1] = 'B';
    matriz[1][1] = 'C';

    // Cabeçalho das colunas
    cout << "    ";
    for (int j = 0; j < colunas; ++j)
        cout << "  " << static_cast<char>('A' + j) << " ";
    cout << "\n";

    // Linha superior
    cout << "   +";
    for (int j = 0; j < colunas; ++j)
        cout << "---+";
    cout << "\n";

    // Conteúdo da matriz
    for (int i = 0; i < linhas; ++i) {
        cout << " " << static_cast<char>('A' + i) << " |";
        for (int j = 0; j < colunas; ++j) {
            cout << " " << matriz[i][j] << " |";
        }
        cout << "\n";

        // Linha inferior entre linhas
        cout << "   +";
        for (int j = 0; j < colunas; ++j)
            cout << "---+";
        cout << "\n";
    }

}

void Buffer::preenche(){
    for(int i = 0; i < linhas; i++)
        for(int j = 0; j < colunas; j++)
            matriz[i][j] = ' ';
}

// Getters para as dimensões do buffer
int Buffer::getLinhas() const {
    return linhas;
}

int Buffer::getColunas() const {
    return colunas;
}

// Sobrecarga do operador << para caracteres
Buffer& Buffer::operator<<(const char c) {
    write(c);
    return *this;
}

// Sobrecarga do operador << para strings
Buffer& Buffer::operator<<(const string& str) {
    write(str);
    return *this;
}

// Sobrecarga do operador << para inteiros
Buffer& Buffer::operator<<(int valor) {
    write(valor);
    return *this;
}

void Buffer::resize(int l, int col) {
    // Aloca uma nova matriz com as dimensões desejadas
    char** novaMatriz = new char*[l];
    for (int i = 0; i < l; ++i) {
        novaMatriz[i] = new char[col]; // Cria as colunas para cada linha
    }

    matriz = novaMatriz;
    linhas = l;
    colunas = col;
}

void Buffer::coloca(int li, int col, char c) {
    matriz[li][col] = c;
}
