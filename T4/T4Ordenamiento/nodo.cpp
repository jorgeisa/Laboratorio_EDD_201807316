#include "nodo.h"

Nodo::Nodo(string cadena)
{
    this->cadena=cadena;
    this->val = obtenerASCII();
    this->derecha=NULL;
    this->izquierda=NULL;
}

//TAREA 4
string Nodo::getCadena(){return this->cadena;}
void Nodo::setCadena(string cadena){this->cadena=cadena;}

int Nodo::obtenerASCII(){
    int longitud = this->cadena.length();
    int codigo = 0;
    for (int i = 0; i < longitud; i++)
    {
        char x = this->cadena.at(i);
        codigo += int(x);
    }
    return codigo;
}
//

int Nodo::getVal(){return this->val;}
void Nodo::setVal(int val){this->val=val;}
void Nodo::setDerecha(Nodo *derecha){this->derecha=derecha;}
void Nodo::setIzquierda(Nodo *izquierda){this->izquierda=izquierda;}
Nodo* Nodo::getDerecha(){return this->derecha;}
Nodo* Nodo::getIzquierda(){return this->izquierda;}


