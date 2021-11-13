/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 7: Simulacion de NFAs
 */

#include "../includes/nfa.h"

int main(int argc, char* argv[]){
  Usage(argc,argv);
  
  // I/O files declaration:
  std::string input_nfa = argv[1];
  std::string secuencce_of_chains = argv[2];
  std::string output_file = argv[3];

  // NFA attributes
  std::vector<States> nfa_states; // 1.NFA states
  Alphabet alphabet;  // 2.Alphabet
  int initial_state_value; // 3.Initial state
  std::set<int> acceptation_states; // 4.Acceptation_states
  std::vector<std::multimap<Symbols,int>> transitions; // 5.Transitions. 

  // Create NFA object:
  Fill_nfa_obj(input_nfa,nfa_states,alphabet,initial_state_value,acceptation_states,transitions);
  Nfa automatom(nfa_states,alphabet,initial_state_value,acceptation_states,transitions);

  std::ofstream out(output_file);

  // Read of secuence_input_file:
  std::ifstream chains_input;
  std::string chain;
  chains_input.open(secuencce_of_chains);

  // Output
  while (getline(chains_input,chain)) {
    if (Check_if_chaing_belong_alphabet(chain,alphabet)) {
      if (automatom.verificate_chain(chain)) { 
        out << chain << " -- Accepted\n"; 
      } else { 
        out << chain << " -- Rejected\n";
      }
    } else {
      out << chain << " -- The chain does not belong to Nfa alphabet.\n";
    }
  }
}