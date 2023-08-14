#include "estructuras.h"

void ListaDobleMiembros::menu1(){
    int opcion = 999999;
        while (opcion != 0){
    	cout << "1. Iniciar sesinn "
        << "\n2. Registrarse "
        << "\n0. Salir\n";
        cout << "Ingrese la opcion: ";
		cin >> opcion;

        switch (opcion){	
            case 1: {
                iniciarSesion();
                break;
            }
            case 2: {
				insertarMiembro();
            	break;
            }
            case 0: {
            	break;
            }
            default:{
                cout << "Ingrese una opcion correcta" << endl;
            }
        }
    }
}

void ListaDobleMiembros::insertarMiembro(){
    string nombre;
	string apellido;
	string genero;
	string lugar;
	string ID;
	string contra;
    cin.ignore(10000,'\n');
    cout << "\nIngrese el nombre: ";
    getline(cin, nombre);
    cout << "\nIngrese el apellido: ";
    getline(cin, apellido);
    cout << "\nIngrese el genero: ";
    getline(cin, genero);
    cout << "\nIngrese el lugar: ";
    getline(cin, lugar);
    cout << "\nIngrese el ID: ";
    getline(cin, ID);
    if (buscarMiembro(ID)!=NULL){
        cout << "El nombre de usuario ya está registrado" << endl;
        return;
    }
    cout << "\nIngrese la contraseña: ";
    getline(cin, contra);
    cout << endl;
    Miembro * miembro = new Miembro(nombre, apellido, genero, lugar,  ID, contra);

    if (primerNodo == NULL)
    {
        primerNodo = new NodoMiembro(miembro);
        ultimoNodo = primerNodo;               
    }
    else{
        NodoMiembro * nuevo = new NodoMiembro(miembro);
        nuevo->siguiente = primerNodo;
        primerNodo ->anterior = nuevo;
        primerNodo = nuevo; 
    }            
}


NodoMiembro * ListaDobleMiembros::buscarMiembro(string _ID){
    NodoMiembro * tmp = primerNodo;
  		while (tmp!= NULL){
  			if (tmp->miembro->ID == _ID)
			  return tmp;
            tmp = tmp ->siguiente;	
		}
	return NULL;
}

bool ListaDobleMiembros::estaVacia(){
		return primerNodo == NULL;
}

void ListaDobleMiembros::iniciarSesion(){
    string _ID;
    string _contra;
    cin.ignore(10000,'\n');
    cout << "\nIngrese el ID: ";
    getline(cin, _ID);
    if (buscarMiembro(_ID)!=NULL){
        cout << "\nIngrese la contraseña: ";
        getline(cin, _contra);
        if(buscarMiembro(_ID)->miembro->contra == _contra){
            menu2(buscarMiembro(_ID)->miembro);
        }
        else{
            cout << "Contraseña incorrecta" << endl;
            return;
        }
    }
    else{
        cout << "El ID ingresado no corresponde a ningun miembro" << endl;
        return;
    }
}
 void ListaDobleMiembros::menu2(Miembro * _miembro){
    int opcion = 999999;
        while (opcion != 0){
    	cout << "1. Ingresar un amigo "
        << "\n2. Hacer una publicacion "
        << "\n3. Consultar lista de amigos "
        << "\n4. Consultar lista de amigos que viven en determinado lugar "
        << "\n5. Consultar lista de amigos de un genero en particular "
        << "\n6. Consultar muro "
        << "\n7. Buscar miembro por nombre o apellido "
        << "\n8. Borrar amigo "
        << "\n9. Borrar cuenta "
        << "\n10. Consultar toda la red social "
        << "\n0. Salir\n";
        cout << "Ingrese la opcion: ";
		cin >> opcion;

        switch (opcion){	
            case 1: {
                string _ID;
                cin.ignore(10000,'\n');
                cout << "\nIngrese el ID del miembro que desea agregar: ";
                getline(cin, _ID);
                if (buscarMiembro(_ID)!=NULL){
                    _miembro->amigos->insertarAmigo(buscarMiembro(_ID)->miembro);
                }
                else{
                    cout << "El ID ingresado no corresponde a ningun miembro" << endl;
                }
                break;
            }
            case 2: {
				menuPublicaciones(_miembro);
            	break;
            }
            case 3: {
                consultaListaAmigos(_miembro);
                break;
            }
            case 4: {
				lugarListaAmigos(_miembro);
            	break;
            }
            case 5: {
                generoListaAmigos(_miembro);
                break;
            }
            case 6: {
				consultarMuro(_miembro);
            	break;
            }
            case 7: {
                string _dato;
                cin.ignore(10000,'\n');
                cout << "\nIngrese el nombre o apellido del miembro a buscar: ";
                getline(cin, _dato);
                if(buscarMiembroNombreApellido(_dato)!=NULL){
                    string validacion;
                    cout << "Desea agregarlo como amigo? SI/NO " << endl;
                    cin >> validacion;
                    transform(validacion.begin(), validacion.end(), validacion.begin(), ::toupper);
                    if(validacion == "SI"){
                        if(_miembro->amigos->buscarAmigo(buscarMiembroNombreApellido(_dato)->miembro->ID)!=NULL){
                            cout << "El miembro ya es su amigo, por tanto no puede agregarlo"<<endl;
                        }

                        else{
                            _miembro->amigos->insertarAmigo(buscarMiembroNombreApellido(_dato)->miembro);
                        }
                    }
                    else if (validacion == "NO"){
                        cout << endl;
                    }

                    else{
                        cout << "Ingrese una opcion valida" << endl;
                    }

                }
                else{
                    cout << "El miembro no se encuentra" << endl;
                }
                break;
            }
            case 8: {
                string _ID;
                cin.ignore(10000,'\n');
                cout << "\nIngrese el ID del amigo que desea eliminar: ";
                getline(cin, _ID);
                if (_miembro->amigos->buscarAmigo(_ID)!=NULL){
				    _miembro->amigos->eliminarAmigo(_ID);
                }
                else{
                    cout << "El ID ingresado no corresponde a ningun amigo" << endl;
                }
            	break;
            }
            case 9: {
                borrarCuenta(_miembro);
                break;
            }
            case 10: {
                imprimirRedSocial();
                break;
            }
            case 0: {
                break;
            }
            default: {
				cout << "Ingrese una opcion correcta" << endl;
            	break;
            }
        }
    }
 }

 void ListaDobleMiembros::consultaListaAmigos(Miembro * _miembro){
    _miembro->amigos->imprimir();
 }

 void ListaDobleMiembros::lugarListaAmigos(Miembro * _miembro){
    string _lugar;
    cin.ignore(10000,'\n');
    cout << "\nIngrese el lugar de los miembros a consultar: ";
    getline(cin, _lugar);
    cout << _lugar << endl;
	_miembro->amigos->imprimirLugar(_lugar);
 }

 void ListaDobleMiembros::generoListaAmigos(Miembro * _miembro){
    string _genero;
    cin.ignore(10000,'\n');
    cout << "\nIngrese el lugar de los miembros a consultar: ";
    getline(cin, _genero);
	_miembro->amigos->imprimirGenero(_genero);
 }

 NodoMiembro * ListaDobleMiembros::buscarMiembroNombreApellido(string _dato){
    NodoMiembro * tmp = primerNodo;
  		while (tmp!= NULL){
  			if (tmp->miembro->nombre == _dato || tmp->miembro->apellido == _dato)
			  return tmp;
            tmp = tmp ->siguiente;	
		}
	return NULL;
 }
 void ListaDobleMiembros::imprimirRedSocial(){
    NodoMiembro * tmp = primerNodo;
  	while (tmp!= NULL){
  	    tmp->miembro->imprimir();
		tmp = tmp ->siguiente;	
	}
}

void ListaDobleMiembros::borrarCuenta(Miembro * _miembro){
    string validacion; 
    cout << "¿Esta seguro? Los cambios son irreversibles SI/NO ";
    cin >> validacion;
    transform(validacion.begin(), validacion.end(), validacion.begin(), ::toupper);
    if(validacion == "SI"){
        NodoMiembro * tmp = primerNodo;
        NodoMiembro * _siguiente;
        NodoMiembro * _anterior;
        NodoMiembro * borrado;
        if (tmp->miembro == _miembro){
            primerNodo = primerNodo->siguiente;
            primerNodo->anterior = NULL;
            delete(tmp);
        }
        else{
		    while (tmp!=NULL){
			    if(tmp->miembro == _miembro){
                    _anterior = tmp->anterior;
                    _siguiente = tmp->siguiente;
                    borrado = tmp;
                    _anterior->siguiente=_siguiente;
                    _siguiente->anterior=_anterior;
                    break;
                }
            }
            tmp=tmp->siguiente;
        }
    }
    else if (validacion == "NO"){
        cout << endl;
        }

    else{
        cout << "Ingrese una opcion valida" << endl;
        }
}

void ListaDobleMiembros::borrarMiembroEnAmigos(NodoMiembro * _amigo){
    NodoMiembro * tmp = primerNodo;
    while (tmp != NULL)
    {
        if (tmp->miembro->amigos->buscarAmigo(_amigo->miembro->ID) != NULL)
        {
            tmp->miembro->amigos->eliminarAmigo(_amigo->miembro->ID);
        }
        tmp=tmp->siguiente;
    }
}

void ListaDobleMiembros::menuPublicaciones(Miembro * _miembro){
int opcion = 999999;
string validacion; 
while (opcion != 0){
    cout << "\n1. Hacer una publicacion en su muro "
    << "\n2. Hacer una publicacion en el muro de un miembro "
    << "\n0. Salir\n";
    cout << "Ingrese la opcion: ";
	cin >> opcion;
    switch (opcion){
        case 1: {
            cout << "¿Va a etiquetar algun miembro? SI/NO ";
            cin >> validacion;
            transform(validacion.begin(), validacion.end(), validacion.begin(), ::toupper);
            if(validacion == "SI"){
                publicarMuroConE(_miembro);
            }
            else if (validacion == "NO"){
                publicarMuroSinE(_miembro);
            }

            else{
                cout << "Ingrese una opcion valida" << endl;
            }
        	break;
        }
        case 2: {
			string validacion; 
            cout << "¿Va a etiquetar algun miembro? SI/NO ";
            cin >> validacion;
            transform(validacion.begin(), validacion.end(), validacion.begin(), ::toupper);
            if(validacion == "SI"){
                publicarMuroAmigoConE(_miembro);
            }
            else if (validacion == "NO"){
                publicarMuroAmigoSinE(_miembro);
                }

            else{
                cout << "Ingrese una opcion valida" << endl;
            }
        	break;
        }
        case 0:
        {
            break;
        }
        default: {
			cout << "Ingrese una opcion correcta" << endl;
        	break;
        }
        }
    }	
}

void ListaDobleMiembros::publicarMuroAmigoSinE(Miembro * _miembro){
    string _ID;
    string _publicacion;
    cin.ignore(10000,'\n');
    cout << "\nIngrese el ID del miembro donde quiere publicar: ";
    getline(cin, _ID);
    NodoMiembro * _receptor = buscarMiembro(_ID);
    if(_receptor!=NULL){
        cout << "\nPublicacion: ";
        getline(cin, _publicacion);
        NodoPublicacion * publi = new NodoPublicacion(_miembro,_receptor->miembro,_publicacion);
        _receptor->miembro->muro->insertarPublicacion(publi);
    }
    else{
        cout << "El miembro no se encuentra " << endl;
    }
}

void ListaDobleMiembros::publicarMuroSinE(Miembro * _miembro){
    string _publicacion;
    cin.ignore(10000,'\n');
    cout << "\nPublicacion: ";
    getline(cin, _publicacion);
    NodoPublicacion * publi = new NodoPublicacion(_miembro,_miembro,_publicacion);
    _miembro->muro->insertarPublicacion(publi);
}

void ListaDobleMiembros::publicarMuroAmigoConE(Miembro * _miembro){
    string _ID;
    string _publicacion;
    cin.ignore(10000,'\n');
    cout << "\nIngrese el ID del miembro donde quiere publicar: ";
    getline(cin, _ID);
    NodoMiembro * _receptor = buscarMiembro(_ID);
    if(_receptor!=NULL){
        cout << "\nPublicacion: ";
        getline(cin, _publicacion);
        NodoPublicacion * publi = new NodoPublicacion(_miembro,_receptor->miembro,_publicacion);
        publi = _miembro->muro->insertarPublicacion(publi);
        bool flag = false;
        while (!flag){
            string IDEtiquetado;
            cout << "\nID de la persona a etiquetar: ";
            getline(cin, IDEtiquetado);
            if(publi->etiquetados->buscarEtiquetado(IDEtiquetado)!=NULL){
                cout << "El miembro ya esta etiquetado" << endl << endl;
            }
            else{
                NodoMiembro *  etiquetado = buscarMiembro(IDEtiquetado); 
                if(etiquetado != NULL){
                    NodoEtiquetado * _etiquetado = new NodoEtiquetado(etiquetado->miembro);
                    publi->etiquetados->insertar(_etiquetado);
                    string validacion;
                    cout << "¿Va a etiquetar a otro miembro? SI/NO ";
                    cin >> validacion;
                    transform(validacion.begin(), validacion.end(), validacion.begin(), ::toupper);
                    if(validacion == "SI"){
                        continue;
                    }
                    else if (validacion == "NO"){
                        flag = true;
                    }
                    else{
                        cout << "Ingrese una opcion valida" << endl;
                    }
                }
                else{
                    cout << "El miembro no se encuentra" << endl << endl;
               }
            }
        }
    
    }
    else{
        cout << "El miembro no se encuentra " << endl;
    }
}

void ListaDobleMiembros::publicarMuroConE(Miembro * _miembro){
    string _publicacion;
    cin.ignore(10000,'\n');
    cout << "\nPublicacion: ";
    getline(cin, _publicacion);
    NodoPublicacion * publi = new NodoPublicacion(_miembro,_miembro,_publicacion);
    publi = _miembro->muro->insertarPublicacion(publi);
    bool flag = false;
    while (!flag){
        string IDEtiquetado;
        cout << "\nID de la persona a etiquetar: ";
        getline(cin, IDEtiquetado);
        if(publi->etiquetados->buscarEtiquetado(IDEtiquetado)!=NULL){
            cout << "El miembro ya esta etiquetado " << endl << endl;
        }
        else{
            NodoMiembro *  etiquetado = buscarMiembro(IDEtiquetado); 
            if(etiquetado != NULL){
                NodoEtiquetado * _etiquetado = new NodoEtiquetado(etiquetado->miembro);
                publi->etiquetados->insertar(_etiquetado);
                string validacion;
                cout << "¿Va a etiquetar a otro miembro? SI/NO ";
                cin >> validacion;
                transform(validacion.begin(), validacion.end(), validacion.begin(), ::toupper);
                if(validacion == "SI"){
                    continue;
                }
                else if (validacion == "NO"){
                    flag = true;
                }
                else{
                    cout << "Ingrese una opcion valida" << endl;
                }
            }
            else{
                cout << "El miembro no se encuentra" << endl << endl;
            }
        }
    }
}

void ListaDobleMiembros::consultarMuro(Miembro * _miembro){
    _miembro->muro->imprimir();
}