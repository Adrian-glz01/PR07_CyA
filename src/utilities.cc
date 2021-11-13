/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 7: Simulacion de NFAs
 */

#include "../includes/utilities.h"

const std::string KError_message{
    "Fatal error! The execution of this programm is not correct.\n\
  Try './{exe_file_name}  --help' to get more information.\n"};

const std::string Khelp_message{
    "The execution of this program must be done with 3 parameters.\n\
  Correct use example: ./{exe_file_name} [input.nfa] [secuence_input] [output_file]\n\n"};

/**
 *
 *  @brief Send a error message if the arguments on the execution are not
 *  corrects.
 *  @param int argc
 *  @param char* argv[]
 *
 */
void Usage(int argc, char* argv[]) {
  if (argc == 1) {
    std::cout << KError_message << std::endl;
    exit(EXIT_SUCCESS);
  }else if (strcmp(argv[1], "--help") == 0) {
    std::cout << Khelp_message << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/**
 *
 *  @brief Verificate if in the nfa definition there is only one initial state.
 *  @param std::string initial_state.
 *
 */
void Verification_of_initial_states_number(std::string initial_state_line) {
  if (initial_state_line.size() > 2) {
    std::cout << "There is more initial states than one in the DFA\n\
                    Aborted program\n";
    exit(EXIT_SUCCESS);
  }
}

/**
 *
 *  @brief Verificate if there is one line on input.nfa by each nfa state.
 *  @param std::string [input nfa file].
 *
 */
void Verificate_nfa_transitions(std::string input_nfa) {

  std::ifstream nfa_input_file;
  std::string nfa_input_line;
  nfa_input_file.open(input_nfa);

  getline(nfa_input_file,nfa_input_line);
  int states_number = std::stoi(nfa_input_line);
  getline(nfa_input_file,nfa_input_line);
  
  int verification_it = 0;
  while(getline(nfa_input_file,nfa_input_line)) {
    verification_it++;
  }

  if( verification_it != states_number) {
    std::cout << "There isn't one line in [input.nfa] by each nfa state\n\
                    Aborted program\n";
    exit(EXIT_SUCCESS);
  }
}

/**
 * @brief Funtion to fill NFA object with nfa parameters.
 * 
 * @param std::string input_nfa
 * @param std::vector<States>& nfa_states 
 * @param Alphabet& alphabet  
 * @param int& initial_state_value 
 * @param std::set<int>& acceptation_states 
 * @param std::vector<std::multimap<Symbols,int>>& transitions 
 */
void Fill_nfa_obj(std::string input_nfa ,std::vector<States>& nfa_states,Alphabet& alphabet,int& initial_state_value,std::set<int>& acceptation_states,std::vector<std::multimap<Symbols,int>>& transitions) {

  // Opening of nfa input file:
  std::ifstream nfa_input_file;
  std::string nfa_input_line;
  nfa_input_file.open(input_nfa);

  // Verification if there is one line on input.nfa by each nfa state.
  Verificate_nfa_transitions(input_nfa);

  // Number of states:
  getline(nfa_input_file,nfa_input_line);
  int states_number = std::stoi(nfa_input_line);

  // Initial state value:
  getline(nfa_input_file,nfa_input_line);
  initial_state_value = std::stoi(nfa_input_line);
  Verification_of_initial_states_number(nfa_input_line);

  // Some datatype to fill the nfa object
  std::string getline_str;

  // Symbols to fill alphabet object:
  std::set<Symbols> alphabet_set_vec;

  // Iterator to fill the attributes of NFA class:
  for (int iterator = 0; iterator < states_number; iterator++) {

    std::multimap<Symbols,int> nfa_transitions_mmap; 

    std::vector<std::string> input_nfa_line_vec;
    getline(nfa_input_file,nfa_input_line);
    std::stringstream ssfile(nfa_input_line);
    while ( ssfile >> getline_str) {
      input_nfa_line_vec.emplace_back(getline_str);
    }
    // 1.nfa_states
    nfa_states.emplace_back(States(std::stoi(input_nfa_line_vec[0]),std::stoi(input_nfa_line_vec[1])));

    int transitions_begin = 3;
    int transitions_number = std::stoi(input_nfa_line_vec[2]);

    if (std::stoi(input_nfa_line_vec[2]) == 0 && std::stoi(input_nfa_line_vec[1]) == 1) {
      acceptation_states.insert(std::stoi(input_nfa_line_vec[0]));
    }

    // Iterator of transitions number:
    for (int iterator_j = 0; iterator_j < transitions_number; iterator_j++) {


      // 3.Acceptation states:
      if(std::stoi(input_nfa_line_vec[1]) == 1) {
        acceptation_states.insert(std::stoi(input_nfa_line_vec[0]));
      }
      //std::cout << input_nfa_line_vec[0] << "\n";
      
      alphabet_set_vec.insert(Symbols(input_nfa_line_vec[transitions_begin]));

      // 4. Transitions
      nfa_transitions_mmap.insert(std::pair<Symbols,int>(Symbols(input_nfa_line_vec[transitions_begin]),std::stoi(input_nfa_line_vec[transitions_begin+1])));

      transitions_begin += 2;
    }
    transitions.emplace_back(nfa_transitions_mmap);
    Alphabet alphabet_aux(alphabet_set_vec);
    alphabet = alphabet_aux;
  }

}

/**
 *
 *  @brief Check if the chain belong to the dfa's alphabet.
 *  @param std::string Chain.
 *  @param Alphabet alphabet.
 *  @return true if the chain belong to the alphabet, and false in the opposite case.
 *
 */
bool Check_if_chaing_belong_alphabet(std::string chain, Alphabet alphabet) {
  std::vector<std::string> alphabet_aux;
  for (auto alphabet_: alphabet.get_alph()) {
    alphabet_aux.emplace_back(alphabet_.get_symbols());
  }
  for (auto element : chain) {
    std::string symbol;
    symbol.push_back(element);
    std::vector<std::string>::iterator belong = std::find(alphabet_aux.begin(),alphabet_aux.end(),symbol);

    if (belong == alphabet_aux.end() && chain != "&") { 
      return false; 
    }
  }
  return true;  
}