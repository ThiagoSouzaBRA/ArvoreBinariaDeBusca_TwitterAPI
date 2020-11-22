#include <iostream>
#include "PalavraFrequencia.cpp"
using namespace std;

class No {
private:
	No *esq, *dir;
	PalavraFrequencia chave;

public:
	No(PalavraFrequencia chave) {
		this->chave = chave;
		esq = NULL;
		dir = NULL;
	}

	PalavraFrequencia getChave() {
		return chave;
	}
	
	// funções getters e setters

	No* getEsq() {
		return esq;
	}

	No* getDir() {
		return dir;
	}

	void setEsq(No *no) {
		esq = no;
	}

	void setDir(No *no) {
		dir = no;
	}
};