cmake_minimum_required(VERSION 3.26)
project(TP_25_26)

set(CMAKE_CXX_STANDARD 20)

include_directories(TP_2025_2026)
include_directories(TP_2025_2026/Ferramentas)
include_directories(TP_2025_2026/Jardim)
include_directories(TP_2025_2026/Jardineiro)
include_directories(TP_2025_2026/Plantas)
include_directories(TP_2025_2026/Utils)

add_executable(TP_25_26
        TP_2025_2026/Ferramentas/Adubo.cpp
        TP_2025_2026/Ferramentas/Adubo.h
        TP_2025_2026/Ferramentas/Ferramenta.cpp
        TP_2025_2026/Ferramentas/Ferramenta.h
        TP_2025_2026/Ferramentas/Ferramentas.cpp
        TP_2025_2026/Ferramentas/Ferramentas.h
        TP_2025_2026/Ferramentas/Regador.cpp
        TP_2025_2026/Ferramentas/Regador.h
        TP_2025_2026/Ferramentas/TesouraDePoda.cpp
        TP_2025_2026/Ferramentas/TesouraDePoda.h
        TP_2025_2026/Jardim/Jardim.cpp
        TP_2025_2026/Jardim/Jardim.h
        TP_2025_2026/Jardim/Simulador.h
        TP_2025_2026/Jardim/Simulator.cpp
        TP_2025_2026/Jardim/Solo.cpp
        TP_2025_2026/Jardim/Solo.h
        TP_2025_2026/Jardineiro/Jardineiro.cpp
        TP_2025_2026/Jardineiro/Jardineiro.h
        TP_2025_2026/Plantas/Cacto.cpp
        TP_2025_2026/Plantas/Cacto.h
        TP_2025_2026/Plantas/ErvaDaninha.cpp
        TP_2025_2026/Plantas/ErvaDaninha.h
        TP_2025_2026/Plantas/Exotica.cpp
        TP_2025_2026/Plantas/Exotica.h
        TP_2025_2026/Plantas/Planta.cpp
        TP_2025_2026/Plantas/Planta.h
        TP_2025_2026/Plantas/Roseira.cpp
        TP_2025_2026/Plantas/Roseira.h
        TP_2025_2026/Utils/Buffer.cpp
        TP_2025_2026/Utils/Buffer.h
        TP_2025_2026/Utils/Comandos.cpp
        TP_2025_2026/Utils/Comandos.h
        TP_2025_2026/Utils/Settings.cpp
        TP_2025_2026/Utils/Settings.h
        TP_2025_2026/Mapa.cpp
        TP_2025_2026/Mapa.h)
