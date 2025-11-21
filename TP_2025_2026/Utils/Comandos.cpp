// Created by Enrique Marques on 22/10/2025.
//

#include "Comandos.h"
#include "../Jardim/Simulador.h"

bool eCaracterAlfabetico(const char& c){
    return isalpha(c);
}

bool eTerrenoValido(const string& s) {
    return s.size() == 2 && isalpha(s[0]) && isalpha(s[1]);
}

// Verificar se é um numero
bool eNumero(const string& str) {
    if (str.empty()) {
        return false; // String vazia não é um número
    }

    // Verifica se o primeiro caractere é um dígito ou um sinal '-'
    size_t start = 0;
    if (str[0] == '-') {
        if (str.size() == 1) {
            return false; // Apenas '-' não é um número
        }
        start = 1; // Ignora o sinal para os próximos caracteres
    }

    // Verifica se os caracteres restantes são dígitos
    for (size_t i = start; i < str.size(); ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

string VerificarComandos(const string& ComandoRecebido, map<string, Comandos>& ListaDeComandos) {

    istringstream iss(ComandoRecebido);  // Separa string em várias strings por espaços
    vector<string> ArgumentosRecebidosSeparado{
            istream_iterator<string>{iss},
            istream_iterator<string>{}
    };
    // Iterador responsavel por tentar encontrar um objecto com mesmo nome que o comando introduzido
    auto ComandoEncontrado = ListaDeComandos.find(ArgumentosRecebidosSeparado[0]);
    int NumeroArgsRemovido0 = ArgumentosRecebidosSeparado.size() - 1;
    // if que verifica que encontrou o comando no array da classe Comandos
    if (ComandoEncontrado != ListaDeComandos.end()) {
        // verificar se os argumentos obrigatórios estão em ordem
        if (NumeroArgsRemovido0 < ComandoEncontrado->second.nArgsObrigatorios){

            string Resultado = "[X] Numero de Argumentos Insuficientes!"
                               "\nMinimo de argumentos: " +
                               to_string(ComandoEncontrado->second.nArgsObrigatorios) +
                               "\nIntroduziu: "+
                               to_string(NumeroArgsRemovido0) +
                               "\nComando aceita args do tipo";

            string MostrarArgumentos = "\n{";
            for (size_t i = 0; i < ComandoEncontrado->second.TipoDeArgs.size(); ++i) {
                MostrarArgumentos += "\"" + ComandoEncontrado->second.TipoDeArgs[i] + "\"";
                if (i < ComandoEncontrado->second.TipoDeArgs.size() - 1) {
                    MostrarArgumentos += ", ";
                }
            }
            MostrarArgumentos += "}\n";

            return Resultado + MostrarArgumentos;
        }

        if (NumeroArgsRemovido0 > (ComandoEncontrado->second.nArgsObrigatorios + ComandoEncontrado->second.nArgsOptionais)){
            string Resultado = "[Y] Demasiados Argumentos!"
                               "\nMaximo de argumentos: " +
                               to_string(ComandoEncontrado->second.nArgsObrigatorios + ComandoEncontrado->second.nArgsOptionais) +
                               "\nIntroduziu: "+
                               to_string(NumeroArgsRemovido0) +
                               "\nComando aceita args do tipo";

            string MostrarArgumentos = "\n{";
            for (size_t i = 0; i < ComandoEncontrado->second.TipoDeArgs.size(); ++i) {
                MostrarArgumentos += "\"" + ComandoEncontrado->second.TipoDeArgs[i] + "\"";
                if (i < ComandoEncontrado->second.TipoDeArgs.size() - 1) {
                    MostrarArgumentos += ", ";
                }
            }
            MostrarArgumentos += "}\n";

            return Resultado + MostrarArgumentos;
        }
        string RespostaExecutada = ComandoEncontrado->second.CodigoExecutar(ArgumentosRecebidosSeparado);

        if (!RespostaExecutada.empty()) {
            return RespostaExecutada;
        } else {
            return ComandoEncontrado->second.Resposta;
        }

    } else {
        return "";
    }
}

void InicializarComandos(map<string, Comandos>& ListaDeComandos) {
    // Fase 2 Comandos

    // Comando: avanca <n>
    ListaDeComandos["avanca"] = {0, 1, // 0 obrigatório, 1 opcional
                                 {"int"},
                                 "Avança n instantes, ou 1 se n não for especificado.",
                                 [](const vector<string> &args) {
                                    stringstream ss;
                                    // Verifica se escreveu avanca ou avanca 1 por exemplo
                                     if (args.size() > 1) {
                                         if (eNumero(args[1])) {
                                             ss << "avanca " << args[1];
                                         } else {
                                             ss << "[Z] Argumento invalido!"
                                                << "\nIntroduziu: " << args[1]
                                                << "\nComando aceita args do tipo: {int}"
                                                << "\nExemplo: avanca 3 ou avanca";
                                         }
                                     } else {
                                         ss << "avanca 1"; // valor default se não especificar
                                     }

                                        return ss.str();
                                    },
                                 "Resposta para o comando avanca"};

    // Comando: lplantas
    ListaDeComandos["lplantas"] = {0, 0,  // 2 obrigatórios, 0 opcionais
                                  {},
                                  "Lista as plantas existentes no jardim",
                                  [](const vector<string>& args) {
                                      stringstream ss;
                                      ss << "lplantas";
                                      return ss.str();
                                  },
                                  "Resposta para o comando lplantas"};

    // Comando: lplanta <l><c>
    ListaDeComandos["lplanta"] = {1, 0,  // 0 obrigatório, 0 opcionais
                                 {"string"},
                                 "Lista no ecrã as propriedades da planta que se encontrar na posição l,c.",
                                 [](const vector<string>& args) {
                                     stringstream ss;
                                     // Verificar se é um caracter

                                     // Validações
                                     // 1 - Argumentos == 2 porque tem que ser com linnhas e colunas
                                     // 2 - Validar porque tem que ser letras do alfabeto
                                     if (eTerrenoValido(args[1])) {
                                         ss << "lplanta " << args[1][0] << " " << args[1][1];
                                     } else {
                                         ss << "[Z] Argumentos Invalidos!"
                                            << "\nIntroduziu: " << args[1]
                                            << "\nComando aceita args do tipo: {string}"
                                            << "\nExemplo: lplanta cc \n";
                                     }
                                     return ss.str();
                                 },
                                 "Resposta para o comando lplanta"};

    // Comando: larea
    ListaDeComandos["larea"] = {0, 0,  // 2 obrigatórios, 0 opcionais
                                   {},
                                   "Lista no ecrã cada uma das posições de solo do jardim que não esteja totalmente vazia com os seus conteudos",
                                   [](const vector<string>& args) {
                                       stringstream ss;
                                       ss << "larea";
                                       return ss.str();
                                   },
                                   "Resposta para o comando lplantas"};

    // Comando: lsolo <l><c> [n]
    ListaDeComandos["lsolo"] = {1, 1,  // 1 obrigatório, 0 opcionais
                                   {"string","int"},
                                   "Lista as props da posição indicada",
                                   [](const vector<string>& args) {
                                       stringstream ss;

                                       if(args.size() == 2 && eTerrenoValido(args[1])){
                                           ss << "lsolo " << args[1][0] << " " << args[1][1];
                                       }
                                       else if (args.size() == 3 && args[1].size() == 2 && eTerrenoValido(args[1]) && eNumero(args[2])) {
                                           ss << "lsolo " << args[1][0] << " " << args[1][1] << " " << args[2];
                                       }
                                       else {
                                           ss << "[Z] Argumentos Invalidos!"
                                              << "\nIntroduziu: " << args[1]
                                              << (args.size() > 2 ? " " + args[2] : "")
                                              << "\nComando aceita args do tipo:"
                                              << "\n {string,int}\n"
                                              << "\nExemplo: lsolo cf \n";
                                       }
                                       return ss.str();
                                   },
                                   "Resposta para o comando caravana"};

    // Comando: lferr
    ListaDeComandos["lferr"] = {0, 0,  // 2 obrigatórios, 0 opcionais
                                {},
                                "Lista no ecrã, uma por linha, as ferramentas que o jardineiro transporta",
                                [](const vector<string>& args) {
                                    stringstream ss;
                                    ss << "lferr";
                                    return ss.str();
                                },
                                "Resposta para o comando lferr"};

    // Comando: colhe <l><c>
    ListaDeComandos["colhe"] = {1, 0,  // 0 obrigatório, 0 opcionais
                                  {"string"},
                                  "Colhe uma planta, removendo-a do jardim.",
                                  [](const vector<string>& args) {
                                      stringstream ss;
                                      // Verificar se é um caracter

                                      if (eTerrenoValido(args[1])) {
                                          ss << "colhe " << args[1][0] << " " << args[1][1];
                                      } else {
                                          ss << "[Z] Argumentos Invalidos!"
                                             << "\nIntroduziu: " << args[1]
                                             << "\nComando aceita args do tipo: {string}"
                                             << "\nExemplo: colhe cc \n";
                                      }
                                      return ss.str();
                                  },
                                  "Resposta para o comando colhe"};

    // Comando: planta <l><c> <tipo>
    ListaDeComandos["planta"] = {2, 0,  // 1 obrigatório, 0 opcionais
                                {"string","char"},
                                "Coloca uma nova planta do tipo indicado (sendo tipo um caracter C, R, E, X, que representa o tipo \n"
                                "de planta), na posição do jardim",
                                [](const vector<string>& args) {
                                    stringstream ss;
                                    // Verificação se é um char e se argumentos = 2

                                    if (eTerrenoValido(args[1]) && eCaracterAlfabetico(args[2][0])) {
                                        ss << "planta " << args[1][0] << " " << args[1][1] << " " << args[2];
                                    } else {
                                        ss << "[Z] Argumentos Invalidos!"
                                           << "\nIntroduziu: " << args[1] << " " << args[2]
                                           << "\nComando aceita args do tipo:"
                                           << "\n {string,char}"
                                           << "\nExemplo: planta cf c";
                                    }

                                    return ss.str();
                                },
                                "Resposta para o comando planta"};

    // Comando: larga
    ListaDeComandos["larga"] = {0, 0,  // 2 obrigatórios, 0 opcionais
                                {},
                                "Se tiver alguma ferramenta na mão, larga-a, juntando-as às outras que transporta.",
                                [](const vector<string>& args) {
                                    stringstream ss;
                                    ss << "larga";
                                    return ss.str();
                                },
                                "Resposta para o comando larga"};

    // Command: pega <n>
    ListaDeComandos["pega"] = {1, 0,
                               {"int"},
                               "Coloca na mão a ferramenta como número de série",
                               [](const vector<string>& args) {
                                   stringstream ss;
                                   if (eNumero(args[1])) {
                                       ss << "pega " << args[1];
                                   }else {
                                        ss << "[Z] Argumento invalido!"
                                           << "\nIntroduziu: " << args[1]
                                           << "\nComando aceita args do tipo: {int}"
                                           << "\nExemplo: pega 3";
                                    }
                                   return ss.str();
                               },
                               "Resposta para o comando pega"};

    // Command: compra <c>
    ListaDeComandos["compra"] = {1, 0,
                               {"string"},
                               "Compra uma ferramenta do tipo indicado em c: g, a, t, z.",
                               [](const vector<string>& args) {
                                   stringstream ss;
                                   if (eCaracterAlfabetico(args[1][0])) {
                                       ss << "compra " << args[1];
                                   }else {
                                       ss << "[Z] Argumento invalido!"
                                          << "\nIntroduziu: " << args[1]
                                          << "\nComando aceita args do tipo: {int}"
                                          << "\nExemplo: compra a";
                                   }
                                   return ss.str();
                               },
                               "Resposta para o comando compra"};

    // Comando: esquerda
    ListaDeComandos["e"] = {0, 0,
                            {},
                            "Desloca o jardineiro uma posição para a esquerda.",
                            [](const vector<string>& args) {
                                stringstream ss;
                                ss << "e";
                                return ss.str();
                            },
                            "Resposta para o comando esquerda"};

// Comando: direita
    ListaDeComandos["d"] = {0, 0,
                            {},
                            "Desloca o jardineiro uma posição para a direita.",
                            [](const vector<string>& args) {
                                stringstream ss;
                                ss << "d";
                                return ss.str();
                            },
                            "Resposta para o comando direita"};

// Comando: cima
    ListaDeComandos["c"] = {0, 0,
                            {},
                            "Desloca o jardineiro uma posição para cima.",
                            [](const vector<string>& args) {
                                stringstream ss;
                                ss << "c";
                                return ss.str();
                            },
                            "Resposta para o comando cima"};

// Comando: baixo
    ListaDeComandos["b"] = {0, 0,
                            {},
                            "Desloca o jardineiro uma posição para baixo.",
                            [](const vector<string>& args) {
                                stringstream ss;
                                ss << "b";
                                return ss.str();
                            },
                            "Resposta para o comando baixo"};

    // Comando: entra <l><c>
    ListaDeComandos["entra"] = {1, 0,  // 0 obrigatório, 0 opcionais
                                {"string"},
                                "Faz o jardineiro entrar no jardim na posição l,c.",
                                [](const vector<string>& args) {
                                    stringstream ss;
                                    // Verificar se é um caracter

                                    if (eTerrenoValido(args[1])) {
                                        ss << "entra " << args[1][0] << " " << args[1][1];
                                    } else {
                                        ss << "[Z] Argumentos Invalidos!"
                                           << "\nIntroduziu: " << args[1]
                                           << "\nComando aceita args do tipo: {string}"
                                           << "\nExemplo: entra cc \n";
                                    }
                                    return ss.str();
                                },
                                "Resposta para o comando entra"};

    // Comando: sai
    ListaDeComandos["sai"] = {0, 0,  // 2 obrigatórios, 0 opcionais
                                {},
                                "O jardineiro sai do jardim. ",
                                [](const vector<string>& args) {
                                    stringstream ss;
                                    ss << "sai";
                                    return ss.str();
                                },
                                "Resposta para o comando sair"};


    // Comando: jardim <n> <n>
    ListaDeComandos["jardim"] = {2, 0,  // 2 argumentos obrigatórios, 0 opcionais
                                 {"int", "int"},  // Espera dois inteiros: <N> e <T>
                                 "Cria o Jardim com as dimensões número de linhas (o primeiro número indicado) e \n"
                                 "número de colunas (o segundo número indicado).",
                                 [](const vector<string>& args) {
                                     stringstream ss;

                                     if (eNumero(args[1]) && eNumero(args[2])) {
                                         ss << "jardim " << args[1] << " " << args[2];
                                     }else {
                                         ss << "[Z] Argumento invalido!"
                                            << "\nIntroduziu: " << args[1] << " " << args[2]
                                            << "\nComando aceita args do tipo: {int}"
                                            << "\nExemplo: jardim 10 10";
                                     }
                                     return ss.str();
                                 },
                                 "Resposta para o comando jardim"};

    // Commando: grava <nome>
    ListaDeComandos["grava"] = {1, 0,
                                {"string"},
                                "Faz uma cópia do estado do buffer associado ao nome indicado.",
                                [](const vector<string>& args) {
                                    stringstream ss;
                                    ss << "grava "<< args[1];
                                    return ss.str();
                                },
                                "Resposta para o comando saves"};

    // Commando: recupera <nome>
    ListaDeComandos["recupera"] = {1, 0,
                                {"string"},
                                "Recupera a cópia do buffer associada ao nome indicado.",
                                [](const vector<string>& args) {
                                    stringstream ss;
                                    ss << "recupera "<< args[1];
                                    return ss.str();
                                },
                                "Resposta para o comando recupera"};

    // Commando: apaga <nome>
    ListaDeComandos["apaga"] = {1, 0,
                               {"string"},
                               "Apaga a cópia do buffer associada ao nome indicado.",
                               [](const vector<string>& args) {
                                   stringstream ss;
                                   ss << "apaga " << args[1];
                                   return ss.str();
                               },
                               "Resposta para o comando apaga"};

    // Comando: exec <nomeFicheiro>
    ListaDeComandos["exec"] = {1, 0,  // 1 obrigatório, 0 opcionais
                               {"string"},
                               "Le comandos do ficheiro indicado e executa-os.",
                               [](const vector<string>& args) {
                                   stringstream ss;
                                   ss << "exec " << args[1];
                                   return ss.str();
                               },
                               "Resposta para o comando exec"};
    // Commando: fim
    ListaDeComandos["fim"] = {0, 0,
                                   {},
                                   "Termina a simulação",
                                   [](const vector<string>& args) {
                                       stringstream ss;
                                       ss << "fim";
                                       return ss.str();
                                   },
                                   "Resposta para o comando fim"};
    // Commando: lists <nome>
    ListaDeComandos["lists"] = {1, 0,
                                   {"string"},
                                   "Lista as cópias dos buffers associados ao nome indicado.",
                                   [](const vector<string>& args) {
                                       stringstream ss;
                                       ss << "lists "<< args[1];
                                       return ss.str();
                                   },
                                   "Resposta para o comando lists"};
}
