CXX = g++
CXXFLAGS = -g -w
NAMEGLAGS = -o
SRC = src

make:
	$(CXX) $(CXXFLAGS) ./$(SRC)/*.cc $(NAMEGLAGS) nfa_simulation

.PHONY: all clean

	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f nfa_simulation *.o
	rm -rf *~ basura b i
