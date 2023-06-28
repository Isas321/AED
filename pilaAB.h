#include "AB.h"

//typedef AB ;

const AB indefinidoAB=NULL;

struct nodo{
    AB dato;
    struct nodo *siguiente;
};
typedef struct{
    struct nodo *cabecera;
    int altura;
} PilaAB; 

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

int altura(PilaAB P){
    return P.altura;
}

PilaAB PilaABVacia(){
    PilaAB P;
    P.cabecera=NULL;
    P.altura=0;
    return P;
}

int esPilaABVacia(PilaAB P){
    if(P.cabecera==NULL && P.altura==0){
        return 1;
    } else{
        return 0;
    }
}

PilaAB push(PilaAB P, AB x){
    struct nodo *nuevo;
    nuevo=(struct nodo*)malloc(sizeof(struct nodo));
    nuevo->dato=x;
    nuevo->siguiente=P.cabecera;
    P.cabecera=nuevo;
    P.altura++;
    return P;
}

PilaAB pop(PilaAB P){
    struct nodo *aux;
    aux=P.cabecera;
    P.cabecera=P.cabecera->siguiente;
    P.altura--;
    free(aux);
    return P;
}

AB top(PilaAB P){
    AB tope;
    tope=P.cabecera->dato;
    return tope;
}

//Para mi que esta mal esto solo muestra una raiz, no tiene sentido
void mostrarPilaAB(PilaAB P){
    AB arbol;
    char caracter;
    while (P.cabecera!=NULL)
    {
        arbol=top(P);
        caracter=RAIZ(arbol);
        printf("    %c", caracter); 
        P.cabecera=P.cabecera->siguiente;
    }   
    printf("\n");
}

// PilaAB pushF(PilaAB P, AB x){
//     AB tope;
//     if(P.cabecera==NULL){
//         return push(P,x);
//     } else{
//         tope=P.cabecera->dato;
//         P.cabecera=P.cabecera->siguiente;
//         return push(pushF(P,x), tope);
//         //return push(pushF(pop(P),x),top(P));  //NO USAR POP PORQUE BORRA TODO
//     }
// }

// AB fondo(PilaAB P){
//     AB fondoPilaAB;
//     if (P.cabecera==NULL)
//     {
//         return indefinidoAB;
//     } else{
//         if(P.cabecera->siguiente==NULL){
//             fondoPilaAB=P.cabecera->dato;
//             return fondoPilaAB;
//         } else{
//             P.cabecera=P.cabecera->siguiente;
//             return fondo(P);
//         }
//     }   
// }

// PilaAB popFondo(PilaAB P){
//     struct nodo *aux;
//     AB x;
//     if(esPilaABVacia(P)){
//         return P;
//     } else{
//         if((P.cabecera->siguiente)->siguiente==NULL){
//             aux=P.cabecera->siguiente;
//             P.cabecera->siguiente=NULL;
//             P.altura--;
//             free(aux);
//             return P;
//         } else{
//             x=P.cabecera->dato;
//             P.cabecera=P.cabecera->siguiente; 
//             return push(popFondo(P),x);
//         } 
//     }
// }



PilaAB PilaAB_AB_expresion_postfija(PilaAB PilaABDeArbol, itemAB token){
    AB arbol, derecho, izquierdo;
    arbol=ABVACIO();
    derecho=ABVACIO();
    izquierdo=ABVACIO();
    if(operando(token)){
        arbol=ARMARAB(ABVACIO(), token, ABVACIO());
        PilaABDeArbol=push(PilaABDeArbol,arbol);
    } else{
        if(operador(token)){
            izquierdo=top(PilaABDeArbol);
            PilaABDeArbol=pop(PilaABDeArbol);
            derecho=top(PilaABDeArbol);
            PilaABDeArbol=pop(PilaABDeArbol);
            if(ESABVACIO(izquierdo)){
                printf("\nError");
            } else{
                if(ESABVACIO(derecho)){
                    arbol=ARMARAB(izquierdo, token, ABVACIO());
                } else{
                    arbol=ARMARAB(izquierdo, token, derecho);
                }
            }
            PilaABDeArbol=push(PilaABDeArbol, arbol);
        }
    }
    return PilaABDeArbol;
}
