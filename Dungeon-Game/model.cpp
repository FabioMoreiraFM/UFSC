#include "model.hpp"
#include <iostream>

Modelo::Modelo() {
	bditem = new BdItem();
	bdperson = new BdPersonagem();
	bddung = new BdDungeon();
	factory = new InimigoFactory();
}

void Modelo::criacaoPersonagem(char* nome, int op) {
	person = new Personagem(100,nome, op);
}

void Modelo::criacaoDungeon(int op) {
	Item* item;
	monster = factory->getInimigo(op);
	switch(op) {
		case 1:
				item = criaItem("DentaCura", 15, "Cura para os dentes", 0);
				dungeon = new Dungeon("Huevânia", item, monster);
				break;
		case 2:
				item = criaItem("Bokken", 25, "Espada de madeira ordinária", 1);
				dungeon = new Dungeon("Japão Feudal", item, monster);
				break;
		case 3:
				item = criaItem("BicoRangue", 15, "Bumerangue feito do bico.. entendeu né?", 1);
				dungeon = new Dungeon("Cemitério do IBAMA", item, monster);
				break;
		case 4:
				item = criaItem("Facão", 20, "Faca grande, o quê mais seria?", 1);
				dungeon = new Dungeon("Amazônia", item, monster);
				break;
		case 5:
				item = criaItem("Erva do Cavaleiro", 15, "Última tecnologia em termos de cura", 0);
				dungeon = new Dungeon("Medieval", item, monster);
				break;
		case 6:
				item = criaItem("Máscara do Fofão", 999, "Item Supremo de cura", 0);
				dungeon = new Dungeon("Piscinão de Ramos", item, monster);
				break;
	}
}

void Modelo::deletaDungeon() {
	delete dungeon;
}

string Modelo::openDungeon(int op) {
	return bddung->abrirHistoriaDungeon(op);
}

void Modelo::criacaoInimigo() {
	monster = dungeon->getInimigo();
}

Item* Modelo::getItemDungeon() {
	return dungeon->getItem();
}

void Modelo::setItemPersonagem(Item* item) {
	person->setItem(item);
}

Item* Modelo::criaItem(char* nome, int qtd, char* desc, bool tipo) {
	Item* item = new Item(nome,qtd,desc,tipo);
	return item;
}

char* Modelo::getNomeMonster() {
	return monster->getNome();
}

int Modelo::getVidaPersonagem() {
	return person->getVida();
}

int Modelo::getVidaMonster() {
	return monster->getVida();
}

bool Modelo::defesa() {
	return person->defender();
}

int Modelo::usarItemPersonagem(int &pc){
	return person->usarItem(pc);
}

void Modelo::setDamageMonster(int dano){
	monster->setDamage(dano);
}

int Modelo::ataquePersonagem(){
	return person->atacar();
}

void Modelo::danoSofridoPersonagem(int ultimaDungeonNavegada) {
    srand(time(NULL));
    int itIn[] = {0,0,1,1,0,0,1,0,1,0,0};
    if (itIn[(rand() % 10)+1] && ultimaDungeonNavegada != 6)
		person->setVida(-monster->ataca());
	else
		person->setVida(-monster->efeitoEspecial());
}

void Modelo::infoPersonagem(char* nome, char* classe, int &vida,int &qA, int &qC) {
	strcpy(nome,person->getNome());
	strcpy(classe,person->getClasse());
	vida = person->getVida();
	qA = person->getQtdArmas();
	qC = person->getQtdCuras();
}

Item** Modelo::getArmas(){
	return person->getArmas();
}

Item** Modelo::getCuras() {
	return person->getCuras();
}

Item* Modelo::itemDrop() {
	return monster->itemDrop();
}

int Modelo::carregarPersonagem(int &ultimaDungeonNavegada) {
	if (!bdperson->verificar()) {
		person = bdperson->carregarPersonagem(ultimaDungeonNavegada);
		carregarItem();
		return 1;
	}
	return 0;
}

int Modelo::salvarPersonagem(int ultimaDungeonNavegada) {
	if (bdperson->verificar()) {
		char *nome = person->getNome();
		char *classe = person->getClasse();
		int vida = person->getVida();
		bdperson->salvarPersonagem(nome,classe,vida,ultimaDungeonNavegada);
		salvarItem();
		return 1;
	} else {
		return 0;
	}
}

void Modelo::deletarPersonagemItem() {
	bdperson->deletarPersonagem();
	bditem->deletarItem();
}

void Modelo::carregarItem() {
	Item** armas = bditem->carregarArmas();
	int i = 0,j = 0;
	while(armas[i] != NULL)
	{
		person->setItem(armas[i]);
		i++;
	}
	Item** curas = bditem->carregarCuras();
	while(curas[j] != NULL)
	{
		person->setItem(curas[j]);
		j++;
	}
}

void Modelo::salvarItem() {
	Item** armas = person->getArmas();
	Item** curas = person->getCuras();
	for (int i = 0; i < person->getQtdArmas(); ++i)
	{
		char *nome = armas[i]->getNome();
		char *desc = armas[i]->getDesc();
		int power = armas[i]->getPower();
		int tipo = armas[i]->getTipo();
		bditem->salvarItem(nome,desc,power,tipo);
	}
	for (int i = 0; i < person->getQtdCuras(); ++i)
	{
		char *nome = curas[i]->getNome();
		char *desc = curas[i]->getDesc();
		int power = curas[i]->getPower();
		int tipo = curas[i]->getTipo();
		bditem->salvarItem(nome,desc,power,tipo);
	}
}