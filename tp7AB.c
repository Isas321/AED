#include <string.h>
#include "pilaAB.h"

int main(){
    PilaAB pilaAB;
    AB ABdeExpresionPosfija, arbol;
    char str[100], x='c';
    char token;
    int largo;
    printf("\nIngrese expresion posfija: ");
    fgets(str, 100, stdin);
    printf("\nLa cadena ingresada es: %s", str);
    printf("\n");
    largo = strlen(str);
    if(largo){
        pilaAB=PilaABVacia();
        if(esPilaABVacia(pilaAB)){
            printf("\nEs pila vacia");
        }

        for(int i = 0; i < largo-1; i++) {
            printf("\n[%c]", str[i]);
            token=str[i];
            pilaAB=PilaAB_AB_expresion_postfija(pilaAB,token);
            printf("  muestra prrek: ");

        }
        //ABdeExpresionPosfija=top(pilaAB);
   }
               arbol=top(pilaAB);
            mostrarAB(arbol);
   printf("\nEL arbol es esto");
               mostrarAB(arbol);
   //mostrarAB(ABdeExpresionPosfija);
      printf("\nEL arbol es esto FIN");
}