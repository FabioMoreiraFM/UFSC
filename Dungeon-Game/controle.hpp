#include <stdlib.h>
#include <string.h>
#include "model.hpp"
#include "interfaceGrafica.hpp"

class Controle {
	private:
		InterfaceGrafica* intGraf; 
		Modelo* modelo;
		int ultimaDungeonNavegada;
	public:
		Controle(InterfaceGrafica* intG, Modelo* model);
		void status();
		int iniciarDungeon(int op);
		int sistemaCombate();
		int itemOUInimigo();
		void menuInicialPD();
		void menuJogoPD();
		void menuDungeonPD();
		void setUltimaDungeonVisitado(int novoValor);
		int opcaoValida(int *op);
		void menuSave();
};