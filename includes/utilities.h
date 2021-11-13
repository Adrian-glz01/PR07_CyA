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

#include "alphabet.h"
#include "chain.h"
#include "states.h"

void Usage(int, char* argv[]);
void Verification_of_initial_states_number(std::string);
void Fill_nfa_obj(std::string ,std::vector<States>& ,Alphabet& ,int& ,std::set<int>& ,std::vector<std::multimap<Symbols,int>>&);
bool Check_if_chaing_belong_alphabet(std::string ,Alphabet);
void Verificate_nfa_transitions(std::string);