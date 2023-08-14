#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

// estructura nodo para lista simple
struct Nodo {
       int dato; // parte de datos
       Nodo* siguiente;// puntero para enlazar nodos
       // constructor
       
       Nodo(int d) 
       {
                dato = d; // asigna los datos 
                siguiente = NULL; // sig es null
       }

       //TODO: CHANGE PRIORITY       
      void imprimir();
       
};


struct Pila {
       // solo con pN es suficiente
       Nodo *tope;
       
       Pila()
       {
        tope = NULL;
       }
       
       // encabezados de funcion
       void push (int dato);
       Nodo* pop (void);
       Nodo* peek(void);
       bool empty(void);
       void imprimir(void);
};

struct InfijaAPostfija{
	Pila * operadores;
	
	InfijaAPostfija(){
	       operadores = new Pila();
	}
	int prioridad(char);
	string infToPost();
	bool isOperador(char);
       float evaluarPostfija(string);
       float realizarOpera(float, float, char);
};
