#include "bListas.h"

//funcion recursiva de igualdad
// int SonIguales(Lista L1, Lista L2){
//     if(longitud(L1)!=longitud(L2)){
//         return 0;
//     } else{
//         if(longitud(L1)==0){
//             return 1;
//         } else{
//             if(primerElemento(L1)!=primerElemento(L2)){
//                 return 0;
//             } else{
//                 SonIguales(borrar(L1), borrar(L2));
//             }
//         }
//     }
// }

//  Funcion recursiva de igualdad mejorada
int SonIguales(Lista L1, Lista L2){
    if(longitud(L1)!=longitud(L2) || primerElemento(L1)!=primerElemento(L2)){
        return 0;
    } else{
        if(longitud(L1)==0){
            return 1;
        } else{
            SonIguales(borrar(L1), borrar(L2));
        }
    }
}

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

    if(SonIguales(L,M)){
        printf("Son iguales");
    } else{
        printf("Son diferentes");
    }
    return 0;
}



