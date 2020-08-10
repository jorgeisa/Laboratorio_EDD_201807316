#include "ListaC.h"

void add(ListaC* l,NodoC* nuevo){
    if(l->head==NULL){
        l->head=nuevo;
    }else if(nuevo->val<=l->head->val){
        nuevo->derecha=l->head;
        l->head->izquierda=nuevo;
        l->head=nuevo;
    }else{
        NodoC* aux=l->head;
        while(aux->derecha!=NULL){
            if(aux->val>nuevo->val){
                NodoC* ant=aux->izquierda;
                ant->derecha=nuevo;
                nuevo->izquierda=ant;
                nuevo->derecha=aux;
                aux->izquierda=nuevo;
                return;
            }else if(nuevo->val<=aux->derecha->val){
                NodoC *siguiente=aux->derecha;
                aux->derecha=nuevo;
                nuevo->izquierda=aux;
                nuevo->derecha=siguiente;
                siguiente->izquierda=nuevo;
                return;
            }
            aux=aux->derecha;
        }
        aux->derecha=nuevo;
        nuevo->izquierda=aux;
    }
}

void Liberar(ListaC* l){
    NodoA* aux=l->head;
    NodoA* tmp;
    while(aux!=NULL){
        tmp=aux->derecha;
        free(aux);
        aux=tmp;
    }
}

void imprimir(ListaC* l){
    NodoA* aux=l->head;
    printf("\nImprimiendo todos los Nodos: \n\n");
    while(aux!=NULL){
        printf("El valor es %i \n",aux->val);

        if(aux->izquierda!=NULL){
            printf("El valor izquierdo es: %i \n", aux->izquierda->val);
        }
        if(aux->derecha!=NULL){
            printf("El valor derecho es: %i \n\n", aux->derecha->val);
        }
        aux=aux->derecha;
    }
}


ListaC* nuevaLista(){
    ListaC* nueva=(ListaC*) malloc(sizeof(ListaC));
    nueva->head=NULL;
    return nueva;
}


void generar(ListaC* l){
    FILE * fp;
    fp=fopen("./cadigo.txt","w");
    if(fp==NULL){
        printf("Error");
        return;
    }
    char cad[1024];
    sprintf(cad,"digraph G{\n rankdir=\"LR\" \n node[shape=\"cylinder\", fillcolor=\"mediumseagreen\", style=\"filled\"];"
                "\ngraph[splines=\"ortho\"]\n");
    fputs(cad,fp);
    NodoC* aux;
    aux=l->head;
    guardarRecursivo(aux,fp,cad);
    sprintf(cad,"}\n");
    fputs(cad,fp);
    fclose(fp);
}

void guardarRecursivo(NodoC* aux,FILE* fp,char c[]){
    if(aux==NULL){
        return;
    }else{
        if(aux->derecha!=NULL){
            if(aux->izquierda==NULL){
                sprintf(c,"node%p[label=\"%i\", shape=\"star\"]\n",&(*aux),aux->val);
            }else{
                sprintf(c,"node%p[label=\"%i\"]\n",&(*aux),aux->val);
            }
            fputs(c,fp);
            guardarRecursivo(aux->derecha,fp,c);
            sprintf(c,"node%p->node%p;\n node%p->node%p;\n",&(*aux),&(*aux->derecha),&(*aux->derecha),&(*aux));
            fputs(c,fp);
        }else{
            sprintf(c,"node%p[label=\"%i\", shape=\"star\"]\n edge[arrowhead=\"dot\", color=\"maroon\"];\n",&(*aux),aux->val);
            fputs(c,fp);
        }
    }
}



//TAREA LABORATORIO
//201807316

//Metodo eliminar sin recursividad
void eliminar(ListaC* lista, int indice){
    int contador = 0;
    NodoC* aux = lista->head;

    if(aux==NULL) printf("\nVacio! :)\n"); //Si esta vacio.

    while (aux!=NULL) {
        if(contador==indice){//Si el contador es igual al indice ingresado.
            if(aux == lista->head){//Si es la cabeza
                lista->head = aux->derecha;
                if(lista->head!=NULL) lista->head->izquierda=NULL;
                //Si head no es null, fijar su izquierdo a null.

            }else if(aux->derecha!=NULL){//Si es un dato de en medio.
                NodoC* temp = aux->izquierda;//guardar el izquierdo del nodo
                temp->derecha = aux->derecha;
                aux->derecha->izquierda = temp;

            }else{//Si es el dato final
                aux->izquierda->derecha=NULL;
            }
            free(aux); //Liberar memoria del nodo a eliminar.
            return;
        }
        aux = aux->derecha; //corro el nodo
        contador++; //aumento el contador
    }
}

//Metodo eliminar con recursividad
void eliminarRecursivo(NodoC* nodoActual, ListaC* lista, int indice){
    if(indice == 0){
        if(nodoActual==NULL){//Si esta vacia.
            printf("\neliminar - Vacio! :)\n");
            return;
        }
        if(nodoActual==lista->head){//Si es el primero(head) a eliminar.
            lista->head = nodoActual->derecha;
            if(lista->head!=NULL) lista->head->izquierda=NULL;
            //Si aun no es null el head, fijar su izquierdo a null.

        }else if(nodoActual->derecha != NULL){//Si es un nodo de en medio.
            NodoC* temp = nodoActual->izquierda;
            temp->derecha = nodoActual->derecha;
            nodoActual->derecha->izquierda = temp;

        }else{
            //Si es el ultimo nodo.
            nodoActual->izquierda->derecha = NULL;
            //La derecha de su anterior debe fijarse a null.
        }
        printf("\neliminar - Valor Eliminado: %i\n", nodoActual->val);
        free(nodoActual);//Liberar memoria del nodo a eliminar.
        return;
    }else{
        if(nodoActual->derecha == NULL){//Si es un indice inexistente
            printf("\neliminar - Nodo invalido :)!\n");
            return;
        }
        nodoActual = nodoActual->derecha;
        eliminarRecursivo(nodoActual, lista, (indice-1));//avanza disminuyendo indice.
    }
}

//Metodo get recursivo
void getRecursivo(NodoC* nodoActual, int indice){
    if(indice==0){//Significa que ya encontro el nodo.

        if(nodoActual==NULL){//Si esta vacio.
            printf("\nget - Vacio! :O\n");
            return;
        }
        printf("\nget - El numero del get es: %i \n", nodoActual->val);
        return;
    }else{//Si no es ese nodo aun.

        if(nodoActual->derecha == NULL){//Si ya llego al final. Indice invalido.
            printf("\nget - Nodo invalido! :)\n");
            return;
        }
        nodoActual = nodoActual->derecha;
        getRecursivo(nodoActual, (indice-1)); //avanzo disminuyendo el indice.
    }
}
