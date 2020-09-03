#include "listadoble.h"
#include "nodo.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    //TAREA 4 - Ordenamiento por Seleccion , 201807316 - Jorge Isaac Xicol Vicente

    ListaDoble *list=new ListaDoble();
    Nodo *a,*b,*c,*d,*e,*f,*g; //*h,*i,*j, *k, *l, *m, *n, *o;
    a=new Nodo("$$$$$$$$$#$$$$$");
    //80 97 108 97 98 114 97 49 = 740
    b=new Nodo("ESTE ES UN MENSAJE");
    //80 97 108 97 98 114 97 50 = 741
    c=new Nodo("Yo bien gracias");
    // 77 97 114 118 105 110 = 621
    d=new Nodo("Hola como estas");
    // 78 111 = 189
    e=new Nodo("!!!!Vamos a sacar 100");
    // 77 101 32 98 97 106 101 115 32 112 117 110 116 111 115 = 1440
    f=new Nodo("Vamos a ganar EDD todos juntos");
    // 80 111 114 32 102 97 118 111 114 32 58 40 = 1009
    g=new Nodo("Este es el ultimo mensaje del dia de hoy*45");
    // 69 115 32 98 114 111 109 97 44 32 115 97 +
    // 108 117 100 111 115 32 77 97 114 118 105 110 32 58 68 = 2395
//    h=new Nodo(354);
//    i=new Nodo(1);
//    j=new Nodo(55);

//    k=new Nodo(30);
//    l=new Nodo(2);
//    m=new Nodo(9);
//    n=new Nodo(15);
//    o=new Nodo(10);

    list->insertarAlInicio(a);
    list->insertarAlInicio(b);
    list->insertarAlInicio(c);
    list->insertarAlInicio(d);
    list->insertarAlInicio(e);
    list->insertarAlInicio(f);
    list->insertarAlInicio(g);
//    list->insertarAlInicio(h);
//    list->insertarAlInicio(i);
//    list->insertarAlInicio(j);
//    list->insertarAlInicio(k);
//    list->insertarAlInicio(l);
//    list->insertarAlInicio(m);
//    list->insertarAlInicio(n);
//    list->insertarAlInicio(o);

    cout<<"\nLista no ordenada:"<<endl;
    list->imprimir();
    list->ordenamientoSeleccion();
    cout<<"\nLista Ordenada:"<<endl;
    list->imprimir();
    ofstream file("salida.dot");
    file<<list->generar();
    file.close();
    system("dot -Tpng salida.dot -o imagen.png");
    delete list;
    return 0;
}
