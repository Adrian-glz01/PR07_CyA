/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 7: Simulacion de NFAs
 */

#include "chain.h"
#include "alphabet.h"
#include "symbols.h"
#include "utilities.h"

class Nfa {
 public:
  Nfa(std::vector<States>, Alphabet, int, std::set<int>, std::vector<std::multimap<Symbols,int>>);
  bool verificate_chain(const Chain&);
 private:
  std::vector<States> states_;
  Alphabet alphabet_;
  int initial_state_;
  std::set<int> acceptation_states_;
  std::vector<std::multimap<Symbols,int>> transitions_;
};


