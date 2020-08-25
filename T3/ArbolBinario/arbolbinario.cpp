#include "arbolbinario.h"

ArbolBinario::ArbolBinario()
{
    this->raiz=NULL;
}

ArbolBinario::~ArbolBinario(){

}

nodoBinario* ArbolBinario::getRaiz(){
    return this->raiz;
}

void ArbolBinario::insertarNodo(int data){
    this->raiz = insertarNodo(this->raiz, data);
    cout<<"Usted ha insertado el elemento.\n"<<endl;
}

nodoBinario* ArbolBinario::insertarNodo(nodoBinario* raiz, int data){
    if(raiz==NULL){//Si esta vacio
        nodoBinario* nuevo = new nodoBinario(data);
        raiz = nuevo;
    }else if(data < raiz->getData()){//Si esta lleno o al menos con un elemento
        //Si la data es menor a la raiz
        nodoBinario* izquierda;
        izquierda = insertarNodo(raiz->getIzquierda(), data);
        raiz->setIzquierda(izquierda);
    }else if(data > raiz->getData()){
        //Si la data es mayor a la raiz
        nodoBinario* derecha;
        derecha = insertarNodo(raiz->getDerecha(),data);
        raiz->setDerecha(derecha);
    }
    return raiz;
}

void ArbolBinario::eliminarNodo(int data){
    this->raiz = eliminarNodo(this->raiz, data);
}

nodoBinario* ArbolBinario::eliminarNodo(nodoBinario* raiz, int data){
    if(raiz==NULL){
        cout<<"Vacio o no se ha encontrado.";
        return NULL;
    }else if(data < raiz->getData()){//El dato sea menor a
        nodoBinario* izquierda;
        izquierda = eliminarNodo(raiz->getIzquierda(), data);
        raiz->setIzquierda(izquierda);

    }else if(data > raiz->getData()){//El dato sea mayor a
        nodoBinario* derecha;
        derecha = eliminarNodo(raiz->getDerecha(), data);
        raiz->setDerecha(derecha);

    }else{//Dato ya fue encontrado

        nodoBinario* temp = raiz;
        if(temp->getDerecha() == NULL && temp->getIzquierda()== NULL){
            //tengo que eliminar el nodo que encontre
            raiz = NULL;
        }else if(temp->getIzquierda()==NULL){//Solamente el subarbol derecho
            raiz = temp->getDerecha();
        }else if(temp->getDerecha()==NULL){//Solamente el subarbol izquierdo
            raiz = temp->getIzquierda();
        }else{//Tiene ambos subarboles
            temp = reemplazo(temp); //temp = raiz
        }
        //temp->setDerecha(NULL);
        //temp->setIzquierda(NULL);
        delete(temp);
    }
    return raiz;
}

nodoBinario* ArbolBinario::reemplazo(nodoBinario* nodoActual){
    nodoBinario *primero, *segundo;

    primero = nodoActual;
    segundo = primero->getIzquierda(); // Rama de menores, hacia la izquierda
    while(segundo->getDerecha()!=NULL){
        primero = segundo; //Corro primero hacia segundo
        segundo = segundo->getDerecha(); //Corro segundo hacia la derecha
    }

    nodoActual->setData(segundo->getData()); //El valor se traslada a valor de nodo a eliminar
    if(primero==nodoActual){// No se movieron los punteros
        primero->setIzquierda(segundo->getIzquierda());
    }else{//Se movieron los punteros
        primero->setDerecha(segundo->getIzquierda());
    }
    return segundo;
}

//Recorrido Preorden NID
void ArbolBinario::recorridoPreorden(){
    cout<<"\nRecorrido PreOrden NID:"<<endl;
    recorridoPreorden(this->raiz);
    cout<<"\n";
}

//Recorrido Inorden IND
void ArbolBinario::recorridoInorden(){
    cout<<"\nRecorrido Inorden IND:"<<endl;
    recorridoInorden(this->raiz);
    cout<<"\n";
}

//Recorrido Postorden IDN
void ArbolBinario::recorridoPostorden(){
    cout<<"\nRecorrido Postorden IDN:"<<endl;
    recorridoPostorden(this->raiz);
    cout<<"\n";
}

//Recorrido NID Preorden
void ArbolBinario::recorridoPreorden(nodoBinario* raiz){
    if(raiz!=NULL){
        raiz->visitarNodo();
        recorridoPreorden(raiz->getIzquierda());
        recorridoPreorden(raiz->getDerecha());
    }
}

//Recorrido IND Inorden
void ArbolBinario::recorridoInorden(nodoBinario* raiz){
    if(raiz!=NULL){
        recorridoInorden(raiz->getIzquierda());
        raiz->visitarNodo();
        recorridoInorden(raiz->getDerecha());
    }
}

//Recorrido IDN Postorden
void ArbolBinario::recorridoPostorden(nodoBinario* raiz){
    if(raiz!=NULL){
        recorridoPostorden(raiz->getIzquierda());
        recorridoPostorden(raiz->getDerecha());
        raiz->visitarNodo();
    }
}


