/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 7: Simulacion de NFAs
 */

#ifndef CADENA
#define CADENA

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


class Chain {
 public:
  //Constructor.
  Chain(const std::string);
  void set(std::string);
  std::string get_chain() const;
  int size() const; 
  friend std::ostream&operator<<(std::ostream& , const Chain&);
  friend bool operator<(const Chain&, const Chain&);
  char get_chain_symbol(int) const ;
 private:
  std::string str_;
};

#endif

