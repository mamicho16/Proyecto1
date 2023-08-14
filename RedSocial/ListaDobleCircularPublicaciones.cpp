#include "estructuras.h"

void ListaDobleCircularPublicaciones::imprimir(){
    if (primerNodo != NULL){
		NodoPublicacion * tmp = primerNodo;
		do{
			cout << tmp->emisor->nombre << " " << tmp->emisor->nombre << " #" << tmp->emisor->ID << endl;
            cout << tmp->receptor->nombre << " " << tmp->receptor->nombre << " #" << tmp->receptor->ID << endl;
            cout << tmp->publicacion<<endl;
            if(tmp->etiquetados->primerNodo!=NULL){
                cout << "Etiquetados: ";
                tmp->etiquetados->imprimirEtiquetados();
            }
			tmp = tmp->siguiente;
            cout<<endl;
		}while(tmp!=primerNodo);
        cout << endl;
	}
    else{
        cout << "Aun no hay publicaciones" << endl;
    }
}