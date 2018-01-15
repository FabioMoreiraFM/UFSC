#ifndef NINJA_HPP
#define NINJA_HPP
#include "inimigo.hpp"

class Ninja: public Inimigo {
	public:
		Ninja() {
			strcpy(nome,"Ninja");
			vida = 10;
			dano = 5;
		}

		int efeitoEspecial() {
			cout << "Ninja recupera 10 de vida\n";
			vida += 10;
			return 1;
		}

		Item* itemDrop() {
			Item* item = new Item("Shuriken",15,"Estrela que machuca", true);
		}
};

#endif