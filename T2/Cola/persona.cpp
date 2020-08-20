#include "persona.h"

Persona::Persona(string nombre, int edad)
{
    this->nombre = nombre;
    this->edad = edad;
}

Persona::Persona(){}

int Persona::getEdad(){
    return  this->edad;
}

string Persona::getNombre(){
    return this->nombre;
}
