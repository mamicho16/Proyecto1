#include "estructuras.h"

NodoEtiquetado * ListaSimpleEtiquetas::buscarEtiquetado(string _ID){
	NodoEtiquetado * tmp = primerNodo;
	while (tmp!= NULL){
  		if (tmp->miembro->ID == _ID)
		    return tmp;
        tmp = tmp ->siguiente;	
		}
	return NULL;
}

void ListaSimpleEtiquetas::imprimirEtiquetados(){
	NodoEtiquetado * tmp = primerNodo;
  	while (tmp!= NULL){
  	    cout << tmp->miembro->ID << "   ";
        tmp = tmp ->siguiente;	
	}
}