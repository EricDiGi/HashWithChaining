CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

SRCS = $(wildcard *.hpp)
OBJECTS = $(SRCS: .hpp=.o)

all: Hash

clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc* test/*.o Hash core main

Hash: $(OBJECTS) testBench.cpp Hash.cpp Link.cpp Node.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^