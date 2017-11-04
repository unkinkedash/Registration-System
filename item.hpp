#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
using namespace std;

class item {
private:
    //colocando a classe acampamento como amiga para que ela possa
    //acessar os atributos de item
    unsigned int id;
    char nome[50];
    char descricao[200];
    char utilidade[100];
    float valor;
    int prioridade;
    char resistenciaAgua[10];
    char durabilidade[10];
    float peso;
    friend ostream& operator<<(ostream& output, const item& dado);
    friend istream& operator>>(istream& input, item& dado);
    friend class acamp;
public:
    item();
};

#endif
