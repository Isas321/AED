
#include <stdio.h>
#include <stdlib.h>

typedef char item;

const char indefinido='-';

struct nodoAB{
    struct nodoAB *izq;
    item raiz;
    struct nodoAB *der;
};

typedef struct nodoAB *AB;


struct nodo{
    struct nodoAB arbol;
    struct nodo *siguiente;
};

const AB indefinidoAB=NULL;

typedef struct{
    struct nodo *cabecera;
    int altura;
} Pila;






AB abVacio(){
    return NULL;
}

AB armarAb(AB izquierdo, item dato, AB derecho){
    struct nodoAB *nuevo;
    nuevo=(struct nodoAB*)malloc(sizeof(struct nodoAB));
    nuevo->raiz=dato;
    nuevo->izq=izquierdo;
    nuevo->der=derecho;
    return nuevo;
}

int esVacioAB(AB arbol){
    if(arbol==NULL){
        return 1;
    } else{
        return 0;
    }
}

AB izquierdo(AB arbol){
        if(esVacioAB(arbol)){
        return abVacio();
    } else{
        return arbol->izq;
    }
}

AB derecho(AB arbol){
    if(esVacioAB(arbol)){
        return abVacio();
    } else{
    return arbol->der;
    }
}

item raiz(AB arbol){
    if(esVacioAB(arbol)){
        return indefinido;
    } else{
        return arbol->raiz;
    }
}

int pertenece(AB arbol, item x){
    if(esVacioAB(arbol)){
        return 0;
    } else{
        if(x==raiz(arbol) || pertenece(izquierdo(arbol), x) || pertenece(derecho(arbol), x)){
            return 1;
        }
    }
}

void ordenSimetrico(AB arbol){
    if(!esVacioAB(arbol)){
        printf("(");
        ordenSimetrico(izquierdo(arbol));
        printf("%c", raiz(arbol));
        ordenSimetrico(derecho(arbol));
        printf(")");
    }
}


int main(){
    AB arbol;
    arbol=abVacio();
    arbol=armarAb(arbol, 'c', arbol);
    ordenSimetrico(arbol);
    return 0;
}
