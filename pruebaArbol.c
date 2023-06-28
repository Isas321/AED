#include"AB.h"

char ingresaChar(){
    char x;
    scanf("%c", &x);
    fflush(stdin);
    return x;
}

char ingresaInt(){
    int x;
    scanf("%d", &x);
    fflush(stdin);
    return x;
}

int main(){
    char x;
    int n, i=0;
    AB arbol, raiz, der, izq;

    arbol=ABVACIO();
    printf("\ningresar: izq");
    x=ingresaChar();
    izq=ARMARAB(NULL, x, NULL);
    printf("\ningresar: der");
    x=ingresaChar();
    der=ARMARAB(NULL, x, NULL);
    printf("\ningresar: raiz");
    x=ingresaChar();
    arbol=ARMARAB(izq, x, der);
    printf("\ningresar: raiz1");
    x=ingresaChar();
    arbol=ARMARAB(arbol, x, der);
    
    if(ESABVACIO(arbol)){
        printf("\nEs vacio el arbol");
    } else{
        printf("\nNo Es vacio el ab");
    }
    printf("\nEl arbol es: ");
    mostrarAB(arbol);
    printf("\nEl arbol fue mostrado");

}