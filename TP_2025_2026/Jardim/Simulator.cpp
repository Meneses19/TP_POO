#include "../Utils/Comandos.h"
#include "Simulador.h"
#include "Plantas/Cacto.h"
#include "Plantas/Roseira.h"
#include "Plantas/ErvaDaninha.h"
#include "Plantas/Exotica.h"

void mostrarBanner() {
    cout << "******************************************************\n";
    cout << "*                                                    *\n";
    cout << "*                SIMULADOR DE JARDIM                 *\n";
    cout << "*                                                    *\n";
    cout << "*        Programacao Orientada a Objetos (POO)       *\n";
    cout << "*               Ano Letivo 2025 / 2026               *\n";
    cout << "*                                                    *\n";
    cout << "*   Instituto Superior de Engenharia de Coimbra      *\n";
    cout << "*                                                    *\n";
    cout << "*   Autores: Henrique Marques 2021141476             *\n";
    cout << "*            Guilherme Meneses 2022149107            *\n";
    cout << "*                                                    *\n";
    cout << "*   Descricao: Simulador interativo de um jardim,    *\n";
    cout << "*   onde o jardineiro gere plantas e ferramentas,    *\n";
    cout << "*   controlando a passagem do tempo e as acoes.      *\n";
    cout << "*                                                    *\n";
    cout << "******************************************************\n\n";
}

bool fileExists(const string& filename) {
    return fs::exists(filename);
}

int Simulador::processarComandos(const string& RespostaComando) {
    istringstream iss(RespostaComando);
    vector<string> ComandoParaExecutar{
            istream_iterator<string>{iss},
            istream_iterator<string>{}
    };

    // Eu acho que isto nunca vai acontecer
    if (ComandoParaExecutar.empty()) {
        cout << "\nTeste123";
        return 1;
    }

    if (ComandoParaExecutar[0] == "exec") {
        cout << "\nA executar comando exec: Le comandos do ficheiro " << ComandoParaExecutar[1];
        // Implementacao para carregar e executar comandos de um ficheiro
    }
    else if (ComandoParaExecutar[0] == "avanca") {
        int n = 1;
        // Verifica se o utilizador escreveu um número
        if (ComandoParaExecutar.size() > 1) {
            try {
                n = stoi(ComandoParaExecutar[1]);
            } catch (...) {
                cout << "Numero invalido. A avancar 1 instante.";
                n = 1;
            }
        }
        cout << "\nA avancar " << n << " instantes...\n";
        // Chama a função que acabámos de criar
        jardim.avancarTempo(n);
        // Mostra o resultado na consola
        jardim.mostrar();
    }
    else if (ComandoParaExecutar[0] == "lplantas") {
        cout << "\nA executar comando lplantas";
    }
    else if (ComandoParaExecutar[0] == "lplanta") {
        cout << "\nA executar comando lplanta: Listando a planta na posicao " << ComandoParaExecutar[1] << " " << ComandoParaExecutar[2];
    }
    else if (ComandoParaExecutar[0] == "lsolo") {
        if (ComandoParaExecutar.size() == 3)
            cout << "\nA executar comando lsolo na posicao " << ComandoParaExecutar[1] << " " << ComandoParaExecutar[2];
        else if (ComandoParaExecutar.size() == 4) {
            cout << "\nA executar comando lsolo na posicao " << ComandoParaExecutar[1] << " "
                 << ComandoParaExecutar[2]
                 << " com profundidade " << ComandoParaExecutar[3];
        }
    }
    else if (ComandoParaExecutar[0] == "larea") {
        cout << "\nA executar comando larea";
    }
    else if (ComandoParaExecutar[0] == "lferr") {
        cout << "\nA executar comando lferr: Listando ferramentas transportadas";
    }
    else if (ComandoParaExecutar[0] == "colhe") {
        char lChar = ComandoParaExecutar[1][0];
        char cChar = ComandoParaExecutar[1][1];
        int l = Solo::letraParaIndice(lChar);
        int c = Solo::letraParaIndice(cChar);

        cout << "\nA colher planta na posicao " << lChar << cChar << "...\n";

        jardim.removerPlantaNaPosicao(l, c);
        jardim.mostrar();
    }
    else if (ComandoParaExecutar[0] == "planta") {
        char lChar = ComandoParaExecutar[1][0];
        char cChar = ComandoParaExecutar[1][1];
        char tipo = tolower(ComandoParaExecutar[2][0]); // Tipo da planta (c, r, e, x)

        int l = Solo::letraParaIndice(lChar);
        int c = Solo::letraParaIndice(cChar);

        cout << "\nA plantar '" << tipo << "' na posicao " << lChar << cChar << "...\n";

        shared_ptr<Planta> novaPlanta = nullptr;

        switch (tipo) {
            case 'c': novaPlanta = make_shared<Cacto>(l, c); break;
            case 'r': novaPlanta = make_shared<Roseira>(l, c); break;
            case 'e': novaPlanta = make_shared<ErvaDaninha>(l, c); break;
            case 'a': novaPlanta = make_shared<Exotica>(l, c); break; // Assumindo 'a' ou 'x'
            case 'x': novaPlanta = make_shared<Exotica>(l, c); break;
            default: cout << "Tipo de planta desconhecido!\n"; break;
        }
        if (novaPlanta) {
            bool sucesso = jardim.adicionarPlanta(novaPlanta);
            if (sucesso) {
                cout << "Planta adicionada com sucesso!\n";
            } else {
                cout << "Erro: Nao foi possivel plantar (posicao ocupada ou invalida).\n";
            }
        }
        jardim.mostrar();
    }
    else if (ComandoParaExecutar[0] == "larga") {
        cout << "\nA executar comando larga: Largando ferramenta da mão";
    }
    else if (ComandoParaExecutar[0] == "pega") {
        cout << "\nA executar comando pega: Pegando ferramenta com número de série " << ComandoParaExecutar[1];
    }
    else if (ComandoParaExecutar[0] == "compra") {
        cout << "\nA executar comando compra: Comprando ferramenta do tipo " << ComandoParaExecutar[1];
    }
    else if (ComandoParaExecutar[0] == "entra") {
        cout << "\nA executar comando entra: Jardineiro a entrar do jardim\n";
        if(jardim.posicaoValida(ComandoParaExecutar[1][0],ComandoParaExecutar[2][0])){
            jardim.JardineiroEntra(ComandoParaExecutar[1][0],ComandoParaExecutar[2][0]);

            int l = Solo::letraParaIndice(ComandoParaExecutar[1][0]);
            int c = Solo::letraParaIndice(ComandoParaExecutar[2][0]);
            buffer.coloca(l,c,'*');
            buffer.display();
        }

        cout << "\nA executar comando entra na posicao " << ComandoParaExecutar[1] << " " << ComandoParaExecutar[2];
    }
    else if (ComandoParaExecutar[0] == "sai") {
        cout << "\nA executar comando sai: Jardineiro a sair do jardim\n";
        int i = 0, j = 0;
        jardim.getJardineiroLinCol(i,j);
        buffer.coloca(i,j,' ');
        buffer.display();
    }
    else if (ComandoParaExecutar[0] == "jardim") {
        cout << "\nA executar comando jardim: Criando jardim com " << ComandoParaExecutar[1] << " linhas e "<< ComandoParaExecutar[2] << " colunas\n";
        jardim.Criargrelha(stoi(ComandoParaExecutar[1]),stoi(ComandoParaExecutar[2]));
        buffer.resize(stoi(ComandoParaExecutar[1]),stoi(ComandoParaExecutar[2]));
        buffer.preenche();
        buffer.display();
    }
    else if (ComandoParaExecutar[0] == "grava") {
        cout << "\nA executar comando grava: Salvando buffer com nome " << ComandoParaExecutar[1];
    }
    else if (ComandoParaExecutar[0] == "recupera") {
        cout << "\nA executar comando recupera: Restaurando buffer com nome " << ComandoParaExecutar[1];
    }
    else if (ComandoParaExecutar[0] == "apaga") {
        cout << "\nA executar comando apaga: Apagando buffer com nome " << ComandoParaExecutar[1];
    }
    else if (ComandoParaExecutar[0] == "e") {
        cout << "\nA mover jardineiro para a esquerda";
    }
    else if (ComandoParaExecutar[0] == "d") {
        cout << "\nA mover jardineiro para a direita";
    }
    else if (ComandoParaExecutar[0] == "c") {
        cout << "\nA mover jardineiro para cima";
    }
    else if (ComandoParaExecutar[0] == "b") {
        cout << "\nA mover jardineiro para baixo";
    }
    else if (ComandoParaExecutar[0] == "fim") {
        cout << "\n A sair do ciclo de verificacao de comandos";
        return 0;
    }
    else if (ComandoParaExecutar[0] == "lists") {
        cout << "\n A listar todos os buffer guardados";
    }
    else {
        cout << "\nComando errado: " << RespostaComando;
        // Mensagem de erro para comando inválido
    }
    return 1;
}

void Simulador::iniciar() {

    mostrarBanner();
    string input,nome_fich,cmd;

    map<string, Comandos> ListaDeComandos;
    InicializarComandos(ListaDeComandos);
    string RespostaComando;
    int linhas = 0, colunas = 0;

    while (true){
        cout << "\n>";
        getline(cin, input); // Lê a linha inteira
        stringstream ss(input);
        ss >> cmd >> linhas >> colunas;

        if (cmd == "fim") {
            cout << "\nSaindo do programa...";
            break;
        }

        if (fase == 1) { // Fase de carregar mapa
            if (cmd == "executa") {
                cout << "\n Comando Executa";
                fase = 2;
            }
            else if (cmd == "jardim") {
                cout << "\n Comando Jardim\n";
                jardim.Criargrelha(linhas,colunas);
                buffer.resize(linhas,colunas);
                buffer.preenche();
                buffer.display();

                fase = 2;
            }
            else
                cout << "\nComando invalido na fase 1. Use 'jardim' <n> <n>, 'executa' <nome_ficheiro>' ou 'fim'." << endl;
        }
        else { // Fase de execução de comandos
            if (!input.empty()) {
                RespostaComando = VerificarComandos(input, ListaDeComandos);
                if (!RespostaComando.empty())
                    processarComandos(RespostaComando); // Processa o comando
                else
                    cout << "\nComando nao encontrado, ou invalido. Tente novamente.";
            }
        }
        // Limpeza das variaveis de verificacao de input
        input.clear();
        cmd.clear();
        nome_fich.clear();
        RespostaComando.clear();
    }
    cout << "Pressione qualquer tecla para sair...";
    _getch(); // espera 1 tecla sem precisar de Enter
}

Simulador::Simulador():instantes(0), fase(1) {

}

Simulador::~Simulador() {

}

bool Simulador::fileExists(const string &filename) const {
    return fs::exists(filename);
}

int main(){
    Simulador simulador;
    simulador.iniciar();
    return 0;
}
