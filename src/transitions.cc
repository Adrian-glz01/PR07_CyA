/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 7: Simulacion de NFAs
 */

#include "../includes/transitions.h"

/**
 *
 *  @brief  Transitions empty constructor.
 * 
 */
Transitions::Transitions() {}

/**
 *
 *  @brief  Transitions constructor -> initialize transitions objects-
 *  @param  char symbol.
 *  @param  int current_state.
 *
 */
Transitions::Transitions(std::string symbol, int current_state, int next_state) {
  symbol_ = symbol;
  current_state_ = current_state;
  next_state_ = next_state;
}

/**
 *
 *  @brief  Operator overloading for osstream operator.
 *  @param  ostream& os (output).
 *  @param  const_Transition&
 *  @return Print transitions of a DFA like -> {symbol,current_state,next_state} >> {a,0,1} >> (q0)---a--->(q1)
 *
 */
std::ostream&operator<<(std::ostream& os,  const Transitions& kTr) {
  os << kTr.symbol_ << " " << kTr.current_state_ << " " << kTr.next_state_; 
  return os;
}

/**
 *
 *  @brief  Operator overloading for minor operator
 *  @param  States_const& state.
 *  @return iF the symbols and current states of a state are minor than another.
 *
 */
bool Transitions::operator<(Transitions const& kTr) const {
  return kTr.symbol_ < this->symbol_ || kTr.current_state_ < this->current_state_;
}

/**
 *
 *  @brief  Get the value of the state's symbols.
 *  @return state symbol.
 *
 */
std::string Transitions::get_symbol() const { return symbol_; }

/**
 *
 *  @brief  Get the value of the states's current states.
 *  @return current state value.
 *
 */
int Transitions::get_current_state() const { return current_state_; }

/**
 *
 *  @brief  Get the value of the states's next states.
 *  @return next states value.
 *
 */
int Transitions::get_next_state() const { return next_state_; }

