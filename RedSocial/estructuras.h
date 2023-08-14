#include <iostream>
#include<string> 
#include <cstdlib>
#include<sstream>
#include <conio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct Miembro;
struct NodoMiembro;
struct ListaDobleMiembros;
struct NodoAmigo;
struct ListaSimpleCircularAmigos;
struct NodoEtiquetado;
struct ListaSimpleEtiquetas;
struct NodoPublicacion;
struct ListaDobleCircularPublicaciones;

struct NodoEtiquetado{
	Miembro * miembro;
	NodoEtiquetado * siguiente;

	NodoEtiquetado(Miembro * _miembro){
		miembro = _miembro;
		siguiente = NULL;
	}
};

struct ListaSimpleEtiquetas{
	NodoEtiquetado * primerNodo;
	NodoEtiquetado * ultimoNodo;
	ListaSimpleEtiquetas(){
		primerNodo = NULL;
	}
	NodoEtiquetado * buscarEtiquetado(string);
	void insertar (NodoEtiquetado * etiquetado){
        if (primerNodo == NULL){
		    ultimoNodo = primerNodo = etiquetado;
        }
        else{
            etiquetado->siguiente = primerNodo;
             primerNodo = etiquetado; 
        }
    }
	void imprimirEtiquetados();
};

struct NodoPublicacion{
	Miembro * emisor;
	Miembro * receptor;
	ListaSimpleEtiquetas * etiquetados;
	string publicacion;
	NodoPublicacion * siguiente;
	NodoPublicacion * anterior;
	NodoPublicacion(Miembro * _emisor, Miembro * _receptor, string _publicacion){
		emisor=_emisor;
        receptor=_receptor;
        etiquetados=new ListaSimpleEtiquetas();
        publicacion=_publicacion;
		siguiente=NULL;
		anterior=NULL;
	}
};

struct ListaDobleCircularPublicaciones{
	NodoPublicacion *primerNodo;
	ListaDobleCircularPublicaciones(){
		primerNodo = NULL;
	}
	NodoPublicacion * insertarPublicacion(NodoPublicacion * publi){
		if (primerNodo == NULL){
			primerNodo = publi;
			primerNodo->siguiente = primerNodo;
			primerNodo->anterior = primerNodo;
		}
		else{
			publi->siguiente = primerNodo;
			publi->anterior = primerNodo->anterior;
			primerNodo->anterior->siguiente = publi;
			primerNodo->anterior = publi;
		}
		return publi;
	}
	void imprimir();
};

struct NodoAmigo{
	Miembro * miembro;
	NodoAmigo * siguiente;

	NodoAmigo(Miembro * _miembro){
		miembro = _miembro;
		siguiente = NULL;
	}
};

struct ListaSimpleCircularAmigos{
	NodoAmigo * primerNodo, *ultimoNodo;
	ListaSimpleCircularAmigos(){
		primerNodo = ultimoNodo = NULL;
	}
	void insertarAmigo(Miembro*);
	void imprimirSin();
	void imprimir();
	void imprimirLugar(string);
	void imprimirGenero(string);
	NodoAmigo * buscarAmigo(string);
	NodoAmigo * eliminarAmigo(string);
};

struct Miembro{
	string nombre;
	string apellido;
	string genero;
	string lugar;
	string ID;
	string contra;
	ListaSimpleCircularAmigos * amigos;
	ListaDobleCircularPublicaciones * muro;

	Miembro(string _nombre, string _apellido, string _genero, string _lugar, string _ID, string _contra){
		nombre=_nombre;
		apellido = _apellido;
		genero = _genero;
		lugar = _lugar;
		ID = _ID;
		contra = _contra;
		amigos = new ListaSimpleCircularAmigos();
		muro = new ListaDobleCircularPublicaciones();
	}

	void imprimir (){
		cout << "Miembro #" << ID << ":\t" << nombre << " "  << apellido;
		cout << "\tGenero: " << genero <<endl;
		cout << "Amigos: " << endl << endl;
		amigos->imprimir();
	}
	void imprimirSin(){
		cout << "Miembro #" << ID << ":\t" << nombre << " "  << apellido;
		cout << "\tGenero: " << genero <<endl;
		cout <<"-----------------------------"<<endl<<endl;
	}
};

struct NodoMiembro{
	Miembro * miembro;
	NodoMiembro * siguiente;
	NodoMiembro * anterior;

	NodoMiembro(Miembro * _miembro){
		miembro = _miembro;
		siguiente = NULL;
	}
};

struct ListaDobleMiembros{
	NodoMiembro *primerNodo, *ultimoNodo;
	ListaDobleMiembros(){
		primerNodo = ultimoNodo = NULL;
	}
	void menu1();
	void menu2(Miembro*);
	bool estaVacia();
	NodoMiembro * buscarMiembro(string);
	void insertarMiembro();
	void iniciarSesion();
	void consultaListaAmigos(Miembro*);
	void lugarListaAmigos(Miembro*);
	void generoListaAmigos(Miembro * miembro);
	NodoMiembro * buscarMiembroNombreApellido(string);
	void imprimirRedSocial();
	void borrarCuenta(Miembro*);
	void borrarMiembroEnAmigos(NodoMiembro*);
	void publicarMuroAmigoSinE(Miembro*);
	void menuPublicaciones(Miembro*);
	void publicarMuroSinE(Miembro*);
	void publicarMuroConE(Miembro*);
	void publicarMuroAmigoConE(Miembro*);
	void consultarMuro(Miembro*);
	
};






