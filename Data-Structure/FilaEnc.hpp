//! Classe FilaEnc
/*!Semelhante a PilhaEnc, realiza funções iguais a uma fila da vida real
 * inclui dados no final da fila, retira dados do início da fila.
 * Sua diferença com a fila de vetor é o seu tamanho indefinido.
 * \n
 * \author Copyright - Fabio Moreira
 * \since 11/09/15
 * \version 1.0
 * \n
 */
#include "Elemento.hpp"

template <typename T>
//! \n Template
/*! template<typename T> Necessário para a criação de templates */

class FilaEnc{
 private:
    Elemento<T> *inicio, *fim; /*!< Ponteiros que indicam inicio e fim da fila*/
    int tamanho;  /*!< int tamanho - tamanho da fila */

 public:
    //! FilaEnc()
    /*! 
    * Inicializa a fila, ponteiros inicio e fim recebem NULL
    * e tamanho é zerado, indicando que não há elementos.
    */

	FilaEnc<T>() {
	    inicio = NULL;
	    fim = NULL;
	    tamanho = 0;
	}

	/*! ~FilaEnc() - Destrutor. Destrói os elementos da fila.*/

	~FilaEnc() {
	    limparFila();
	}

	/*! método inclui(const T& dado) - usado para receber um valor e guardar
    * na fila, armazena o valor recebido no final da fila.
    * \param dado
    */

	void inclui(const T& dado) {
	    Elemento<T> *adiciona = new Elemento<T>(dado, NULL);
	    if (filaVazia()) {
	        inicio = adiciona;
	    } else {
	        fim->setProximo(adiciona);
	    }
	    fim = adiciona;
	    tamanho++;
	}

	/*! Contrário ao método inclui(const T& dado), retira() retira o elemento 
    * do início da fila.
    * \return retorna o dado retirado da fila
    */

	T retira() {
	    Elemento<T> *retira;
	    T retirado;
	    if (filaVazia())
	        throw "Erro";
	    retira = inicio;
	    retirado = retira->getInfo();
	    inicio = retira->getProximo();
	    if (tamanho == 1)
	        fim = NULL;
	   tamanho--;
	   retira->~Elemento();
	   return retirado;
	}

	/*! ultimo() - Informa o valor que está no final da fila, verificando se há 
    * um topo. 
    */

	T ultimo() {
	    if (filaVazia())
	        throw "ERRO";
	    return fim->getInfo();
	}

	/*! primeiro() - retorna o valor do primeiro elemento da fila.
	* \return primeiro dado da fila.
	*/

	T primeiro() {
	    return inicio->getInfo();
	}

	/*! filaVazia() -  Verifica se a fila está vazia */

	bool filaVazia() {
	    return (tamanho == 0);
	}

	/*! limparFila() -  elimina todos os elementos da fila. */

	void limparFila() {
	    Elemento<T> *anterior, *atual;
	    anterior = inicio;
	    for (int i = 0; i < tamanho; i++) {
	        atual = anterior->getProximo();
	        anterior->~Elemento();
	        anterior = atual;
	    }
	    tamanho = 0;
	}
};

