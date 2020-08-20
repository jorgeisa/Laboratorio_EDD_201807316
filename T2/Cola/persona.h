#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <string.h>
using namespace std;


class Persona
{
private:
    string nombre;
    int edad;
public:
    Persona(string, int);
    Persona();
    ~Persona();
    string getNombre();
    int getEdad();
};

#endif // PERSONA_H
