// Copyright Fabio Moreira
// Método Remover pode não funcionar, inserção 
// e demais métodos estão corretos

#ifndef NO_RB_HPP
#define NO_RB_HPP

#include <vector>

#define RB_RUBRO true
#define RB_NEGRO false

template <typename T>

class NoRB {
 private:
    T* dado;  //!< Atributo onde é guardado o valor representado pelo nó
    NoRB<T>* esquerda;  //!< Atributo que aponta para menor nó descendente
    NoRB<T>* direita;  //!< Atributo que aponta para maior nó descendente
    NoRB<T>* pai;  //!< Atributo que aponta para nó ascendente
    bool cor;  //!< Atributo que indica a cor do nó
    std::vector<NoRB<T>* > elementos;

 public:
    explicit NoRB(const T& dado) {
      esquerda = NULL;
      direita = NULL;
      pai = NULL;
      cor = RB_RUBRO;
      this->dado = new T(dado);
    }

    virtual ~NoRB() {
     while (getEsquerda() != NULL) {
       delete minimo(this);
     }
     while (getDireita() != NULL) {
      delete maximo(this);
     }
    }

    NoRB<T>* getPai() {
     return pai;
    }

    void setPai(NoRB<T>* pai) {
     this->pai = pai;
    }

    bool getCor() {
     return cor;
    }

    void setCor(bool cor) {
     this->cor = cor;
    }

    NoRB<T>* rotacaoSimplesDireita(NoRB<T>* raiz) {
     NoRB<T> *y, *pai;
     bool lado;  // 0 esq  --  1 dir
     pai = raiz->getPai();
     if (pai->getEsquerda() == raiz) // tanto o filho esquerdo quanto o direito podem fazer a rotação para esq/dir essa parte teste mostra quem está fazendo.
      lado = 0;
     else
      lado = 1;
     y = raiz->getEsquerda();
     y->setPai(pai);
     raiz->setEsquerda(y->getDireita());
     raiz->getEsquerda()->setPai(raiz);
     y->setDireita(raiz);
     y->getDireita()->setPai(y);
     if (!lado)
      pai->setEsquerda(y);
     else
      pai->setDireita(y);
     return y;
    }

    NoRB<T>* rotacaoSimplesEsquerda(NoRB<T>* raiz) {
     NoRB<T> *y, *pai;
     bool lado;
     pai = raiz->getPai();
     if (pai->getEsquerda() == raiz)
      lado = 0;
     else
      lado = 1;
     y = raiz->getDireita();
     y->setPai(pai);
     raiz->setDireita(y->getEsquerda());
     raiz->getDireita()->setPai(raiz);
     y->setEsquerda(raiz);
     y->getEsquerda()->setPai(y);
     if (!lado)
      pai->setEsquerda(y);
     else
      pai->setDireita(y);
     return y;
    }

    NoRB<T>* correcaoEsquerdaInsercao(NoRB<T>* arv, NoRB<T>* pai,
    NoRB<T>* avo) {
     NoRB<T>* tio;
     tio = avo->getDireita();
     if (tio->getCor() == RB_RUBRO) {
      pai->setCor(RB_NEGRO);
      avo->setCor(RB_RUBRO);
      tio->setCor(RB_NEGRO);
      arv = avo;
     } else {
      if (pai->getDireita() == arv) {
       rotacaoSimplesEsquerda(pai);
       arv = arv->getEsquerda();
      } else {
       pai->setCor(RB_NEGRO);
       avo->setCor(RB_RUBRO);
       rotacaoSimplesDireita(avo);
      }
     }
     return NULL;
    }

    NoRB<T>* correcaoDireitaInsercao(NoRB<T>* arv, NoRB<T>* pai, NoRB<T>* avo) {
     NoRB<T>* tio;
     tio = avo->getEsquerda();
     if (tio->getCor() == RB_RUBRO) {
      pai->setCor(RB_NEGRO);
      avo->setCor(RB_RUBRO);
      tio->setCor(RB_NEGRO);
      arv = avo;
     } else {
      if (pai->getEsquerda() == arv) {
       rotacaoSimplesDireita(pai);
       arv = arv->getDireita();
      } else {
       pai->setCor(RB_NEGRO);
       avo->setCor(RB_RUBRO);
       rotacaoSimplesEsquerda(avo);
      }
     }
     return NULL;
    }

    NoRB<T>* correcaoEsquerdaRemocao(NoRB<T>* raiz, NoRB<T>* w) {
     NoRB<T>* y;
     y = w->getPai()->getDireita();
     if (y->getCor() == RB_RUBRO) {
      y->setCor(RB_NEGRO);
      w->getPai()->setCor(RB_RUBRO);
      rotacaoSimplesEsquerda(w->getPai());
      y = w->getPai()->getDireita();
     }
     if (y->getEsquerda()->getCor() == RB_NEGRO && y->getDireita()->getCor() == RB_NEGRO) {
      y->setCor(RB_RUBRO);
      w = w->getPai();
     } else {
        if (y->getDireita()->getCor() == RB_NEGRO) {
         y->getEsquerda()->setCor(RB_NEGRO);
         y->setCor(RB_RUBRO);
         rotacaoSimplesDireita(y);
         y = w->getPai()->getDireita();
        }
        y->setCor(w->getPai()->getCor());
        w->getPai()->setCor(RB_NEGRO);
        y->getDireita()->setCor(RB_NEGRO);
        rotacaoSimplesEsquerda(w->getPai());
        w = raiz;
     }
     return w;
    }

    NoRB<T>* correcaoDireitaRemocao(NoRB<T>* raiz, NoRB<T>* w) {
     NoRB<T>* y;
     y = w->getPai()->getEsquerda();
     if (y->getCor() == RB_RUBRO) {
      y->setCor(RB_NEGRO);
      w->getPai()->setCor(RB_RUBRO);
      rotacaoSimplesDireita(raiz->getPai());
      y = w->getPai()->getEsquerda();
     }
     if (y->getDireita()->getCor() == RB_NEGRO && y->getEsquerda()->getCor() == RB_NEGRO) {
      y->setCor(RB_RUBRO);
      w = w->getPai();
     } else {
        if (y->getEsquerda()->getCor() == RB_NEGRO) {
         y->getDireita()->setCor(RB_NEGRO);
         y->setCor(RB_RUBRO);
         rotacaoSimplesEsquerda(y);
         y = w->getPai()->getEsquerda();
        }
        y->setCor(w->getPai()->getCor());
        w->getPai()->setCor(RB_NEGRO);
        y->getEsquerda()->setCor(RB_NEGRO);
        rotacaoSimplesDireita(w->getPai());
        w = raiz;
     }
     return w;
    }

    std::vector<NoRB<T>* > getElementos() {
     return elementos;
    }

    NoRB<T>* getEsquerda() {
     return esquerda;
    }

    NoRB<T>* getDireita() {
     return direita;
    }

    NoRB<T>* inserir(const T& dado, NoRB<T>* arv) {
      NoRB<T> *atual, *pai, *avo;
      arv->setCor(RB_RUBRO);
      atual = arv;
      while (atual != arv && atual->getPai()->getCor() == RB_RUBRO) {
       pai = atual->getPai();
       avo = pai->getPai();
       if (avo->getEsquerda() == pai)
        correcaoEsquerdaInsercao(atual, pai, avo);
       else
        correcaoDireitaInsercao(atual, pai, avo);
      }
      arv->setCor(RB_NEGRO);
      arv->setDado(dado);
      return arv;
    }

    NoRB<T>* passoCED(NoRB<T>* arv, NoRB<T>* w) {
      while (w != raiz) {
       if (w == w->getPai()->getEsquerda()) {
        w = correcaoEsquerdaRemocao(arv,w);
       } else {
        w = correcaoDireitaRemocao(arv,w);
       }
      }
      return w;
    }


    NoRB<T>* remover(NoRB<T>* arv, const T& dado) {
     NoRB<T> *tmp, *filho;
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
          if (arv->getDireita() != NULL && arv->getEsquerda() != NULL) { // 2 filhos
           arv = passoCED(arv,arv->getDireita());
           return arv;
         } else {
           tmp = arv;
           if (arv->getDireita() != NULL) { // 1 filho a direita
            filho = arv->getDireita();
            filho = passoCED(arv,filho);
            return filho;
           } else {
            if (arv->getEsquerda() != NULL) { // 1 filho a esquerda
             filho = arv->getEsquerda();
             filho = passoCED(arv,filho);
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

    NoRB<T>* minimo(NoRB<T>* nodo) {
     NoRB<T>* tmp = nodo;
     while (tmp->getEsquerda() != NULL) {
       tmp = minimo(tmp->getEsquerda());
     }
     return tmp;
    }

    NoRB<T>* maximo(NoRB<T>* nodo) {
     NoRB<T>* tmp = nodo;
     while (tmp->getDireita() != NULL) {
           tmp = maximo(tmp->getDireita());
     }
     return tmp;
    }

    T* getDado() {
     return dado;
    }

    T* busca(const T& dado, NoRB<T>* arv) {
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

    void preOrdem(NoRB<T>* nodo) {
     if (nodo != NULL) {
        elementos.push_back(nodo);
        preOrdem(nodo->getEsquerda());
        preOrdem(nodo->getDireita());
      }
    }

    void emOrdem(NoRB<T>* nodo) {
      if (nodo != NULL) {
        emOrdem(nodo->getEsquerda());
        elementos.push_back(nodo);
        emOrdem(nodo->getDireita());
      }
    }

    void posOrdem(NoRB<T>* nodo) {
     if (nodo != NULL) {
        posOrdem(nodo->getEsquerda());
        posOrdem(nodo->getDireita());
        elementos.push_back(nodo);
     }
    }

    /*!< setEsquerda - seta o nó esquerdo.*/
    void setEsquerda(NoRB<T>* nodo) {
      this->esquerda = nodo;
    }

    /*!< setDireita - seta o nó direito.*/
    void setDireita(NoRB<T>* nodo) {
      this->direita = nodo;
    }

    /*!< setDado - seta o dado no nó atual.*/
    void setDado(T dado) {
     *(this->dado) = dado;
    }
};

#endif /* NO_RB_HPP */