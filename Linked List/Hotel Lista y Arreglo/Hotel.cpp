#include <iostream>
#include <array>

using namespace std;


struct Hotel{
    int codHotel;
    int cantHab;
    int cantDias;
};


struct Nodo{
    int codHotel;
    int cantDias;
    Nodo *next;
};

unsigned const CANT=3;

char guion='-';


void cargarArray(Hotel[]);

void imprimirArray(Hotel[]);

void cargarLista(Nodo *&);

void imprimirLista(Nodo *&);

void insertaOrdenado(Nodo *&, int, int );

int buscar(int, Hotel[]);

int main() {
    int indice;
    //array<Hotel,CANT> hoteles;
    Hotel hoteles [100];

    Nodo *listasReservas=NULL;

    Nodo *aux=NULL;

    cargarArray(hoteles);
    cout<<""<<endl;
    cout<<"Contenido de array: "<<endl;
    cout<<""<<endl;
    imprimirArray(hoteles);

    cout<<"------------------------------------------------------------"<<endl;

    cargarLista(listasReservas);

    imprimirLista(listasReservas);

    cout<<"------------------------------------------------------------"<<endl;

    aux=listasReservas;

    while(aux!=NULL){
        indice=buscar(aux->codHotel,hoteles); //Supongo que los codHotel de la lista siempre estan en el array
        hoteles[indice].cantDias-=aux->cantDias;
        aux=aux->next;
    }
    cout<<"Lista actualizada: "<<endl;
    imprimirArray(hoteles);

}

void cargarArray(Hotel hoteles [CANT]){


    for(int i=0;i<CANT;i++){

        cout<<"Ingrese codigo de hotel: "<<endl;
        cin>>hoteles[i].codHotel;

        cout<<"Ingrese cantidad de habitaciones: "<<endl;
        cin>>hoteles[i].cantHab;

        cout<<"Ingrese cantidad de dias: "<<endl;
        cin>>hoteles[i].cantDias;

    }


};

void imprimirArray(Hotel hoteles [CANT]){

    for(int i=0;i<CANT;i++){

        cout<<"Codigo de hotel: "<<hoteles[i].codHotel<<endl;

        cout<<"Cantidad de habitacion: "<<hoteles[i].cantHab<<endl;

        cout<<"Cantidad de dias: "<<hoteles[i].cantDias<<endl;

    }
}

void cargarLista(Nodo *&lista){

    int codHotel,cantDias;


    for(int i=0; i < CANT; i++){

        cout<<"Ingrese codigo de hotel: "<<endl;
        cin>>codHotel;

        cout<<"Ingrese cantidad de dias: "<<endl;
        cin>>cantDias;

        insertaOrdenado(lista, codHotel,cantDias);
    }

}

void insertaOrdenado(Nodo *&lista , int codHotel, int cantDias ){
    Nodo* q = NULL; //Declaro un nodo auxiliar
    Nodo* p = new Nodo(); //Creo una instancia del nodo que voy a ingresar a la cola
    p->cantDias = cantDias; //A p le asigno el valor que quiero ingresar
    p->codHotel= codHotel;

    if(lista == NULL || codHotel < lista->codHotel){ //Si la lsita está vacia o el valor es menor que el que está al principio
        p->next= lista; //Pongo el nodo al principio y le digo que el siguiente es que antes estaba en lista
        lista = p; //Actualizo el inicio de la lista

    } else {
        q = lista; //A q le doy el valor del inicio de la lista
        while(q -> next != NULL && codHotel > q->next->codHotel){ //Mientras que no esté en el ultimo elemento de la lista Y el valor sea mayor que el siguiente
            q = q->next; //Paso al siguiente nodo
        }
        //Una vez que llegué al lugar donde tengo que meter mi nuevo nodo
        p->next = q->next; //Al nodo que va a ingresar le pongo como siguiente el nodo que viene despues al que acabo de encontrar
        q->next = p; //AL nodo que acabo de encontrar le asigno como siguiente el nodo nuevo
    }

}

int buscar(int codHotel,Hotel hoteles[CANT]){
    int i=0;

    while(codHotel!=hoteles[i].codHotel){
        i++;
    }

    return i;
}

void imprimirLista(Nodo *&lista){
    Nodo* p = lista;

    cout<<"Contenido lista: "<<endl;
    while(p != NULL){

        cout << "Codigo de hotel: " <<  p->codHotel << endl;
        cout<< "Cantidad de dias: "<<p->cantDias<<endl;
        p = p->next;
    }

}
