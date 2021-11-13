/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 7: Simulacion de NFAs
 */

#ifndef ALPHABET
#define ALPHABET

#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include <fstream>
#include <sstream>
#include <unordered_set>

#include "symbols.h"

class Alphabet {
 public:
  Alphabet();
  Alphabet(std::set<Symbols>);
  std::set<Symbols> get_alph(void);
  friend std::ostream&operator<<(std::ostream& ,  const Alphabet& );
  int size(void);
  
 private:
  std::set<Symbols> alph_;
};

#endif