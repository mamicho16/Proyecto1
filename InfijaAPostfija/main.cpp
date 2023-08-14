#include <iostream>
#include "estructuras.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	InfijaAPostfija * x = new InfijaAPostfija();
	string postfija = x->infToPost();
	cout << "Resultado: " << x->evaluarPostfija(postfija);
	return 0;
}
