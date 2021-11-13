/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 7: Simulacion de NFAs
 */

#ifndef SYMBOLS
#define SYMBOLS

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

class Symbols {
 public:
  Symbols();
	Symbols(std::string Symbol);
	std::string get_symbols() const;
	friend std::ostream&operator<<(std::ostream& , const Symbols& );
	friend bool operator<(const Symbols& , const Symbols& );
	Symbols operator=(std::string c2);
	friend bool operator==(std::string , const Symbols& );
 private:
 	std::string symbol_;
};

#endif