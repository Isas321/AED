#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item;

const item indefinido=-9999;

struct nodo
{
    item dato;
    struct nodo *siguiente;     //Apunta a una estructura nodo! es decir que apunta a un struct que tiene dato y sig
};

typedef struct{
    struct nodo *cabecera;  //Apunta a una estructura nodo que cuenta con dato y siguiente
    int altura;
}Pila;

int altura(Pila P){
    return P.altura;
}

Pila pilaVacia(){
    Pila P;
    P.cabecera=NULL;
    P.altura=0;
    return P;
}

int esPilaVacia(Pila P){
    if(P.cabecera==NULL && P.altura==0){
        return 1;
    } else{
        return 0;
    }
}

Pila push(Pila P, item x){
    struct nodo *nuevo;
    nuevo=(struct nodo*)malloc(sizeof(struct nodo));
    nuevo->dato=x;
    nuevo->siguiente=P.cabecera;
    
    P.cabecera=nuevo;
    P.altura++;
    return P;
}

Pila pop(Pila P){
    struct nodo *aux;
    //Siempre preguntar si esta vacia o no
    //Si esta vacia porque si borro altura seria negativo!
    //Y P apuntaria a cualquier cosa excepto a NULL que es lo que debe ser
    if(!esPilaVacia(P)){
        aux=P.cabecera;
        P.cabecera=P.cabecera->siguiente;
        P.altura--;
        free(aux);
        return P;
    } else{
        return pilaVacia();
    }

}

item top(Pila P){
    item tope;
    //Aqui tambien! debo tener un valor indefinido para cuando me entreguen una pila vacia!
    if(!esPilaVacia(P)){
        tope=P.cabecera->dato;
        return tope;
    } else{
        return indefinido;
    }

}

void mostrarPila(Pila P){
    while (P.cabecera!=NULL)
    {
        printf("    %d",top(P)); 
        P.cabecera=P.cabecera->siguiente;
    }   
    printf("\n");
}

Pila pushF(Pila P, item x){
    struct nodo *nuevo;
    item tope;
    if(P.cabecera==NULL){
        return push(P,x);
    } else{
        tope=P.cabecera->dato;
        P.cabecera=P.cabecera->siguiente;
        return push(pushF(P,x), tope);
        //return push(pushF(pop(P),x),top(P));  //NO USAR POP PORQUE BORRA TODO
    }
}

item fondo(Pila P){
    item fondoPila;
    if (P.cabecera==NULL)
    {
        return indefinido;
    } else{
        if(P.cabecera->siguiente==NULL){
            fondoPila=P.cabecera->dato;
            return fondoPila;
        } else{
            P.cabecera=P.cabecera->siguiente;
            return fondo(P);
        }
    }   
}


Pila popFondo(Pila P){
    struct nodo *aux;
    item x;
    if(esPilaVacia(P)){
        return P;
    } else{
        if((P.cabecera->siguiente)->siguiente==NULL){ //     1   -   2  -   NULL
            aux=P.cabecera->siguiente;                  // P.cabecera=1 
            P.cabecera->siguiente=NULL;                 // P.cabecera->siguiente=2
            P.altura--;                                 //(P.cabecera->siguiente)->siguiente==NULL
            free(aux);
            return P;
        } else{
            x=P.cabecera->dato;
            P.cabecera=P.cabecera->siguiente; 
            return push(popFondo(P),x);
        } 
    }
}

// int main(){
//     Pila P;
//     int x, n;
//     int fond;
//     printf("\nCantidad de elementos de la pila: ");
//     scanf("%d", &n);
//     fflush(stdin);

//     P=pilaVacia();
//     for (int i = 0; i < n; i++)
//     {
//         printf("\nElemento [%d]: ", i);
//         scanf("%d", &x);
//         fflush(stdin);
//         P=push(P, x);
//     }
//     mostrarPila(P);
//     printf("\nBorramos el ultimo elemento");
//     P=pop(P);
//     mostrarPila(P);
//     printf("\nIngrese elemento nuevo al comienzo de la pila: ");
//     scanf("%d", &x);
//     fflush(stdin);
//     P=pushF(P,x);
//     mostrarPila(P);
//     fond=fondo(P);
//     printf("\nEl fondo de la pila es: %i", fond);
//     printf("\npila sola \n");
//     mostrarPila(P);
//     P=popFondo(P);
//     printf("\nPopFondo \n");
//     mostrarPila(P);
//     return 0;
// }

