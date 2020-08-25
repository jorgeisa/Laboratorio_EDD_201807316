#include "arbolbinario.h"

template<class DATA>
ArbolBinario<DATA>::ArbolBinario()
{
    this->raiz=NULL;
}

template <class DATA>
ArbolBinario<DATA>::~ArbolBinario(){

}

template <class DATA>
NodoBinario<DATA>* ArbolBinario<DATA>::getRaiz(){
    return this->raiz;
}

template<class DATA>
void ArbolBinario<DATA>::insertarNodo(DATA data){
    DATA* dataP= &data;
    this->raiz = insertarNodo(this->raiz, dataP);
    cout<<"Usted ha insertado el elemento.\n"<<endl;
}

template<class DATA>
NodoBinario<DATA>* ArbolBinario<DATA>::insertarNodo(NodoBinario<DATA>* raiz, DATA* data){
    if(raiz==NULL){//Si esta vacio
        NodoBinario<DATA>* nuevo = new NodoBinario<DATA>(data);
        raiz = nuevo;
    }else if(data < raiz->getData()){//Si esta lleno o al menos con un elemento
        //Si la data es menor a la raiz
        NodoBinario<DATA>* izquierda;
        izquierda = insertarNodo(raiz->getIzquierda(), data);
        raiz->setIzquierda(izquierda);
    }else if(data > raiz->getData()){
        //Si la data es mayor a la raiz
        NodoBinario<DATA>* derecha;
        derecha = insertarNodo(raiz->getDerecha(),data);
        raiz->setDerecha(derecha);
    }
    return raiz;
}

template <class DATA>
void ArbolBinario<DATA>::eliminarNodo(DATA* data){
    DATA* dataP=&data;
    eliminarNodo(this->raiz, dataP);

}

template <class DATA>
void ArbolBinario<DATA>::eliminarNodo(NodoBinario<DATA>* raiz, DATA* data){
    if(this->raiz==NULL){
        cout<<"Vacio o no se ha encontrado.";
        return;
    }else if(data < raiz->getData()){
        eliminarNodo(raiz->getIzquierda(), data);
    }else if(data > raiz->getData()){
        eliminarNodo(raiz->getDerecha(), data);
    }else{
        //ya fue encontrado
        NodoBinario<DATA>* temp = raiz;
        if(temp->getDerecha() == NULL && temp->getIzquierda()== NULL){
            //tengo que eliminar el nodo que encontre
        }else if(temp->getIzquierda()==NULL){//Solamente el subarbol derecho
            raiz = temp->getDerecha();
        }else if(temp->getDerecha()==NULL){//Solamente el subarbol izquierdo
            raiz = temp->getIzquierda();
        }else{//Tiene ambos subarboles
            temp = reemplazo(temp); //temp = raiz
        }
        temp->setDerecha(NULL);
        temp->setIzquierda(NULL);
        delete(temp);
    }
}


template <class DATA>
NodoBinario<DATA>* ArbolBinario<DATA>::reemplazo(NodoBinario<DATA>* nodoActual){
    NodoBinario<DATA> *primero, *segundo;

    primero = nodoActual;
    segundo = primero->getIzquierda(); // Rama de menores, hacia la izquierda
    while(segundo->getDerecha()!=NULL){
        primero = segundo; //Corro primero hacia segundo
        segundo = segundo->getDerecha(); //Corro segundo hacia la derecha
    }

    nodoActual->setData(segundo->getData()); //El valor se traslada a valor de nodo a eliminar
    if(primero==nodoActual){
        primero->setIzquierda(segundo->getIzquierda());
    }else{
        primero->setDerecha(segundo->getIzquierda());
    }
    return segundo;
}

//Recorrido Inorden IND
template <class DATA>
void ArbolBinario<DATA>::recorridoInorden(){
    recorridoInorden(this->raiz);
}

//Recorrido Postorden IDN
template <class DATA>
void ArbolBinario<DATA>::recorridoPostorden(){
    recorridoPostorden(this->raiz);
}

//Recorrido Preorden NID
template <class DATA>
void ArbolBinario<DATA>::recorridoPreorden(){
    recorridoPreorden(this->raiz);
}

//Recorrido IND Inorden
template <class DATA>
void ArbolBinario<DATA>::recorridoInorden(NodoBinario<DATA>* raiz){
    if(this->raiz==NULL){
        cout<<"Esta vacia!\n"<<endl;
        return;
    }else{
        recorridoInorden(raiz->getIzquierda());
        raiz->visitarNodo();
        recorridoInorden(raiz->getDerecha());
    }
}

//Recorrido IDN Postorden
template <class DATA>
void ArbolBinario<DATA>::recorridoPostorden(NodoBinario<DATA>* raiz){
    if(this->raiz==NULL){
        cout<<"Esta vacia!\n";
        return;
    }else{
        recorridoPostorden(raiz->getIzquierda());
        recorridoPostorden(raiz->getDerecha());
        raiz->visitarNodo();
    }
}

//Recorrido NID Preorden
template <class DATA>
void ArbolBinario<DATA>::recorridoPreorden(NodoBinario<DATA>* raiz){
    if(this->raiz==NULL){
        cout<<"Esta vacia!\n"<<endl;
    }else{
        raiz->visitarNodo();
        recorridoPreorden(raiz->getIzquierda());
        recorridoPreorden(raiz->getDerecha());
    }
}





