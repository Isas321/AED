#include <stdio.h>
#include <stdlib.h>

const int indefinido=999;

typedef int item;

struct nodo{
    item dato;
    struct nodo *siguiente;
};

struct fila{
    struct nodo *frente;
    struct nodo *final;
    int longitud;
};

typedef struct fila Tfila;

Tfila filaVacia(){
    Tfila fila;
    fila.frente=NULL;
    fila.final=NULL;
    fila.longitud=0;
    return fila;
}

int esFilaVacia(Tfila fila){
    if(fila.final==NULL && fila.frente==NULL && fila.longitud==0){
        return 1;
    } else{
        return 0;
    }
}

item frente(Tfila fila){
    if(esFilaVacia(fila)){
        return indefinido;
    } else{
        return fila.frente->dato;
    }
}

item fondo(Tfila fila){
    if(esFilaVacia(fila)){
        return indefinido;
    } else{
        return fila.final->dato;
    }
}

Tfila enfila(Tfila fila, item x){
    struct nodo *nuevo;
    //Reserva de memoria + inicializacion
    nuevo=(struct nodo*)malloc(sizeof(struct nodo));
    nuevo->dato=x;
    nuevo->siguiente=NULL;

    if(esFilaVacia(fila)){  //Si no tiene elementos
        fila.frente=nuevo;
        fila.final=nuevo;
        fila.longitud++;
    } else{                 //Si tiene 1 o mas elementos
        fila.final->siguiente=nuevo;
        fila.final=nuevo;
        fila.longitud++;
    }
    return fila;
}

Tfila defila(Tfila fila){
    struct nodo *aux;
    aux=fila.frente;
    if(esFilaVacia(fila)){
        return filaVacia();
    } else{
        if(fila.frente==fila.final){ //Tiene 1 elemento
            fila.frente=NULL;
            fila.final=NULL;
            fila.longitud--;
            free(aux);  
        } else{
            fila.frente=fila.frente->siguiente;
            fila.longitud--;
            free(aux);
        }
    }
    return fila;
}

void mostrar(Tfila fila){
    if(esFilaVacia(fila)){
        printf("\nfila vacia");
    } else{
        while (fila.frente!=NULL){
            printf("\t%d", fila.frente->dato);
            fila.frente=fila.frente->siguiente;
        }
    }
}

// int pertenece(Tfila fila, item x){
//     if(fila.frente==NULL){
//         return 0;
//     } else{
//         if(fila.frente->dato==x){
//             return 1;
//         } else{
//             fila.frente=fila.frente->siguiente;
//             return pertenece(fila, x);
//         }
//     }
// }

//Como usuario: En estos casos es de suma importancia el pasar los parametros por referencia
int pertenece(Tfila *fila, item x){     //Trabajando por referencia nos aseguramos que nunca quedara apuntando a la nada nuestra lista
    if(esFilaVacia(*fila)){
        return 0;
    } else{
        if(frente(*fila)==x){
            return 1;
        } else{
            *fila=defila(*fila);
            return pertenece(fila, x);
        }
    }
}


Tfila concat(Tfila *fila1, Tfila *fila2){
    item x;
    if(esFilaVacia(*fila2)){
        return *fila1;
    } else{
        x=frente(*fila2);
        *fila1=enfila(*fila1,x);
        *fila2=defila(*fila2);
        return concat(fila1, fila2);
    }
}

Tfila invertir(Tfila *fila){
    Tfila *invertida;
    if(esFilaVacia(*fila)){
        return filaVacia();
    } else{
        return enfila(invertir(fila), frente(defila(*fila)));
    }
}

// Especificacion Algebraica 

//Operacion defilaX

//sintaxis
//defilax: tfila x item -> tfila

//Semantica: fila E Tfila, q y x E item
//defilaX(filaVacia, x)=filaVacia
//defilaX(enfila(fila,q), x)= si q=x entonces                   q seria el fondo
//                                  defilaX(fila, x)
//                            sino
//                                  enfila(defilaX(fila, x), q)


// Tfila defilaFondo(Tfila fila){
//     item f;
//     struct nodo *aux;

//     if(fila.frente==NULL){
//         return filaVacia();
//     } else{
//         if(fila.frente->siguiente==fila.final){     //  0   -   1   -   2   -   NULL
//             aux=fila.final;
//             fila.final=fila.frente;                 //  1   -   2   -   NULL    0
//             fila.final->siguiente=NULL;
//             fila.longitud--;
//             free(aux);
//             return fila;    //    1   -   NULL
//         } else{
//             f=frente(fila);
//             fila.frente=fila.frente->siguiente;
//             return enfila(defilaFondo(fila),f);
//         }
//     }                                                   //  1   -   0   -   
// }



// Tfila defilaX(Tfila fila, item x){
//     if(fila.final==NULL){
//         return filaVacia();
//     } else{
//         if(fila.final->dato==x){
            
//             defilaX()
//         }
//     }
// }


//Operacion enfilan

//sintaxis
//enfilan: tfila x item x entero -> tfila

//Semantica
//enfilan(fila, x, n)= si n>0 entonces
//                          enfilan(enfila(fila, x), x, n-1)  



int main(){
    int x, n;
    Tfila fila, filaNueva;
    printf("\nCantidad de elementos: ");
    scanf("%d", &n);
    fflush(stdin);
    fila=filaVacia();
    for (int i = 0; i < n; i++){
        printf("\nIngrese elemento: ");
        scanf("%d", &x);
        fflush(stdin);
        fila=enfila(fila, x);
    }
    mostrar(fila);
    fila=defila(fila);
            printf("\n");
    mostrar(fila);

    filaNueva=filaVacia();
    printf("\nCantidad de elementos f2: ");
    scanf("%d", &n);
    fflush(stdin);
    for (int i = 0; i < n; i++){
        printf("\nIngrese elemento f2: ");
        scanf("%d", &x);
        fflush(stdin);
        filaNueva=enfila(filaNueva, x);
    }
    mostrar(filaNueva);
        printf("\n\nconcatenada ");
    fila=concat(&fila, &filaNueva);
    mostrar(fila);
        printf("\n\ndefilaX ");
        //         printf("\nIngrese x: ");
        // scanf("%d", &x);
        // fflush(stdin);
    fila=defilaFondo(fila);
        mostrar(fila);
    return 0;
}