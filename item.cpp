#include <iostream>
#include <fstream>
#include <cstring>
#include "acamp.hpp"
using namespace std;

item::item() {
    //construtor que inicializa tudo com 0 ou vazio
    id = 0;
    strcpy(nome," ");
    strcpy(descricao," ");
    strcpy(utilidade," ");
    valor = 0.0f;
    prioridade = 0;
    strcpy(resistenciaAgua," ");
    strcpy(durabilidade," ");
    peso = 0.0f;
}