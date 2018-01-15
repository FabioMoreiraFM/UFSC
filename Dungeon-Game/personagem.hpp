#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP
#include "item.hpp"

using namespace std;

class Personagem {
	private:
		int vida;
		Item* armas[10];
		int arma;
		Item* curas[10];
		int cura;
		char* nome;
		char* classe;
	public:
		Personagem(int life, char* nome,int op);
		Personagem(char* nome, char* classe, int vida);
		int usarItem(int &pc);
		int atacar();
		bool defender();
		void setItem(Item* item);	
		char* getNome();			
		void setNome(char* nomeP);
		void setVida(int life);
		int getVida();				
		char* getClasse();			
		int getQtdArmas();			
		int getQtdCuras();			
	    Item** getArmas();			
		Item** getCuras();			
};

#endif