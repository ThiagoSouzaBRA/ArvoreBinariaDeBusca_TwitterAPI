#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <chrono>
#include "arvore.cpp"
using namespace std;
using namespace std::chrono;

#define ARQUIVO_TWEETS "tweets.txt"

//Função para leitura de arquivo
vector<PalavraFrequencia> lerArquivo() {
	vector<PalavraFrequencia> listaTweets;

  ifstream arquivoTweets (ARQUIVO_TWEETS);
  unsigned linhaCounter = 0;
  while(!arquivoTweets.eof()) {

    string palavra;
    getline(arquivoTweets, palavra);
    string frequenciaString;
    getline(arquivoTweets, frequenciaString);
    unsigned frequencia = stoul(frequenciaString, nullptr, 0);
    PalavraFrequencia palavraFrequencia = {palavra, frequencia};
    listaTweets.push_back(palavraFrequencia);

    linhaCounter++;
  }

  arquivoTweets.close();
  return listaTweets;
}

//Função principal
int main() {
  cout << "--- Arvore Binaria de Busca ---" << endl << endl;

  vector<PalavraFrequencia> listaTweets = lerArquivo();
  Arvore arvore;

  high_resolution_clock::time_point horarioInicionInsercao = high_resolution_clock::now();
  for (auto &tweet: listaTweets) {
    arvore.inserir(tweet);
  }
  high_resolution_clock::time_point horarioFimInsercao = high_resolution_clock::now();
  duration<double, std::milli> tempoDeExecucao = horarioFimInsercao - horarioInicionInsercao;

  sort(listaTweets.begin(), listaTweets.end());
  
  cout << "Ordem alfabetica: " << endl;
  for (auto &tweet: listaTweets) {
    cout << tweet.palavra << ": " << tweet.frequencia << endl;
  }
  cout << endl;

	cout << "Trending topics: " << endl;
	arvore.emOrdem(arvore.getRaiz());

  cout << endl;

  cout << "Numero de comparações: " << arvore.getQuantidadeComparacoes() << endl;

  cout << "Tempo de execução: " << tempoDeExecucao.count() << "s" << endl;

	return 0;
}
