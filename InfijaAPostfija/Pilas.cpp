#include "estructuras.h"


void Pila::push (int dato)
{
     // si no hay elementos
     if (empty ())
     {
         // ambos apuntan al nuevo en memoria
         tope = new Nodo(dato);
     }
     else
     {
         Nodo *nuevo = new Nodo(dato);
         // a lo que apunta pN ahora es el segundo
         // por eso, nuevo->siguiente es pN
         nuevo->siguiente = tope;
         // ahora devolvemos pN a que apunte al nuevo
         // y primero de las lista
         tope = nuevo; 
         // el puntero nuevo deja de existir, no se libera
         // memoria porque se pierde la info
     }
}

// funcion que elimina el primer elemento de las lista
// entradas: no tiene
// salidas: el puntero al primer nodo. Este puntero
// en siguiente apuntara a null. No se libera memoria

Nodo* Pila::pop(void)
{
      // si no hay elementos, no borra nada, retorna null
      if (empty())
      {
         return NULL;
      }
      else
      {
          // un puntero que apunta al nodo que se
          // "despegara" de la lista y se retorna
          Nodo* borrado = tope;     
          // pN se pasa al segundo de la lista
          // porque el primero se eliminara
          tope = tope->siguiente;
          // el nodo borrado, se debe despegar
          // entonces siguiente apunta a null y no
          // al segundo de la lista que ahora es pN
          borrado->siguiente = NULL;
          // aca se deberia liberar la memoria si no se
          // retornara el borrado
          return borrado;
      }
}

bool Pila::empty (void)
{
     if (tope == NULL)
        return true;
     else
         return false;
}

void Pila::imprimir(void)
{
     cout << "tope" << endl;
     // puntero temporal que avanza
     // por toda la lista
     // apunta a los mismo que pN
     Nodo *tmp = tope;
     
     // mientras tmp no sea nulo, avanza
     while (tmp != NULL)
     {
           // imprime el dato del nodo en el que esta tmp
           cout << tmp->dato << "  " << endl;
           // tmp avanza al siguiente nodo
           // esto no puede faltar porque se encicla
           tmp = tmp->siguiente;
     }
     cout << "fondo" << endl;
}

Nodo * Pila::peek()
{
     return tope;
     }

