#include <string.h>
#include "pilaAB.h"

// char ingresaChar(){
//     char x;
//     scanf("%c", &x);
//     fflush(stdin);
//     return x;
// }

int main(){
    PilaAB pilaAB;
    AB  arbolDeExpresion;
    char str[100];
    char token;
    int largo;
    printf("\nIngrese expresion posfija: ");
    fgets(str, 100, stdin);
    printf("\nLa cadena ingresada es: %s", str);
    printf("El numero ingresado es: %d", atoi(str));
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
        }
printf("arbolll: ");
        arbolDeExpresion=top(pilaAB);
        pilaAB=pop(pilaAB);
        mostrarAB(arbolDeExpresion);
   }

    printf("\nEL arbol es esto FIN");
}


// int main(){
//     char cadena[100];
//     int largo;
//     printf("Ingrese cad: ");
//     fgets(cadena, 100, stdin);
//     largo=strlen(cadena)-1;
//     printf("Largo: %d", largo);
//     for (int i = 0; i < largo; i++)
//     {
//         printf("\n  %c", cadena[i]);
        
//     }
// }
