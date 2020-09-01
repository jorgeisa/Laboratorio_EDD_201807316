#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include "nodo.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class ListaDoble
{
public:
    ListaDoble();
    ~ListaDoble();
    void insertarOrdenado(Nodo *nuevo);
    void insertarAlInicio(Nodo *nuevo);
    void ordenamientoSeleccion();
    string generar();
    string generar(Nodo* aux);
    void imprimir();

private:
    void ordenamientoSeleccion(Nodo *cabeza);
    Nodo* head;
};

#endif // LISTADOBLE_H
