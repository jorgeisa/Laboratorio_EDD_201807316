#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ListaC.h"
#include "NodoC.h"

int main(){
    /*El metodo imprimir ahora indica cuales son los valores de sus punteros
     izquierda y derecha.
    Si es el metodo get la impresion comenzara con la palabra get.
    Si es el metodo eliminar la impresion comenzara con la palabra eliminar.*/
    NodoA* a=newNodoC(2);
    NodoA* b=newNodoC(6);
    NodoC* c=newNodoC(10);
    NodoC* d=newNodoC(100);
    NodoC* e=newNodoC(56);

    NodoC* u=newNodoC(200);
    NodoC* v=newNodoC(250);
    NodoC* w=newNodoC(289);

    NodoC* x=newNodoC(1000);
    NodoC* y=newNodoC(1001);
    NodoC* z=newNodoC(1002);

    ListaC* l=nuevaLista();
    add(l,a);
    add(l,b);
    add(l,c);
    add(l,d);
    add(l,e);

    imprimir(l);

    //Metodo get "Recursivo"
    getRecursivo(l->head,0); // Obteniendo 2
    getRecursivo(l->head,4); // Obteniendo 100
    getRecursivo(l->head,2); // Obteniendo 10

    //Metodo eliminar "normal" no recursivo
    /*eliminar(l, 0); //eliminando 2
    eliminar(l, 2); //eliminando 56
    eliminar(l, 1); //eliminando 10
    eliminar(l, 1); //eliminando 100
    eliminar(l, 0); //eliminando 6*/

    //Metodo eliminar "recursivo"
    eliminarRecursivo(l->head,l,0);//eliminando 2
    eliminarRecursivo(l->head,l,2);//eliminando 56
    eliminarRecursivo(l->head,l,1);//eliminando 10

    getRecursivo(l->head, 25);//get invalido, indice no existe

    eliminarRecursivo(l->head,l,2);//Eliminacion invalida
    eliminarRecursivo(l->head,l,10);//Eliminacion invalida

    getRecursivo(l->head, 0);//get valido solo queda 6 y 100

    add(l,x);
    add(l,y);
    add(l,z);

    add(l,u);
    add(l,v);
    add(l,w);

    imprimir(l);
    generar(l);
    Liberar(l);
    free(l);
    return 0;
}



