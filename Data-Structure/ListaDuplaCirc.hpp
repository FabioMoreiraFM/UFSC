//! Classe ListaDuplaCircular
/*! Funciona da mesma forma que a lista circular
* mas possuindo ponteiro tanto do próximo elemento quanto do anterior.
*\n
* \author Copyright - Fabio Moreira
* \since 11/09/15
* \version 1.0
* \n
*/
//! \n Include "Elemento.hpp"
/*! Invoca a classe Elemento para ser usado aqui */
#include "Elemento.hpp"

template<typename T>
//! \n Template
/*! Padrão para criar tipos genéricos */

class ListaDuplaCirc {
 private:
    Elemento<T> *head; /*!< head - cabeça da lista, aponta para o 1º elemento.*/
    Elemento<T> *sentinela; /*!< sentinela - indica inicio/fim da lista.*/
    int size;/*!< int size - guarda o tamanho da lista. */

 public:
    //! ListaCirc()
    /*! \n Construtor - aloca recursos e inicializa head, sentinela e size.
    */

	ListaDuplaCirc() {
	 head = sentinela;
	 sentinela = NULL;
	 size = 0;
	}

    //! ~ListaCirc()
    /*! Destrutor - libera espaço na memória que foi alocado para o objeto.
    */

	~ListaDuplaCirc() {
	 destroiListaDuplo();
	}

    /*! adicionaNoInicioDuplo(const T& dado) - adiciona o dado informado pelo 
    * usuário ao início da lista. 
    * \param dado a Type T
    */

	void adicionaNoInicioDuplo(const T& dado) {
	  Elemento<T> *novo = new Elemento<T>(dado, sentinela, NULL);
	  if (novo == NULL) {
	      throw "ErroMemóriaCheia";
	  } else {
	       if (this->listaVazia()) {
	        novo->setProximo(sentinela);
	        novo->setAnterior(sentinela);
	       }
	       size++;
	       sentinela = novo;
	       if (novo->getProximo() != NULL)
	        novo->getProximo()->setAnterior(novo);
	  }
	}

	/*! retiraDoInicioDuplo() - retira do início da lista circular os ponteiros 
    * que apontam para os elementos e para o próximo elemento da lista encadeada 
    * sem eliminar  a lista de elementos.
    * \return o dado que foi retirado.
    */

	T retiraDoInicioDuplo() {
	 Elemento<T> *elimina;
     T retorna;
     if (listaVazia()) {
      throw "ListaVazia";
     } else {
      elimina = sentinela;
      retorna = elimina->getInfo();
      sentinela = elimina->getProximo();
      elimina->getProximo()->setAnterior(elimina->getAnterior());
      size--;
      elimina->~Elemento();
     }
     return retorna;
	}

    /*! eliminaDoInicioDuplo(const T& dado) - tem a mesma função que
    * retiraDoInicio() exceto que retira também a lista de elementos que um dos 
    * ponteiros removidos apontam.
    */

	void eliminaDoInicioDuplo() {
	 Elemento<T> *elimina;
     T retorna;
     if (listaVazia()) {
      throw "ListaVazia";
     } else {
      elimina = sentinela;
      retorna = elimina->getInfo();
      sentinela = elimina->getProximo();
      elimina->getProximo()->setAnterior(elimina->getAnterior());
      size--;
      elimina->~Elemento();
     }
     return retorna;
	}

    /*! adicionaNaPosicaoDuplo(const T& dado, int pos) - adiciona o dado 
    * informado pelo usuário na posicao também informada. 
    * \param dado a Type T
    * \param pos a Integer
    */

	void adicionaNaPosicaoDuplo(const T& dado, int pos) {
	 if (size < pos) {
      throw "ErroValorExcedeu";
     }
     if (pos == 0) {
      adicionaNoInicioDuplo(dado);
      return;
     }
     Elemento<T> *temp = sentinela;
     for (int i = 0; i < pos-1 ; i++)
        temp = temp->getProximo();
     Elemento<T> *novo = new Elemento<T>(dado, NULL, NULL);
     novo->setAnterior(temp);
     if (temp->getProximo() != NULL)
      temp->getProximo()->setAnterior(novo);
     novo->setProximo(temp->getProximo());
     temp->setProximo(novo);
     size++;
	}

    /*! posicaoDuplo(const T& dado) - verifica em que posição da lista se
    * encontra o dado informado e retorna ao usuário. 
    * \param dado a Type T
    * \return posicao se existir.
    */

	int posicaoDuplo(const T& dado) const {
	 Elemento<T> *auxilia = sentinela;
     for (int i = 0; i < size; i++) {
      if (dado == auxilia->getInfo())
       return i;
      auxilia = auxilia->getProximo();
     }
     throw "ItemNãoEncontrado";
	}

    /*! posicaoMemDuplo(const T& dado) - semelhante a posicao(), verifica onde o 
    * o dado informado se encontra e retorna o endereço da memória. 
    * \param dado a Type T
    * \return o endereço do dado se existir.
    */

	T* posicaoMemDuplo(const T& dado) const {
	 Elemento<T> *atual = sentinela;
     for (int i = 0; i < size; i++) {
      if (dado == atual->getInfo())
       return &(atual->getInfo());
      atual = atual->getProximo();
     }
     throw "ERRO";
	}

    /*! contemDuplo(const T& dado) - verifica se a lista contém o elemento 
    * fornecido e retorna para o usuário.
    * \param dado a Type T
    * \return se existir true, caso contrário, false.
    */

	bool contemDuplo(const T& dado) {
	 int pos = -1;
     Elemento<T> *auxilia = sentinela;
     for (int i = 0; i < size; i++) {
      if (dado == auxilia->getInfo()) {
       pos = i;
      }
      auxilia = auxilia->getProximo();
     }
     return (pos >= 0);
	}

    /*! retiraDaPosicaoDuplo(int pos) - pega a posição informada, encontra o 
    * dado, retira-o e retorna ao usuário.
    * \param posicao as Integer.
    * \return o dado retirado.
    */

	T retiraDaPosicaoDuplo(int pos) {
      if (listaVazia())
  	      throw "Erro";
  	  if (pos > size-1) {
  	   throw "Erro";
  	  }
      if (pos == 0)
  	   return retiraDoInicioDuplo();
      Elemento<T> *elimina , *anterior = sentinela;
      T retirado;
      for (int i = 0; i < pos-1; i++)
         anterior = anterior->getProximo();
      elimina = anterior->getProximo();
      retirado = elimina->getInfo();
      anterior->setProximo(elimina->getProximo());
      if (elimina->getProximo() != NULL)
       elimina->getProximo()->setAnterior(anterior);
      elimina->~Elemento();
      size--;
      return retirado;
	}

    /*! adicionaDuplo(const T& dado) - adiciona um novo elemento no fim da lista
    * \param dado as Type T.
    */

	void adicionaDuplo(const T& dado) {
	  adicionaNaPosicaoDuplo(dado, size);
	}

    /*! retiraDuplo() - retira o último elemento da lista.
    * \return o dado retirado.
    */

	T retiraDuplo() {
	 if (this->listaVazia())
	  throw "ListaVazia";
	 return retiraDaPosicaoDuplo(size-1);
	}

    /*! retiraEspecificoDuplo(const T& dado) - busca e retira o elemento 
	* informado da lista.
    * \param dado as Type T.
    * \return o dado retirado.
    */

	T retiraEspecificoDuplo(const T& dado) {
	 if (listaVazia()) {
      throw "Erro";
     }
     int pos = posicaoDuplo(dado);
     T retira = retiraDaPosicaoDuplo(pos);
     return retira;
	}

    /*! mostra(int pos) - busca e mostra o elemento que está na posição
	*  informada no parâmetro.
    * \param pos as Integer.
    * \return o dado procurado se existir.
    */

	T mostra(int pos) {
	 Elemento<T> *temp = sentinela;
     int posicao = 0;
     while ((posicao < pos) < size) {
       temp = temp->getProximo();
       posicao++;
     }
     if (posicao > size)
      throw "ERRO";
     T mostraValor = temp->getInfo();
     return mostraValor;
	}

    /*! adicionaEmOrdem(const T& dado) - verifica onde o dado informado se
    * encaixa na lista e adiciona-o lá.
    * \param dado as Type T.
    */

	void adicionaEmOrdem(const T& data) {
	 if (listaVazia()) {
      adicionaNoInicioDuplo(data);
      return;
     }
     Elemento<T> *atual = sentinela;
     int posicao = 0;
     while (atual->getProximo() != sentinela && maior(data, atual->getInfo())) {
      atual = atual->getProximo();
      posicao++;
     }
     if (maior(data, atual->getInfo()))
      return (adicionaNaPosicaoDuplo(data, posicao+1));
     else
      return (adicionaNaPosicaoDuplo(data, posicao));
	}

    /*! verUltimo() - retorna a info do último elemento da lista.
    */

	int verUltimo() {
	  if (listaVazia())
	   throw "Erro";
	  return size-1;
	}

	/*! listaVazia() - verifica se a lista está vazia.*/

	bool listaVazia() const {
	 return size == 0;
	}

    /*! igual(T dado1, T dado2) - verifica se os dados são iguais.*/
	bool igual(T dado1, T dado2) {
	 return dado1 == dado2;
	}

	/*! maior(T dado1, T dado2) - verifica se o dado1 é maior que o dado2.*/
	bool maior(T dado1, T dado2) {
	 return dado1 > dado2;
	}

	/*! menor(T dado1, T dado2) - verifica se o dado1 é menor que o dado2.*/
	bool menor(T dado1, T dado2) {
	 return dado1 < dado2;
	}

    /*! destroiLista() - chamado pelo destrutor para eliminar todos os itens
    * da lista e liberar memória.
    */

	void destroiListaDuplo() {
	 Elemento<T> *atual, *anterior;
     anterior = sentinela;
     for (int i = 0; i < size ; i++) {
       if (anterior->getProximo() != sentinela) {
        atual = anterior->getProximo();
        anterior->~Elemento();
        anterior = atual;
       }
     }
     size = 0;
	}
};

