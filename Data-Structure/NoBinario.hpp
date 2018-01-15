//! Classe NoBinario
/*! Implementação de Árvore Binária de Busca com Percursos.
* Uma estrutura de dados mais eficiente que permite eliminar vários dados de uma
* vez ao invés de fazer uma comparação dado por dado, sendo este possível graças
* a organização hierárquica da árvore.
* \author Copyright - Fabio Moreira
* \since 11/10/15
* \version 1.0
* \n
*/

#ifndef NO_BINARIO_HPP
#define NO_BINARIO_HPP
#include <stdio.h>
#include <cstdlib>
#include <vector>

template <typename T>
//! \n Template
/*! Padrão para criar tipos genéricos */

class NoBinario {
 protected:
    T* dado; /*!< T* dado - ponteiro para a informação armazenada no nó.*/
    NoBinario<T>* esquerda; /*!< esquerda - ponteiro para o filho à esquerda.*/
    NoBinario<T>* direita; /*!< direita - ponteiro para o filho à direita.*/
    std::vector<NoBinario<T>* > elementos;  //!< Elementos acessados durante
                                            // o percurso realizado

 public:
    //! NoBinario<T>(const T& dado)
    /*! \n Construtor - recebe o dado que será apontado pelo nó, e 
    * inicializa os nós filhos.
    */

    NoBinario<T>(const T& dado) {
       esquerda = NULL;
       direita = NULL;
       this->dado = new T(dado);
    }

    //! ~NoBinario()
    /*! \n Destrutor - apaga todos os nós da árvore.
    */

    virtual ~NoBinario() {
     while (getEsquerda() != NULL) {
       delete minimo(this);
     }
     while (getDireita() != NULL) {
      delete maximo(this);
     }
    }

    //! T* getDado()
    /*! \return retorna o dado do nó.
    */

    T* getDado() {
     return dado;
    }

    //! std::vector< NoBinario<T>* > getElementos()
    /*! \return retorna os elementos acessados durante o percurso.
    */

    std::vector< NoBinario<T>* > getElementos() {
     return elementos;
    }

    //! NoBinario<T>* getEsquerda()
    /*! \return retorna o valor do nó filho à esquerda.
    */

    NoBinario<T>* getEsquerda() {
     return esquerda;
    }

    //! NoBinario<T>* getDireita()
    /*! \return retorna o valor do nó filho à direita.
    */

    NoBinario<T>* getDireita() {
     return direita;
    }

    //! T* busca(const T& dado, NoBinario<T>* arv)
    /*! O dado que é passado no parâmetro é buscado a partir do nó
    * que é passado também por parâmetro e é retornado caso seja encontrado.
    * 
    */

    T* busca(const T& dado, NoBinario<T>* arv) {
      while (arv != NULL && *(arv->getDado()) != dado) {
       if ( *(arv->getDado()) < dado)
         arv = arv->getDireita();
       else
         arv = arv->getEsquerda();
      }
      if (arv == NULL) {
            throw "ERROBUSCA";
      } else {
            return arv->getDado();
      }
    }

    //!  NoBinario<T>* inserir(const T& dado, NoBinario<T>* arv)
    /*! insere um dado na árvore, com um algoritmo recursivo que verifica
    * se o dado é maior ou menor que aquele nó e se é nulo, caso não seja 
    * nulo, o método se chamará de forma recursiva passando como parâmetro
    * o nó à esquerda ou direita do nó original.
    */

    NoBinario<T>* inserir(const T& dado, NoBinario<T>* arv) {
      NoBinario<T>* novo;
      if (dado < *(arv->getDado())) {
       if (arv->getEsquerda() == NULL) {
        novo = new NoBinario<T>(dado);
        arv->setEsquerda(novo);
       } else {
        arv = inserir(dado, arv->getEsquerda());
       }
      } else {
       if (arv->getDireita() == NULL) {
        novo = new NoBinario<T>(dado);
        arv->setDireita(novo);
       } else {
        arv = inserir(dado, arv->getDireita());
       }
      }
      return novo;
    }

    //!  NoBinario<T>* remover(NoBinario<T>* arv, const T& dado)
    /*! o remove deve remover o dado sem alterar a organização da árvore.
    * por isso possui vários testes.
    * 1º - Se o nó não tem filhos, simplesmente o remove sem prejuízos
    * e seta o nó direito/esquerdo de seu ancestral para nulo.
    * 2º se possuir somente uma subárvore, exclui esse nó e sobe essa subárvore
    * 3º - se possuir duas subárvores filhas, ele procura o nó direito
    * se esse nó não possui descendente à esquerda ele é colocado no lugar,
    * se possui, esse nó ocupa o lugar do removido, para ocupar o lugar desse
    * realocado, olha para o nó dele e vê se há descendente à direita e segue 
    * o processo.
    */

    NoBinario<T>* remover(NoBinario<T>* arv, const T& dado) {
      NoBinario<T> *tmp, *filho;
      if (arv == NULL) {
        return arv;
      } else {
        if (dado < *(arv->getDado())) { // prox subarv à esquerda
         arv->setEsquerda(remover(arv->getEsquerda(), dado)); 
         return arv;
        } else {
         if (dado > *(arv->getDado())) { // prox subarv à direita
          arv->setDireita(remover(arv->getDireita(), dado));
          return arv;
         } else {
          if (arv->getDireita() != NULL && arv->getEsquerda() != NULL) {
           tmp = minimo(arv->getDireita());
           arv->setDado(*(tmp->getDado()));
           arv->setDireita(remover(arv->getDireita(), *(arv->getDado())));
           return arv;
         } else {
           tmp = arv;
           if (arv->getDireita() != NULL) {
            filho = arv->getDireita();
            return filho;
           } else {
            if (arv->getEsquerda() != NULL) {
             filho = arv->getEsquerda();
             return filho;
            } else {
             free(arv);
             return NULL;
            }
           }
          }
          }
        }
      }
    }

    //! NoBinario<T>* minimo(NoBinario<T>* nodo)
    /*! o minimo retorna o valor minímo encontrado na subárvore de raiz nodo. 
    */

    NoBinario<T>* minimo(NoBinario<T>* nodo) {
     NoBinario<T>* tmp = nodo;
     while (tmp->getEsquerda() != NULL) {
       tmp = minimo(tmp->getEsquerda());
     }
     return tmp;
    }

    //! NoBinario<T>* maximo(NoBinario<T>* nodo)
    /*! o maximo retorna o valor máximo encontrado na subárvore de raiz nodo.
    * Adicionado pra facilitar a visualização do destrutor.
    */

    NoBinario<T>* maximo(NoBinario<T>* nodo) {
     NoBinario<T>* tmp = nodo;
     while (tmp->getDireita() != NULL) {
           tmp = maximo(tmp->getDireita());
     }
     return tmp;
    }

    //! preOrdem(), emOrdem() e posOrdem()
    /*! Os três métodos citados acima percorrem a árvore.
    * preOrdem - percorre primeiro a raiz depois o nó esquerdo e direito.
    * emOrdem - percorre primeiro o nó esquerdo depois a raiz e o nó direito.
    * posOrdem - percorre primeiro o nó esquerdo depois o nó direito e a raiz.
    */

    void preOrdem(NoBinario<T>* nodo) {
      if (nodo != NULL) {
        elementos.push_back(nodo);
        preOrdem(nodo->getEsquerda());
        preOrdem(nodo->getDireita());
      }
    }

    /*!< Já citado acima .*/

    void emOrdem(NoBinario<T>* nodo) {
      if (nodo != NULL) {
        emOrdem(nodo->getEsquerda());
        elementos.push_back(nodo);
        emOrdem(nodo->getDireita());
      }
    }

    /*!< Já citado acima.*/

    void posOrdem(NoBinario<T>* nodo) {
      if (nodo != NULL) {
        posOrdem(nodo->getEsquerda());
        posOrdem(nodo->getDireita());
        elementos.push_back(nodo);
      }
    }

    /*!< setEsquerda - seta o nó esquerdo.*/
    void setEsquerda(NoBinario<T>* nodo) {
      this->esquerda = nodo;
    }

    /*!< setDireita - seta o nó direito.*/
    void setDireita(NoBinario<T>* nodo) {
      this->direita = nodo;
    }

    /*!< setDado - seta o dado no nó atual.*/
    void setDado(T dado) {
     *(this->dado) = dado;
    }
};

#endif /* NO_BINARIO_HPP */
