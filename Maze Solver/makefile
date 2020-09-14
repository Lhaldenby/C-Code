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

main:	main.cpp Grid
	$(CXX) $(CXXFLAGS) main.cpp Grid.o -o main
		
Grid:	Grid.cpp Grid.h
	$(CXX) $(CXXFLAGS) -c Grid.cpp -o Grid.o

deepclean: 
	rm -f *~ *.o main *.exe *.stackdump

clean:
	-rm -f *~ *.o *.stackdump

