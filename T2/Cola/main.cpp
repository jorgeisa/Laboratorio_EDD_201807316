#include <iostream>
#include "queue.h"
#include "queue.cpp"
#include "persona.h"
using namespace std;

int main()
{
    //TAREA 2 - 201807316 - Jorge Isaac Xicol Vicente
    cout << "Hello World!\n" << endl;
    Queue<Persona>*cola=new Queue<Persona>();
    //Queue<Persona>*cola2=new Queue<Persona>();
    Persona *p1 = new Persona("Dilan", 18);
    Persona *p2 = new Persona("Jose", 24);
    Persona *p3 = new Persona("Daniel", 35);
    Persona *p4 = new Persona("Huriel", 66);
    Persona *p5 = new Persona("Brandon", 70);
    Persona *p6 = new Persona("Javier", 75);
    cola->enqueue(p1);
    cola->enqueue(p2);
    cola->enqueue(p3);
    cola->enqueue(p4);
    cola->enqueue(p5);
    cola->enqueue(p6);
    //cola2->enqueue("hola");
    //cola2->enqueue("como");
    //cola->imprimirPersonas();
    //cout<<cola->dequeue()<<endl;
    //cout<<cola->dequeue()<<endl;
    //cout<<cola2->dequeue()->getValue()<<endl;
    cola->imprimirPersonas();
    cola->vaciar();
    delete cola;
    return 0;
}
