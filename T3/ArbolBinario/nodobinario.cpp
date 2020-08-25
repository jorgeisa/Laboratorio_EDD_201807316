#include "nodobinario.h"

nodoBinario::nodoBinario(int data)
{
    this->data=data;
    this->derecha=NULL;
    this->izquierda=NULL;
}

nodoBinario::~nodoBinario(){
    cout<<"\nNodo Eliminado\n"<<endl;
}

void nodoBinario::setData(int data){
    this->data=data;
}


void nodoBinario::setDerecha(nodoBinario* derecha){
    this->derecha = derecha;
}


void nodoBinario::setIzquierda(nodoBinario* izquierda){
    this->izquierda=izquierda;
}

int nodoBinario::getData(){
    return this->data;
}

nodoBinario* nodoBinario::getIzquierda(){
    return this->izquierda;
}

nodoBinario* nodoBinario::getDerecha(){
    return this->derecha;
}

void nodoBinario::visitarNodo(){
    cout<<this->getData()<<" , ";
}
