#include <iostream>
using namespace std;

struct Nodo;
struct Hydra;

struct Nodo{
	int dato;
	Nodo * arriba;
	Nodo * abajo;

	
	Nodo(int _dato){
		dato = _dato;
		arriba = NULL;
		abajo = NULL;
	}
};

struct Hydra{
	int size;
	int cont;
	Nodo * primerNodo;

	Hydra(){
		size = 0;
		cont = 0;
		primerNodo = new Nodo(0);
	}
	Nodo * cortarCabeza(int);

	void renumerar();
	void _renumerar(Nodo*);
	void renumerarNegativo(Nodo*);

	Nodo * implantar(int, Hydra*);

	void imprimir();
	void _imprimir(Nodo*,int);

	Nodo * buscar(int, Nodo*);

	Nodo * primerCampoLibre(Nodo*);
	
	Nodo *escogerPuntero(Nodo*,Nodo*);
};
