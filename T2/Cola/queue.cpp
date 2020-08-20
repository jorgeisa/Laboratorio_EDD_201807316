#include "queue.h"
#include "persona.h"

template<class T>
Queue<T>::Queue()
{
    this->top=NULL;
    this->bottom=NULL;
}

template<class T>
Queue<T>::~Queue(){
    NodoGenerico<T>*aux=this->top;
    NodoGenerico<T>*tmp=NULL;
    while(aux!=NULL){
        tmp=aux->getSiguiente();
        delete aux;
        aux=tmp;
    }
}


//METODO AGREGAR COLA PRIORIDAD
//TAREA 2   201807316 - Jorge Isaac Xicol V.
template<class T>
void Queue<T>::enqueue(T* valor){
    if(this->top==NULL){
        NodoGenerico<T> *nuevo=new NodoGenerico<T>(valor);
        this->top=nuevo;
        this->bottom=nuevo;
    }else{
        NodoGenerico<T>*nuevo=new NodoGenerico<T>(valor);
        if(valor->getEdad()>65){
            //Si tiene +65
            nuevo->setSiguiente(this->top);
            this->top = nuevo;
        }else{
            //De lo contrario hasta el el final
            NodoGenerico<T>*aux=this->bottom;
            aux->setSiguiente(nuevo);
            this->bottom=nuevo;
        }
    }
}

template <class T>
NodoGenerico<T>* Queue<T>::dequeue(){
    if(top==NULL){return NULL;}
    NodoGenerico<T>*aux=top;
    top=top->getSiguiente();
    return aux;
}

template<class T>
void Queue<T>::vaciar(){
    cout<<"\nVaciando Cola!\n"<<endl;
    NodoGenerico<T>*aux=this->top;
    NodoGenerico<T>*tmp;
    while(aux!=NULL){
        //cout<<aux->getValue()<<"\n";
        tmp=aux->getSiguiente();
        delete aux;
        aux=tmp;
    }
}

//METODO IMPRIMIR DATOS DE PERSONAS
//TAREA 2   201807316 - Jorge Isaac Xicol V.
template<class T>
void Queue<T>::imprimirPersonas(){
    cout<<"Cola de personas son: "<<endl;
    NodoGenerico<T>*aux = this->top;
    int cont = 0;
    while(aux!=NULL){
        cont++;
        cout<<"Persona: "<<cont<<endl;
        cout<<"Edad:"<<aux->getValue()->getEdad()<<endl;
        cout<<"Nombre:"<<aux->getValue()->getNombre()<<"\n"<<endl;
        aux = aux->getSiguiente();
    }
}





