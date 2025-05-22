CXX=g++
CXXFLAGS=-std=c++14 -Wall -g
RM=rm -rf

# List of source files (.cpp files)
SRCS = adjacencymatrix.cpp bruteforce.cpp geneticalgorithm.cpp travelingsalesmanproblem.cpp 

# Generate the object files
OBJS = $(SRCS:.cpp=.o)

# Make Command Recipes
main: main.o $(OBJS)
	$(CXX) -o $@ $^

test: test.o $(OBJS)
	$(CXX) -o $@ $^

%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) a.out *.o *.gch *.dSYM main test