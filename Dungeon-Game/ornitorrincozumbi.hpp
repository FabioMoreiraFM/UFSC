#ifndef ORNITORRINCOZUMBI_HPP
#define ORNITORRINCOZUMBI_HPP
#include "inimigo.hpp"

class OrnitorrincoZumbi: public Inimigo {
	public:
		OrnitorrincoZumbi() {
			strcpy(nome,"OrnitorrincoZumbi");
			vida = 10;
			dano = 20;
		}

		int efeitoEspecial() {
			cout << "OrnitorrincoZumbi se regenera\n";
			vida += 20;
			return 1;
		}

		Item* itemDrop() {
			Item* item = new Item("Fucim", 15, "Um pudim feito do fucinho de um ornitorrinco",false);
		}
};
#endif