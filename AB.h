#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int indefinido=-9999;

typedef char itemAB;
struct nodoAB{
    itemAB raiz;
    struct nodoAB *izq;
    struct nodoAB *der;
};

typedef struct nodoAB *AB;

AB ABVACIO(){
    return NULL;
}

AB ARMARAB(AB I, itemAB r, AB D){
    AB nuevoArbol;
    nuevoArbol=(struct nodoAB*)malloc(sizeof(struct nodoAB));
    nuevoArbol->izq=I;
    nuevoArbol->raiz=r;
    nuevoArbol->der=D;
    return nuevoArbol;
}

int ESABVACIO(AB T){
    if(T==NULL){
        return 1;
    } else{
        return 0;
    }
}

int PERTENECEAB(AB T, itemAB x){
    if(ESABVACIO(T)){
        return 0;
    } else{
        if(T->raiz==x){
            return 1;
        } else{
            return (PERTENECEAB(T->der,x) || PERTENECEAB(T->izq,x));
        }
    }
}

AB IZQUIERDO(AB T){
    if(ESABVACIO(T)){
        return NULL;
    } else{
        return T->izq;
    }
}


AB DERECHO(AB T){
    if(ESABVACIO(T)){
        return NULL;
    } else{
        return T->der;
    }
}

itemAB RAIZ(AB T){
    if(ESABVACIO(T)){
        return indefinido;
    } else{
        return T->raiz;
    }
}

int esHoja(AB arbol){
    if(ESABVACIO(arbol->izq)==1 && ESABVACIO(arbol->der)==1){
        return 1;
    } else{
        return 0;
    }
}

void mostrarAB(AB arbol){
    if(ESABVACIO(arbol)==0){   
        mostrarAB(arbol->izq);
        if(RAIZ(arbol)!=indefinido){
            printf("\t%c", RAIZ(arbol));
        }     
        mostrarAB(arbol->der);
    }
}

