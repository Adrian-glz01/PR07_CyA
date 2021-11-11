/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 7: Simulacion de NFAs
 */

#include "../includes/alphabet.h"


/**
 *
 *  @brief  Alphabet empty constructor.
 * 
 */
Alphabet::Alphabet() {}

/**
 *
 *  @brief  Alphabet constructor -> initialize Alphabet objects-
 *  @param  std::set<std::strings> set of symbols that make up the alphabet.
 *
 */
Alphabet::Alphabet(std::set<Symbols> alph) { alph_ = alph; }

/**
 *
 *  @brief  Get the value of a called alphabet obj.
 *  @return alphabet value.
 *
 */
std::set<Symbols> Alphabet::get_alph() { return alph_; }

/**
 *
 *  @brief  Operator overloading for osstream operator.
 *  @param  ostream& os (output).
 *  @param  const_Alphabet& symbol
 *  @return Write the symbols of the alphabet
 *
 */
std::ostream&operator<<(std::ostream& os ,  const Alphabet& Kalph_) {
  for (auto symbol: Kalph_.alph_ ) {
    os << symbol << " ";
  }
  return os;
}

/**
 *
 *  @brief  Get the size of a set of symbols inside an alphabet.
 *  @return alphabet size.
 *
 */
int Alphabet::size() { return alph_.size(); }