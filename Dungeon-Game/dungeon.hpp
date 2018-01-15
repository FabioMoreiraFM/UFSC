#include "item.hpp"
#include "capivaraVampira.hpp"
#include "cacique.hpp"
#include "hidraFuracao.hpp"
#include "ninja.hpp"
#include "darknight.hpp"
#include "ornitorrincozumbi.hpp"

using namespace std;

class Dungeon {
	private:
		char nome[20];
		Item* item;
		Inimigo* monster;
	public:
		Dungeon(char nome[], Item* item, Inimigo* monster);
		Inimigo* getInimigo();
		Item* getItem();
};
