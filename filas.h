#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item;               //Tipo de datos que contiene la fila
const int indefinido=-9999;

// struct nodo{
//     item dato;
//     struct nodo* sig;
// };

typedef struct nodo{
    item dato;
    struct nodo* sig;
}Tnodo; //Haciendo uso de typedef le asigno un alias a struct nodo como Tnodo(Tipo Nodo)
typedef struct Fila{
    struct nodo* frente;    //Frente apunta a la estructura nodo al igual que Final
    struct nodo* final;
    int longitud;
}Tfila; //Haciendo uso de typedef le asigno un alias a struct Fila como TFila(Tipo fila)


Tfila FilaVacia(){
    Tfila F;
    F.frente=NULL;
    F.final=NULL;
    F.longitud=0;
    return F;
}

int EsFilaVacia(Tfila F){
    if(F.frente==NULL && F.final==NULL && F.longitud==0){
        return 1;
    } else{
        return 0;
    }
}

Tfila EnFila(Tfila F, item x){
    struct nodo *nuevo;     //Apunta a la estructura de nodo
    nuevo=(struct nodo*)malloc(sizeof(struct nodo));
    nuevo->dato=x;
    nuevo->sig=NULL;
    if(EsFilaVacia(F)){
        F.frente=nuevo;
        F.final=nuevo;
    } else{
        F.final->sig=nuevo;
        F.final=nuevo;
    }
    F.longitud++;
    return F;
}

item Frente(Tfila F){
    if(EsFilaVacia(F)){
        return indefinido;
    } else{
        return F.frente->dato;
    }
}

Tfila Defila(Tfila F){
    struct nodo *aux;
    aux=F.frente;
    if(EsFilaVacia(F)){
        //printf("\nDefila  No hay elementos");
        return F;
    } else{
        if(F.frente==F.final && F.longitud==1){
            //printf("\nDefila  Un solo elemento"); 
            F.frente=NULL;
            F.final=NULL;
        } else{
            //printf("\nDefila  Mas de un elemento");
            F.frente=F.frente->sig;
        }
        F.longitud--;
        free(aux);
    }
    return F;
}

int Longitud(Tfila F){
    return F.longitud;
}

//IMPORTANTE -> No usar defila porque borra todo! libera la memoria
// int Pertenece(Tfila F, item x){
//     if(EsFilaVacia(F)){
//         return 0;
//     }
//     return (Frente(F)==x || Pertenece(Defila(F),x)); //Es lo mismo que lo de arriba
// }

int Pertenece(Tfila F, item x){
    int frente;
    if(F.frente==NULL){
        return 0;
    }
    //frente=F.frente->dato;
    frente=Frente(F);
    F.frente=F.frente->sig;
    //F=Defila(F); //ESTO ROMPE TODO funciona bien solo si uso F.frente=F.frente->dato
        return (frente==x || Pertenece(F,x));
}

 
int IgualF(Tfila F, Tfila G){
    int frenteF, frenteG;
    if(F.frente==NULL && F.frente==NULL){
        return 1;
    } else{
        if(F.frente==NULL || F.frente==NULL){
            return 0;
        } else{
            frenteF=Frente(F);
            frenteG=Frente(G);
            F.frente=F.frente->sig;
            G.frente=G.frente->sig;
            return (frenteF==frenteG && IgualF(F,G));
            //return (Frente(F)==Frente(G) && IgualF(Defila(F), Defila(G)));
            //NO USAR DEFILA ROMPE TODO!
        }
    }
}



Tfila Concat(Tfila F, Tfila G){
    if(EsFilaVacia(G)){
        return F;
    } else{
        return Concat(EnFila(F,Frente(G)),Defila(G));
    }
}

//NO USAR DEFILA
// Tfila Invertir(Tfila F){
//     if(EsFilaVacia){
//         return F;
//     } else{
//         return EnFila(Invertir(Defila(F)), Frente(F));        
//     }
// }


//  Funcion recursiva CONTATN implementada como usuario

Tfila CONCATN(Tfila F, Tfila G, int N){
    int frente;
    if(N==0 || EsFilaVacia(G)){
        return F;
    } else{
        frente=Frente(G);
        F=EnFila(F, frente);
        G=Defila(G);
        return CONCATN(F, G, N-1);
    }
}

void Mostrar(Tfila F){
    printf("\n\n");
    while (F.frente!=NULL)
    {
        printf("    %d", F.frente->dato);
        F.frente=F.frente->sig;
    }
    printf("\n\n");
}

