//! Classe Lista
    /*!Sua função é executar funções como uma lista real
    * através de seus métodos.
    * Lista pode inserir elementos e retirar elementos
    * seja do início, do fim, em uma determinada posição ou em uma ordem,
    * para funções de retirar elemento também é possível remover um item
    * específico.
    * \n
    * \author Copyright - Fabio Moreira
    * \since 29/08/15
    * \version 1.0
    * \n
    */
template <typename T>
//! \n Template
/*! template<typename T> Necessário para a criação de templates */

class Lista {
 private:
    int maxLista; /*!< int maxLista - tamanho máximo da lista */
    T* dados; /*!< T* dados - ponteiro para um vetor que armazena os dados. */
    int ultimo; /*!< int ultimo - aponta para o último elemento do vetor. */

 public:
    //! Lista()
    /*! \n destroiLista() - chama o método de mesmo nome, para limpar a variável
    * ultimo de possíveis "lixos".
    *\n
    * A segunda linha pede um espaço na memória para a criação do vetor dados.
    *\n E maxLista é definido como 100.
    * Para o segundo construtor Lista(int tam), maxLista recebe um valor
    * definido pelo usuário.
    */
	Lista() {
	    maxLista = 100;
	    dados = new T[maxLista];
	    destroiLista();
	}
	/*!  Pilha<T>(int t) - Já mencionado no comentário anterior*/
	explicit Lista(int tam) {
	    maxLista = tam;
	    dados = new T[maxLista];
	    destroiLista();
	}
    /*! adiciona(T dado) - adiciona o dado informado pelo usuário ao final 
    * da lista. 
    * \param dado a Type T
    */
	void adiciona(T dado) {
	    if (listaCheia()) {
	      throw "lista cheia";
	    } else {
	      ultimo++;
	      dados[ultimo] = dado;
	    }
	}
	/*! adicionaNoInicio(T dado) - adiciona o dado informado pelo usuário ao 
    * início da lista.
    * \param dado a Type T
    */
	void adicionaNoInicio(T dado) {
	    int posica;
	    if (listaCheia()) {
	       throw "lista cheia";
	    } else {
	        ultimo++;
	        posica = ultimo;
	        while (posica > 0) {
	            dados[posica] = dados[posica - 1];
	            posica--;
	       }
	        dados[0] = dado;
	    }
	}
	/*! adicionaNaPosicao(T dado, int posicao) - adiciona o dado informado pelo 
    * usuário na posição também informada por ele.
    * \param dado a type T
    * \param posicao an integer
    */
	void adicionaNaPosicao(T dado, int posicao) {
	    int posica;
	    if (listaCheia()) {
	        throw "lista cheia";
	    } else {
	        if ((posicao > (ultimo+1)) || (posicao < 0))
	            throw "erro de posição";
	        ultimo++;
	        posica = ultimo;
	       while (posica > posicao) {
	        dados[posica] = dados[posica-1];
	        posica--;
	       }
	       dados[posicao] = dado;
	    }
	}
	/*! adicionaEmOrdem(T dado) - adiciona o dado informado pelo usuário na
    * ordem estabelecida na lista.
    * \param dado a type T
    */
	void adicionaEmOrdem(T dado) {
	    int posicao;
	    if (listaCheia()) {
	        throw "lista cheia";
	    } else {
	        posicao = 0;
	        while ( posicao <= ultimo && maior(dado, dados[posicao]) ) {
	            posicao++;
	       }
	    }
	   return adicionaNaPosicao(dado, posicao);
	}
	/*! retira() - retira o último elemento da lista. 
	* \return o valor removido da lista no final.
	*/
	T retira() {
	    if (listaVazia()) {
	        throw "a lista está vazia";
	    } else {
	        ultimo--;
	        return (dados[ultimo+1]);
	    }
	}
	/*! retiraDoInicio() - retira o primeiro elemento da lista.
	* \return o valor removido da lista no início.
	*/
	T retiraDoInicio() {
	    int posica, valor;
	    if (listaVazia()) {
	     throw "lista vazia";
	    } else {
	        posica = 0;
	        ultimo--;
	        valor = dados[0];
	        while (posica <= ultimo) {
	            dados[posica] = dados[posica+1];
	            posica++;
	       }
	        return valor;
	    }
	}
	/*! retiraDaPosicao(int posicao) - retira o elemento da lista na posicao
	* informada pelo usuário. 
	* \param posicao an integer
	* \return dado retira da posição específica.
	*/
	T retiraDaPosicao(int posicao) {
	 int posica, valor;
	 if ((posicao > ultimo) || (posicao < 0)) {
	        throw "erro de posição";
	    } else {
	        if (listaVazia())
	            throw "lista vazia";
	        ultimo--;
	        valor = dados[posicao];
            posica = posicao;
	        while (posica <= ultimo) {
	            dados[posica] = dados[posica+1];
	            posica++;
	       }
	        return valor;
	   }
	}
	/*! retiraEspecifico(T dado) - retira o elemento da lista que for igual
	* ao dado informado pelo usuário. 
	* \param dado a type T
	* \return valor retirado informado pelo usuário.
	*/
	T retiraEspecifico(T dado) {
	    int lugar = 0;
	    if (listaVazia())
	        throw "está vazia";
	    else
	        lugar = posicao(dado);
	    return ((lugar < 0) ? throw "erro de posicao" : retiraDaPosicao(lugar));
	}
	/*! posicao(T dado) -  verifica a posição em que o dado informado pelo 
	* usuário se encontra na lista. 
	* \param dado a type T.
	* \return posição onde o dado se encontra na lista.
	*/
	int posicao(T dado) {
	    int posicao = 0;
	    while ( (posicao <= ultimo) && !(igual(dado , dados[posicao]) ) ) {
	        posicao++;
	   }
	    return (posicao > ultimo ? throw "erro posicao" : posicao);
	}
	/*! contem(T dado) - verifica se o dado informado pelo usuário está na lista
	* se positivo retorna a sua posição. 
	* \param dado a type T
	* \return se o dado se encontra na lista.
	*/
	bool contem(T dado) {
	    int posicao = 0;
	    while ( (posicao <= ultimo) && !(igual(dado , dados[posicao]) ) ) {
	        posicao++;
	   }
	    return (igual(dado, dados[posicao]));
	}
	/*! igual(T dado1, T dado2) - verifica se os dados são iguais. */
	bool igual(T dado1, T dado2) {
	    return (dado1 == dado2);
	}
	/*! maior(T dado1, T dado2) - verifica se os dado1 é maior que o dado2.*/
	bool maior(T dado1, T dado2) {
	    return (dado1 > dado2);
	}
	/*! menor(T dado1, T dado2) - verifica se os dado1 é menor que o dado2. */
	bool menor(T dado1, T dado2) {
	    return (dado1 < dado2);
	}
	/*! listaCheia() - verifica se a lista contém elementos. */
	bool listaCheia() {
	    return (ultimo == (maxLista-1));
	}
	/*! listaVazia() - verifica se a lista está vazia. */
	bool listaVazia() {
	    return (ultimo == -1);
	}
	/*! destroiLista() - reinicia a lista. */
	void destroiLista() {
	    ultimo = -1;
	}
};
