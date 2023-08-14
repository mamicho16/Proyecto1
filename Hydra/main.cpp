#include <iostream>

using namespace std;
#include "Estructuras.h"

//Creador: Diego Mora Montes
//Fecha de creación: 16 de Septiembre del 2022
//Ultima edición: 11 de Septiembre del 2022
int main(int argc, char** argv) {
    Hydra * h;
    Hydra * h2 = new Hydra();
    Nodo * n;
    h = new Hydra();
    h->cortarCabeza(0);
        h->imprimir();

    h->cortarCabeza(1);
        h->imprimir();

    h->cortarCabeza(4);
        h->imprimir();

    cout << endl;
    h->cortarCabeza(6);

    h2->cortarCabeza(0);
    h2->cortarCabeza(1);
    h->imprimir();

    h->implantar(4,h2);

    h->imprimir();
    h2->imprimir();
    return 0;
}
