#include "filaNueva.h"  //Como se trata de una biblioteca hecha por nosotros la incluimos en comillas

int main(){
    int n, x, i;
    Fila F, G, X;
    printf("\n\nLista 1");
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
    printf("\nLista 1");
    Mostrar(F);
    printf("\nLista 2");
    printf("\nCantidad de elementos a ingresar: ");
    scanf("%d", &n);
    fflush(stdin);
    G=FilaVacia();
    for (i = 0; i < n; i++)
    {
        printf("Ingrese elemento [%d]: ", i);
        scanf("%d", &x);
        fflush(stdin);
        G=EnFila(G,x);
    }
    printf("\nLista 2");
    Mostrar(G);

    // printf("\nLas filas son iguales? ");
    
    // if(IgualF(F,G)){    
    //     printf("\nSon iguales");
    // } else{
    //     printf("\nSon distintas");    
    // }
         Mostrar(F);
         Mostrar(G);
    printf("\n\nIngrese un elemento y se determinara si pertenece o no a las filas: ");
    scanf("%d", &x);
    fflush(stdin);

    if(Pertenece(F, x)){
        printf("\nPertenece F");
    } else{
        printf("\nNo pertenece F");  
    }
    if(Pertenece(G, x)){
        printf("\nPertenece a G");
    } else{
        printf("\nNo pertenece G");  
    }
    Mostrar(F);
    Mostrar(G);

     printf("Cantidad de elementos de fila 2 que desea concatenar: ");
     scanf("%d", &x);
     fflush(stdin);
     X=FilaVacia();
     X=CONCATN(&F, &G, x);
     Mostrar(X);
          Mostrar(F);
               Mostrar(G);

    return 0;
}