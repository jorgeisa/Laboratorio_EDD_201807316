#include <iostream>
#include "arbolbinario.h"
using namespace std;

int main()
{
    //Tarea 3 LAB-EDD
    //Jorge Isaac Xicol Vicente
    //201807316
    ArbolBinario* enteros = new ArbolBinario();

    enteros->insertarNodo(100);
    enteros->insertarNodo(50);
    enteros->insertarNodo(150);
    enteros->insertarNodo(25);
    enteros->insertarNodo(125);
    enteros->insertarNodo(75);
    enteros->insertarNodo(200);
    enteros->insertarNodo(12);
    enteros->insertarNodo(85);
    enteros->insertarNodo(135);
    enteros->insertarNodo(175);
    enteros->insertarNodo(178);
    enteros->insertarNodo(129);
    //enteros->eliminarNodo(100);
    enteros->eliminarNodo(129);
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
