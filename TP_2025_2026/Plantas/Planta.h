//
// Created by Enrique Marques on 28/10/2025.
//

#ifndef TP_2025_2026_PLANTA_H
#define TP_2025_2026_PLANTA_H

#include <iostream>
#include <string>
#include <memory>

class Solo;
using namespace std;

class Planta {
    string tipo; // cacto, roseira, erva daninha, planta exótica
    string posicao;
    int linha, coluna; // posição da planta no Jardim
    int nutrientes; // unidades de nutrientes
    int agua; // quantidade de agua
    string beleza; // feias, bonitas, neutras
    bool estado; // viva ou morta
    char displayChar; // Caracter para o jardim ('c', 'r', 'e', 'x')

public:
    Planta(const string& tipo, int linha, int coluna, int nutrientes, int agua, const string& beleza, bool estado, char displayChar);


    virtual void avancaInstante(int& soloAgua, int& soloNutrientes) = 0;
    virtual shared_ptr<Planta> duplicar(int l, int c) const = 0;
    virtual bool deveReproduzir() const = 0;
    virtual string getDescricao() const;
    string getNome() const;
    string getTipo() const;
    int getLinha() const;
    int getColuna() const;
    void setPosicao(int l, int c);
    int getNutrientes() const;
    int getAgua() const;
    string getBeleza() const;
    char getDisplayChar() const;
    bool isViva() const;

    // Para alterar os valores internos
    void addAgua(int quantidade);
    void addNutrientes(int quantidade);

    // Para definir valores específicos
    void setAgua(int valor);
    void setNutrientes(int valor);

    // Para o estado
    void morre();

    virtual ~Planta() = default;
};
#endif //TP_2025_2026_PLANTA_H
