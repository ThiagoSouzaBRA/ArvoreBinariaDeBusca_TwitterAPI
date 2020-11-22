#include <iostream>
#include "no.cpp"
using namespace std;

class Arvore {
private:
	No *raiz;
  unsigned numeroDeComparacoes = 0;

  void inserirAux(No *no, PalavraFrequencia chave) {
		// se for menor, então insere à esquerda
    numeroDeComparacoes++;
		if(chave.frequencia < no->getChave().frequencia) {
      numeroDeComparacoes++;
			// verifica se a esquerda é nulo
			if(no->getEsq() == NULL) {
				No *novo_no = new No(chave);
				no->setEsq(novo_no); // seta o novo_no à esquerda
			} else {
				// senão, continua percorrendo recursivamente
				inserirAux(no->getEsq(), chave);
			}
		} else if(chave.frequencia > no->getChave().frequencia) {
		  // se for maior, então insere à direita
    	// verifica se a direita é nulo
      numeroDeComparacoes++;
      numeroDeComparacoes++;
			if(no->getDir() == NULL) {
				No *novo_no = new No(chave);
				no->setDir(novo_no); // seta o novo_no à direita
			} else {
				// senão, continua percorrendo recursivamente
				inserirAux(no->getDir(), chave);
			}
		}
		// se for igual, não vai inserir
		// não pode existir 2 chaves iguais
	}

public:
	Arvore() {
		raiz = NULL;
	}

  unsigned getQuantidadeComparacoes() {
    return numeroDeComparacoes;
  }

	void inserir(PalavraFrequencia chave) {
		if(raiz == NULL) { // verifica se a árvore está vazia
      numeroDeComparacoes++;
			raiz = new No(chave); // cria um novo nó
    } else {
			inserirAux(raiz, chave);
    }
	}

	No* getRaiz() {
		return raiz;
	}

	void emOrdem(No* no) {
		if(no != NULL) {
			emOrdem(no->getEsq());
			cout << no->getChave().palavra << ": " << no->getChave().frequencia << endl;;
			emOrdem(no->getDir());
		}
	}
};