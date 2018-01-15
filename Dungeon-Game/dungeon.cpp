#include "dungeon.hpp"

Dungeon::Dungeon(char nome[], Item* item, Inimigo* monster) {
	nome = nome;
	this->monster = monster;
	this->item = item;
}

Inimigo* Dungeon::getInimigo() {
	return monster;
}

Item* Dungeon::getItem() {
	return item;
}