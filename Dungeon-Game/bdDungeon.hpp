#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <pqxx/pqxx> 

using namespace std;
using namespace pqxx;

class BdDungeon {
	public:
		string abrirHistoriaDungeon(int op) {
	         char * sql;
	         string historia;
	         try{
	            connection C("dbname=teste user=postgres password=postgres \
	            hostaddr=127.0.0.1 port=5432");
	            if (!C.is_open())
	            	cout << "Can't open database" << endl;

	            char c[1];
	            switch (op) {
	            	case 1:
	            		strcpy(c,"1");
	            		break;
	            	case 2:
	            		strcpy(c,"2");
	            		break;
	            	case 3:
	            		strcpy(c,"3");
	            		break;
	            	case 4:
	            		strcpy(c,"4");
	            		break;
	            	case 5:
	            		strcpy(c,"5");
	            		break;
	            	case 6:
	            		strcpy(c,"6");
	            		break;
	            }

	            char escolhido[50];
	            strcpy(escolhido,"SELECT historia from HISTORIADUNGEON WHERE COD =");
	            strcat(escolhido,c);
	            /* Create SQL statement */
	            sql = escolhido;

	            /* Create a non-transactional object. */
	            nontransaction N(C);
	            
	            /* Execute SQL query */
	            result R( N.exec( sql ));
	         
	            /* List down all the records */
	            for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
	               historia = c[0].as<string>();
	            }
	            C.disconnect ();
	         }catch (const std::exception &e){
	            cerr << e.what() << std::endl;
	         }
	         return historia;
		}
};