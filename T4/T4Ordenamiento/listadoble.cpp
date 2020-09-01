#include "listadoble.h"

ListaDoble::ListaDoble()
{
    this->head=NULL;
}
ListaDoble::~ListaDoble(){
    Nodo* aux=this->head;
    Nodo* tmp;
    while(aux!=NULL){
        tmp=aux->getDerecha();
        delete aux;
        aux=tmp;
    }
}

void ListaDoble::insertarOrdenado(Nodo *nuevo){
    if(this->head==NULL){
        this->head=nuevo;
    }else{
        int valorcabeza=this->head->getVal();
        int valornuevo=nuevo->getVal();
        if(valornuevo<=valorcabeza){
            nuevo->setDerecha(this->head);
            this->head->setIzquierda(nuevo);
            this->head=nuevo;
        }else{
            Nodo* aux=this->head;
            while(aux!=NULL){
                if(aux->getIzquierda()!=NULL){
                    if(valornuevo>aux->getIzquierda()->getVal()&&valornuevo<=aux->getVal()){
                        Nodo *izq=aux->getIzquierda();
                        Nodo *der=aux;
                        izq->setDerecha(nuevo);
                        nuevo->setIzquierda(izq);
                        nuevo->setDerecha(der);
                        der->setIzquierda(nuevo);
                        break;
                    }
                }
                if(aux->getDerecha()==NULL){
                    aux->setDerecha(nuevo);
                    nuevo->setIzquierda(aux);
                    break;
                }
                aux=aux->getDerecha();
            }
        }
    }
}

//TAREA 4
void ListaDoble::insertarAlInicio(Nodo *nuevo){
    if(this->head==NULL){
        this->head = nuevo;
    }else{
        nuevo->setDerecha(this->head);
        this->head->setIzquierda(nuevo);
        this->head = nuevo;
    }
}


string ListaDoble::generar(){
    ostringstream cadena;
    cadena<<"digraph G {"<<endl<<"node[shape=\"record\"];"<<endl;
    cadena<<"rankdir=LR;"<<endl;
    cadena<<generar(this->head)<<endl;
    cadena<<"}"<<endl;
    return cadena.str();
}

string ListaDoble::generar(Nodo* aux){
    ostringstream cadena;
    if(aux!=NULL){
        cadena<<"nodo"<<&(*aux)<<"[label=\""<<aux->getVal()<<"\"];"<<endl;
        Nodo* siguiente=aux->getDerecha();
        //Creacion de nodos

        cadena<< (siguiente==NULL?"":generar(siguiente));
        //Union de nodos
        if(siguiente!=NULL){
            cadena<<"nodo"<<&(*siguiente)<<"->nodo"<<&(*aux)<<";"<<endl;
            cadena<<"nodo"<<&(*aux)<<"->nodo"<<&(*siguiente)<<";"<<endl;
        }
    }
    return cadena.str();
}

void ListaDoble::imprimir(){
    Nodo* aux=this->head;
    while(aux!=NULL){
        cout<<"Elemento Cadena : "<<aux->getCadena()<<endl;
        cout<<"Elemento ASCII: "<<aux->getVal()<<endl;
        aux=aux->getDerecha();
    }
    cout<<"------------------------------"<<endl;
}


//TAREA 4 - 201807316
void ListaDoble::ordenamientoSeleccion(){
    ordenamientoSeleccion(this->head);
}

void ListaDoble::ordenamientoSeleccion(Nodo *cabeza){
    Nodo *minimo;
    int aux;
    while(cabeza != NULL){
        minimo = cabeza;

        Nodo *siguienteActual = cabeza->getDerecha(); //Elemento que le sigue al actual
        while(siguienteActual != NULL){ //Recorro desde el elemento que le sigue

            if(siguienteActual->getVal()<minimo->getVal()){ //comparo la cabeza con cada valor que le sigue
                minimo = siguienteActual;
            }

            siguienteActual = siguienteActual->getDerecha(); //Recorro hacia el siguiente 2do While
        }
        //Cambio valores
        aux = cabeza->getVal();
        cabeza->setVal(minimo->getVal());
        minimo->setVal(aux);

        cabeza = cabeza->getDerecha(); //Recorro hacia el siguiente 1er While
    }
}
