//! Classe NoAVL
 /*! Implementação de Árvore AVL-balanceada
 * Semelhante implementação de uma árvore binária de busca com percurso, com a
 * a diferença que a árvore será balanceada, não permitindo que um dos lados do
 * nó seja muito maior do que o outro.
 * \author Copyright - Fabio Moreira
 * \since 02/11/15
 * \version 1.0
 * \n
 */
#ifndef NO_AVL_HPP
#define NO_AVL_HPP
#include <stdio.h>
#include <vector>

template <typename T>
//! \n Template
/*! Padrão para criar tipos genéricos */

class NoAVL  {
 private:
    int altura;  //!< Representa a altura do nó AVL
    T* dado;  //!< Ponteiro para a info que o nó aponta.
    NoAVL<T>* esquerda;  //!< filho da esquerda do nó.
    NoAVL<T>* direita;  //!< filho da direita do nó.
    std::vector<NoAVL<T>* > elementos;  //!< Elementos acessados durante
                                        // o percurso realizado

 public:
    //! NoAVL<T>(const T& dado)
    /*! \n Construtor - recebe o dado que será apontado pelo nó, e 
    * inicializa os nós filhos.
    */
    explicit NoAVL(const T& dado) {
     esquerda = NULL;
     direita = NULL;
     this->dado = new T(dado);
     altura = 0;
    }

    //! ~NoAVL()
    /*! \n Destrutor - apaga todos os nós da árvore.
    */
    virtual ~NoAVL() {
     while (getEsquerda() != NULL) {
       delete minimo(this);
     }
     while (getDireita() != NULL) {
      delete maximo(this);
     }
    }

    //!< retorna altura do nó.

    int getAltura() {
     return this->altura;
    }

    //!< seta a altura do nó.

    void setAlt(int altura) {
     this->altura =  altura;
    }

    //!< retorna a altura do nó, verificando se os filhos são nulos.

    int alturaNo(NoAVL<T>* subArv) {
      if (subArv == NULL) {
       return -1;
      } else {
       return subArv->getAltura();
      }
    }

    //! std::vector< NoAVL<T>* > getElementos()
    /*! \return retorna os elementos acessados durante o percurso.
    */

    std::vector<NoAVL<T>* > getElementos() {
     return elementos;
    }

    //!< atualiza a altura do nó fazendo max(altura do filhos)+1.

    void upAltura(NoAVL<T> *arv) {
     int altura;
     if (alturaNo(arv->getEsquerda()) > alturaNo(arv->getDireita()))
      altura = alturaNo(arv->getEsquerda());
     else
      altura = alturaNo(arv->getDireita());
     arv->setAlt(altura+1);
    }

    //! NoAVL<T>* getEsquerda()
    /*! \return retorna o valor do nó filho à esquerda.
    */

    NoAVL<T>* getEsquerda() {
     return esquerda;
    }

    //! NoAVL<T>* getDireita()
    /*! \return retorna o valor do nó filho à direita.
    */

    NoAVL<T>* getDireita() {
     return direita;
    }

    //!< simp_rot_esq() -faz uma rotação simples à esquerda.
    // rotação simples à esquerda significa que eu pego os elementos da esquerda e os rotaciono para a direita;=.
    NoAVL<T>* simp_rot_esq(NoAVL<T>* k2) {
     NoAVL<T>* k1 = k2->getEsquerda(); // Eu criei um ponteiro que aponta para o elemento k2->getDireita, cuidado pra não achar que que k1 aponta pra ele mesmo
     k2->setEsquerda(k1->getDireita());
     k1->setDireita(k2);
     upAltura(k2);
     upAltura(k1);
     return k1;
    }

    //!< simp_rot_dir() - faz uma rotação simples à direita.

    NoAVL<T>* simp_rot_dir(NoAVL<T>* k2) {
     NoAVL<T>* k1 = k2->getDireita(); 
     k2->setDireita(k1->getEsquerda());
     k1->setEsquerda(k2);
     upAltura(k2);
     upAltura(k1);
     return k1;
    }

    //!< dup_rot_esq() - rotação dupla à esquerda a partir de rotações simples.

    NoAVL<T>* dup_rot_esq(NoAVL<T>* k3) {
     k3->setEsquerda(simp_rot_dir(k3->getEsquerda()));
     return simp_rot_esq(k3);
    }

    //!< dup_rot_dir() - rotação dupla à direita a partir de rotações simples.

    NoAVL<T>* dup_rot_dir(NoAVL<T>* k3) {
     k3->setDireita(simp_rot_esq(k3->getDireita()));
     return simp_rot_dir(k3);
    }

    //! NoAVL<T>* balancear(NoAVL<T>* arv, T dado)
    /*! Faz o balanceamento do nó, baseado na altura relativa de suas
    * subárvores, verifica se é necessário uma rotação simples ou dupla.
    */

    NoAVL<T>* balancear(NoAVL<T>* arv, T dado) {
      int altEsq = alturaNo(arv->getEsquerda());
      int altDir = alturaNo(arv->getDireita());
      if (dado < *arv->getDado()) {
       if (altEsq - altDir == 2) {
         if (dado < *(arv->getEsquerda()->getDado()))
          return simp_rot_esq(arv);
         else
          return dup_rot_esq(arv);
       }
      } else {
        if (altDir - altEsq == 2) {
          if (dado > *(arv->getDireita()->getDado()))
           return simp_rot_dir(arv);
          else
           return dup_rot_dir(arv);
        }
       }
      return arv;
    }

     //! NoAVL<T>* inserir(const T& dado, NoAVL<T>* arv)
     /*! insere um dado na árvore, com um algoritmo recursivo que verifica
     * se o dado é maior ou menor que aquele nó e se é nulo, caso não seja 
     * nulo, o método se chamará de forma recursiva passando como parâmetro
     * o nó à esquerda ou direita do nó original e faz o balanceamento da árvore
     * toda vez que o algoritmo retorna o seu valor recursivo.
     */

    NoAVL<T>* inserir(const T& dado, NoAVL<T>* arv) {
     NoAVL<T>* novo = new NoAVL<T>(dado);
     if (dado < *(arv->getDado())) {
       if (arv->getEsquerda() == NULL) {
        arv->setEsquerda(novo);
       } else {
        novo = arv->inserir(dado, arv->getEsquerda());
        arv = balancear(arv, dado);
        if (*arv->getDado() != *novo->getDado()) {
		       arv->setEsquerda(novo);
		    }
       }
     } else {
        if (arv->getDireita() == NULL) {
         arv->setDireita(novo);
        } else {
         novo = arv->inserir(dado, arv->getDireita());
         arv = balancear(arv, dado);
         if (*arv->getDado() != *novo->getDado()) {
		       arv->setDireita(novo);
		     }
        }
     }
     upAltura(arv);
     return arv;
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
     * Faz o balanceamento sempre que o dado é removido.
     */

    NoAVL<T>* remover(NoAVL<T>* arv, const T& dado) {
      NoAVL<T> *tmp, *filho;
      if (arv == NULL) {
        return arv;
      } else {
        if (dado < *arv->getDado()) {  // prox subarv à esquerda
         arv->setEsquerda(remover(arv->getEsquerda(), dado));
         arv = balancear(arv, *maximo(arv)->getDado());
         upAltura(arv);
         return arv;
        } else {
         if (dado > *arv->getDado()) {  // prox subarv à direita
          arv->setDireita(remover(arv->getDireita(), dado));
          arv = balancear(arv, *minimo(arv)->getDado());
          upAltura(arv);
          return arv;
         } else {
          if (arv->getDireita() != NULL && arv->getEsquerda() != NULL) {   // 2
           tmp = minimo(arv->getDireita());
           arv->setDado(*tmp->getDado());
           arv->setDireita(remover(arv->getDireita(), *(arv->getDado())));
           arv = balancear(arv, *minimo(arv)->getDado());
           upAltura(arv);
           return arv;
         } else {
           tmp = arv;
           if (arv->getDireita() != NULL) {   // 1 filho à direita
            filho = arv->getDireita();
            return filho;
           } else {
            if (arv->getEsquerda() != NULL) {   // 1 filho à esquerda
             filho = arv->getEsquerda();
             return filho;
            } else {    // sem filhos
             arv->~NoAVL();
             return NULL;
            }
           }
          }
          }
        }
      }
    }

    //! NoAVL<T>* minimo(NoAVL<T>* nodo)
    /*! o minimo retorna o valor minímo encontrado na subárvore de raiz nodo. 
    */

    NoAVL<T>* minimo(NoAVL<T>* nodo) {
     NoAVL<T>* tmp = nodo;
     while (tmp->getEsquerda() != NULL) {
       tmp = minimo(tmp->getEsquerda());
     }
     return tmp;
    }

    //! NoAVL<T>* maximo(NoAVL<T>* nodo)
    /*! o maximo retorna o valor máximo encontrado na subárvore de raiz nodo.
    * Adicionado pra facilitar a visualização do destrutor.
    */

    NoAVL<T>* maximo(NoAVL<T>* nodo) {
     NoAVL<T>* tmp = nodo;
     while (tmp->getDireita() != NULL) {
           tmp = maximo(tmp->getDireita());
     }
     return tmp;
    }

    //! T* getDado()
    /*! \return retorna o dado do nó.
    */

    T* getDado() {
     return dado;
    }

    //! T* busca(const T& dado, NoBinario<T>* arv)
    /*! O dado que é passado no parâmetro é buscado a partir do nó
    * que é passado também por parâmetro e é retornado caso seja encontrado.
    * 
    */

    T* busca(const T& dado, NoAVL<T>* arv) {
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

    //! preOrdem(), emOrdem() e posOrdem()
    /*! Os três métodos citados acima percorrem a árvore.
    * preOrdem - percorre primeiro a raiz depois o nó esquerdo e direito.
    * emOrdem - percorre primeiro o nó esquerdo depois a raiz e o nó direito.
    * posOrdem - percorre primeiro o nó esquerdo depois o nó direito e a raiz.
    */

    void preOrdem(NoAVL<T>* nodo) {
      if (nodo != NULL) {
        elementos.push_back(nodo);
        preOrdem(nodo->getEsquerda());
        preOrdem(nodo->getDireita());
      }
    }

    /*!< Já citado acima .*/

    void emOrdem(NoAVL<T>* nodo) {
     if (nodo != NULL) {
        emOrdem(nodo->getEsquerda());
        elementos.push_back(nodo);
        emOrdem(nodo->getDireita());
      }
    }

    /*!< Já citado acima .*/

    void posOrdem(NoAVL<T>* nodo) {
      if (nodo != NULL) {
        posOrdem(nodo->getEsquerda());
        posOrdem(nodo->getDireita());
        elementos.push_back(nodo);
      }
    }

     /*!< setEsquerda - seta o nó esquerdo.*/

    void setEsquerda(NoAVL<T>* nodo) {
      this->esquerda = nodo;
    }

    /*!< setDireita - seta o nó direito.*/

    void setDireita(NoAVL<T>* nodo) {
      this->direita = nodo;
    }

    /*!< setDado - seta o dado no nó atual.*/

    void setDado(T dado) {
     *(this->dado) = dado;
    }
};

#endif /* NO_AVL_HPP */
