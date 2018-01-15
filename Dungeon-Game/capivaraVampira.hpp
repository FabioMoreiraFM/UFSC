#ifndef CAPIVARAVAMPIRA_HPP
#define CAPIVARAVAMPIRA_HPP
#include "inimigo.hpp"

class CapivaraVampira: public Inimigo {
	public:
		CapivaraVampira() {
			strcpy(nome,"CapivaraVampira");
			vida = 10;
			dano = 100;
		}

		int efeitoEspecial() {
			cout << "\nCapivara drenou sua vida\n";
			vida += 10;
			return 10;
		}

		Item* itemDrop() {
			Item* item = new Item("Azar da Capivara",10,"Seu azar machuca", true);
		}
};
#endif
