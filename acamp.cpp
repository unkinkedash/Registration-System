#include <iostream>
#include <fstream>
#include <cstring>
#include "acamp.hpp"
#include "item.hpp"
using namespace std;

istream& operator>>(istream& input, item& dado){//sobrecarga de leitura
    cout << "ID: ";
    input >> dado.id;
    input.ignore();
    cout << "Nome: ";
    input.getline(dado.nome, 50);
    cout << "Descricao: ";
    input.getline(dado.descricao, 200);
    cout << "Utilidade: ";
    input.getline(dado.utilidade, 100);
    cout << "Valor: ";
    input >> dado.valor;
    cout << "Prioridade: ";
    input >> dado.prioridade;
    cout << "Resistencia a agua: ";
    input >> dado.resistenciaAgua;
    cout << "Durabilidade: ";
    input >> dado.durabilidade;
    cout << "Peso: ";
    input >> dado.peso;
    return input;
}

ostream& operator<<(ostream& output, const item& dado) {//sobrecarga de escrita
    output << "Identificador: " << dado.id << endl
           << "Nome: " << dado.nome << endl
           << "Descricao: " << dado.descricao << endl
           << "Utilidade: " << dado.utilidade << endl
           << "Valor: " << dado.valor << endl
           << "Prioridade: " << dado.prioridade << endl
           << "Resistencia a agua: " << dado.resistenciaAgua << endl
           << "Durabilidade: " << dado.durabilidade << endl
           << "Peso: " << dado.peso << endl << endl;
    return output;
}

acamp::acamp() {
    quantidade = 0;
    capacidade = 5;
    dados = new item[5];
}

acamp::~acamp() {
    cout << "Estou chamando o destrutor\n";
    delete[] dados;
}

item* acamp::realocarVetor() {
    capacidade += 5;
    item* vetDados = new item[capacidade];
    for (int i = 0; i < (capacidade-5); ++i) {
        vetDados[i] = dados[i];
    }
    delete[] dados;
    return vetDados;
}

void acamp::inserir() {
    item dado;
    cin >> dado;

    if (quantidade == capacidade) {
        dados = realocarVetor();
    }

    dados[quantidade] = dado;
    ++quantidade;
}


void acamp::imprimirItem(const item& dado) {
    cout << dado;
}

void acamp::remover(char* nomeProc) {
    //receber um paramentro para buscar
    int pos = 0;
    bool naoAchou = true;
    while ((pos < quantidade) and (naoAchou)) {
        if (strcmp(dados[pos].nome, nomeProc) == 0) {
            naoAchou = false;
        }
        else {
            ++pos;
        }
    }

    if (naoAchou) {
        cout << "Item nao encontrado, por favor tente novamente\n";
    }
    else {
        for (int i = pos; i < quantidade; ++i) {
            dados[i] = dados[i+1];
        }
        cout << "Item removido com sucesso!\n";
        --quantidade;
    }
}

void acamp::procurar(char* nomeProc) {
    bool naoAchou = true;
    int pos = 0;
    while ((pos < quantidade) and (naoAchou)) {
        if (strcmp(dados[pos].nome, nomeProc) == 0) {
            naoAchou = false;
        }
        else {
            ++pos;
        }
    }

    if (naoAchou) {
        cout << "Item nao encontrado, favor tentar novamente\n" << endl;
    }
    else {
        imprimirItem(dados[pos]);
    }
}

void acamp::imprimirTudo() {
    for (int i = 0; i < quantidade; ++i) {
        imprimirItem(dados[i]);
    }
}

void acamp::Juntar(item* vetor, int ini, int meio, int fim, item* aux) {
    int esq = ini;
    int dir = meio;
    for (int i = ini; i < fim; ++i) {
        if ((esq < meio) and ((dir >= fim) or (strcmp(vetor[esq].nome, vetor[dir].nome) < 0))) {
            aux[i] = vetor[esq];
            ++esq;
        }
        else {
            aux[i] = vetor[dir];
            ++dir;
        }
    }

    for (int i = ini; i < fim; ++i) {
        vetor[i] = aux[i];
    }
}

void acamp::MergeSort(item* vetor, int inicio, int fim, item* aux) {
    if ((fim - inicio) > 1) {
        int meio = (inicio+fim)/2;
        MergeSort(vetor, inicio, meio, aux);
        MergeSort(vetor, meio, fim, aux);
        Juntar(vetor, inicio, meio, fim, aux);
    }
}

void acamp::MergeSort(item* vetor, int tamanho) {
    item* aux = new item[tamanho];
    MergeSort(vetor, 0, tamanho, aux);
    delete[] aux;
}


void acamp::imprimirOrdenado() {
    item* vetAux = new item[quantidade];
    for (int i = 0; i < quantidade; ++i) {
        vetAux[i] = dados[i];
    }

    MergeSort(vetAux, quantidade);
    for (int i = 0; i < quantidade; ++i) {
        imprimirItem(vetAux[i]);
    }

    delete[] vetAux;
}

void acamp::lerArquivo(char* nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    if (not arquivo) {
        ofstream arquivo(nomeArquivo);
        arquivo.write(reinterpret_cast<char*>(&quantidade), sizeof(int));
        cout << "Arquivo nao aberto" << endl;
    }
    else {
        arquivo.read(reinterpret_cast<char*>(&quantidade), sizeof(int));
        for (int i = 0; i < quantidade ; ++i) {
            if (i == capacidade) {
                dados = realocarVetor();
            }
            arquivo.read(reinterpret_cast<char*>(&dados[i]),sizeof(item));
        }
    }
    arquivo.close();
}
void acamp::escreverArquivo(char* nomeArquivo) {
    ofstream arquivo(nomeArquivo);
    if (arquivo){
        arquivo.write(reinterpret_cast<char*>(&quantidade), sizeof(int));
        for (int i = 0; i < quantidade; ++i) {
            arquivo.write(reinterpret_cast<char*>(&dados[i]),sizeof(item));
        }
    }
    else {
        cout << "Erro, nao conseguimos abrir o arquivo para escrita\n" <<endl;
    }
    arquivo.close();
}
