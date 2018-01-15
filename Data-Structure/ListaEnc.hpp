//! Classe Lista Encadeada
/*! Uma função mais avançada e otimizada da lista de vetor não consome uma
* quantidade de memória tão grande, comporta vários tipos de dados.
*   Possui uma cabeça de lista e um tamanho, a cabeça aponta para o próximo
* elemento da lista que possui informações manipuladas por um ponteiro e que
* também possui outro ponteiro apontado para o próximo elemento da lista.
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

class ListaEnc {
 public:
    //! ListaEnc()
    /*! \n Construtor - aloca recursos e inicializa head e size.
    */
	ListaEnc() {
	    head = NULL;
	    size = 0;
	}

  //! ~ListaEnc()
   /*! Destrutor - libera espaço na memória que foi alocado para o objeto.
    */
	~ListaEnc() {
	    destroiLista();
	}

    /*! adicionaNoInicio(const T& dado) - adiciona o dado informado pelo usuário
    * ao início da lista. 
    * \param dado a Type T
    */

	void adicionaNoInicio(const T& dado) {
	    Elemento<T> *novo = new Elemento<T>(dado, head);
	    if (novo == NULL) {
	        throw "ErroMemóriaCheia";
	    } else {
	        size++;
	        head = novo;
	    }
	}

    /*! retiraDoInicio() - retira do início da lista encadeada os ponteiros que 
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
	    elimina = head;
	    retorna = elimina->getInfo();
	    head = elimina->getProximo();
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
	   Elemento<T> *elimina = head;
	   if (listaVazia()) {
	    throw "ListaVazia";
	  } else {
	    elimina = head;
	    head = elimina->getProximo();
	    size--;
	    elimina->~Elemento();
	  }
	}

    /*! adicionaNoInicio(const T& dado, int pos) - adiciona o dado informado 
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
	   anterior = head;
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
	    Elemento<T> *auxilia = head;
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
	    Elemento<T> *atual = head;
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
	    Elemento<T> *auxilia = head;
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
	    if (pos > size-1)
	     throw "TamanhoExcedeu";
	    if (pos == 0)
	     return retiraDoInicio();
	    Elemento<T> *anterior, *elimina;
	    T eliminado;
	    anterior = head;
	    for (int i = 0; i < pos-1 ; i++)
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
	    return retiraDaPosicao(size);
	}

	/*! retiraEspecifico(const T& dado) - busca e retira o elemento informado
	*  da lista.
    * \param dado as Type T.
    * \return o dado retirado.
    */

	T retiraEspecifico(const T& dado) {
	    if (listaVazia())
	       throw "Erro";
	    int pos = posicao(dado);
	    T retira = retiraDaPosicao(pos);
	    return retira;
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
		Elemento<T>* novo = new Elemento<T>(dado,NULL);
		Elemento<T>* temp = head;
		int tmp;
		while (temp != NULL || temp->getInfo() < data) {
			temp = temp->getProximo();
			tmp++;
		}
		if (temp == NULL)
			adicionaNaPosicao(dado, tmp);
		else
			adicionaNaPosicao(data,tmp+1);
	}

    /*! listaVazia() - verifica se a lista está vazia.*/
	bool listaVazia() const {
	    return (size == 0);
	}

    /*! igual(T dado1, T dado2) - verifica se os dados são iguais.*/
	bool igual(T dado1, T dado2) {
	    return  (dado1 == dado2);
	}

    /*! maior(T dado1, T dado2) - verifica se o dado1 é maior que o dado2.*/
	bool maior(T dado1, T dado2) {
	    return (dado1 > dado2);
	}

    /*! menor(T dado1, T dado2) - verifica se o dado1 é menor que o dado2.*/
	bool menor(T dado1, T dado2) {
	    return (dado1 < dado2);
	}

    /*! destroiLista() - chamado pelo destrutor para eliminar todos os itens
    * da lista e liberar memória.
    */

	void destroiLista() {
       Elemento<T> *atual, *anterior;
       anterior = head;
       for (int i = 0; i < size ; i++) {
         atual = anterior->getProximo();
         anterior->~Elemento();
         anterior = atual;
       }
        size = 0;
	}

 private:
	Elemento<T>* head; /*!< head - cabeça da lista, aponta para o 1º elemento.*/
	int size; /*!< int size - guarda o tamanho da lista. */
};
