#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
struct Nodo{
    int data;
    Nodo *next;
}*primero;


void addData(int );

void mostrarLista();

void mostrarLista2(int);

void deleteData(int );
int main() {

    addData(4);
    addData(45);
    addData(33);
    addData(2);
    mostrarLista();
    //mostrarLista2(2);

}

void addData(int dato){
    Nodo *nuevoNodo=new Nodo;
    nuevoNodo->data=dato;
    if (primero=NULL){
        nuevoNodo->next=primero;
        primero=nuevoNodo;
    }
    else{
        while(primero!=NULL){
            primero=primero->next;
        }
        nuevoNodo->next=primero->next;
        primero->next=nuevoNodo;

    }
    nuevoNodo->next=primero;
    primero=nuevoNodo;
};

void mostrarLista(){
    Nodo *nuevoNodo=new Nodo;
    nuevoNodo=primero;
    while(primero!=NULL){
        cout<<nuevoNodo->data<<endl;
        nuevoNodo=nuevoNodo->next;

    }

};

void mostrarLista2(int a){
    Nodo *nuevoNodo= new Nodo;
    nuevoNodo=primero;
    for(int i=0; i!=a; i++){
        primero=primero->next;                //No me corre
    }
    cout<<primero->data;
};

void deleteData(int a){
    Nodo *nuevoNodo= new Nodo;
    nuevoNodo=primero;

    if(nuevoNodo!=NULL and nuevoNodo->next=a){
        primero=nuevoNodo->next;
    }
    else{
        while(nuevoNodo!=NULL and nuevoNodo->data!=a){
            nuevoNodo=nuevoNodo->next;
        }
    }


}
