//
// Created by Enrique Marques on 19/10/2025.
//

#ifndef TP_2025_2026_SIMULADOR_H
#define TP_2025_2026_SIMULADOR_H

#include <string>
#include <sstream>
#include <numeric>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <filesystem>
#include <sstream>
#include <vector>
#include <iterator>
#include <conio.h> // para o getchar no final
#include "../Mapa.h"
#include "../Utils/Buffer.h"
#include "Jardim.h"

using namespace std;
namespace fs = filesystem;

class Simulador {

    Jardim jardim;
    Buffer buffer;
    int instantes;
    int fase;

    // Divisão Simulador -> Utilizador + Buffer + Jardim -> Ferramentas + Plantas + Solo + Jardineiro -> Ferramentas
    const string BUFFER_FILE = "buffers.txt";

    bool fileExists(const string& filename) const;
public:
    Simulador();
    ~Simulador();
    void iniciar();

    // Manipulação de comandos
    int processarComandos(const string& RespostaComando);
};

#endif //TP_2025_2026_SIMULADOR_H
