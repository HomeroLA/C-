/*Desarrolle los siguientes Subprogramas:
a-	Una función que retorne una lista sin orden a partir de la Unión de una pila y una lista.
b-	Un procedimiento que genere una lista ordenada a partir de la INTERSECCION de 2 listas.

Defina usted las estructuras de los nodos de la manera que considere más conveniente y detallar.*/



#include <iostream>
#include <mmcobj.h>


using namespace std;

struct Nodo{
    int dato;
    Nodo *next;
};

void agregarPila(Nodo *&, int );

void mostrarPila(Nodo *&);

void agregarLista(Nodo *&, int );

void insertarAlFinal(Nodo *& lista, int x);

void append(Nodo*& head_ref, int new_data);

void mostrarLista(Nodo *&);

int desapilar(Nodo *&);

Nodo * unionListaPila(Nodo *&, Nodo*&);

void listaInter(Nodo *&,Nodo *&,Nodo*&);

bool buscar(int, Nodo*&);

void insertarOrdenado(Nodo *&,int);

int main() {
    Nodo *pila=NULL;
    Nodo *lista=NULL;
    Nodo *lista2=NULL;
    Nodo *listaResultado=NULL;
    Nodo *listaInterseccion=NULL;
    //Punto a
    agregarPila(pila,11);
    agregarPila(pila,12);
    agregarPila(pila,13);
    //mostrarPila(pila);


    /*agregarLista(lista,1);
    agregarLista(lista,3);
    agregarLista(lista,2);
    */

    /*append(lista,2);
    append(lista,3);
    mostrarLista(lista);*/
    insertarAlFinal(lista,2);
    insertarAlFinal(lista,10);
    insertarAlFinal(lista,1);
    insertarAlFinal(lista,4);
    insertarAlFinal(lista,15);
    insertarAlFinal(lista,9);


    listaResultado= unionListaPila(lista,pila);
    cout<<"Punto a:"<<endl;
    mostrarLista(listaResultado);



    //Punto B

    insertarAlFinal(lista2,8);
    insertarAlFinal(lista2,6);
    insertarAlFinal(lista2,1);
    insertarAlFinal(lista2,7);
    insertarAlFinal(lista2,15);
    insertarAlFinal(lista2,4);
    insertarAlFinal(lista2,21);


    listaInter(listaInterseccion,lista,lista2);
    cout<<"Punto b:"<<endl;
    mostrarLista(listaInterseccion);
}
void agregarPila(Nodo *&pila, int a){
    Nodo *nuevoNodo=new Nodo;
    nuevoNodo->dato=a;
    nuevoNodo->next=pila;
    pila=nuevoNodo;

}

void mostrarPila(Nodo *&pila){
    while(pila!=NULL){
        cout<<pila->dato<<endl;
        pila=pila->next;
    }
};


void insertarAlFinal(Nodo *& lista, int x){
    Nodo* nuevo = new Nodo();
    nuevo->dato= x;
    nuevo->next= NULL;

    if( lista==NULL )  {
        lista = nuevo; }
    else {
        Nodo* aux = lista;
        while(aux->next!=NULL )
            aux = aux->next;

        aux->next = nuevo;
    }

}

void agregarLista(Nodo *&Lista, int a){
    Nodo *nuevoNodo=new Nodo;
    nuevoNodo->dato=a;

    nuevoNodo->next=Lista;
    Lista=nuevoNodo;

}

/*
void agregarLista(Nodo *&Lista, int a){
    Nodo *nuevoNodo=new Nodo;
    nuevoNodo->dato=a;

    Nodo *aux1=Lista;
    Nodo *aux2;

    while((aux1 != NULL)&&(aux1->dato<a)){
        aux2=aux1;
        aux1=aux1->next;

    }

    if(Lista==aux1){
        Lista=nuevoNodo;
    }

    else{
        aux2->next=nuevoNodo;
    }

    nuevoNodo->next=aux1;
}
*/
void append(Nodo*& head_ref, int new_data)
{
    /* 1. allocate node */
    Nodo* new_node = new Nodo();

    Nodo *last = head_ref; /* used in step 5*/

    /* 2. put in the data */
    new_node->dato = new_data;

    /* 3. This new node is going to be
    the last node, so make next of
    it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty,
    then make the new node as head */
    if (head_ref == NULL)
    {
        head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
    {
        last = last->next;
    }

    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

void mostrarLista(Nodo *&lista){
    Nodo *aux=lista;

    while(aux!=NULL){
        cout<<aux->dato<<endl;
        aux=aux->next;
    }
};


int desapilar(Nodo *&pila){
    Nodo *nuevoNodo=pila;
    int dato;
    dato=pila->dato;
    pila=pila->next;
    delete nuevoNodo;
    return dato;
}

Nodo * unionListaPila(Nodo *&lista, Nodo*&pila){
    Nodo *nuevaLista=NULL;
    Nodo *aux=lista;
    while(pila!=NULL){
        insertarAlFinal(nuevaLista,desapilar(pila));
    }

    while(aux!=NULL){
        insertarAlFinal(nuevaLista,aux->dato);
        aux=aux->next;
    }

    return nuevaLista;
}

bool buscar(int a, Nodo*&lista){
    Nodo *aux=lista;
    while(aux!=NULL){
        if(a==aux->dato){
            return true;
        }
        aux=aux->next;
    }

    return false;

}
void insertarOrdenado(Nodo*& lista, int v){
    Nodo* nuevo = new Nodo();
    nuevo->dato = v;
    nuevo->next= NULL;
    if(lista==NULL||(v<lista->dato)){
        nuevo->next = lista;
        lista = nuevo;
    }

    else{
        Nodo* aux = lista;

        while(aux->next!=NULL && v>aux->next->dato){
            aux = aux->next;
        }
        nuevo->next = aux->next;
        aux->next= nuevo;

    }

}
void listaInter(Nodo *&listaInterseccion,Nodo *&lista,Nodo*&lista2){
    Nodo *aux=lista;
    Nodo *aux2=lista2;

    while(aux!=NULL){
        if(buscar(aux->dato,aux2)){
            insertarOrdenado(listaInterseccion,aux->dato);
        }
        aux=aux->next;
    }

}

