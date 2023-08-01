
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char item;

struct nodo{
    item dato;
    struct nodo *siguiente;
};

typedef struct nodo *cadena;

cadena nula(){
    return NULL;
}

int esNula(cadena cad){
    if(cad==NULL){
        return 1;
    } else{
        return 0;
    }
}

int largo(cadena cad){
    int largoCad=0;
    if(!esNula(cad)){
        cad=cad->siguiente;
        largoCad++;
    }
    return largoCad;
}

cadena agregar(cadena cad, item x){
    struct nodo *nuevo;
    nuevo =(struct nodo*)malloc(sizeof(struct nodo));
    nuevo->dato=x;
    nuevo->siguiente=cad;
    cad=nuevo;
    return cad;    
}

cadena invertirCadena(cadena cad){
    cadena invertida;
    invertida=nula();
    while (!esNula(cad)){
        invertida=agregar(invertida, cad->dato);
        cad=cad->siguiente;
    }
    return invertida;      
}

// De manera iterativa
// cadena concat(cadena cad1, cadena cad2){
//     cadena invertida;
//     invertida=nula();

//     if(esNula(cad1)){
//         return cad2;
//     } else{
//         invertida=invertirCadena(cad1);
//         while(!esNula(invertida)){
//             cad2=agregar(cad2, invertida->dato);
//             invertida=invertida->siguiente;
//         }
//         return cad2;
//     }
// }

//De manera recursiva
//Notar que es mucho mas sensilla de resolverclaro
cadena concat(cadena cad1, cadena cad2){
    item dato;
    if(esNula(cad2)){
        return cad1;
    } else{
        dato=cad2->dato;
        cad2=cad2->siguiente;
        return agregar(concat(cad1,cad2), dato);
    }
}



void mostrar(cadena cad){
    if(!esNula(cad)){
        while(!esNula(cad)){
            printf("%c", cad->dato);
            cad=cad->siguiente;
        }
    }
}

int main(){
    cadena cad, cad2, cadenaNueva, concatenada;
    char x;

    cad=nula();
    cad2=nula();
    cadenaNueva=nula();
        concatenada=nula();
    printf("\nCadena 1:\n");
    cad=agregar(cad, 'a');
    cad=agregar(cad, 'b');
    cad=agregar(cad, 'c');
    mostrar(cad);
    printf("\nCadena 2:\n");
    cad2=agregar(cad2, 'x');
    cad2=agregar(cad2, 'y');
    cad2=agregar(cad2, 'z');
    mostrar(cad2);
    // printf("\nCadena 1 invertida:\n");
    // cadenaNueva=invertirCadena(cad);
    // mostrar(cadenaNueva);
    printf("\nCadena concatenada:\n");   
    concatenada=concat(cad,cad2);
    mostrar(concatenada);
    return 0;
}

