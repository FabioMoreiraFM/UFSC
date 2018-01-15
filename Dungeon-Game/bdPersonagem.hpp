#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "personagem.hpp"
#include <pqxx/pqxx> 

using namespace std;
using namespace pqxx;

class BdPersonagem {
	public:
		int verificar() {
	         char * sql;
	         int valor;
	         try{
	            connection C("dbname=teste user=postgres password=postgres \
	            hostaddr=127.0.0.1 port=5432");
	            if (!C.is_open())
					cout << "Can't open database" << endl;

	            /* Create SQL statement */
	            sql = "SELECT COUNT(*) from PERSONAGEM";

	            /* Create a non-transactional object. */
	            nontransaction N(C);
	            
	            /* Execute SQL query */
	            result R( N.exec( sql ));

	            /* List down all the records */
	            for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
	                valor = c[0].as<int>();
	            }
	            C.disconnect ();
	         }catch (const std::exception &e){
	            cerr << e.what() << std::endl;
	         }
	        if (valor)
	        	return 0;
	        else 
	        	return 1;
		}

		Personagem* carregarPersonagem(int &ultimaDungeonNavegada) {
	         char * sql;
	         string nome, classe;
	         int vida;
	         try{
	            connection C("dbname=teste user=postgres password=postgres \
	            hostaddr=127.0.0.1 port=5432");
	            if (!C.is_open())
					cout << "Can't open database" << endl;

	            /* Create SQL statement */
	            sql = "SELECT * from PERSONAGEM";

	            /* Create a non-transactional object. */
	            nontransaction N(C);
	            
	            /* Execute SQL query */
	            result R( N.exec( sql ));
	         
	            /* List down all the records */
	            for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
	                nome = c[0].as<string>();
	                classe = c[1].as<string>();
	                vida = c[2].as<int>();
	                ultimaDungeonNavegada = c[3].as<int>();
	            }
	            C.disconnect ();
	         }catch (const std::exception &e){
	            cerr << e.what() << std::endl;
	         }
	         char *name = new char[nome.length()+1];
			 memcpy(name, nome.c_str(), nome.length() + 1);

	         char *classeP = new char[classe.length()+1];
			 memcpy(classeP, classe.c_str(), classe.length() + 1);

	         Personagem* person = new Personagem(name,classeP,vida);
	         return person;
		}

		void salvarPersonagem(char* nome, char* classe, int vida, int ultimaDungeonNavegada) {
		   char * sql;
		   try{
		      connection C("dbname=teste user=postgres password=postgres \
		      hostaddr=127.0.0.1 port=5432");
		      if (!C.is_open())
				cout << "Can't open database" << endl;

		      char cmd_sql[256];

		      sprintf(cmd_sql,"INSERT INTO PERSONAGEM (NOME,CLASSE,VIDA,ULTDUN) VALUES ('%s','%s',%d,%d);",nome,classe,vida,ultimaDungeonNavegada);
		      /* Create SQL statement */
		      sql = cmd_sql;

		      /* Create a transactional object. */
		      work W(C);
		      
		      /* Execute SQL query */
		      W.exec( sql );
		      W.commit();
		      C.disconnect ();
		   }catch (const std::exception &e){
		      cerr << e.what() << std::endl;
		   }
		}

		void deletarPersonagem() {
			char * sql;
			try{
			   connection C("dbname=teste user=postgres password=postgres \
			   hostaddr=127.0.0.1 port=5432");
			   if (!C.is_open())
			   		cout << "Can't open database" << endl;
			   
			   /* Create a transactional object. */
			   work W(C);
			   
			   /* Create  SQL DELETE statement */
			   sql = "DELETE from PERSONAGEM";
			   /* Execute SQL query */
			   W.exec(sql);
			   W.commit();

			   C.disconnect ();
			}catch (const std::exception &e){
			   cerr << e.what() << std::endl;
			}
		}
};