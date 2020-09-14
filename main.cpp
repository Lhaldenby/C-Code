#include <iostream>

#include "Grid.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;

int main() {

	Grid grid;
	try{
		grid.loadFromFile("grid");
		bool exists = grid.existsPath();
		if(exists){
			cout<<"Found a path"<<endl;
			grid.outputDirections(cout);
			grid.outputPath(cout);
		}
	}
	catch(string s){
		cerr<<s<<endl;
	}	
	return 0;
}

