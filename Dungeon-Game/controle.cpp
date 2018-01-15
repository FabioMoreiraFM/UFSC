#include "controle.hpp"

Controle::Controle(InterfaceGrafica* intG, Modelo* model) {
    intGraf = intG;
    modelo = model;
    menuInicialPD();
    ultimaDungeonNavegada = 0;
}

void Controle::status() {
    char *nome = new char, *classe = new char;
    int vida, qtdA, qtdC;
    Item **armas = modelo->getArmas(), **curas = modelo->getCuras();
    modelo->infoPersonagem(nome,classe,vida,qtdA,qtdC);
    intGraf->personagemStatus(nome,vida,classe);
    if (qtdA > 0)
        for (int i = 0; i < qtdA; ++i)
            intGraf->itemDesc(armas[i]->getNome(),armas[i]->getDesc(),armas[i]->getPower()); 
    if (qtdC > 0)
        for (int i = 0; i < qtdC; ++i)
           intGraf->itemDesc(curas[i]->getNome(),curas[i]->getDesc(),curas[i]->getPower()); 
}

void Controle::menuDungeonPD() {
    int op = 0;
    int tmp = 0;
    while (op!=10) {
        op = intGraf->menuDung(ultimaDungeonNavegada);
        if (op > 0 && op < 7) {
        	tmp = ultimaDungeonNavegada;
        	setUltimaDungeonVisitado(opcaoValida(&op));
        	if (tmp != ultimaDungeonNavegada) {
				modelo->criacaoDungeon(op);
            	op = iniciarDungeon(op);
                modelo->deletaDungeon();
            }
        }
        if (op == 7) {
            system("clear");
            status();
            intGraf->menuPause();
        }
        if (op == 8) {
            system("clear");
            int qtdDC = 0, esc = 0;
            esc = modelo->usarItemPersonagem(qtdDC);
            if (esc == 1)
                intGraf->personagemSemCuras();
            else if (esc == 2)
                intGraf->personagemLifeCheio();
            else if (!esc)
                intGraf->itemEfeito("cura", "pontos de vida curado",qtdDC);
            intGraf->menuPause();
        }
        if (op == 9) {
            menuSave();
            op = 10;
        }
        if (op == 10)
            op = 10;
    }
}

void Controle::menuJogoPD() {
    char* nome = new char;
    system("clear");
    int op = 0;
    while (op < 1 || op >= 5) {
      intGraf->criacaoPersonagem(nome,&op);
      if (op < 1 || op >= 5)
        intGraf->valorInvalido();
    }
    modelo->criacaoPersonagem(nome,op);
    menuDungeonPD();
    delete nome;
}

void Controle::menuSave() {
   if(!modelo->salvarPersonagem(ultimaDungeonNavegada)) {
    if(intGraf->personMax() == 1) {
        modelo->deletarPersonagemItem();
        modelo->salvarPersonagem(ultimaDungeonNavegada);
    }
   }
}

void Controle::menuInicialPD() {
    int op = 0; 
    intGraf->menuInicio(op);
      switch(op) {
        case 1:
            menuJogoPD();
            break;
        case 2:
            if(modelo->carregarPersonagem(ultimaDungeonNavegada)) {
                menuDungeonPD();
            } else {
                intGraf->naoHaPerson();
                menuInicialPD();
            }
            break;
        case 3:
            intGraf->sair();
            break;
        default:
            break;
      }
}

int Controle::iniciarDungeon(int op) {
    intGraf->historia(modelo->openDungeon(op));
    if (!itemOUInimigo()) {
        intGraf->dungeonInimigo(modelo->getNomeMonster());
        intGraf->menuPause();
        if (sistemaCombate() == 9)
            return 9;
    } else {
        intGraf->ganhouItem();
        intGraf->menuPause();
    }
    return 0;
}

int Controle::sistemaCombate(){
        int dano, esc, qtdDC, op = 0;
        bool def = false;
        while (modelo->getVidaPersonagem() > 0 && modelo->getVidaMonster() > 0) {
                op = intGraf->dungeonMenuAtDef();
                system("clear");
                switch (op) {
                    case 1:
                        dano = modelo->ataquePersonagem();
                        if (dano == 0) {
                            intGraf->personagemSemArmas();
                        } else {
                            modelo->setDamageMonster(dano);
                            intGraf->itemEfeito("Arma", "dano",dano);
                            intGraf->menuPause();
                        }
                        break;
                    case 2:
                        def = modelo->defesa();
                        break;
                    case 3:
                        esc = modelo->usarItemPersonagem(qtdDC);
                        if (esc == 1)
                            intGraf->personagemSemCuras();
                        else if (esc == 2)
                            intGraf->personagemLifeCheio();
                        else if (!esc)
                            intGraf->itemEfeito("cura", "pontos de vida curado",qtdDC);
                        intGraf->menuPause();
                        break;
                    case 4:
                        status();
                        intGraf->menuPause();
                        break;
                    case 5:
                        return 9;
                }
                
                system("clear");
                intGraf->acabouTurno();

                if (!def) {
                    if (modelo->getVidaMonster() > 0) {
                        modelo->danoSofridoPersonagem(ultimaDungeonNavegada);
                    } else if(modelo->getVidaMonster() <= 0){
                        intGraf->ganhou(modelo->getNomeMonster());
                        modelo->setItemPersonagem(modelo->itemDrop());
                    }
                } else {
                    intGraf->defenderAtaque();
                    def = false;
                }

                intGraf->menuPause();
                system("clear");
        }

        if (modelo->getVidaPersonagem() <= 0) {
            intGraf->vocePerdeu();
            intGraf->menuPause();
            return 9;
        }
        return 0;
}

int Controle::itemOUInimigo() {
    srand(time(NULL));
    int itIn[] = {0,1,0,1,0,1,0,0,1,0,0};
    if (itIn[(rand() % 10)+1] && ultimaDungeonNavegada != 6) {
        modelo->setItemPersonagem(modelo->getItemDungeon());
        return 1;
    } else {
        modelo->criacaoInimigo();
        return 0;
    }
}

void Controle::setUltimaDungeonVisitado(int novoValor) {
	ultimaDungeonNavegada = novoValor;
}

int Controle::opcaoValida(int *op) {
	switch (ultimaDungeonNavegada) {
		case 0:
			if (*op != 1  && *op < 7) {
				intGraf->opcaoInvalida();
				*op = 0;
			} else {
				return *op;
			}
			break;
		case 1:
			if ((*op != 2 && *op != 3) && *op < 7) {
				intGraf->opcaoInvalida();
				*op = 0;
			} else {
				return *op;
			}
			break;
		case 2:
			if ((*op != 4 && *op != 3) && *op < 7) {
				intGraf->opcaoInvalida();
				*op = 0;
			} else {
				return *op;
			}
			return *op;
			break;
		case 3:
			if ((*op != 2 && *op != 5) && *op < 7) {
				intGraf->opcaoInvalida();
				*op = 0;
			} else {
				return *op;
			}
			break;
		case 4:
			if ((*op != 2 && *op != 5 && *op != 6) && *op < 7) {
				intGraf->opcaoInvalida();
				*op = 0;
			} else {
				return *op;
			}
			break;
		case 5:
			if ((*op != 4 && *op != 3 && *op != 6) && *op < 7) {
				intGraf->opcaoInvalida();
				*op = 0;
			} else {
				return *op;
			}
			break;
	}
	return ultimaDungeonNavegada;
}