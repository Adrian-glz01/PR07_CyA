/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 7: Simulacion de NFAs
 */

#include "../includes/nfa.h"

/**
 *
 *  @brief  Nfa constructor -> initialize Nfa objects-
 *  @param  std::vector<States> set states of the NFA.
 *  @param  Alphabet Buiild the alphabet of the NFA
 *  @param  int build initial state.
 *  @param  std::set<int> set of aceptation states.
 *  @param  std::vector<std::multimap<Symbols,int>> set of transitions that make up the NFA.
 *
 */
Nfa::Nfa(std::vector<States> states, Alphabet alphabet , int initial_state , std::set<int> acceptation_states, std::vector<std::multimap<Symbols,int>> transitions) {
  states_ = states;
  alphabet_ = alphabet;
  initial_state_ = initial_state;
  acceptation_states_ = acceptation_states;
  transitions_ = transitions;
}

/**
 *
 *  @brief  Algorithim that verificate if a chain is accepted or not by the NFA.
 *  @param  const_Chain& the chain that going to get examinated.
 *  @return True if the chain is accepted or False if it is rejected.
 *
 */
bool Nfa::verificate_chain(const Chain& mystr) {
  std::set<int> current_state = {initial_state_};
  for (int i = 0; i < mystr.size(); i++) {
    std::set<int> next_states = {};
    for (auto state: current_state) {
      //std::cout << "ac: " << state;
      for (auto it = transitions_[state].begin(); it != transitions_[state].end(); it++) {
        if (std::string(1,mystr.get_chain_symbol(i)) == it->first) {
          next_states.insert(it->second);
          //std::cout << "\n" << it->first<< " -> " << it->second;
        }
      }
    }
    //std::cout << "\n";
    current_state = next_states;
    
  }
  //intersection:
  std::set<int> states_intersection;
  //std::set_intersection(current_state.begin(), current_state.end(), acceptation_states_.begin(), acceptation_states_.end(),std::inserter(states_intersection,states_intersection.begin()));
    for (const int &kCurrentState: current_state)
      for (const int &kAcceptanceState: acceptation_states_) {
        if (kCurrentState == kAcceptanceState) {
          states_intersection.insert(kCurrentState);
        }
      }
    if(states_intersection.size() > 0) return true;
    return false;
}