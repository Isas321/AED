
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//  1) Escriba una tipificación adecuada que defina LISTA como una lista enlazada
typedef int item;               //Asigno el alias "item" al tipo de dato, en este caso int

const item indefinido=9999;     //Defino un valor para lo indefinido

struct Nodo{                        
    item dato;
    struct Nodo *siguiente;
};
typedef struct Nodo *Lista;     //Se define un alias llamado “Lista” que es un puntero a una estructura de tipo “Nodo”.
                                // “Lista” es un puntero que apunta a la dirección de memoria de una estructura de tipo “Nodo”.



//  2) Escriba las siguientes funciones básicas de lista enlazada:
//      a) Crea una lista vacia
Lista crearLista(){             
    return NULL;
}



//      b) Determina si la lista esta vacia, devuelve un booleano
int esListaVacia(Lista L){
    if(L==NULL){
        return 1;                            //incluir la biblioteca #include <stdbool.h>
    } else{
        return 0;
    }
}



// //      c) Muestra por pantalla el contenido de los nodos de la lista
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




// // //      e)Insertar un nodo al comienzo de la lista

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




//      f)Borra el nodo del comienzo de la lista
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



// //      g) Cuenta la cantidad de nodos que tiene la lista
int longitud(Lista L){
    int n=0;
    while (!esListaVacia(L))
    {
        n++;
        L=L->siguiente;
    }
    return n;
}


//      h)determina si un dato pertenece a la lista
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

Lista borrarUltimo(Lista L){
    if (!esListaVacia(L))
    {
        while (L->siguiente!=NULL)
        {
            L=L->siguiente;
        }
        
        
        
        free();
    }
    
}


// 4) Escribir un programa que permita probar todas las funciones de la lista

int main(){
    Lista L;                    //Declaro una variable L que es un nodo
    int x, y, n;
    L = crearLista();
    if(esListaVacia(L)){
        printf("\nCantidad de valores que desea ingresar en la lista: ");
          scanf("%d", &n);
          getchar();
          for(int i=0; i<n; i++){
          printf("Ingrese valor %d: ", i+1);
          scanf("%d", &x);
              getchar();
              L=insertar(L,x);
          }
          printf("\nCantidad de valores ingresados %d: \n", longitud(L));
          mostrar(L);
          printf("\nEl primer elemento de la lista es: %d", primerElemento(L));
          printf("\n");
          L=borrar(L);
          printf("\nLos elementos de la lista despues de borrar el primer elemento de la lista son %d: \n", longitud(L));
          mostrar(L);
          printf("\nBuscar valor entero: ");
          scanf("%d", &y);
         if(pertenece(L,y)){
             printf("\nEl valor pertenece a la lista\n");
         }else{
             printf("\nEl valor No pertenece a la lista\n");
        }
        printf("Cantidad de pares %d", ContarPares(&L));
        borrarUltimo(&L);
        mostrar(L);
    }
    return 0;
}

//Listas enlazadas
