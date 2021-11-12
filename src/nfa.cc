/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 7: Simulacion de NFAs
 */

#include "../includes/nfa.h"

Nfa::Nfa(std::vector<States> states, Alphabet alphabet , int initial_state , std::set<int> acceptation_states, std::vector<std::multimap<Symbols,int>> transitions) {
  states_ = states;
  alphabet_ = alphabet;
  initial_state_ = initial_state;
  acceptation_states_ = acceptation_states;
  transitions_ = transitions;
}

bool Nfa::verificate_chain(const Chain& mystr) {
  std::set<int> current_state = {initial_state_};
  for (int i = 0; i < mystr.size(); i++) {
    std::set<int> next_states = {};
    for (auto state: current_state) {
      for (auto it = transitions_[state].begin(); it != transitions_[state].end(); it++) {
        if (std::string(1,mystr.get_chain_symbol(i)) == it->first) {
          next_states.insert(it->second);
        }
      }
    }
    current_state = next_states;
  }
  //intersection:
  for (auto state: current_state) {
    for (auto acceptation: acceptation_states_) {
      if(state == acceptation) {
        return true;
      }
    }
  }
  return false;
}