#include "estructuras.h"

void ListaSimpleCircularAmigos::insertarAmigo(Miembro * miembro){
	if (primerNodo == NULL){
		primerNodo = new NodoAmigo(miembro);
        primerNodo->siguiente = primerNodo;
        ultimoNodo = primerNodo;
	}
	else{
		NodoAmigo *nuevo = new NodoAmigo(miembro);
		ultimoNodo->siguiente = nuevo;
        nuevo->siguiente = primerNodo;
		ultimoNodo = nuevo;
	}
}

void ListaSimpleCircularAmigos::imprimirLugar(string _lugar){
	if (primerNodo != NULL){
		NodoAmigo * tmp = primerNodo;
		do{
            if(tmp->miembro->lugar == _lugar){
			    tmp->miembro->imprimirSin();
            }
			tmp = tmp->siguiente;
		}while(tmp!=primerNodo);
        cout << "--------------------------" << endl << endl;
	}
}

void ListaSimpleCircularAmigos::imprimirGenero(string _genero){
	if (primerNodo != NULL){
		NodoAmigo * tmp = primerNodo;
		do{
            if(tmp->miembro->genero == _genero){
			    tmp->miembro->imprimirSin();
            }
			tmp = tmp->siguiente;
		}while(tmp!=primerNodo);
        cout << "--------------------------" << endl << endl;
	}
}

NodoAmigo * ListaSimpleCircularAmigos::buscarAmigo(string _ID){
    if (primerNodo != NULL){
		NodoAmigo * tmp = primerNodo;
		do{
            if(tmp->miembro->ID == _ID){
                return tmp;
            }
            tmp = tmp->siguiente;
            }while(tmp!=primerNodo);
    }
    return NULL;
}

NodoAmigo * ListaSimpleCircularAmigos::eliminarAmigo(string _ID){
    NodoAmigo * eliminado = buscarAmigo(_ID);
    if(eliminado!=NULL){
		if (primerNodo->siguiente == primerNodo){
			eliminado->siguiente = NULL;
            }
        else{
            NodoAmigo * tmp = primerNodo;
		    do{
                tmp = tmp->siguiente;
            }while(tmp->siguiente!=eliminado);
            tmp->siguiente = tmp->siguiente->siguiente;
            eliminado->siguiente = NULL;
        }
    }
    return eliminado;
}

void ListaSimpleCircularAmigos::imprimirSin(){
    if (primerNodo != NULL){
		NodoAmigo * tmp = primerNodo;
		do{
            tmp->miembro->imprimirSin();
            tmp = tmp->siguiente;
            }while(tmp!=primerNodo);
    }
    else{
        cout << "No tiene amigos"<< endl << endl;
    }
}

void ListaSimpleCircularAmigos::imprimir(){
    if (primerNodo != NULL){
		NodoAmigo * tmp = primerNodo;
		do{
            tmp->miembro->imprimirSin();
            tmp = tmp->siguiente;
            }while(tmp!=primerNodo);
    }
    else{
        cout << "No tiene amigos"<< endl << endl;
    }
}


