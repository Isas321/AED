#include "bListas.h"

int main(){
    Lista L, M;                    //Declaro una variable L que es un nodo
    int x, y, n;
    L = crearLista();
    M = crearLista();

    if(esListaVacia(L)){
        printf("\nCantidad de valores que desea ingresar en la lista 1: ");
          scanf("%d", &n);
          getchar();
          for(int i=0; i<n; i++){
          printf("Ingrese valor %d: ", i+1);
          scanf("%d", &x);
              getchar();
              L=insertar(L,x);
          }
          mostrar(L);
    }

    if(esListaVacia(M)){
        printf("\nCantidad de valores que desea ingresar en la lista 1: ");
          scanf("%d", &n);
          getchar();
          for(int i=0; i<n; i++){
          printf("Ingrese valor %d: ", i+1);
          scanf("%d", &x);
              getchar();
              M=insertar(M,x);
          }
          mostrar(M);
    }

    if(iguales(L,M)){
        printf("Son iguales");
    }
    return 0;
}

//Listas enlazadas
