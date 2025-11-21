//
// Created by Enrique Marques on 31/10/2025.
//

#ifndef TP_2025_2026_FERRAMENTA_H
#define TP_2025_2026_FERRAMENTA_H

#include <string>
#include "../Jardim/Solo.h"

class Jardim;

using namespace std;
class Ferramenta {
    int numeroSerie;
    int serie;
    string posicao;

public:
    Ferramenta(int s, const string &p);
    ~Ferramenta();
    virtual string usar(Jardim &jardim) = 0;
    virtual char getSimbolo() const = 0;
    virtual bool deveRemover() const = 0;
    string getPosicao() const;
    void setPosicao(const std::string &novaPos);

    int getSerie() const;
};
#endif //TP_2025_2026_FERRAMENTA_H
