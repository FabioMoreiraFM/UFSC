#ifndef DARKNIGHT_HPP
#define DARKNIGHT_HPP
#include "inimigo.hpp"

class Darknight: public Inimigo {
	public:
		Darknight() {
			strcpy(nome,"Darknight");
			vida = 10;
			dano = 15;
		}

		int efeitoEspecial() {
			cout << "Darknight dará o dobro de dano até o fim da luta\n";
			dano *= 2;
			return 1;
		}

		Item* itemDrop() {
			Item* item = new Item("Escudo",10,"Parece um escudo, mas machuca", true);
		}
};
#endif