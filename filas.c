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
        printf("\nDefila  No hay elementos");
        return F;
    } else{
        if(F.frente==F.final && F.longitud==1){
            printf("\nDefila  Un solo elemento"); 
            F.frente=NULL;
            F.final=NULL;
        } else{
            printf("\nDefila  Mas de un elemento");
            F.frente=F.frente->sig;
        }
        F.longitud--;
        free(aux);
    }
    return F;
}

int Longitud(Tfila F){
    /*if(EsFilaVacia(F)){
        return 0;
    } else{
        return (1+Longitud(Defila(F)));
    }*/
    return F.longitud;
}

int Pertenece(Tfila F, item x){
    if(EsFilaVacia(F)){
        return 0;
    } else{
        if(Frente(F)==x || Pertenece(Defila(F),x)){
            return 1;
        }
        //return (Frente(F)==x || Pertenece(Defila(F),x)); Es lo mismo que lo de arriba
    }
}


int IgualF(Tfila F, Tfila G){
    if(EsFilaVacia(F) && EsFilaVacia(G)){
        return 1;
    } else{
        if(EsFilaVacia(F) || EsFilaVacia(G)){
            return 0;
        } else{
            return (Frente(F)==Frente(G) && IgualF(Defila(F), Defila(G)));
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

Tfila Invertir(Tfila F){

    if(EsFilaVacia){
        return F;
    } else{
        return EnFila(Invertir(Defila(F)), Frente(F));        
    }
}


int main(){
    int n, x, i;
    Tfila F;

    printf("\nCantidad de elementos a ingresar: ");
    scanf("%d", &n);
    fflush(stdin);
    F=FilaVacia();
    for (i = 0; i < n; i++)
    {
        printf("Ingrese elemento [%d]: ", i);
        scanf("%d", &x);
        fflush(stdin);
        F=EnFila(F,x);
    }
    F=Defila(F);
    F=Defila(F);
    if(EsFilaVacia(F)){
        printf("\n\nVacia");
    } else{
        printf("\n\nNo vacia");
    }
    printf("\n\n");
    return 0;
}