#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "item.hpp"
#include <pqxx/pqxx> 

using namespace std;
using namespace pqxx;

class BdItem {
	private:
		Item* curas[10];
		Item* armas[10];
	public:
		Item** carregarArmas() {
	         char* sql;
	         string nome, descricao;
	         int power, arma = 0, cura = 0, tipo;
	         try{
	            connection C("dbname=teste user=postgres password=postgres \
	            hostaddr=127.0.0.1 port=5432");
	            if (!C.is_open())
	            	cout << "Can't open database" << endl;

	            /* Create SQL statement */
	            sql = "SELECT * from ITEM WHERE TIPO = 1";

	            /* Create a non-transactional object. */
	            nontransaction N(C);
	            
	            /* Execute SQL query */
	            result R( N.exec( sql ));
	         
	            /* List down all the records */
	            for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
	                nome = c[0].as<string>();
	                descricao = c[1].as<string>();
	                tipo = c[2].as<int>();
	                power = c[3].as<int>();
	                
	                char *nomeC = new char[nome.length() + 1];
	                strcpy(nomeC, nome.c_str());
	                
	                char *descricaoC = new char[descricao.length() + 1];
	                strcpy(descricaoC, descricao.c_str());	                

	                armas[arma] =  new Item(nomeC,power,descricaoC,tipo);
	                arma++;
	            }
	            C.disconnect ();
	         }catch (const std::exception &e){
	            cerr << e.what() << std::endl;
	         }
	         return armas;
		}

		Item** carregarCuras() {
	         char* sql;
	         string nome, descricao;
	         int power, arma = 0, cura = 0, tipo;
	         try{
	            connection C("dbname=teste user=postgres password=postgres \
	            hostaddr=127.0.0.1 port=5432");
	            if (!C.is_open())
					cout << "Can't open database" << endl;

	            /* Create SQL statement */
	            sql = "SELECT * from ITEM WHERE TIPO = 0";

	            /* Create a non-transactional object. */
	            nontransaction N(C);
	            
	            /* Execute SQL query */
	            result R( N.exec( sql ));
	         
	            /* List down all the records */
	            for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
	                nome = c[0].as<string>();
	                descricao = c[1].as<string>();
	                tipo = c[2].as<int>();
	                power = c[3].as<int>();
	                
	                char *nomeC = new char[nome.length() + 1];
	                strcpy(nomeC, nome.c_str());
	                
	                char *descricaoC = new char[descricao.length() + 1];
	                strcpy(descricaoC, descricao.c_str());	                
	                
	                curas[cura] = new Item(nomeC,power,descricaoC,tipo);
	                cura++;
	            }
	            C.disconnect ();
	         }catch (const std::exception &e){
	            cerr << e.what() << std::endl;
	         }
	         return curas;
		}

		void salvarItem(char* nome, char* desc, int power, int tipo) {
		   char* sql;
		   try{
		      connection C("dbname=teste user=postgres password=postgres \
		      hostaddr=127.0.0.1 port=5432");
		      if (!C.is_open())
		      	cout << "Can't open database" << endl;

		      char cmd_sql[256];

		      sprintf(cmd_sql,"INSERT INTO ITEM (NOME,DESCRICAO,TIPO,POWER) VALUES ('%s','%s',%d,%d);",nome,desc,tipo,power);
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

		void deletarItem() {
			char * sql;
			try{
			   connection C("dbname=teste user=postgres password=postgres \
			   hostaddr=127.0.0.1 port=5432");
			   if (!C.is_open())
			   		cout << "Can't open database" << endl;
			   
			   /* Create a transactional object. */
			   work W(C);

			   /* Execute SQL query */
			   sql = "DELETE FROM ITEM";
			   W.exec( sql );
			   W.commit();

			   C.disconnect ();
			}catch (const std::exception &e){
			   cerr << e.what() << std::endl;
			}
		}
};