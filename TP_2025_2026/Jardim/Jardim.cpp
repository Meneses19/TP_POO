//
// Created by Enrique Marques on 29/10/2025.
//

#include "Jardim.h"
#include <algorithm>
#include <random>

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
// --- Comandos de Informação ---

void Jardim::listarTodasPlantas() const {
    if (plantas.empty()) {
        cout << "Nao ha plantas vivas no jardim.\n";
        return;
    }

    cout << "\n--- Lista de Plantas (" << plantas.size() << ") ---\n";
    for (const auto& p : plantas) {
        cout << p->getDescricao() << "\n";
    }
    cout << "------------------------------\n";
}

void Jardim::mostrarDetalhesPlanta(int l, int c) const {
    if (!posicaoValida(l, c)) {
        cout << "Posicao invalida.\n";
        return;
    }

    if (grelha[l][c].temPlanta()) {
        cout << "\n--- Detalhes da Planta ---\n";
        cout << grelha[l][c].getPlanta()->getDescricao() << "\n";
    } else {
        cout << "Nao existe nenhuma planta na posicao indicada.\n";
    }
}

void Jardim::mostrarDetalhesSolo(int l, int c) const {
    if (!posicaoValida(l, c)) {
        cout << "Posicao invalida.\n";
        return;
    }

    int agua = grelha[l][c].getAgua();
    int nutri = grelha[l][c].getNutrientes();

    cout << "\n--- Estado do Solo [" << (char)('a' + l) << (char)('a' + c) << "] ---\n";
    cout << "Agua: " << agua << "\n";
    cout << "Nutrientes: " << nutri << "\n";

    if (grelha[l][c].temPlanta()) {
        cout << "Ocupante: " << grelha[l][c].getPlanta()->getNome() << "\n";
    } else {
        cout << "Ocupante: (Vazio)\n";
    }
}

void Jardim::avancarTempo(int instantes) {
    for (int t = 0; t < instantes; ++t) {

        vector<shared_ptr<Planta>> novasPlantas;

        for (auto it = plantas.begin(); it != plantas.end(); ) {
            shared_ptr<Planta> p = *it;
            int l = p->getLinha();
            int c = p->getColuna();

            int aguaSolo = grelha[l][c].getAgua();
            int nutriSolo = grelha[l][c].getNutrientes();

            int aAntes = aguaSolo;
            int nAntes = nutriSolo;

            p->avancaInstante(aguaSolo, nutriSolo); // Planta come

            grelha[l][c].adicionarAgua(aguaSolo - aAntes);
            grelha[l][c].adicionarNutrientes(nutriSolo - nAntes);

            if (!p->isViva()) {
                grelha[l][c].removerPlanta();
                it = plantas.erase(it);
                continue;
            }

            if (p->deveReproduzir()) {

                vector<pair<int, int>> vizinhos = getVizinhosLivres(l, c);

                if (!vizinhos.empty()) {
                    int idx = rand() % vizinhos.size();
                    int novaL = vizinhos[idx].first;
                    int novaC = vizinhos[idx].second;

                    // Cria o clone
                    shared_ptr<Planta> bebe = p->duplicar(novaL, novaC);
                    novasPlantas.push_back(bebe);
                    int custo = p->getNutrientes() / 2;
                    p->setNutrientes(0); // (Opcional, não sei se é para a mãe perder os nutrientes ou não)
                }
            }

            ++it;
        }
        for (auto& bebe : novasPlantas) {
            if (!grelha[bebe->getLinha()][bebe->getColuna()].temPlanta()) {
                grelha[bebe->getLinha()][bebe->getColuna()].setPlanta(bebe);
                plantas.push_back(bebe);
            }
        }
    }
}
vector<pair<int, int>> Jardim::getVizinhosLivres(int l, int c) const {
    vector<pair<int, int>> livres;

    int dLin[] = {-1, 1, 0, 0};
    int dCol[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nl = l + dLin[i];
        int nc = c + dCol[i];

        if (posicaoValida(nl, nc)) {
            if (!grelha[nl][nc].temPlanta()) {
                livres.push_back({nl, nc});
            }
        }
    }
    return livres;
}
