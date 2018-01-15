//! Classe Fila
/*!Semelhante a Pilha, realiza funções iguais a uma fila da vida real
 * inclui dados no final da fila, retira dados do início da fila.
 * \n
 * \author Copyright - Fabio Moreira
 * \since 22/08/15
 * \version 1.0
 * \n
 */

template <typename T>
//! \n Template
/*! template<typename T> Necessário para a criação de templates */

class Fila {
 private:
  int ultimoE;   /*!< verifica o último elemento da fila */
  T* dados;      /*!< vetor para armazenar os dados da fila */
  int maxpilha;  /*!< tamanho máximo da fila */

 public:
  //! Fila()
  /*! inicializaFila()  - chama o método de mesmo nome, para inicializar 
  * a variável ultimoE de possíveis "lixos".
  * 
  * A segunda linha atribiu um valor fixo para maxpilha indicando o tamanho
  * do vetor. Para Fila<T> esse valor é variável
  *
  * A keyword new pede um espaço na memória para ser armazenado os futuros
  * valores do vetor dados.
  */
	Fila() {
	 inicializaFila();
     maxpilha = 100;
     dados = new T[maxpilha];
    }
     /*!  Fila<T>(int t) - Já mencionado no comentário anterior */
	Fila<T>(int tam) {
     inicializaFila();
     maxpilha = tam;
     dados = new T[maxpilha];
    }
    /*! método inclui(T dado) - usado para receber um valor e guardar na fila
    * verifica se a fila está ou não cheia, caso esteja lança uma exceção
    * caso contrário armazena o valor recebido no final da fila
    * \param dado
    */
	void inclui(T dado) {
     if (filaCheia()) { throw 1;
     } else {
      ultimoE += 1;
      dados[ultimoE] = dado;
     }
    }
    /*! Contrário ao método inclui(T dado), retira() retira o elemento do início
    * da fila.
    * \return retorna o dado retirado da fila
    */
	T retira() {
	 T dado;   /*!< variável temporária para armazenar o primeiro valor; */
     if (filaVazia()) { throw 1;
     } else {
        dado = dados[0];
        for (int i = 0 ; i < ultimoE ; i++)
             dados[i] = dados[i+1];
        ultimoE -= 1;
     }
     return dado;
    }
    /*! ultimo() - Informa o valor que está no final da fila, verificando se há 
    * um topo. 
    */
	T ultimo() {
     if (filaVazia())
      throw 1;
     else
      return dados[ultimoE];
    }
    /*! getUltimo() - Informa qual o tamanho atual da fila */
	int getUltimo() {
     if (ultimoE == -1) throw 1;
     else
      return ultimoE;
    }
    /*! FilaCheia() - Verifica se a fila está cheia */
	bool filaCheia() {
     return (ultimoE == (maxpilha-1));
    }
    /*! FilaVazia() -  Verifica se a fila está vazia */
	bool filaVazia() {
     return (ultimoE == -1);
    }
    /*! inicializaFila() - Limpa o valor do ultimoE de possíveis "lixos" */
	void inicializaFila() {
     ultimoE = -1;
    }
};

