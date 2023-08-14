#include "estructuras.h"

string InfijaAPostfija::infToPost(){
	string postfija = "";
	string infija = "";
	int i = 0;
	char operador;
	cout << "Ingrese la expresion infija: ";
	cin>>infija;
	while(i<infija.length()){
		if(isOperador(infija[i])){
			while( !(operadores->empty()) && (operador = operadores->peek()->dato)!='(' && prioridad(infija[i]) <= prioridad(operador)){
				postfija += operador;
				operadores->pop();
			}
			operadores->push(infija[i]);

		}else if(infija[i] == '('){
			operadores->push(infija[i]);

		}else if(infija[i] == ')'){
			while((operador = operadores->peek()->dato) != '('){
				postfija+=operador;
				operadores->pop();
			}
			operadores->pop();
		}
		else{
			postfija+=infija[i];
		}
		
		i++;
	}
	while(!operadores->empty()){
		postfija += operadores->peek()->dato;
		operadores->pop();
	}
	cout << "Postfija: " << postfija << endl;
	return postfija;
}

float InfijaAPostfija::evaluarPostfija(string postfija){
	float a, b, result;
	int i = 0;
	Pila * pila = new Pila();
	char elemento;
	while(i<postfija.length()){
		elemento = postfija[i];
		if(!isOperador(elemento)){
			pila->push(elemento-'0');
		}
		else{
			b=pila->pop()->dato;
			a=pila->pop()->dato;
			result=realizarOpera(a,b,elemento);
			pila->push(result);
		}
		i++;
	}
	result = pila->pop()->dato;
	return result; 
}
float InfijaAPostfija::realizarOpera(float a, float b, char o){
	float result = 0;
	switch (o){
		case '^':{
			result = pow(a,b);
			break;
		}
		case '*':{
			result = a * b;
			break;
		}
		case '/':{
			result = a / b;
			break;
		}
		case '+':{
			result = a + b;
			break;
		}
		case '-':{
			result = a - b;
			break;
		}
	}
	return result;
}


bool InfijaAPostfija::isOperador(char c){
	string symbols = "^*/+-";
	if(symbols.find(c)!=string::npos)
		return true;
	return false;
}
int InfijaAPostfija::prioridad(char c){
	switch(c){
		case '^':{
			return 3;
			break;
		}
		case '*':{
			return 2;
			break;
		}
		case '/':{
			return 2;
			break;
		}
		case '+':{
			return 1;
			break;
		}
		case '-':{
			return 1;
			break;
		}
		default:{
			return 0;
			break;
		}
	}
}

