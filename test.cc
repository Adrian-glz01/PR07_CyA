#include <map>
#include <iostream>
#include <vector>
#include <string>


int main(){
  
  std::string chain = "aba";

  std::multimap< char, int > transitions0, transitions1, transitios2;

  transitions0.insert(std::pair<char,int>('a',0));
}   