#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "controle.hpp"

using namespace std;

int main() {
	InterfaceGrafica* intGraf = new InterfaceGrafica(); // V
	Modelo* modelo = new Modelo(); // M
	Controle* controle = new Controle(intGraf, modelo); // C
	return 0;
}
