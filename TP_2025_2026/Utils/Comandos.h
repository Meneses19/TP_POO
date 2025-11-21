//
// Created by Enrique Marques on 22/10/2025.
//

#ifndef TP_2025_2026_COMANDOS_H
#define TP_2025_2026_COMANDOS_H

#include <iostream>
#include <functional>
#include <map>
#include <sstream>
#include <vector>
#include <iterator>
#include <fstream>
#include "../Plantas/Planta.h"

using namespace std;

bool eNumero(const string& str);

using namespace std;
class Comandos {
public:
    int nArgsObrigatorios;
    int nArgsOptionais;
    vector<string> TipoDeArgs;
    string nome;
    function<string(const vector<string>&)> CodigoExecutar;
    string Resposta;

    Comandos() : nArgsObrigatorios(0), nArgsOptionais(0), nome(""), CodigoExecutar(nullptr), Resposta("") {}

    Comandos(int nObrigatorios, int nOptionais, const vector<string>& tipos, const string& Nome, function<string(const vector<string>&)> codigoExecutar, const string& resposta)
            : nArgsObrigatorios(nObrigatorios), nArgsOptionais(nOptionais), TipoDeArgs(tipos), nome(Nome), CodigoExecutar(codigoExecutar), Resposta(resposta) {}
    ~Comandos(){}
};

string VerificarComandos(const string& ComandoRecebido, map<string, Comandos>& ListaDeComandos);
void InicializarComandos(map<string, Comandos>& ListaDeComandos);
#endif //TP_2025_2026_COMANDOS_H
