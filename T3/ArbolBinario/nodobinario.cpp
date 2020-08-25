#include "nodobinario.h"

template<class DATA>
NodoBinario<DATA>::NodoBinario(DATA* data)
{
    this->data=data;
    this->derecha=NULL;
    this->izquierda=NULL;
}

template<class DATA>
void NodoBinario<DATA>::setData(DATA* data){
    this->data=data;
}

template<class DATA>
void NodoBinario<DATA>::setDerecha(NodoBinario* derecha){
    this->derecha = derecha;
}

template<class DATA>
void NodoBinario<DATA>::setIzquierda(NodoBinario* izquierda){
    this->izquierda=izquierda;
}

template<class DATA>
DATA* NodoBinario<DATA>::getData(){
    return this->data;
}

template<class DATA>
NodoBinario<DATA>* NodoBinario<DATA>::getIzquierda(){
    return this->izquierda;
}

template<class DATA>
NodoBinario<DATA>* NodoBinario<DATA>::getDerecha(){
    return this->derecha;
}

template <class DATA>
void NodoBinario<DATA>::visitarNodo(){
    cout<<this->getData()<<endl;
}

