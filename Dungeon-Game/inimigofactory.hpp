#include "capivaraVampira.hpp"
#include "cacique.hpp"
#include "hidraFuracao.hpp"
#include "ninja.hpp"
#include "darknight.hpp"
#include "ornitorrincozumbi.hpp"

class InimigoFactory {
	public:
		Inimigo* getInimigo(int op) {
			switch(op) {
				case 1:
						return new CapivaraVampira();
				case 2:
						return new Ninja();
				case 3:
						return new OrnitorrincoZumbi();
				case 4:
						return new Cacique();
				case 5:
						return new Darknight();
				case 6:
						return new HidraFuracao();
			}
		}
};