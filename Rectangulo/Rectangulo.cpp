//Representa un rectangulo con las siguientes operaciones:
// • GetBase
// • GetAltura
// • GetPerímetro
// • GetÁrea
// • GetLongitudDiagonal
// • IsCuadrado
// • GetVértice (opcional): Retorna el punto correspondiente a cada uno de los cuatro vértices, es decir,
// SuperiorIzquierdo, SuperiorDerecho, InferiorIzquierdo, e InferiorDerecho.

#include <iostream>
#include <array>
#include <valarray>

using namespace std;
struct Punto{double x, y;};

struct Rectangulo{array<Punto,4> rectangulo{};};

Rectangulo crearRectangulo(Rectangulo &);

double getDistanciaEntrePuntos(Punto, Punto);

double GetBase(Rectangulo &);

double GetAltura(Rectangulo &);

double GetPerimetro(Rectangulo &);

double GerArea(Rectangulo &);


int main() {
    Rectangulo rect;
    crearRectangulo(rect);
}

Rectangulo crearRectangulo(Rectangulo &rect){

    array<string ,4> coordenadas{"A","B","C","D"};
    Punto vertice;
    for(int i=0;i<4;i++){

        cout<<"Ingrese coordenada x: "<<endl;
        cin>>vertice.x;
        rect.rectangulo.at(i).x=vertice.x;

        cout<<"Ingrese coordenada y: "<<endl;
        cin>>vertice.y;
        rect.rectangulo.at(i).y=vertice.y;

        cout<<"El punto "<<coordenadas.at(i)<<" es ("<<rect.rectangulo.at(i).x<<";"<<rect.rectangulo.at(i).y<<")"<<endl;
        cout<<""<<endl;

    }
    return rect;
}// Deberia verificar que sea un rectangulo.

double getDistanciaEntrePuntos(Punto extremo, Punto origen) {
    return sqrt(pow(extremo.x - origen.x, 2) + pow(extremo.y - origen.y, 2));
}

double GetBase(Rectangulo &rect){
    getDistanciaEntrePuntos(rect.rectangulo.at(0),rect.rectangulo.at(1));
}

double GetAltura(Rectangulo &rect){
    getDistanciaEntrePuntos(rect.rectangulo.at(0),rect.rectangulo.at(2));
}

double GetPerimetro(Rectangulo &rect ){
    double perimetro;

    perimetro=2*(GetBase(rect)+2*GetAltura(rect));

    return perimetro;
}

double GerArea(Rectangulo &rect){
    double area;

    area=GetBase(rect)* GetAltura(rect);

    return area;
}


