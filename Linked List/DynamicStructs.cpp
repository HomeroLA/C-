#include <iostream>
#include <string>


using namespace std;


struct Persona{
    int edad;
    string nombre;
};

struct Nodo{
    Persona persona{};
    struct Nodo *next{nullptr};
};
//struct Nodo *p{nullptr};
//Nodo *tail=NULL;

struct Lista{
    Nodo *primero{nullptr};
};

void addNodo(Lista &);
void mostrarLista();
void crearLista();
int main() {
    crearLista();
    mostrarLista();
}
/*
void addNodo(int valor){
    Nodo *nuevoNodo=new Nodo;
    nuevoNodo->valor=valor;
    nuevoNodo->next=NULL;

    if(p==NULL){
        p=nuevoNodo;
        tail=nuevoNodo;
    }
    else{
        tail->next=nuevoNodo;
        tail=nuevoNodo;
    }
};*/

void addNodo(){


}
void crearLista(){
    int i;

    cout<<"Cuantos valores quiere ingresar: ";
    cin>>i;

    for(int z=0;z<i;z++){
        int a;
        cout<<"Ingrese numero: ";
        cin>>a;
        addNodo(a);
    }
}
void mostrarLista(){
    Nodo *nuevoNodo=p;

    cout<<"Lista: "<<endl;

    if(p==NULL){
        cout<<"Lista vacia"<<endl;
    }
    else{
        while(nuevoNodo->next != NULL){
            cout<<nuevoNodo->valor<<", ";
            nuevoNodo=nuevoNodo->next;
        }
        cout<<tail->valor<<"."<<endl;
    }
}
