#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//  Tipificación adecuada para lista enlazada
typedef int item;               //Asigno el alias "item" al tipo de dato, en este caso int
const item indefinido=9999;     //Defino un valor para lo indefinido

struct Nodo{                        
    item dato;
    struct Nodo *siguiente;
};
typedef struct Nodo *Lista;     //Se define un alias llamado “Lista” que es un puntero a una estructura de tipo “Nodo”.
                                // “Lista” es un puntero que apunta a la dirección de memoria de una estructura de tipo “Nodo”.

//  Crea una lista vacia
Lista crearLista(){             
    return NULL;
}

//  Determina si la lista esta vacia, devuelve un booleano
int esListaVacia(Lista L){
    if(L==NULL){
        return 1;                        
    } else{
        return 0;
    }
}


//  Muestra por pantalla el contenido de los nodos de la lista
void mostrar(Lista L){
    if(esListaVacia(L)){
        printf("\nLa Lista esta vacia\n");
    } else{
        printf("Los valores cargados en la lista enlazada son: \n");
        while (!esListaVacia(L))        //Mientras la lista No este vacia mostrar
        {
            printf("\t%d  ", L->dato);
            L=L->siguiente;             //Guarda el valor siguiente hasta llegar al nulo en donde sale del while   
        }
    }
}


// //      d)Retorna el contenido del primer elemento de la lista.
int primerElemento(Lista L){
    int x;
    if(esListaVacia(L))
        return indefinido;
    else
        return L->dato;;
}


//  Insertar un nodo al comienzo de la lista
// //  *   *   *   FUNCION POR VALOR   *   *   *
Lista insertar(Lista L, item x){
    struct Nodo* nuevo;
    nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));  //sizeof(struct Nodo) Reserva la memoria dinamica y (struct Nodo*) castea, convierte al void* que me da malloc a un struct Nodo
    nuevo->dato = x;                                    //Guardo en el campo de dato a x
    nuevo->siguiente = L;                               //nuevo siguiente apunta hacia lo que era el primer elemento de la lista
    L=nuevo;                                            //Ahora sobreescirimos a L cosa de que siempre que lo llamemos obtengamos al nuevo de la lista
    return L;
}

// *    *   *   Funcion por referencia  *   *   *
// void insertar(Lista *L, item x){
//     struct Nodo* nuevo;
//     nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));  //sizeof(struct Nodo) Reserva la memoria dinamica y (struct Nodo*) castea, convierte al void* que me da malloc a un struct Nodo
//     nuevo->dato = x;                                    //Guardo en el campo de dato a x
//     nuevo->siguiente = *L;                               //nuevo siguiente apunta hacia lo que era el primer elemento de la lista
//     *L=nuevo;                                            //Ahora sobreescirimos a L cosa de que siempre que lo llamemos obtengamos al nuevo de la lista
// }


//  Borra el nodo del comienzo de la lista
Lista borrar(Lista L){
    struct Nodo* aux;                      //Recordar que aux al ser Lista ya es un puntero
    if(!esListaVacia(L)){           //Reviso, si esta vacia no borro nada
        aux=L;                      //Uso un puntero para guardar la direccion de memoria del primero para despues "borrarlo"
        L = L->siguiente;           //Guardamos la direccion del segundo en la lista porqeue al borrar se convertira en el primero, realizamos un desplazamiento
        free(aux);                  //Libera la memoria que se habia reservado para el primer elemento
    }         
    return L;
}


//Implementacion de quiz1
int ContarPares(Lista *L){
    int cant=0;
    while(!esListaVacia(*L)){
        if(primerElemento(*L)%2==0){
            cant++;
        }
        *L=borrar(*L);
    }
    return cant;
}


//  Cuenta la cantidad de nodos que tiene la lista
int longitud(Lista L){
    int n=0;
    while (!esListaVacia(L))
    {
        n++;
        L=L->siguiente;
    }
    return n;
}


//  Determina si un dato pertenece a la lista
int pertenece(Lista L, item x){
    Lista aux;
    while (!esListaVacia(L))
    {
        if(L->dato==x){
            return 1;
        }
        L=L->siguiente;
    }
    return 0;
}


//  Borra el ultimo de la lista
Lista borrarUltimo(Lista L){
    struct Nodo* aux;
    // Null
    //  1   -   Null
    //  1   -   2   -   Null
    aux=L;
    if(!esListaVacia(aux)){
        printf("\nno es vacia");
        if((aux->siguiente)!=NULL){
            printf("\nno es el caso de 1-null");
            while ((aux->siguiente)->siguiente!=NULL)
            {
                aux = aux->siguiente;
                printf("\ncantidad de sig");
            }
            free(aux->siguiente);
            aux->siguiente=NULL;
        } else{
            printf("\nes el caso 1-null");
            free(aux);
            aux=crearLista();
            //aux=NULL;
        }
    } else{
        printf("\nLa lista esta vacia\n");
    }
    return L;
}


//  Funcion que determina si son iguales
bool iguales(Lista L1, Lista L2){
    if(longitud(L1)==longitud(L2)){
        //Tienen igual cantidad de datos, sigo analizando
        while (!esListaVacia(L1)){
            if(primerElemento(L1)!=primerElemento(L2)){
                //printf("primer elemento distinto");
                return false;
            }
            L1=borrar(L1);
            L2=borrar(L2);
        }
   }else{
        //Las listas son distintas
        return false;
   }
   //printf("son iguales perro");
   return true;
}

