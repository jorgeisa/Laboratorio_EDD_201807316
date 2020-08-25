#ifndef NODOBINARIO_H
#define NODOBINARIO_H
#include <iostream>
using namespace std;

template<class DATA>
class NodoBinario
{
public:
    NodoBinario(DATA* data);
    void setData(DATA* data);
    void setDerecha(NodoBinario* derecha);
    void setIzquierda(NodoBinario* izquierda);

    DATA* getData();
    NodoBinario* getIzquierda();
    NodoBinario* getDerecha();

    void visitarNodo();
private:
    DATA* data;
    NodoBinario* derecha;
    NodoBinario* izquierda;
};

#endif // NODOBINARIO_H
