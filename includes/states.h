/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 7: Simulacion de NFAs
 */

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

class States {
 public:
  States();
  States(int, int);
  int get_state(void) const;
  int get_type(void) const;
  bool operator<(States const& ) const;
  friend std::ostream&operator<<(std::ostream& ,  const States& );
 private:
  int states_;
  int type_;
};


