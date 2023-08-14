#include "Estructuras.h" 
Nodo * Hydra::buscar(int _dato, Nodo * nodo){
    if(nodo == NULL){
        return NULL;
    }else if(nodo->dato == _dato){
        return nodo;
    }else{
        return escogerPuntero(buscar(_dato, nodo->arriba), buscar(_dato, nodo->abajo));
    }
}
Nodo * Hydra::escogerPuntero(Nodo * n1, Nodo * n2){
    if(n1 != NULL){
        return n1;
    }
    return n2;
}
Nodo * Hydra::cortarCabeza(int id){
    Nodo * tmp = buscar(id, primerNodo);
    if(tmp != NULL && (tmp->arriba == NULL || tmp->abajo == NULL)){
        if(tmp->arriba == NULL){
            size++;
            tmp->arriba = new Nodo(size);
        }
        if(tmp->abajo == NULL){
            size++;
            tmp->abajo =  new Nodo(size);
        }
        renumerar();
        return tmp;
    }
    return NULL;
}
void Hydra::renumerar(){
    cont = 0;
    _renumerar(primerNodo);
    size = cont;
}
void Hydra::_renumerar(Nodo * nodo){
    if(nodo == NULL){
        return;
    }else{
        nodo->dato = cont;
        cont++;
        _renumerar(nodo->arriba);
        _renumerar(nodo->abajo);
    }
}

void Hydra::renumerarNegativo(Nodo * nodo){
    if(nodo == NULL){
        return;
    }else{
        nodo->dato -= nodo->dato*2;
        renumerarNegativo(nodo->arriba);
        renumerarNegativo(nodo->abajo);
    }
}

Nodo * Hydra::primerCampoLibre(Nodo * nodo){
    if(nodo->arriba == NULL){
        return nodo;
    }else if(nodo->abajo == NULL){
        return nodo;
    }else{
        return escogerPuntero(primerCampoLibre(nodo->arriba), primerCampoLibre(nodo->abajo));
    }
}

Nodo * Hydra::implantar(int id, Hydra * hija){
    Nodo * tmp = buscar(id, primerNodo);
    string x  = "";
    if(tmp != NULL){
        renumerarNegativo(tmp);
        for (int i = 0; i <= size; i++)
        {
            Nodo * tmp2 = buscar(i, primerNodo);
            if(tmp2->arriba == tmp){
                tmp2->arriba = NULL;
                break;
            } else if (tmp2->abajo == tmp){
                tmp2->abajo = NULL;
                break;
            }
        }
        renumerar();
        Nodo * tmp2 = hija->primerCampoLibre(hija->primerNodo);
        if(tmp2->arriba == NULL){
            tmp2->arriba = tmp;
        } else if(tmp2->abajo == NULL){
            tmp2->abajo = tmp;
        }
        return tmp;
    }
    return NULL;
}
void Hydra::imprimir(){
    cout << endl;
    _imprimir(primerNodo, 0);
    cout << endl;
}
void Hydra::_imprimir(Nodo * nodo,int n){
    if(nodo == NULL){
        return;
    }else{
        _imprimir(nodo->arriba,n+1);
        for (int i = 0; i < n; i++)
        {
            cout<< "   ";
        }
        cout<<nodo->dato<<endl;
        _imprimir(nodo->abajo,n+1);
    }
}
