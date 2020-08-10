#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "NodoC.h"
typedef struct ListaC
{
    NodoC* head;

}ListaC;

ListaC* nuevaLista();
void add(ListaC* l,NodoC* nuevo);
void imprimir(ListaC* l);
void generar(ListaC* l);

void Liberar(ListaC* l);
void guardarRecursivo(NodoC* aux,FILE *fp,char *c);

//TAREA LABORATORIO
//201807316
void eliminar(ListaC*, int);
void eliminarRecursivo(NodoC*, ListaC*, int);
void getRecursivo(NodoC*, int);
