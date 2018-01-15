//! Classe Pilha
/*!Sua função é executar funções como uma pilha real
 * através de seus métodos.
 * Realiza funções básicas, tais como empilhar, desempilhar
 * \n
 * \author Copyright - Fabio Moreira
 * \since 22/08/15
 * \version 1.0
 * \n
 */


template<typename T>
//! \n Template
/*! template<typename T> Necessário para a criação de templates */

class Pilha {
 private:
  int topoP;  /*!< int topoP. */
  T* dados;   /*!< T* dados  - vetor que armazenará os valores inseridos */
  int maxpilha;  /*!< int maxpilha - tamanho máximo que o vetor assume. */

 public:
  //! Pilha()
  /*! \n limparPilha()  - chama o método de mesmo nome, para limpar a variável
  * topoP de possíveis "lixos".
  *\n
  * A segunda linha atribiu um valor fixo para maxpilha indicando o tamanho
  * do vetor. Para Pilha<T> esse valor é variável
  *\n
  * A keyword new pede um espaço na memória para ser armazenado os futuros
  * valores do vetor dados.
  */
  Pilha() {
    limparPilha();
    maxpilha = 100;
    dados = new T[maxpilha];
  }
  /*!  Pilha<T>(int t) - Já mencionado no comentário anterior*/
  Pilha<T>(int t) {
    limparPilha();
    maxpilha = t;
    dados = new T[maxpilha];
  }
  /*! empilha(T dado) - usado para receber um valor e guardar na pilha
  * verifica se a pilha está ou não cheia, caso esteja lança uma exceção
  * caso contrário armazena o valor recebido no topo da pilha
  * \param dado
  */
  void empilha(T dado) {
    if (PilhaCheia()) {throw 1;
    } else {
        topoP += 1;
        dados[topoP] = dado;
    }
  }
  /*!  desempilha() -
   * Contrário ao método empilha, desempilha() retira o elemento do topo da 
   * \return retorna o dado retirado da pilha
   */
  T desempilha() {
    if (PilhaVazia()) {throw 1;
    } else {
        topoP -= topoP;
        return (dados[topoP+1]);
    }
  }
  /*! topo() - Informa o valor que está no topo da pilha, verificando se há um
  * topo.*/
  T topo() {
    if (PilhaVazia())
     throw 1;
    else
     return dados[topoP];
  }
  /*! getPosTopo()- Informa qual o tamanho atual da Pilha */
  int getPosTopo() {
    if (topoP == -1) throw 1;
    else
     return topoP;
  }
  /*! limparPilha() - Limpa o valor do topo de possíveis "lixos" */
  void limparPilha() {
    topoP = -1;
  }
  /*! PilhaVazia() -  Verifica se a pilha está vazia */
  bool PilhaVazia() {
    return (topoP == -1);
  }
  /*! PilhaCheia() - Verifica se a pilha está cheia */
  bool PilhaCheia() {
    return (topoP == (maxpilha-1));
  }
};
