#include <iostream>
#include <valarray>
#include <cassert>

using namespace std;

struct Punto {
    double x, y;
};

struct Nodo {
    Punto val{};
    Nodo *next{nullptr};
};

struct Poligono {
    Nodo *primero{nullptr};
};

void addVertice(Poligono &, unsigned, Punto);

Punto getVertice(const Poligono &, unsigned);

void setVertice(Poligono &, unsigned, Punto);

void removeVertice(Poligono &, unsigned);

unsigned getCantidadLados(const Poligono &);

double getPerimetro(const Poligono &);

double getDistanciaEntrePuntos(Punto, Punto);

//TESTS
void runTests();

void testAddVertice();

void testGetVertice();

void testSetVertice();

void testRemoveVertice();

void testGetCantidadLados();

void testGetPerimetro();

void testPoligonoConCincoPuntos();

int main() {
    runTests();
    cout << "Ejecucion exitosa" << endl;
}

void addVertice(Poligono &poligono, unsigned posicion, Punto punto) {
    Nodo *p{poligono.primero};
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->val = punto;
    if (posicion == 0) {
        nuevoNodo->next = poligono.primero;
        poligono.primero = nuevoNodo;
    } else {
        for (unsigned i = 1; i != posicion; i++) {
            p = p->next;
        }
        nuevoNodo->next = p->next;
        p->next = nuevoNodo;
    }
}

Punto getVertice(const Poligono &poligono, unsigned posicion) {
    Nodo *p(poligono.primero);
    for (unsigned i = 0; i != posicion; i++) {
        p = p->next;
    }
    return p->val;
}

void setVertice(Poligono &poligono, unsigned posicion, Punto punto) {
    Nodo *p{poligono.primero};
    for (unsigned i = 0; i != posicion; i++) {
        p = p->next;
    }
    p->val = punto;
}

void removeVertice(Poligono &poligono, unsigned posicion) {
    Nodo *p{poligono.primero};
    if (posicion == 0) {
        poligono.primero = p == nullptr ? nullptr : poligono.primero->next;
    } else {
        for (unsigned i = 0; i != posicion - 1; i++) {
            p = p->next;
        }
        Nodo *nodoABorrar = p->next;
        p->next = nodoABorrar->next;
    }
}

unsigned getCantidadLados(const Poligono &poligono) {
    Nodo *p{poligono.primero};
    unsigned cantidadLados = 0;
    while (p) {
        p = p->next;
        cantidadLados++;
    }
    return cantidadLados;
}

double getPerimetro(const Poligono &poligono) {
    Nodo *p{poligono.primero};
    double perimetro = 0;
    unsigned ultimaPosicion = getCantidadLados(poligono) - 1;
    for (unsigned i = 0; i < ultimaPosicion; i++) {
        perimetro += getDistanciaEntrePuntos(p->next->val, p->val);
        p = p->next;
    }
    perimetro += getDistanciaEntrePuntos(poligono.primero->val, p->val);
    return perimetro;
}

double getDistanciaEntrePuntos(Punto extremo, Punto origen) {
    return sqrt(pow(extremo.x - origen.x, 2) + pow(extremo.y - origen.y, 2));
}

//TESTS
void runTests() {
    testAddVertice();
    testGetVertice();
    testSetVertice();
    testRemoveVertice();
    testGetCantidadLados();
    testGetPerimetro();
    testPoligonoConCincoPuntos();
}

void testAddVertice() {
    Poligono poligono;
    Punto punto{1, 1};
    addVertice(poligono, 0, punto);
    assert(poligono.primero->val.x == punto.x);
    assert(poligono.primero->val.y == punto.y);
}

void testGetVertice() {
    Poligono poligono;
    Punto punto{1, 1};
    addVertice(poligono, 0, punto);
    assert(getVertice(poligono, 0).x == punto.x);
    assert(getVertice(poligono, 0).y == punto.y);
}

void testSetVertice() {
    Poligono poligono;
    Punto punto{1, 1};
    Punto otroPunto{2, 2};
    addVertice(poligono, 0, punto);
    setVertice(poligono, 0, otroPunto);
    assert(poligono.primero->val.x == otroPunto.x);
    assert(poligono.primero->val.y == otroPunto.y);
}

void testRemoveVertice() {
    Poligono poligono;
    Punto punto{3, 3};
    addVertice(poligono, 0, punto);
    removeVertice(poligono, 0);
    assert(poligono.primero == nullptr);
}

void testGetCantidadLados() {
    Poligono poligono;
    Punto punto0{1, 1};
    Punto punto1{2, 2};
    Punto punto2{3, 3};
    addVertice(poligono, 0, punto0);
    addVertice(poligono, 1, punto1);
    addVertice(poligono, 2, punto2);
    assert(getCantidadLados(poligono) == 3);
}

void testGetPerimetro() {
    Poligono poligono;
    Punto punto0{0, 1};
    Punto punto1{0, 2};
    Punto punto2{1, 2};
    Punto punto3{1, 1};
    addVertice(poligono, 0, punto0);
    addVertice(poligono, 1, punto1);
    addVertice(poligono, 2, punto2);
    addVertice(poligono, 3, punto3);
    assert(getPerimetro(poligono) == 4);
}

void testPoligonoConCincoPuntos() {
    Poligono poligono;
    Punto punto0{1, 5};
    Punto punto1{4, 2};
    Punto punto2{0, -1};
    Punto punto3{-3, 3};
    Punto punto4{-2, 6};
    Punto punto5{3, 6};
    Punto punto6{-2, -2};
    addVertice(poligono, 0, punto0);
    addVertice(poligono, 1, punto1);
    addVertice(poligono, 2, punto2);
    addVertice(poligono, 3, punto3);
    addVertice(poligono, 4, punto4);
    addVertice(poligono, 5, punto5);
    removeVertice(poligono, 0);
    setVertice(poligono, 1, punto6);
    assert(getVertice(poligono, 1).x == -2);
    assert(getVertice(poligono, 1).y == -2);
    assert(getPerimetro(poligono) < 24.6);
    assert(getPerimetro(poligono) > 24.5);
    assert(getCantidadLados(poligono) == 5);
}

