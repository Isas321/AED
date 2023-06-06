/*b) Implemente en lenguaje C el ADT GRUPO(ELEMENTO) usando lista simplemente
enlazada. ELEMENTO debe identificarse con un entero. */
#include "bListas.h"

typedef int ELEMENTO; //Asigno el alias "ELEMENTO" al tipo de dato, en este caso int

typedef Lista GRUPO;

GRUPO GRUPOVACIO(){
    return crearLista();
}

GRUPO AGREGAR(GRUPO g, ELEMENTO x){
    return insertar(g, x);
}

bool ESVACIO(GRUPO g){
    if(esListaVacia(g)){
        return true;
    } else{
        return false;
    }
}

int CANTIDAD(GRUPO g){
    return longitud(g);
}

GRUPO QUITARULTIMO(GRUPO g){
    return borrar(g);
}

ELEMENTO ULTIMOELEMENTO(GRUPO g){
    return primerElemento(g);
}

bool INCLUIDO(GRUPO g, ELEMENTO x){
    return pertenece(g, x);
}

int CONTARCOMUNES(GRUPO f, GRUPO g){
    if(INCLUIDO(f,primerElemento(g))){
        return 1+CONTARCOMUNES(f,QUITARULTIMO(g));
    } else{
        CONTARCOMUNES(f, QUITARULTIMO(g));
    }
}

int main(){
    int x, y;
    GRUPO f, g;
    ELEMENTO z;

    f=GRUPOVACIO();
    g=GRUPOVACIO();

    if(ESVACIO(f)){
        printf("\nes vacia f");
    }

    if(ESVACIO(g)){
        printf("\nes vacia g");
    }

    printf("\nCantidad de elementos a cargar en grupo 1: ");
    scanf("%d", &x);
    getchar();

    for (int i = 0; i < x; i++)
    {
        printf("\nIngrese elemento: ");
        scanf("%d",&z);
        getchar();
        f=AGREGAR(f,z);
    }

    printf("\nCantidad de elementos a cargar en grupo 2: ");
    scanf("%d", &y);
    getchar();

    for (int i = 0; i < y; i++)
    {
        printf("\nIngrese elemento: ");
        scanf("%d",&z);
        getchar();
        g=AGREGAR(g,z);
    }

        if(ESVACIO(f)){
        printf("\nes vacia f");
        } else{
            printf("\nNo es vacia f");
        }

    if(ESVACIO(g)){
        printf("\nes vacia g");
    } else{
            printf("\nNo es vacia g");
    }
    
}