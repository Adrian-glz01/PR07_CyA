/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 7: Simulacion de NFAs
 */

#include "../includes/states.h"

/**
 *
 *  @brief  States empty constructor.
 * 
 */
States::States() {}

/**
 *
 *  @brief  States constructor -> initialize states objects-
 *  @param  int states.
 *  @param  int type {1 aceptation, 0 another else state type}
 *
 */
States::States(int states, int type) { 
  states_ = states;
  type_= type;
}

/**
 *
 *  @brief  Operator overloading for minor operator
 *  @param  States_const& state.
 *  @return If the sent state is minor than other state.
 *
 */
bool States::operator<(States const& kState) const { return kState.states_ < states_; }

/**
 *
 *  @brief Get the int value of a state.
 *  @return The value{number} of the state.
 *
 */
int States::get_state() const { return states_; }

/**
 *
 *  @brief Get the type of a state.
 *  @return The type{1 aceptation, 0 another else state type} of the state.
 *
 */
int States::get_type() const { return type_; }

/**
 *
 *  @brief  Operator overloading for osstream operator.
 *  @param  ostream& os (output).
 *  @param  const_State& state.number state.type
 *  @return Print the states number and state type.
 *
 */
std::ostream&operator<<(std::ostream& os ,  const States& kState ) {
  os << kState.get_state() << kState.get_type();
  return os;
}
