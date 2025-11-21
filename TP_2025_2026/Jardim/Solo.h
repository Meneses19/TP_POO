//
// Created by Enrique Marques on 30/10/2025.
//

#ifndef TP_2025_2026_SOLO_H
#define TP_2025_2026_SOLO_H

#include "../Plantas/Planta.h"
#include "../Ferramentas/Ferramenta.h"
#include <memory>
using namespace std;
class Ferramenta;

class Solo {
    int agua;
    int nutrientes;
    char Simbolo;
    Planta* planta;
    Ferramenta* ferramenta;

public:
    Solo();
    Solo(string const& tipo);

    static int letraParaIndice(char letra);

    int getAgua() const;
    int getNutrientes() const;

    void retirarAgua(int quantidade);
    void retirarNutrientes(int quantidade);
    void adicionarAgua(int quantidade);
    void adicionarNutrientes(int quantidade);

    shared_ptr<Planta> getPlanta() const;
    void setPlanta(shared_ptr<Planta> p);
    void removerPlanta();

    char getSimbolo() const;
    void setSimbolo(char c);
};
#endif //TP_2025_2026_SOLO_H
