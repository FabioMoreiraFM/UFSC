#include "personagem.hpp"

Personagem::Personagem(int life, char* nome, int op) {
	vida = life;
	this->nome = nome;
	switch (op) {
		case 1:
			classe = new char;
			classe = "Ninja";
			armas[0] = new Item("Sai", 15, "Espada Sagrada entregue pela Dama do Lago", 1);//arma 1, cura 0
			curas[0] = new Item("Ramen", 15, "Item de cura natural", 0);
			arma++;
			cura++;
			break;
		case 2:
			classe = new char;
			classe = "Guerreiro";
			armas[0] = new Item("Zweihander", 15, "Espada Sagrada entregue pela Dama do Lago", 1);//arma 1, cura 0
			curas[0] = new Item("Meat", 15, "Item de cura natural", 0);
			arma++;
			cura++;
			break;
		case 3:
			classe = new char;
			classe = "Mago";
			armas[0] = new Item("Crystal Soul Spear", 15, "Espada Sagrada entregue pela Dama do Lago", 1);//arma 1, cura 0
			curas[0] = new Item("Heal", 15, "Item de cura natural", 0);
			arma++;
			cura++;
			break;
		case 4:
			classe = new char;
			classe = "Elfo";
			armas[0] = new Item("Lhang", 15, "Espada Sagrada entregue pela Dama do Lago", 1);//arma 1, cura 0
			curas[0] = new Item("Leaf", 15, "Item de cura natural", 0);
			arma++;
			cura++;
			break;
	}
}

Personagem::Personagem(char* nome, char* classe, int vida) {
	this->vida = vida;
	this->nome = nome;
	this->classe = classe;
	arma = 0;
	cura = 0;
}

void Personagem::setItem(Item* item) {
	if (item->getTipo()) {
		++arma;
		armas[arma-1] = item;
	} else {
		++cura;
		curas[cura-1] = item;
	}
}

int Personagem::usarItem(int &pc) {
	int qtdC;
	if (getVida() < 100) {
		if (cura > 0) {
		 qtdC = curas[cura-1]->efeito();
		 setVida(qtdC);
		 pc = qtdC;
		 delete curas[cura-1];
		 cura--;
		 return 0;
		} else {
			return 1;
		}
	} else {
		return 2;
	}
}

void Personagem::setVida(int life) {
	if (life != -1) {
		if (!(vida + life > 100))
		 vida += life;
		else
		 vida = 100;
	}
}

int Personagem::getVida() {
	return vida;
}

char* Personagem::getClasse() {
	return classe;
}

char* Personagem::getNome() {
	return nome;
}

Item** Personagem::getArmas() {
	return armas;
}

Item** Personagem::getCuras() {
	return curas;
}

int Personagem::getQtdArmas() {
	return arma;
}

int Personagem::getQtdCuras() {
	return cura;
}

int Personagem::atacar() {
	if (arma > 0) { 
	 int dano = armas[arma-1]->efeito();
	 delete armas[arma-1];
	 arma--;
	 return dano;
	} else {
		return 0;
	}
}

bool Personagem::defender() {
	srand(time(NULL));
	int defender[] = {0,0,1,0,0,0,1,0,0,1,0};
	return defender[rand() % 10];
}