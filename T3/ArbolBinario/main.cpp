#include <iostream>
#include "arbolbinario.h"
#include "arbolbinario.cpp"
using namespace std;



int main()
{
    ArbolBinario<int>* enteros = new ArbolBinario<int>();

    enteros->insertarNodo(70);
    enteros->insertarNodo(35);
    enteros->insertarNodo(65);
    cout<<enteros->getRaiz()<<endl;
    //enteros->recorridoPreorden();
    //enteros->eliminarNodo(11);
    cout << "Hello World!"<<endl;
    return 0;
}
//1.4.2.5.10
