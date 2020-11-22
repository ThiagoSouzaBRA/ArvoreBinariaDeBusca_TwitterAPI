#include <string>

class PalavraFrequencia {
public:
  std::string palavra;
  unsigned frequencia;
  bool operator< (const PalavraFrequencia &other) const {
    return palavra < other.palavra;
  }
};