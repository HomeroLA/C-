#include <iostream>
#include <string.h>
#include <array>
#include <valarray>
#include <cstring>
using namespace std;

struct Ventas{
    unsigned idEmp;
    float ventAn;
    char sector[100];
};

struct Nodo{
    Ventas venta;
    Nodo *next;
};

void cargarventas();

void cargarArray(Ventas array[10],Ventas,int);

void cargarArrayC(array<Ventas,10>,Ventas,int);

void insertarOrdenado(Nodo *&,Ventas);

void mostrarLista(Nodo *&);
int main() {
    cargarventas();
    FILE * f=fopen("ventas.dat","rb+");
    Nodo *lista=NULL;

    Ventas arrayVent[10]={};
    std::array<Ventas,10> ventasC;




    Ventas r;
    Ventas b;
    int i=0;
    while(fread(&r,sizeof(r),1,f)){

        b.ventAn=r.ventAn;
        b.idEmp=r.idEmp;
        strcpy(b.sector,r.sector);
        ventasC.at(i).ventAn=b.ventAn;
        ventasC.at(i).idEmp=b.idEmp;
        i++;
        //insertarOrdenado(lista,b);      //DEBO CAMBIAR LA ESTRUCTURA: DEBO CREAR UN ARRAY DONDE IR CARGANDO LOS DATOS
                                              // PARA DESPUES CARGARLO EN UNA LISTA.

    };

    for(int z=0;z<3;z++){
        insertarOrdenado(lista,ventasC.at(z));
    }
    mostrarLista(lista);

}

void cargarventas() {
    FILE *f = fopen("ventas.dat", "wb");
    Ventas p;
    p.ventAn =2000;
    strcpy(p.sector,"c");
    p.idEmp=1506;

    fwrite(&p,sizeof(p),1,f);

    Ventas q;
    q.ventAn =35000;
    strcpy(q.sector,"c");
    q.idEmp=1507;

    fwrite(&q,sizeof(q),1,f);

    Ventas d;
    d.ventAn =3050;
    strcpy(d.sector,"a");
    d.idEmp=1508;

    fwrite(&d,sizeof(d),1,f);
    fclose(f);
}

void insertarOrdenado(Nodo *&lista, Ventas venta){
    Nodo *nuevoNodo=new Nodo();
    nuevoNodo->venta.ventAn=venta.ventAn;
    nuevoNodo->venta.idEmp=venta.idEmp;
    nuevoNodo->next=NULL;
    strcpy(nuevoNodo->venta.sector,nuevoNodo->venta.sector);
    //if(venta.sector=="c" or venta.sector=="C"){
    if(lista==NULL or venta.ventAn>lista->venta.ventAn){
        nuevoNodo->next=lista;
        lista=nuevoNodo;
    }
    else{
        Nodo *q=lista;
        while(q->next!=NULL and q->next->venta.ventAn>venta.ventAn){
            q=q->next;
        }
        nuevoNodo->next=q->next;
        q->next=nuevoNodo;

    }
}

void cargarArray(Ventas array[10], Ventas ventasAn, int i){
    array[i].ventAn=ventasAn.ventAn;
    array[i].idEmp=ventasAn.idEmp;
};

void cargarArrayC(array<Ventas,10> arrayC, Ventas ventasAn, int i){
    arrayC.at(i).ventAn=ventasAn.ventAn;
    cout<<arrayC.at(i).ventAn;
    arrayC.at(i).idEmp=ventasAn.idEmp;
    cout<<arrayC.at(i).idEmp;
};

void mostrarLista(Nodo *&lista){
    Nodo *&aux=lista;
    while(aux!=NULL){
        cout<<"Venta: "<<aux->venta.ventAn<<endl;
        cout<<"Id: "<<aux->venta.idEmp<<endl;
        aux=aux->next;
    }
}
