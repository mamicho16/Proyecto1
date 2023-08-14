#include <iostream>

using namespace std;
#include "Estructuras.h"

//Creador: Diego Mora Montes
//Fecha de creación: 16 de Septiembre del 2022
//Ultima edición: 11 de Septiembre del 2022

int main(int argc, char** argv) {
    Nodo * n;
    ListaEspecial * l = new ListaEspecial();
    l->imprimir();
    l->insertarAnaranjado(31);
        l->imprimir();
    l->insertarAnaranjado(4);
    l->insertarAzul(4);
    l->insertarAnaranjado(2);
    l->imprimir();
    l->borrarAnaranjado(4);
    l->imprimir();

    l->borrarAnaranjado(2);
    l->imprimir();

    l->borrarAnaranjado(31);
    l->imprimir();

    l->borrarAnaranjado(31);
    l->imprimir();

    l->insertarAnaranjado(1);
    l->insertarAnaranjado(2);
    l->insertarAnaranjado(3);
    l->imprimir();

    l->insertarAzul(31);
    l->imprimir();

    l->borrarAnaranjado(4);
    l->imprimir();


   // cout << l->primerNodo->abajo->dato << "arroz" <<endl;
    //cout << l->buscar(1)->dato << endl;

}
