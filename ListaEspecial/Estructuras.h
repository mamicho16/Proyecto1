#include <iostream>
using namespace std;

struct NodoAzul;
struct Nodo;
struct NodoAnaranjado;
struct ListaEspecial;

struct Nodo{
	int dato;
	bool azul;
	Nodo * siguiente; // para naranja
	Nodo * arriba; // para azul
	Nodo * medio; // para azul
	Nodo * abajo; // para azul

	Nodo(int _dato, bool _azul){
		dato = _dato;
		azul = _azul;
		arriba = NULL;
		medio = NULL;
		abajo = NULL;
		siguiente = NULL;
	}
	bool apuntarAzul();
};

struct ListaEspecial{
	int size;
	Nodo * primerNodo;

	ListaEspecial(){
		primerNodo =  new Nodo(1,true);
	}
	bool insertarAzul(int);
	bool insertarAnaranjado(int);
	Nodo * borrarAnaranjado(int);
	void imprimir();
	Nodo * buscar (int);
	bool estaVacia();
};
