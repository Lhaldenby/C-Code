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

main:	main.cpp Expression
	$(CXX) $(CXXFLAGS) main.cpp Expression.o -o main
		
Expression:	Expression.cpp Expression.h
	$(CXX) $(CXXFLAGS) -c Expression.cpp -o Expression.o

deepclean: 
	rm -f *~ *.o main *.exe *.stackdump

clean:
	-rm -f *~ *.o *.stackdump

