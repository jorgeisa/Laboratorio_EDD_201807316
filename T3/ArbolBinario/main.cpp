#include <iostream>
#include "arbolbinario.h"
using namespace std;

int main()
{
    //Tarea 3 LAB-EDD
    //Jorge Isaac Xicol Vicente
    //201807316
    ArbolBinario* enteros = new ArbolBinario();

    enteros->insertarNodo(10);
    enteros->insertarNodo(1);
    enteros->insertarNodo(20);
    enteros->insertarNodo(15);
    enteros->insertarNodo(8);
    enteros->insertarNodo(96);
    enteros->insertarNodo(23);
    enteros->insertarNodo(4);
    enteros->insertarNodo(7);
    enteros->insertarNodo(32);
    //RAIZ:
    cout<<"\nLa raiz es:"<<enteros->getRaiz()->getData()<<endl;

    //PREORDEN NID
    enteros->recorridoPreorden();
    cout<<"\n";
    //INORDEN IND
    enteros->recorridoInorden();
    cout<<"\n";
    //POSTORDEN IDN
    enteros->recorridoPostorden();
    cout<<"\n";
    cout << "Hello World!" << endl;
    return 0;
}
