#ifndef HIDRAFURACAO_HPP
#define HIDRAFURACAO_HPP
#include "inimigo.hpp"
#include <unistd.h>

class HidraFuracao: public Inimigo {
	public:
		HidraFuracao() {
			strcpy(nome,"HidraFuracao");
			vida = 100;
			dano = 10;
		}

		int efeitoEspecial() {
			unsigned int microseconds;
			microseconds = 3500000;
			usleep(microseconds);
			cout << "Você foi atacado pela cabeça do popeye..." << "\n";
			usleep(microseconds);
			cout << "A cabeça do popeye foi atropelada por uma bicicleta e você não sofreu dano " << "\n";
			usleep(microseconds);
			cout << "Você foi atacado pela cabeça do fofão... " << "\n";
			usleep(microseconds);
			cout << "A cabeça do fofão de uma segunda hidra apareceu e neutralizou o ataque... " << "\n";
			usleep(microseconds);
			cout << "Você foi atacado pela cabeça do BEN10... " << "\n";
			usleep(microseconds);
			cout << "Ao chegar perto de você a Hidra Furacão caiu da ponte " << "\n";
			usleep(microseconds);
			cout << "Hidra Furacão foi derrotada " << "\n";
			usleep(microseconds);
			vida = 0;
			return 1;
		}

		Item* itemDrop() {
			Item* item = new Item("Punhal do Fofão",10,".....o_O....", true);
		}
};
#endif