/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 7: Simulacion de NFAs
 */

#include <fstream>
#include <iostream>
#include <regex>
#include <set>
#include <string>
#include <vector>

class Transitions {
 public:
  Transitions(std::string, int, int);
  Transitions();
  friend std::ostream&operator<<(std::ostream& ,  const Transitions& );
  bool operator==(Transitions const&) const;
  bool operator<(Transitions const& ) const;
  std::string get_symbol(void) const;
  int get_current_state(void) const;
  int get_next_state(void) const;

 private:
  std::string symbol_;
  int current_state_;
  int next_state_;
};