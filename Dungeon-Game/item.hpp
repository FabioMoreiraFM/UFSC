#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

#ifndef ITEM_HPP
#define ITEM_HPP

using namespace std;

class Item{
	private:
		char* nome;
		int power;
		char* desc;
		int tipo;
	public:

		Item(char* nome,int power, char* desc, int tipo) {
			this->nome  = nome;
			this->power = power;
			this->desc = desc;
			this->tipo = tipo;
		}

	  	int efeito() {
	  		return power;
	  	}

	  	char* getNome() {
	  		return nome;
	  	}

		int getPower() {
			return power;
		}
		
		char* getDesc() {
	  		return desc;
	  	}

	  	int getTipo() {
	  		return tipo;
	  	}
};

#endif