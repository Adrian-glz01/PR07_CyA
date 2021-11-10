CXX = g++
CXXFLAGS = -g -w
NAMEGLAGS = -o
SRC = src

make:
	$(CXX) $(CXXFLAGS) ./$(SRC)/*.cc $(NAMEGLAGS) dfa_simulation

.PHONY: all clean

	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f dfa_simulation *.o
	rm -rf *~ basura b i
