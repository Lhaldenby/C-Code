# Makefile

# the C++ compiler
CXX     = g++
CXXVERSION = $(shell g++ --version | grep ^g++ | sed 's/^.* //g')

# options to pass to the compiler
CXXFLAGS = -O0 -g3

ifeq "$(CXXVERSION)" "4.6.3"
	CXXFLAGS += -std=c++0x
else
	CXXFLAGS += -std=c++11
endif

All: all
all: main

main:	main.cpp Person
	$(CXX) $(CXXFLAGS) main.cpp Person.o -o main
		
Person:	Person.cpp Person.h
	$(CXX) $(CXXFLAGS) -c Person.cpp -o Person.o
	
deepclean: 
	rm -f *~ *.o main *.exe *.stackdump

clean:
	-rm -f *~ *.o *.stackdump

