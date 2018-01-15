//! Classe ListaCircular
/*! A lista circular possui os mesmos métodos e atributos da lista encadeada
* com a diferença que o elemento do início também é o fim da lista, possuindo
* assim, um elemento "sentinela" que indica o início e fim da lista.
*\n
* \author Copyright - Fabio Moreira
* \since 06/09/15
* \version 2.0
* \n
*/
//! \n Include "Elemento.hpp"
/*! Invoca a classe Elemento para ser usado aqui */

#include "Elemento.hpp"

//! \n Template
/*! Padrão para criar tipos genéricos */

template<typename T>

class ListaCirc {
 private:
    Elemento<T> *head;/*!< head - cabeça da lista, aponta para o 1º elemento.*/
    Elemento<T> *sentinela;/*!< sentinela - marca o início/fim da lista. */
    int size;/*!< int size - guarda o tamanho da lista. */

 public:
    //! ListaCirc()
    /*! \n Construtor - aloca recursos e inicializa head, sentinela e size.
    */

	ListaCirc() {
	 head = sentinela;
	 sentinela = NULL;
	 size = 0;
	}

	//! ~ListaCirc()
    /*! Destrutor - libera espaço na memória que foi alocado para o objeto.
    */

	~ListaCirc() {
	 destroiLista();
	}

	/*! adicionaNoInicio(const T& dado) - adiciona o dado informado pelo usuário
    * ao início da lista. 
    * \param dado a Type T
    */

	void adicionaNoInicio(const T& dado) {
	  Elemento<T> *novo = new Elemento<T>(dado, sentinela);
	  if (novo == NULL) {
	      throw "ErroMemóriaCheia";
	  } else {
	      size++;
	      sentinela = novo;
	  }
	}

	/*! retiraDoInicio() - retira do início da lista circular os ponteiros que 
    * apontam para os elementos e para o próximo elemento da lista encadeada sem
    * eliminar  a lista de elementos.
    * \return o dado que foi retirado.
    */

	T retiraDoInicio() {
	  Elemento<T> *elimina;
	  T retorna;
	  if (listaVazia()) {
	    throw "ListaVazia";
	  } else {
	    elimina = sentinela;
	    retorna = elimina->getInfo();
	    sentinela = elimina->getProximo();
	    size--;
	    elimina->~Elemento();
	  }
	  return retorna;
	}

    /*! eliminaDoInicio(const T& dado) - tem a mesma função que retiraDoInicio()
    * exceto que retira também a lista de elementos que um dos ponteiros 
    * removidos apontam.
    */

	void eliminaDoInicio() {
	  Elemento<T> *elimina;
	  T retorna;
	  if (listaVazia()) {
	    throw "ListaVazia";
	  } else {
	    elimina = sentinela;
	    retorna = elimina->getInfo();
	    sentinela = elimina->getProximo();
	    size--;
	    elimina->~Elemento();
	  }
	  return retorna;
	}

    /*! adicionaNaPosicao(const T& dado, int pos) - adiciona o dado informado 
    * pelo usuário na posicao também informada. 
    * \param dado a Type T
    * \param pos a Integer
    */

	void adicionaNaPosicao(const T& dado, int pos) {
	   Elemento<T> *anterior, *novo;
	   if (size < pos)
	    throw "TamanhoExcedeu";
	   if (pos == 0) {
	    adicionaNoInicio(dado);
	    return;
	   }
	   anterior = sentinela;
	   for (int i = 0; i < (pos-1) ; i++)
	    anterior = anterior->getProximo();
	   novo = new Elemento<T>(dado, NULL);
	   novo->setProximo(anterior->getProximo());
	   anterior->setProximo(novo);
	   size++;
	}

    /*! posicao(const T& dado) - verifica em que posição da lista se encontra
    * o dado informado e retorna ao usuário. 
    * \param dado a Type T
    * \return posicao se existir.
    */

	int posicao(const T& dado) const {
	  Elemento<T> *auxilia = sentinela;
	    for (int i = 0; i < size; i++) {
	        if (dado == auxilia->getInfo())
	            return i;
	       auxilia = auxilia->getProximo();
	    }
	    throw "ItemNãoEncontrado";
	}

    /*! posicaoMem(const T& dado) - semelhante a posicao(), verifica onde o 
    * o dado informado se encontra e retorna o endereço da memória. 
    * \param dado a Type T
    * \return o endereço do dado se existir.
    */

	T* posicaoMem(const T& dado) const {
	  Elemento<T> *atual = sentinela;
	    for (int i = 0; i < size; i++) {
	        if (dado == atual->getInfo())
	            return &(atual->getInfo());
	        atual = atual->getProximo();
	    }
	   throw "ERRO";
	}

     /*! contem(const T& dado) - verifica se a lista contém o elemento fornecido
    * e retorna para o usuário.
    * \param dado a Type T
    * \return se existir true, caso contrário, false.
    */

	bool contem(const T& dado) {
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

    /*! retiraDaPosicao(int pos) - pega a posição informada, encontra o dado,
    *  retira-o e retorna ao usuário.
    * \param posicao as Integer.
    * \return o dado retirado.
    */

	T retiraDaPosicao(int pos) {
	    if (listaVazia())
	     throw "ErroListaVazia";
	    if (pos > size)
	     throw "TamanhoExcedeu";
	    if (pos == 0)
	     return retiraDoInicio();
	    Elemento<T> *anterior, *elimina;
	    T eliminado;
	    anterior = sentinela;
	    for (int i = 0; i < pos-1; i++)
	      anterior = anterior->getProximo();
	    elimina = anterior->getProximo();
	    eliminado = elimina->getInfo();
	    anterior->setProximo(elimina->getProximo());
	    elimina->~Elemento();
	    this->size--;
	    return eliminado;
	}

	 /*! adiciona(const T& dado) - adiciona um novo elemento no fim da lista.
    * \param dado as Type T.
    */

	void adiciona(const T& dado) {
	  adicionaNaPosicao(dado, size);
	}

	/*! retira() - retira o último elemento da lista.
    * \return o dado retirado.
    */

	T retira() {
	  return retiraDaPosicao(size-1);
	}

    /*! retiraEspecifico(const T& dado) - busca e retira o elemento informado
	*  da lista.
    * \param dado as Type T.
    * \return o dado retirado.
    */

	T retiraEspecifico(const T& dado) {
	 if (listaVazia())
	   throw "Erro";
	 return retiraDaPosicao(posicao(dado));
	}

    /*! mostra(int pos) - busca e mostra o elemento que está na posição
	*  informada no parâmetro.
    * \param pos as Integer.
    * \return o dado procurado se existir.
    */

	T mostra(int pos) {
	  Elemento<T> *anterior;
	  T retorna;
	  if (listaVazia())
	   throw "Erro";
	  anterior = sentinela;
	  for (int i = 0; i < (pos-1) ; i++) {
	   if ( anterior->getProximo() != head)
	    anterior = anterior->getProximo();
	  }
	  retorna = anterior->getProximo()->getInfo();
	  return retorna;
	}

    /*! adicionaEmOrdem(const T& dado) - verifica onde o dado informado se
    * encaixa na lista e adiciona-o lá.
    * \param dado as Type T.
    */

	void adicionaEmOrdem(const T& data) {
	 if (listaVazia()) {
	    adicionaNoInicio(data);
	    return;
	  }
	  Elemento<T> *atual = sentinela;
	  Elemento<T> *adiciona = new Elemento<T>(data, NULL);
	  size++;
	  for (int i = 0; i < size-1; i++) {
	    if (maior(atual->getInfo(), data)) {
	        adiciona->setProximo(atual->getProximo());
	        break;
	    }
	    atual = atual->getProximo();
	  }
	  atual->setProximo(adiciona);
	}

    /*! verUltimo() - retorna a info do último elemento da lista.
    */
	int verUltimo() {
	  if (listaVazia())
	   throw "Erro";
	  return mostra(size);
	}

	/*! listaVazia() - verifica se a lista está vazia.*/

	bool listaVazia() const {
	  return (size == 0);
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

	void destroiLista() {
	  Elemento<T> *atual, *anterior;
       anterior = sentinela;
       for (int i = 0; i < size ; i++) {
         if (anterior->getProximo() != sentinela)
          atual = anterior->getProximo();
         anterior->~Elemento();
         anterior = atual;
       }
      size = 0;
	}
};
