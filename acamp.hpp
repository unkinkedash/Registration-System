#ifndef ACAMP_HPP
#define ACAMP_HPP

#include <iostream>
#include <fstream>
#include "item.hpp"
using namespace std;

class acamp {
private:
    item* dados;
    int quantidade;
    int capacidade;
public:
    acamp();
    ~acamp();
    void inserir();
    item* realocarVetor();
    void imprimirItem(const item& dado);
    void remover(char* nomeProc);
    void procurar(char* nomeProc);
    void imprimirTudo();
    void Juntar(item* valor, int ini, int meio, int fim, item* aux);
    void MergeSort(item* vetor, int inicio, int fim, item* aux);
    void MergeSort(item* vetor, int tamanho);
    void imprimirOrdenado();
    void lerArquivo(char* nomeArquivo);
    void escreverArquivo(char* nomeArquivo);
};

#endif
