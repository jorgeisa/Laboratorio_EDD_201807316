#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include <iostream>
#include "nodobinario.h"

class ArbolBinario
{
public:
    ArbolBinario();
    ~ArbolBinario();
    nodoBinario* getRaiz();
    void insertarNodo(int data);
    void eliminarNodo(int data);
    void recorridoPreorden();
    void recorridoInorden();
    void recorridoPostorden();

private:
    nodoBinario* raiz;

    nodoBinario* eliminarNodo(nodoBinario* raiz, int data);
    nodoBinario* reemplazo(nodoBinario* nodoActual);
    nodoBinario* insertarNodo(nodoBinario* raiz, int data);
    void recorridoPreorden(nodoBinario* raiz);
    void recorridoInorden(nodoBinario* raiz);
    void recorridoPostorden(nodoBinario* raiz);
};

#endif // ARBOLBINARIO_H
