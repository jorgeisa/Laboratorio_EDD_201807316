#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include <iostream>
#include "nodobinario.h"
#include "nodobinario.cpp"
using namespace std;

template<class DATA>
class ArbolBinario
{
public:
    ArbolBinario();
    ~ArbolBinario();
    NodoBinario<DATA>* getRaiz();
    void insertarNodo(DATA data);
    void eliminarNodo(DATA* data);
    void recorridoPreorden();
    void recorridoInorden();
    void recorridoPostorden();

private:
    NodoBinario<DATA>* raiz;

    void eliminarNodo(NodoBinario<DATA>* raiz, DATA* data);
    NodoBinario<DATA>* reemplazo(NodoBinario<DATA>* nodoActual);
    NodoBinario<DATA>* insertarNodo(NodoBinario<DATA>* raiz, DATA* data);
    void recorridoPreorden(NodoBinario<DATA>* raiz);
    void recorridoInorden(NodoBinario<DATA>* raiz);
    void recorridoPostorden(NodoBinario<DATA>* raiz);
};

#endif // ARBOLBINARIO_H
