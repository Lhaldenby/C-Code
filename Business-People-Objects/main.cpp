#include <iostream>
#include <utility>
#include <sstream>

#include "Person.h"

// This is a file that will help you test your classes.
// There is no need to submit this file and you can edit
// and change it as you wish.

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;


int main(int argc, char* argv[]) {


	const int NUM_PEOPLE=5;
	Person* people_array[NUM_PEOPLE];
		
	people_array[0] = new Customer("John Smith",42);
	people_array[1] = new Manager("Alice Jones",50000.50);
	people_array[2] = new Customer("Mary Smith",55);
	people_array[3] = new Consultant("Bob Lewis",3000);
	people_array[4] = new Consultant("Jane Doe",4000);

	Manager* mgr = dynamic_cast<Manager*>(people_array[1]);

	for (int i=0 ; i<NUM_PEOPLE ; ++i) {
		if (people_array[i]->type() == "Customer") {
			Customer* c=dynamic_cast<Customer*>(people_array[i]);
			c->addOrder((i+1)*100+1);
			c->addOrder((i+1)*100+2);
			c->addOrder((i+1)*100+3);
		}
		if (people_array[i]->type() == "Consultant") {
			Consultant* c =dynamic_cast<Consultant*>(people_array[i]);
			c->setManager(mgr);
		}
	}
	for (unsigned int i=0 ; i<NUM_PEOPLE ; ++i) {
		cout << *people_array[i] << endl;
	}

	delete people_array[4];
	delete people_array[3];
	delete people_array[2];
	delete people_array[1];
	delete people_array[0];
	

	return 0;
}

