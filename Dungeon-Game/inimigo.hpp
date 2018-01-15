#ifndef INIMIGO_HPP
#define INIMIGO_HPP
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "item.hpp"

using namespace std;

class Inimigo {
	protected:
	  int vida, dano;
	  char nome[20];
	 public:
	 	Inimigo() {}

	 	virtual int efeitoEspecial() =0;

	 	int ataca() {
			cout << nome << " atacou você. Receba " << dano << " de dano" << "\n" << endl;
	 		return dano;
	 	}

	 	void setDamage(int danolevado) {
	 		vida -= danolevado;
	 	}

	 	int getVida() {
	 		return vida;
	 	}

	 	char* getNome() {
	 		return nome;
	 	}

	 	virtual Item* itemDrop()=0;
};

#endif
