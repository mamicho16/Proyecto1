#include "Estructuras.h"

bool ListaEspecial::estaVacia(){
	return primerNodo == NULL;
}

bool ListaEspecial::insertarAzul(int dato){
    Nodo * tmpAzul = primerNodo;
    Nodo * tmp = NULL;
    while(tmpAzul != NULL){
        if(tmpAzul->arriba != NULL){
            tmp = tmpAzul->arriba;
        } else if(tmpAzul->medio != NULL){
            tmp = tmpAzul->medio;
        } else {
            tmp = tmpAzul->abajo;
        }

        if(tmp != NULL){
            if(tmp->siguiente != NULL){
                tmpAzul = tmp->siguiente;
            } else{
                Nodo *n = new Nodo(dato, true);
                if(tmpAzul->arriba != NULL){
                    tmpAzul->arriba->siguiente = n;
                }
                if(tmpAzul->medio != NULL){
                    tmpAzul->medio->siguiente = n;
                }
                if (tmpAzul->abajo != NULL){
                    tmpAzul->abajo->siguiente = n;
                }
                return true;
            }
        } else{
            break;
        }
    }
    return false;
}

bool ListaEspecial::insertarAnaranjado(int dato){
    Nodo * tmpAzul = primerNodo;
    Nodo * tmp = NULL;
    bool ce = false;
    while(tmpAzul != NULL){
        if(tmpAzul->arriba == NULL){
            tmp = new Nodo(dato, false);
            tmpAzul->arriba = tmp;
            ce = true;
        } else if(tmpAzul->medio == NULL){
            tmp =  new Nodo(dato, false);
            tmpAzul->medio = tmp;
            ce = true;
        } else if(tmpAzul->abajo == NULL){
            tmp = new Nodo(dato, false);
            tmpAzul->abajo = tmp;
            ce = true;
        } 

        if(ce){
            if(tmpAzul->arriba != NULL && tmpAzul->arriba->siguiente != NULL){
                if(tmpAzul->medio != NULL){
                    tmpAzul->medio->siguiente = tmpAzul->arriba->siguiente;
                }
                
                if(tmpAzul->abajo != NULL){
                    tmpAzul->abajo->siguiente = tmpAzul->arriba->siguiente;
                }

            } else if(tmpAzul->medio != NULL && tmpAzul->medio->siguiente != NULL){
                if(tmpAzul->arriba != NULL){
                    tmpAzul->arriba->siguiente = tmpAzul->arriba->siguiente;
                }
                
                if(tmpAzul->abajo != NULL){
                    tmpAzul->abajo->siguiente = tmpAzul->arriba->siguiente;
                }

            } else if(tmpAzul->abajo != NULL && tmpAzul->abajo->siguiente != NULL){
                if(tmpAzul->arriba != NULL){
                    tmpAzul->arriba->siguiente = tmpAzul->arriba->siguiente;
                }
                
                if(tmpAzul->medio != NULL){
                    tmpAzul->medio->siguiente = tmpAzul->arriba->siguiente;
                }

            }
            return true;
        }else{
            if(tmpAzul->arriba->siguiente != NULL){
                tmpAzul = tmpAzul->arriba->siguiente;
            } else if(tmpAzul->medio->siguiente != NULL){
                tmpAzul = tmpAzul->medio->siguiente;
            } else {
                tmpAzul = tmpAzul->abajo->siguiente;
            }
        }
    }
    return false;
}
 
Nodo *  ListaEspecial::borrarAnaranjado(int dato){
    Nodo * tmpAzul = primerNodo;
    Nodo * tmp = primerNodo;
    while(tmp != NULL){ 
        if(tmp->arriba != NULL && tmp->arriba->dato == dato){
            if(tmp->medio != NULL || tmp->abajo != NULL || tmp->arriba->siguiente == NULL){
                tmpAzul = tmp;
                tmp = tmp->arriba;
                tmpAzul->arriba = NULL;
                tmp->siguiente = NULL;
                return tmp;
            } 
        } else if(tmp->medio != NULL && tmp->medio->dato == dato){
            if(tmp->arriba != NULL || tmp->abajo != NULL || tmp->medio->siguiente == NULL){
                tmpAzul = tmp;
                tmp = tmp->medio;
                tmpAzul->medio = NULL;
                tmp->siguiente = NULL;
                return tmp;
            } 
        } else if(tmp->abajo != NULL && tmp->abajo->dato == dato){
            if(tmp->arriba != NULL || tmp->medio != NULL || tmp->abajo->siguiente == NULL){
                tmpAzul = tmp;
                tmp = tmp->abajo;
                tmpAzul->abajo = NULL;
                tmp->siguiente = NULL;
                return tmp;
            } 
        }

        if(tmp->arriba != NULL ){ 
            tmp = tmp->arriba;
        } else if(tmp->medio != NULL){
            tmp = tmp->medio;
        }else{
            tmp = tmp->abajo;
        }

        if(tmp != NULL){
            tmp = tmp->siguiente;
        }
    }
    return NULL;
}

void ListaEspecial::imprimir(){
    Nodo * tmp = primerNodo;
    string f1 = "";
    string f2 = "";
    string f3 = "";
    while(tmp!= NULL){
        if(tmp->azul){
            f1 += "    ";
            f2 += to_string(tmp->dato);
            f2 += "   ";
            f3 += "    ";
        }
        
        if(tmp->arriba != NULL){
            f1 += to_string(tmp->arriba->dato);
            f1 += "   ";
        } else{
            f1 += "    ";
        }

        if(tmp->medio != NULL){
            f2 += to_string(tmp->medio->dato);
            f2 += "   ";
        } else{
            f2 += "    ";
        }

        if(tmp->abajo != NULL){
            f3 += to_string(tmp->abajo->dato);
            f3 += "   ";
        } else{
            f3 += "    ";
        }

        if(tmp->arriba != NULL ){
            tmp = tmp->arriba;
        } else if(tmp->medio != NULL){
            tmp = tmp->medio;
        }else{
            tmp = tmp->abajo;
        }
        if(tmp!= NULL){
            tmp = tmp->siguiente;
        }
    }
    cout<<endl;
    cout << f1 << endl;
    cout << f2 << endl;
    cout << f3 << endl;
    cout<<endl;
}

Nodo * ListaEspecial::buscar(int dato){
    Nodo * tmpAzul = primerNodo;
    Nodo * tmp = NULL;
    while(tmpAzul != NULL){
        if(tmpAzul->dato == dato){
            return tmpAzul;
        }

        if(tmpAzul->arriba->dato == dato){
            return tmpAzul->arriba;
        } else if(tmpAzul->medio->dato == dato){
            return tmpAzul->medio;
        } else if(tmpAzul->abajo->dato == dato){
            return tmpAzul->abajo;
        }

        if(tmpAzul->arriba->siguiente != NULL ){
            tmp = tmpAzul->abajo->siguiente;
        } else if(tmpAzul->medio->siguiente != NULL){
            tmp = tmpAzul->abajo->siguiente;
        } else {
            tmpAzul = tmpAzul->abajo->siguiente;
        } 
    }
    return NULL;

}