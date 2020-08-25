#include "nodo.h"


template<class DATA>
NodoAvl<DATA>::NodoAvl(DATA* data)
{
    this->data=data;
    this->derecha=NULL;
    this->izquierda=NULL;
}

template<class DATA>
void NodoAvl<DATA>::setData(DATA* data){
    this->data=data;
}

template<class DATA>
void NodoAvl<DATA>::setDerecha(NodoAvl* derecha){
    this->derecha = derecha;
}

template<class DATA>
void NodoAvl<DATA>::setIzquierda(NodoAvl* izquierda){
    this->izquierda=izquierda;
}

template<class DATA>
DATA* NodoAvl<DATA>::getData(){
    return this->data;
}

template<class DATA>
NodoAvl<DATA>* NodoAvl<DATA>::getIzquierda(){
    return this->izquierda;
}

template<class DATA>
NodoAvl<DATA>* NodoAvl<DATA>::getDerecha(){
    return this->derecha;
}
