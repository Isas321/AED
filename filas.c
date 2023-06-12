typedef int item;               //Tipo de datos que contiene la fila
const int indefinido=-9999;
struct nodo{
    item dato;
    struct nodo* sig;
};
struct Fila{
    struct nodo* frente;
    struct nodo* final;
    int longitud;
};

Fila FilaVacia(){
    Fila F;
    F.frente=NULL;
    F.final=NULL;
    F.longitud=0;
    return L;
}

int EsFilaVacia(Fila F){
    if(!F.frente && !F.final){
        return 1;
    } else{
        return 0;
    }
}

Fila EnFila(Fila F, item x){
    struct nodo nuevo;
    nuevo=(struct nodo*)malloc(sizeof(struct nodo));
    nuevo->dato=x;
    nuevo->sig=NULL;
    if(EsFilaVacia(F)){
        F.frente=nuevo;
        F.final=nuevo;
    } else{
        F.final->siguiente=nuevo;
        F.Fi=nuevo;
    }
    F.longitud++;
    return F;
}

item Frente(Fila F){
    if(EsFilaVacia(F)){
        return indefinido;
    } else{
        return F.frente->dato;
    }
}

Fila Desfila(Fila F){
    struct nodo *aux;

    if(EsFilaVacia(F)){
        return F;
    } else{
        if(F.longitud==1){ puedo hacer que sean iguales frente y final
            F.frente=NULL;
            F.frente=NULL;
            free aux
        } else{
            F.frente=F.frente->siguiente;
        }
    }
    //decrementar la longitud
    return F;
}