#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <set>


int main(){
  
  std::string chain;
  std::cin >> chain;

  std::multimap< char, int > transitions0, transitions1, transitions2, transitions3;

  transitions0.insert(std::pair<char,int>('a' , 0));
  transitions0.insert(std::pair<char,int>('b' , 0));
  transitions0.insert(std::pair<char,int>('b' , 1));
  
  transitions1.insert(std::pair<char,int>('a' , 2));
  transitions1.insert(std::pair<char,int>('b' , 2));

  transitions2.insert(std::pair<char,int>('a' , 3));
  transitions2.insert(std::pair<char,int>('b' , 3));


  std::set<int> acceptation_states{3};

  std::vector<std::multimap<char,int>> mmap_vec = {transitions0,transitions1,transitions2, transitions3};

  std::set<int> current_state{0};
  for (int i = 0; i < chain.size();i++) {
    std::set<int> next_states = {};
    //std::multimap<char,int>::iterator it;
    for(auto state : current_state) { 
      for (auto it = mmap_vec[state].begin(); it != mmap_vec[state].end(); it++) {
        if (chain[i] == it->first) {
          next_states.insert(it->second);
        }
      }
    }
    current_state = next_states;
  }
  for(auto state: current_state ) {
    for (auto acceptation : acceptation_states) {
      if (state == acceptation) {
        std::cout << chain << " -- accepted\n";
        return 1;
      }
    }
  }
  std::cout << chain << " -- rejected\n";
}   