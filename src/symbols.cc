/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 7: Simulacion de NFAs
 */

#include "../includes/symbols.h"

/**
 *
 *  @brief  Symbols empty constructor.
 * 
 */
Symbols::Symbols() {}

/**
 *
 *  @brief  Symbols constructor -> initialize symbols objects-
 *  @param  std::string symbol.
 *
 */
Symbols::Symbols(std::string Symbol) { symbol_ = Symbol; }

/**
 *
 *  @brief  Get the value of a called symbol obj.
 *  @return Symbol value.
 *
 */
std::string Symbols::get_symbols() const { return symbol_; }

/**
 *
 *  @brief  Operator overloading for osstream operator.
 *  @param  ostream& os (output).
 *  @param  const_Symbols& symbol
 *  @return Write the symbols of the alphabet
 *
 */
std::ostream&operator<<(std::ostream& os , const Symbols& symb_) {
  os << symb_.symbol_;
  return os;
}

/**
 *
 *  @brief  Operator overloading for minor operator.
 *  @param  const_Symbols& symbol1.
 *  @param  const_Symbols& symbol2.
 *  @return True if symbol1 is minor than symbol 2, false in the other case.
 *
 */
bool operator<(const Symbols& sym1, const Symbols& sym2) {
  return sym1.get_symbols() < sym2.get_symbols();
}

/**
 *
 *  @brief  Operator overloading for equal operator.
 *  @param  std::string string character.
 *  @return Allows you to match a character of a string to a symbol of the class.
 *
 */
Symbols Symbols::operator=(std::string c2) { return symbol_ = c2; }

/**
 *
 *  @brief  Operator overloading for boolean equal operator.
 *  @param  std::string string character.
 *  @param  const_Symbols& symbol object character
 *  @return Compare if one sended string character is equal than the Symbols object character.
 *
 */
bool operator==(std::string mystr_symbol, const Symbols& my_sym) { return mystr_symbol == my_sym.symbol_; }

