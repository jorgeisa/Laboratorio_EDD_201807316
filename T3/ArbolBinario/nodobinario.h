#ifndef NODOBINARIO_H
#define NODOBINARIO_H
#include <iostream>

using namespace std;

class nodoBinario
{
public:
    nodoBinario(int data);
    ~nodoBinario();
    void setData(int data);
    void setDerecha(nodoBinario* derecha);
    void setIzquierda(nodoBinario* izquierda);

    int getData();
    nodoBinario* getIzquierda();
    nodoBinario* getDerecha();

    void visitarNodo();
private:
    int data;
    nodoBinario* derecha;
    nodoBinario* izquierda;
};

#endif // NODOBINARIO_H
