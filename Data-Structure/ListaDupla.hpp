//! Classe ListaDupla
/*! Uma função mais avançada e otimizada da lista encadeada,
* comporta vários tipos de dados.
*\n
*   Possui uma cabeça de lista e um tamanho, a cabeça aponta para o próximo
* elemento da lista que possui informações manipuladas por um ponteiro e que
* também possui outro ponteiro apontado para o próximo elemento da lista.
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

class ListaDupla {
 private:
    Elemento<T> *head; /*!< head - cabeça da lista, aponta para o 1º elemento.*/
    int size;          /*!< int size - guarda o tamanho da lista. */

 public:
    //! ListaDupla()
    /*! \n Construtor - aloca recursos e inicializa head e size.
    */

	ListaDupla() {
	    head = NULL;
	    size = 0;
	}

	//! ~ListaDupla()
    /*! Destrutor - libera espaço na memória que foi alocado para o objeto.
    */

	~ListaDupla() {
	    destroiListaDuplo();
	}

    /*! adicionaNoInicioDuplo(const T& dado) - adiciona o dado informado 
    * pelo usuário ao início da lista. 
    * \param dado a Type T
    */

	void adicionaNoInicioDuplo(const T& dado) {
	   Elemento<T> *novo = new Elemento<T>(dado, head, NULL);
	   head = novo;
	   if (novo->getProximo() != NULL)
	    novo->getProximo()->setAnterior(novo);
	   size++;
	}

    /*! retiraDoInicioDuplo() - retira do início da lista encadeada os ponteiros 
    * que apontam para os elementos e para o próximo elemento da lista encadeada 
    * sem eliminar  a lista de elementos.
    * \return o dado que foi retirado.
    */

	T retiraDoInicioDuplo() {
	    if (listaVazia())
	      throw "Erro";
	    Elemento<T> *elimina = head;
	    T eliminado = elimina->getInfo();
	    head = elimina->getProximo();
	    if (head != NULL)
	      head->setAnterior(NULL);
	    elimina->~Elemento();
	    size--;
	    return eliminado;
	}

    /*! eliminaDoInicioDuplo() - tem a mesma função que retiraDoInicioDuplo()
    * exceto que retira também a lista de elementos que um dos ponteiros 
    * removidos apontam.
    */

	void eliminaDoInicioDuplo() {
	    retiraDoInicioDuplo();
	}

    /*! adicionaNaPosicaoDuplo(const T& dado, int pos) - adiciona o dado 
    * informado pelo usuário na posicao também informada. 
    * \param dado a Type T
    * \param pos a Integer
    */

	void adicionaNaPosicaoDuplo(const T& dado, int pos) {
	    if (size < pos)
	     throw "ErroValorExcedeu";
	    if (pos == 0) {
	       adicionaNoInicioDuplo(dado);
	       return;
	    }
	    Elemento<T> *temp = head;
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
	 Elemento<T> *auxilia = head;
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
	  Elemento<T> *atual = head;
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
	  Elemento<T> *auxilia = head;
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
	    if (pos > size-1)
	     throw "Erro";
	    if (pos == 0)
	     return retiraDoInicioDuplo();
	    Elemento<T> *elimina , *anterior = head;
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
	    return retiraDaPosicaoDuplo(size-1);
	}

    /*! retiraEspecificoDuplo(const T& dado) - busca e retira o elemento 
	* informado da lista.
    * \param dado as Type T.
    * \return o dado retirado.
    */

	T retiraEspecificoDuplo(const T& dado) {
	 if (listaVazia())
	  throw "Erro";
	 int pos = posicaoDuplo(dado);
     T retira = retiraDaPosicaoDuplo(pos);
	 return retira;
	}

    /*! mostra(int pos) - retorna o valor do elemento que se encontra na posição
    * informada pelo usuário.
    * \param pos as Integer.
    * \return elemento nessa posição.
    */

	T mostra(int pos) {
	    Elemento<T> *temp = head;
	    int posicao = 0;
	    while (posicao < pos) {
	     temp = temp->getProximo();
	     posicao++;
	    }
	    T mostraValor = temp->getInfo();
	    return mostraValor;
	}

    /*! adicionaEmOrdem(const T& data) - verifica onde o dado informado se
    * encaixa na lista e adiciona-o lá.
    * \param dado as Type T.
    */

	void adicionaEmOrdem(const T& data) {
	    if (listaVazia()) {
	        adicionaNoInicioDuplo(data);
	        return;
	    }
	    Elemento<T> *atual = head;
	    int posicao = 0;
	    while (atual->getProximo() != NULL && maior(data, atual->getInfo())) {
	        atual = atual->getProximo();
	        posicao++;
	    }
	    if (maior(data, atual->getInfo()))
	     return (adicionaNaPosicaoDuplo(data, posicao+1));
	    else
	     return (adicionaNaPosicaoDuplo(data, posicao));
	}

    /*! verUltimo() - retorna o valor do último elemento
    * \return último elemento 
    */

	int verUltimo() {
	    Elemento<T> *temp = head;
	    while (temp->getProximo() != NULL)
	        temp = temp->getProximo();
	    T ultimo = temp->getInfo();
	    return ultimo;
	}

    /*! listaVazia() - verifica se a lista está vazia.*/

	bool listaVazia() const {
	    return (size == 0);
	}

    /*! igual(T dado1, T dado2) - verifica se os dados são iguais.*/

	bool igual(T dado1, T dado2) {
	    return (dado1 == dado2);
	}

    /*! maior(T dado1, T dado2) - verifica se o dado1 é maior que o dado2.*/

	bool maior(T dado1, T dado2) {
	    return (dado1 > dado2);
	}

    /*! menor(T dado1, T dado2) - verifica se o dado1 é menor que o dado2.*/
	bool menor(T dado1, T dado2) {
	    return (dado1 < dado2);
	}

    /*! destroiListaDuplo() - chamado pelo destrutor para eliminar todos os 
    * itens da lista e liberar memória.
    */

	void destroiListaDuplo() {
	    Elemento<T> *atual, *anterior;
       anterior = head;
       for (int i = 0; i < size ; i++) {
         atual = anterior->getProximo();
         anterior->~Elemento();
         anterior = atual;
       }
        size = 0;
	}
};
