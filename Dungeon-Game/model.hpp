#include "personagem.hpp"
#include "dungeon.hpp"
#include "bdDungeon.hpp"
#include "bdPersonagem.hpp"
#include "bdItem.hpp"
#include "inimigofactory.hpp"


using namespace std;

class Modelo {
	private:
		Personagem* person;
		Inimigo* monster;
		Dungeon* dungeon;
		BdItem* bditem;
		BdPersonagem* bdperson;
		BdDungeon* bddung;
		InimigoFactory* factory;
	public:
		Modelo();
		void criacaoPersonagem(char* nome, int op);
		void criacaoDungeon(int op);
		void deletaDungeon();
		string openDungeon(int op); 
		void criacaoInimigo();
		void setItemPersonagem(Item* item);
	    Item* criaItem(char* nome, int qtd, char* desc, bool tipo);
	    Item* getItemDungeon();
		char* getNomeMonster();
		int getVidaPersonagem();
		int getVidaMonster();
		bool defesa();
		int usarItemPersonagem(int &pc);
		void setDamageMonster(int dano);
		int ataquePersonagem();
		void danoSofridoPersonagem(int ultimaDungeonNavegada);
		void infoPersonagem(char* nome, char* desc, int &vida,int &qA, int &qC);
		Item** getArmas();
		Item** getCuras();
		Item* itemDrop();
		int carregarPersonagem(int &ultimaDungeonNavegada);
		int salvarPersonagem(int ultimaDungeonNavegada);
		void carregarItem();
		void deletarPersonagemItem();
		void salvarItem();
};