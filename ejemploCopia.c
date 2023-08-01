#include "bListas.h"

int main(){
    Lista nueva, otra, ultima;
    int x;
    nueva=insertar(crearLista(), 1);
        nueva=insertar(nueva, 2);
                nueva=insertar(nueva, 2);
    //mostrar(nueva);
    //x=ContarPares(nueva);
    //printf("\n\n\t%d", x);
    mostrar(nueva);
        otra=insertar(crearLista(), 7);
        otra=insertar(otra, 8);
                otra=insertar(otra, 9);
                    mostrar(otra);

    mostrarComoUsusario(&nueva);
        mostrarComoUsusario(&nueva);
    return 0;
}