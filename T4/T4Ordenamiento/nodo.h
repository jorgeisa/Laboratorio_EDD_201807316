#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <string.h>
using namespace std;

class Nodo
{
public:
    Nodo(string cadena);
    Nodo *getDerecha();
    Nodo *getIzquierda();
    void setDerecha(Nodo *derecha);
    void setIzquierda(Nodo *izquierda);
    void setVal(int val);
    void setCadena(string cadena);
    int getVal();
    string getCadena();

    int obtenerASCII();
private:
    Nodo *izquierda;
    Nodo *derecha;
    int val;
    string cadena;
};

#endif // NODO_H

