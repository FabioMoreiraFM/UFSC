#ifndef CACIQUE_HPP
#define CACIQUE_HPP
#include "inimigo.hpp"

class Cacique: public Inimigo {
	public:
		Cacique() {
			strcpy(nome,"Cacique");
			vida = 10;
			dano = 25;
		}

		int efeitoEspecial() {
			cout << "Cacique ativa seu ataque especial: Cachimbo da Paz\n";
			cout << "Uma horda vinda do bosque ataca você, levou 10 de dano";
			return 15;
		}

		Item* itemDrop() {
			Item* item = new Item("Babosa",10,"Cura e minha vó diz que é bom para os cabelos", false);
		}
};

#endif