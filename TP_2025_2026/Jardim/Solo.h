//
// Created by Enrique Marques on 30/10/2025.
//

#ifndef TP_2025_2026_SOLO_H
#define TP_2025_2026_SOLO_H

#include "../Plantas/Planta.h"
#include "../Ferramentas/Ferramenta.h"
#include <memory>
#include <string>

using namespace std;
class Planta;
class Ferramenta;

class Solo {
    int agua;
    int nutrientes;
    shared_ptr<Planta> planta;
    shared_ptr<Ferramenta> ferramenta;

public:
    Solo();

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
    bool temPlanta() const;

    shared_ptr<Ferramenta> getFerramenta() const;
    void setFerramenta(std::shared_ptr<Ferramenta> f);
    void removerFerramenta();
    bool temFerramenta() const;

};
#endif //TP_2025_2026_SOLO_H
