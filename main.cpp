#include <iostream>
#include <fstream>
#include <cstring>
#include "acamp.hpp"
#include "item.hpp"
using namespace std;

unsigned int menu() {
    cout << "\"procurar\" - para procurar um item no arquivo\n"
         << "\"inserir\"  - para inserir um elemento\n"
         << "\"imprimir\" - para imprimir o conteudo todo\n"
         << "\"remover\"  - para remover um elemento do arquivo\n"
         << " \"sair\"    - para encerrar o programa\n"
         << "Digite a opcao desejada: ";

        string teste;
        cin >> teste;
        if (teste == "procurar") {
            return 1;
        }
        else if (teste == "inserir") {
            return 2;
        }
        else if (teste == "imprimir") {
            return 3;
        }
        else if(teste == "remover"){
            return 4;
        }
        else if (teste == "sair") {
            return 5;
        }
        return 0;
}


int main(int argc, char* argv[]) {
    acamp meusItens;
    meusItens.lerArquivo(argv[1]);
    unsigned int opcao = 0;
    string resposta;
    char nomeAux[50];
    while(opcao != 5) {
        opcao = menu();
        switch (opcao) {
            case 1:
                cout <<"Digite o nome que deseja procurar: ";
                cin.ignore();
                cin.getline(nomeAux, 50);
                cout << endl;
                meusItens.procurar(nomeAux);
                break;
            case 2:
                cout << endl;
                meusItens.inserir();
                cout << "Objeto inserido com sucesso\n";
                break;
            case 3:
                cout << "\nComo deseja imprimir os itens (1.armazenamento/2.alfabetica)? ";
                {
                    int opcao;
                    cin >> opcao;
                    cout << endl;
                    if (opcao == 1) {
                        meusItens.imprimirTudo();
                    }
                    else if (opcao == 2) {
                        meusItens.imprimirOrdenado();
                    }
                    else {
                        cout << "Opcao invalida\n";
                    }
                }
                break;
            case 4:
                cout << "Digite o nome do item para remover: ";
                cin.ignore();
                cin.getline(nomeAux, 50);
                cout << endl;
                meusItens.remover(nomeAux);
                break;
            case 0:
                cout << "Opcao invalida\n";
                break;
            default:
                meusItens.escreverArquivo(argv[1]);
                cout << "Finalizando programa\n";
        }
        cout << endl << endl;
    }

    return 0;
}
