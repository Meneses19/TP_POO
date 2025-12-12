//
// Created by Enrique Marques on 29/10/2025.
//

#include "Jardim.h"
#include <algorithm>

Jardim::Jardim() : grelha(nullptr), linhas(0), colunas(0){
}
Jardim::Jardim(int linhas, int colunas) : linhas(linhas), colunas(colunas), grelha(nullptr) {
    Criargrelha(linhas, colunas);
}

Jardim::~Jardim() {
    if (grelha) {
        for (int i = 0; i < linhas; ++i) {
            delete[] grelha[i];
        }
        delete[] grelha;
    }
}
void Jardim::Criargrelha(int l, int c) {
    // Se já existir grelha, limpa primeiro
    if (grelha) {
        for (int i = 0; i < linhas; ++i) delete[] grelha[i];
        delete[] grelha;
    }
    linhas = l;
    colunas = c;
    // Alocação dinâmica, cumpre a restrição de não usar vetor
    grelha = new Solo*[linhas];
    for (int i = 0; i < linhas; i++) {
        grelha[i] = new Solo[colunas];
    }
}

Solo& Jardim::getSolo(int linha, int coluna) {
    return grelha[linha][coluna];
}
bool Jardim::posicaoValida(int l, int c) const {
    return l >= 0 && l < linhas && c >= 0 && c < colunas;
}

bool Jardim::posicaoValida(char linha, char coluna) const {
    int l = Solo::letraParaIndice(linha);
    int c = Solo::letraParaIndice(coluna);
    return posicaoValida(l, c);
}

bool Jardim::adicionarPlanta(shared_ptr<Planta> p) {
    if (!p) return false;

    int l = p->getLinha();
    int c = p->getColuna();

    if (!posicaoValida(l, c)) return false;

    // Verifica se já existe planta nessa posição do solo
    if (grelha[l][c].temPlanta()) {
        return false; // Já está ocupado
    }

    // 1. Adiciona à Grelha (Solo)
    grelha[l][c].setPlanta(p);

    // 2. Adiciona à Lista (Vetor)
    plantas.push_back(p);

    return true;
}

void Jardim::removerPlantaNaPosicao(int l, int c) {
    if (!posicaoValida(l, c)) return;

    if (grelha[l][c].temPlanta()) {
        shared_ptr<Planta> plantaRemover = grelha[l][c].getPlanta();

        // Remove da Grelha
        grelha[l][c].removerPlanta();

        // Isto apaga a planta do vetor. Se ninguém mais apontar para ela, é destruída.
        plantas.erase(
            remove(plantas.begin(), plantas.end(), plantaRemover),
            plantas.end()
        );
    }
}

shared_ptr<Planta> Jardim::getPlantaNaPosicao(int l, int c) const {
    if (!posicaoValida(l, c)) return nullptr;
    return grelha[l][c].getPlanta();
}
void Jardim::adicionarFerramenta(shared_ptr<Ferramenta> f) {
    ferramentas.push_back(f);
}
void Jardim::removerFerramenta(shared_ptr<Ferramenta> f) {
    ferramentas.erase(
        remove(ferramentas.begin(), ferramentas.end(), f),
        ferramentas.end()
    );
}
int Jardim::getLinhas() const {
    return linhas;
}

int Jardim::getColunas() const {
    return colunas;
}

void Jardim::mostrar() {
    cout << "  ";
    for (int j = 0; j < colunas; ++j)
        cout << static_cast<char>('A' + j);
    cout << "\n";

    for (int i = 0; i < linhas; ++i) {
        cout << static_cast<char>('A' + i) << " ";
        for (int j = 0; j < colunas; ++j) {

            // Prioridade de visualização: Jardineiro -> Planta -> Ferramenta -> Vazio

            if (jardineiro.estaNoJardim() && jardineiro.getLinhas() == i && jardineiro.getColunas() == j) {
                cout << "*";
            }
            else if (grelha[i][j].temPlanta()) {
                // Acede à planta e pede o caracter dela
                cout << grelha[i][j].getPlanta()->getDisplayChar();
            }
            else if (grelha[i][j].temFerramenta()) {
                // Acede à ferramenta e pede o caracter dela
                cout << grelha[i][j].getFerramenta()->getSimbolo();
            }
            else {
                cout << " ";
            }
        }
        cout << "\n";
    }
}
Jardineiro& Jardim::getJardineiro() {
    return jardineiro;
}
void Jardim::JardineiroEntra(const char& l, const char& c) {
    jardineiro.entra(l, c);
}

void Jardim::JardineiroSai() {
    jardineiro.sai();
}
void Jardim::getJardineiroLinCol(int& l, int& col) {
    l = jardineiro.getLinhas();
    col = jardineiro.getColunas();
}

void Jardim::avancarTempo(int instantes) {
    for (int t = 0; t < instantes; ++t) {

        for (auto it = plantas.begin(); it != plantas.end(); ) {
            shared_ptr<Planta> p = *it;
            int l = p->getLinha();
            int c = p->getColuna();

            int aguaAntes = grelha[l][c].getAgua();
            int nutriAntes = grelha[l][c].getNutrientes();

            int aguaSimulada = aguaAntes;
            int nutriSimulada = nutriAntes;

            p->avancaInstante(aguaSimulada, nutriSimulada);

            int diffAgua = aguaSimulada - aguaAntes;
            int diffNutri = nutriSimulada - nutriAntes;


            if (diffAgua > 0) {
                // A planta adicionou água
                grelha[l][c].adicionarAgua(diffAgua);
            } else if (diffAgua < 0) {
                // A planta consumiu água
                grelha[l][c].retirarAgua(-diffAgua);
            }

            if (diffNutri > 0) {
                // A planta devolveu nutrientes
                grelha[l][c].adicionarNutrientes(diffNutri);
            } else if (diffNutri < 0) {
                // A planta consumiu nutrientes
                grelha[l][c].retirarNutrientes(-diffNutri);
            }

            // Verificar se a planta morreu
            if (!p->isViva()) {
                // Remove da Grelha
                grelha[l][c].removerPlanta();
                // Remove do Vector e atualiza o iterador para o próximo elemento
                it = plantas.erase(it);

                cout << "Planta morreu na posicao " << l << " " << c << endl;
            } else {
                ++it;
            }
        }
    }
}
