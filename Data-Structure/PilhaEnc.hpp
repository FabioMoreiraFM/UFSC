//! Classe Pilha Encadeada
/*!Sua função é executar funções como uma pilha real
 * através de seus métodos.
 * Realiza funções básicas, tais como empilhar, desempilhar, com a diferença
 * que não possui um tamanho fixo e sua forma de implementação se dá por pontei-
 * ros.
 * \n
 * \author Copyright - Fabio Moreira
 * \since 11/09/15
 * \version 1.0
 * \n
 */
#include "Elemento.hpp"

template<typename T>
//! \n Template
/*! template<typename T> Necessário para a criação de templates */

class PilhaEnc{
 private:
    Elemento<T> *top;   /*!< Elemento<T> *top - topo da pilha. */
    int altura;         /*!< int altura - tamanho atual da pilha. */

 public:
    //! PilhaEnc()
    /*! \n inicializa a pilha setando NULL para o topo da pilha e zerando seu
    *tamanho.
    */

    PilhaEnc() {
        top = NULL;
        altura = 0;
    }

    /*! ~PilhaEnc() - destrutor da pilha, remove seus elementos. */

    ~PilhaEnc() {
        limparPilha();
    }

    /*! empilha(const T& dado) - usado para receber um valor e guardar na pilha.
    * Armazena o valor recebido no topo da pilha.
    * \param dado
    */

    void empilha(const T& dado) {
        Elemento<T> *novo = new Elemento<T>(dado, top);
        top = novo;
        altura++;
    }

    /*!  desempilha() -
    * Contrário ao método empilha, desempilha() retira o elemento do topo
    * da pilha
    * \return retorna o dado retirado da pilha
    */

    T desempilha() {
     if (PilhaVazia())
       throw "listaVazia";
     Elemento<T> *elimina = top;
     top = elimina->getProximo();
     T info = elimina->getInfo();
     altura--;
     elimina->~Elemento();
     return info;
    }

    /*! topo() - Informa o valor que está no topo da pilha, verificando se há um
    * topo.*/

	T topo() {
	   if (PilhaVazia()) {
	        throw 1;
	   } else {
	    return top->getInfo();
	   }
	}

    /*! limparPilha() - Destroi os elementos presentes na pilha. */

	void limparPilha() {
	    Elemento<T> *anterior, *atual;
	    anterior = top;
	    for (int i = 0 ; i < altura ; i++) {
	        atual = anterior->getProximo();
	        anterior->~Elemento();
	        anterior = atual;
	    }
	    altura = 0;
	}

	/*! PilhaVazia() - Verifica se a pilha está vazia. */

	bool PilhaVazia() {
	    return (altura == 0);
	}
};
