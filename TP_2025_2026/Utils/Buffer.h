//
// Created by Enrique Marques on 29/10/2025.
//

#ifndef TP_2025_2026_BUFFER_H
#define TP_2025_2026_BUFFER_H


#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Buffer {
    int linhas, colunas;           // Dimensões do buffer
    char** matriz;                 // Representação bidimensional do buffer

    void alocaMatriz();            // Aloca memória para a matriz
    void desalocaMatriz();         // Libera memória da matriz

public:
    Buffer(int linhas = 0, int colunas = 0);
    ~Buffer();

    void resize(int l, int col);
    void preenche();
    void coloca(int li, int col, char c);

    void clear(); // Limpa o buffer (preenche com espaços)
    void write(char c); // Escreve um caractere no buffer
    void write(const string& str); // Escreve uma string no buffer
    void write(int valor); // Escreve um inteiro no buffer
    void display(); // Exibe o conteúdo do buffer na consola

    // Getters para as dimensões do buffer
    int getLinhas() const;
    int getColunas() const;

    // Sobrecarga do operador << para facilitar o uso
    Buffer& operator<<(const char c);
    Buffer& operator<<(const std::string& str);
    Buffer& operator<<(int valor);
};
#endif //TP_2025_2026_BUFFER_H
