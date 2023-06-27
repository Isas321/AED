 
#include "AB.h"
#include "pila.h"

typedef AB item;

const AB indefinido=NULL;

struct nodo{
    item dato;
    struct nodo *sig;
};

typedef struct{
    struct nodo *cabecera;
    int altura;
} Pila;

int operando(char token){
    if((token>='A' && token<='Z') || (token>='a' && token<='z')){
        return 1;
    } else{
        return 0;
    }
}

int operador(char token){
    if(token=='*' || token=='/' || token=='+' || token=='-'){
        return 1;
    } else{
        return 0;
    }
}


item arbol_de_expresion(char token){
    item arbol;
    Pila PilaDeArbol;
    if(operando(token)){
        arbol=ARMARAB(ABVACIO, token, ABVACIO);
        PilaDeArbol=push(PilaDeArbol,arbol);

    }
}

