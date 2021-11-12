/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 7: Simulacion de NFAs
 */

#include "../includes/chain.h"

/**
 *
 *  @brief  Chain constructor -> initialize chain objects-
 *  @param  std::string chain.
 *
 */
Chain::Chain(const std::string kStr) { str_ = kStr; }

/**
 *
 *  @brief  Return the value of a string stored in an object.
 *  @param  std::string chain.
 *
 */
void Chain::set(std::string str) { str_ = str; }

/**
 *
 *  @brief  Get the value of a chain object.
 *  @return string value.
 *
 */
std::string Chain::get_chain() const { return str_; }

/**
 *
 *  @brief  Operator overloading for osstream operator.
 *  @param  ostream& os (output).
 *  @param  const_Chain& chain.
 *  @return Print the string.
 *
 */
std::ostream&operator<<(std::ostream& os , const Chain& kChain_) {
  os << kChain_.str_;
  return os;
}

/**
 *
 *  @brief  Get the size of a string.
 *  @return string size.
 *
 */
int Chain::size() const { return str_.size(); }

/**
 *
 *  @brief  Operator overloading for < operator.
 *  @param  const_Chain& chain1.
 *  @param  const_Chain& chain2.
 *  @return True if chain2 is greater than chain1 and false in the other case.
 *
 */
bool operator<(const Chain& chain1, const Chain& chain2) {
  return chain1.str_ < chain2.str_;
} 

/**
 *
 *  @brief  Get one determinated symbol of a chain object.
 *  @return string symbol.
 *
 */
char Chain::get_chain_symbol(int i) const { return str_[i]; }