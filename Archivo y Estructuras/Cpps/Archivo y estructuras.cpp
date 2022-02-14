

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

void cargarArray(array <Venta,100>,Venta);

void insertarOrdenado(Nodo *&,Ventas);
int main() {
    cargarventas();
    FILE * f=fopen("ventas.dat","rb+");
    Nodo *lista=NULL;
    
    array <Venta,100> arrayVent;



    Ventas r;
    Ventas b;

    while(fread(&r,sizeof(r),1,f)){
        b.ventAn=r.ventAn;
        b.idEmp=r.idEmp;
        strcpy(b.sector,r.sector);
        
        //insertarOrdenado(lista,b);      //DEBO CAMBIAR LA ESTRUCTURA: DEBO CREAR UN ARRAY DONDE IR CARGANDO LOS DATOS
                                              // PARA DESPUES CARGARLO EN UNA LISTA.

    }
    /*
    cout<<"Sector: "<<b.sector<<endl;
    cout<<"Id: "<<b.idEmp<<endl;
    cout<<"Venta anual: "<<b.ventAn<<endl;*/
    /*Nodo *listaAux=lista;
    while(listaAux!=NULL){
        cout<<listaAux->venta.ventAn<<endl;
        cout<<listaAux->venta.idEmp<<endl;
        cout<<listaAux->venta.sector<<endl;
        listaAux=listaAux->next;
    }*/



}

void cargarventas() {
    FILE *f = fopen("ventas.dat", "wb");
    Ventas p;
    p.ventAn =2000;
    strcpy(p.sector,"c");
    p.idEmp=1506;

    fwrite(&p,sizeof(p),1,f);

    Ventas q;
    q.ventAn =3000;
    strcpy(q.sector,"c");
    q.idEmp=1506;

    fwrite(&q,sizeof(q),1,f);

    Ventas d;
    d.ventAn =3000;
    strcpy(d.sector,"a");
    d.idEmp=1506;

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
    if(lista==NULL or venta.ventAn<lista->venta.ventAn){
        nuevoNodo->next=lista;
        lista=nuevoNodo;
    }
    else{
        Nodo *q=lista;
        while(q->next!=NULL and q->next->venta.ventAn<venta.ventAn){
            q=q->next;
        }
        nuevoNodo->next=q->next;
        q->next=nuevoNodo;

    }
    //}

}
