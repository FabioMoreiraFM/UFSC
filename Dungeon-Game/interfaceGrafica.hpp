#ifndef INTERFACEGRAFICA_HPP
#define INTERFACEGRAFICA_HPP
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

class InterfaceGrafica {
	public:

		InterfaceGrafica() {}

		// Métodos Gráficos do Main

		void menuInicio(int &op) {
			while (op <= 0 || op > 3) {
			  system("clear");
			  cout << "Bem-Vindo ao NinoTeerã" << "\n" << endl;
			  cout << "1 - New Game" << "\n" << endl;
			  cout << "2 - Load Game" << "\n" << endl;
			  cout << "3 - Exit" << "\n" << endl;
			  cin >> op;
			}
		}

		void historia(string texto) {
			system("clear");
			cout << texto << "\n" << endl;
		}

		void sair() {
			cout << "\nSaindo..." << endl;
		}

		void valorInvalido() {
			cout << "Valor Inválido, repita o processo! \n" << endl;
		}

		void criacaoPersonagem(char* nome, int* op) {
			cout << "Insira seu nome: " << endl;
	    	cin >> nome;
	    	cout << "\n" << endl;
	    	cout << "Escolha uma das classes abaixo para " << nome << "\n"<<endl;	
	    	cout << "1 - Ninja" << "\n" << endl;
	    	cout << "2 - Guerreiro" << "\n" << endl;
	    	cout << "3 - Mago" << "\n" << endl;
	    	cout << "4 - Elfo" << "\n" << endl;
	    	cin >> *op;
	    	cout << "\n" << endl;		
		}

		int menuDung(int ultimaDungeonNavegada) {
			system("clear");
			int op = 0;
			if (ultimaDungeonNavegada != 6)
				cout << "Selecione uma das opções abaixo" << "\n" << endl;
			if (ultimaDungeonNavegada > 0 && ultimaDungeonNavegada < 7) {
				switch(ultimaDungeonNavegada) {
					case 1:
						cout << "2 - Entrar no Japão Feudal" << "\n" << endl;
						cout << "3 - Entrar no Cemitério do IBAMA" << "\n" << endl;
						break;
					case 2:
						cout << "4 - Entrar na Amazônia" << "\n" << endl;
						cout << "3 - Entrar Entrar no Cemitério do IBAMA" << "\n" << endl;
						break;
					case 3:
						cout << "5 - Entrar na Era Medieval" << "\n" << endl;
						cout << "2 - Entrar no Japão Feudal" << "\n" << endl;
						break;
					case 4:
						cout << "5 - Entrar na Era Medieval" << "\n" << endl;
						cout << "2 - Entrar no Japão Feudal" << "\n" << endl;
						cout << "6 - Entrar no Piscinão de Ramos" << "\n" << endl;
						break;
					case 5:
						cout << "4 - Entrar na Amazônia" << "\n" << endl;
						cout << "3 - Entrar no Cemitério do IBAMA" << "\n" << endl;
						cout << "6 - Entrar no Piscinão de Ramos" << "\n" << endl;
						break;
					case 6:
						theEnd1();
						return 9;										
				}
			} else {
				cout << "1 - Entrar na Huevânia" << "\n" << endl;
			}
			cout << "7 - Status do Personagem" << "\n" << endl;
			cout << "8 - Curar Personagem" << "\n" << endl;
			cout << "9 - Salvar Jogo e Sair" << "\n" << endl;
			cout << "10 - Sair sem Salvar" << "\n" << endl;
			cin >> op;
			return op;
		}

		void menuPause() {
			char x;
      		cout << "\nPressione X + ENTER para continuar .." << endl;
        	cin >> x;
		}

		// Métodos Gráficos do Calabouço

		void dungeonInimigo(char* nome) {
			cout << "Um wild "<< nome << " has aparecido" << "\n" << endl;
		}

		int dungeonMenuAtDef() {
			int op;
			while (1) {
			 system("clear");
			 cout << "O que você fará? " << "\n" << endl;
			 cout << "1 - Atacar" << "\n" << endl;
			 cout << "2 - Defender (20\% de chance) " << "\n" << endl;
			 cout << "3 - Usar Cura" << "\n" << endl;
			 cout << "4 - Ver Status" << "\n" << endl;
			 cout << "5 - Abandonar dungeon(GAME OVER)" << endl;
			 cin >> op;
			 if (op > 0 && op < 6)
			    return op;
			}
		}

		void vocePerdeu() {
			unsigned int microseconds;
			microseconds = 1000000;
			usleep(microseconds);
			cout << ".%%..%%...%%%%...%%..%%..........%%%%%...%%%%%%..%%%%%%..%%%%%..\n";
			usleep(microseconds);
			cout << "..%%%%...%%..%%..%%..%%..........%%..%%....%%....%%......%%..%%.\n";
			usleep(microseconds);
			cout << "...%%....%%..%%..%%..%%..........%%..%%....%%....%%%%....%%..%%.\n";
			usleep(microseconds);
			cout << "...%%....%%..%%..%%..%%..........%%..%%....%%....%%......%%..%%.\n";
			usleep(microseconds);
			cout << "...%%.....%%%%....%%%%...........%%%%%...%%%%%%..%%%%%%..%%%%%..\n";
			usleep(microseconds);
			cout << "................................................................\n";
		}

		void theEnd1() {
			unsigned int microseconds;
			microseconds = 1000000;
			cout << " /$$$$$$$$ /$$   /$$ /$$$$$$$$       /$$$$$$$$ /$$   /$$ /$$$$$$$  \n";  
			cout << "|__  $$__/| $$  | $$| $$_____/      | $$_____/| $$$ | $$| $$__  $$\n";
			cout << "   | $$   | $$  | $$| $$            | $$      | $$$$| $$| $$  \\ $$\n";
			cout << "   | $$   | $$$$$$$$| $$$$$         | $$$$$   | $$ $$ $$| $$  | $$\n";
			cout << "   | $$   | $$__  $$| $$__/         | $$__/   | $$  $$$$| $$  | $$\n";
			cout << "   | $$   | $$  | $$| $$            | $$      | $$\\  $$$| $$  | $$\n";
			cout << "   | $$   | $$  | $$| $$$$$$$$      | $$$$$$$$| $$ \\  $$| $$$$$$$/\n";
			cout << "   |__/   |__/  |__/|________/      |________/|__/  \\__/|_______/ \n";                                                                                                                         
			usleep(microseconds);
			system("clear");			
			theEnd2();
		}

		void theEnd2() {
			unsigned int microseconds;
			microseconds = 1000000;
			cout << "$$$$$$$$\\ $$\\   $$\\ $$$$$$$$\\       $$$$$$$$\\ $$\\   $$\\ $$$$$$$\\  \n";
			cout << "\\__$$  __|$$ |  $$ |$$  _____|      $$  _____|$$$\\  $$ |$$  __$$\\ \n";
			cout << "   $$ |   $$ |  $$ |$$ |            $$ |      $$$$\\ $$ |$$ |  $$ |\n";
			cout << "   $$ |   $$$$$$$$ |$$$$$\\          $$$$$\\    $$ $$\\$$ |$$ |  $$ |\n";
			cout << "   $$ |   $$  __$$ |$$  __|         $$  __|   $$ \\$$$$ |$$ |  $$ |\n";
			cout << "   $$ |   $$ |  $$ |$$ |            $$ |      $$ |\\$$$ |$$ |  $$ |\n";
			cout << "   $$ |   $$ |  $$ |$$$$$$$$\\       $$$$$$$$\\ $$ | \\$$ |$$$$$$$  |\n";
			cout << "   \\__|   \\__|  \\__|\\________|      \\________|\\__|  \\__|\\_______/ \n";                                                                                                            
			usleep(microseconds);		
			system("clear");
			theEnd3();
		}

		void theEnd3() {
			unsigned int microseconds;
			microseconds = 1000000;
			cout << " ________  __    __  ________        ________  __    __  _______  \n";
			cout << "/        |/  |  /  |/        |      /        |/  \\  /  |/       \\ \n";
			cout << "$$$$$$$$/ $$ |  $$ |$$$$$$$$/       $$$$$$$$/ $$  \\ $$ |$$$$$$$  |\n";
			cout << "   $$ |   $$ |__$$ |$$ |__          $$ |__    $$$  \\$$ |$$ |  $$ |\n";
			cout << "   $$ |   $$    $$ |$$    |         $$    |   $$$$  $$ |$$ |  $$ |\n";
			cout << "   $$ |   $$$$$$$$ |$$$$$/          $$$$$/    $$ $$ $$ |$$ |  $$ |\n";
			cout << "   $$ |   $$ |  $$ |$$ |_____       $$ |_____ $$ |$$$$ |$$ |__$$ |\n";
			cout << "   $$ |   $$ |  $$ |$$       |      $$       |$$ | $$$ |$$    $$/ \n";
			cout << "   $$/    $$/   $$/ $$$$$$$$/       $$$$$$$$/ $$/   $$/ $$$$$$$/  \n";                            
			usleep(microseconds);
			system("clear");
			theEnd4();
		}

		void theEnd4() {
			unsigned int microseconds;
			microseconds = 8000000;
			cout << " ________  __    __  ________        ________  __    __  _______    			\n";
			cout << "|        \\|  \\  |  \\|        \\      |        \\|  \\  |  \\|       \\   			\n";
			cout << " \\$$$$$$$$| $$  | $$| $$$$$$$$      | $$$$$$$$| $$\\ | $$| $$$$$$$\\  		\n";	
			cout << "   | $$   | $$__| $$| $$__          | $$__    | $$$\\| $$| $$  | $$  			\n";
			cout << "   | $$   | $$    $$| $$  \\         | $$  \\   | $$$$\\ $$| $$  | $$  		\n";	
			cout << "   | $$   | $$$$$$$$| $$$$$         | $$$$$   | $$\\$$ $$| $$  | $$  			\n";
			cout << "   | $$   | $$  | $$| $$_____       | $$_____ | $$ \\$$$$| $$__/ $$  			\n";
			cout << "   | $$   | $$  | $$| $$     \\      | $$     \\| $$  \\$$$| $$    $$  		\n";
			cout << "    \\$$    \\$$   \\$$ \\$$$$$$$$       \\$$$$$$$$ \\$$   \\$$ \\$$$$$$$  	\n"; 
			usleep(microseconds);
			system("clear");
                                                   
		}
		void defenderAtaque() {
			cout << "Você conseguiu defender o ataque" << endl;
		}

		void ganhou(char* nome) {
            cout << "Você derrotou " << nome << " Parabéns!" << endl;
		}

		void acabouTurno() {
			cout << "Seu Turno acabou\n";
		}

		void ganhouItem() {
			system("clear");
			cout << "Você tem sorte! Não há inimigos neste calabouço somente tesouros, olhe seu inventário!" << endl;
		}

		// Métodos Gráficos para Item

		void itemEfeito(char* tipo, char* detalhe, int power) {
			cout << tipo << " usada, " << power << " "<< detalhe << "\n" << endl;
		}

		void itemDesc(char* nome, char* desc, int power) {
			cout << "Nome: " << nome << "  " << "Descrição: " << desc << "  " << "Valor Power: " << power << "  " << endl;
		}

		// Métodos Gráficos para Personagem

		void personagemStatus(char* nome, int vida, char* classe) {
			cout << "Nome: " << nome << endl;
			cout << "Classe: " << classe << endl;
			cout << "Quantidade de vida restante: " << vida << endl;
		}

		void personagemSemArmas() {
			cout << "Não há mais armas" << endl;
			menuPause();
		}

		void personagemSemCuras() {
			cout << "Sem Curas" << endl;
		}
		
		void personagemLifeCheio() {
			cout << "Life cheio" << endl;
		}

		void naoHaPerson() {
			system("clear");
			cout << "Não há personagem salvo\n";
			menuPause();
		}

		int personMax() {
			system("clear");
			cout << "Número máximo de personagens, deseja deletar?\n" << endl;
			cout << "1 - Sim\n" << "2 - Não\n" << endl;
			int valor;
			cin >> valor;
			return valor;
		}

		// Métodos Gráficos para Inimigo (e derivados dele)

		void inimigoAtaca(char* nome, int dano) {
			cout << nome << " atacou você. Receba " << dano << " de dano" << "\n" << endl;
		}

		void opcaoInvalida() {
			cout << "\nOpção Inválida";
			menuPause();
			system("clear");
		}
};

#endif
