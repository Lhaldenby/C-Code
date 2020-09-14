#include <iostream>
#include <utility>
#include <sstream>


// This is a file that will help you test your classes.
// There is no need to submit this file and you can edit 
// and change it as you wish.
// Run the main with an expression as parameter.
#include "Expression.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;


// This collection of functions is used to parse a simple
// structure of expressions and build expressions.
// Notice that the parsing is very basic. 
// This parsing is far from perfect, but
// for now it is sufficient for our purposes.
size_t split(const string& source);
bool nestedInParen(const string& s, size_t l);
size_t splitOnOp(const string& s,char op);
bool parseNumber(const string& source, int& val);
Expression* parseExpression(const string& source);

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Usage: main expression" << endl;
		cout << "For example: main \"Abs(342*(29+Abs(-12)+Square(5)))\"" << endl;
		return 1;
	}
	else {
		Expression *e=parseExpression(argv[1]);
		if (e!=nullptr) {
			cout << e->print() << " = " << e->evaluate() << endl;
			delete e;
		}
		else {
			cout << "Something went wrong with parsing." << endl;
		}	
	}
	return 0;
}

bool nestedInParen(const string& s, size_t l) {
	unsigned int nesting=0;
	for (size_t i=0 ; i<l ; ++i) {
		if (s[i]=='(') {
			++nesting;
		}
		else if (s[i]==')') {
			--nesting;
		}
	}
	return nesting;
}

size_t splitOnOp(const string& s,char op) {
	size_t loc=0;
	for (size_t start = 0 ;
			(loc=s.find(op,start)) != std::string::npos ;
			start = loc+1) {
		if (!nestedInParen(s,loc) &&
			(op != '+' || loc==0 || (s[loc-1]!='e' && s[loc-1]!='E'))) {
			return loc;
		}
	}
	return std::string::npos;
}

size_t split(const string& source) {
	size_t loc=1;
	if (source.substr(0,4) == "Abs(") {
		loc = 4;
	}
	else if (source.substr(0,7) == "Square(") {
		loc = 7;
	}
	else if (source[0] != '(') {
		if (source.find_first_not_of("-0123456789") == std::string::npos) {
			return std::string::npos;
		}
		// As * has precedence over +, if there are no parentheses
		// try to find a + then, the * will bind stronger
		if (((loc=splitOnOp(source,'+')) != std::string::npos) ||
			((loc=splitOnOp(source,'*')) != std::string::npos)) {
			return loc;

		}
		else {
			return std::string::npos;
		}
	}

	unsigned int nesting=1;
	for (; nesting && loc<source.length() ; ++loc) {
		if (source[loc] == '(') {
			++nesting;
		}
		else if (source[loc]==')') {
			--nesting;
		}
	}
	if (!nesting && loc < source.length()-1) {
		return loc;
	}
	return std::string::npos;
}


bool parseNumber(const string& source, int& val) {
	stringstream s(source);
	char c;
	if (s >> val && !(s >> c)) {
		return true;
	}
	return false;
}

Expression* parseExpression(const string& source) {
	size_t place = split(source);
	if (place != std::string::npos) {
		Expression* l=parseExpression(source.substr(0,place));
		if (!l) {
			return nullptr;
		}
		Expression* r=parseExpression(source.substr(place+1,source.length()-place-1));
		if (!r) {
			delete l;
			return nullptr;
		}
		switch (source[place]) {
		case '*':
			return new Multiply(l,r);
		case '+':
			return new Add(l,r);
		default:
			delete l;
			delete r;
			return nullptr;
		}
	}
	else {
		if (source.substr(0,4)=="Abs(" && source[source.length()-1]==')') {
			Expression* t=parseExpression(source.substr(4,source.length()-5));
			if (!t) {
				return nullptr;
			}
			return new Abs(t);
		}
		if (source.substr(0,7)=="Square(" && source[source.length()-1]==')') {
			Expression* t=parseExpression(source.substr(7,source.length()-8));
			if (!t) {
				return nullptr;
			}
			return new Square(t);
		}
		if (source[0]=='(' && source[source.length()-1]==')') {
			return parseExpression(source.substr(1,source.length()-2));
		}

		int temp;
		if (parseNumber(source,temp)) {
			return new Number(temp);
		}
		return nullptr;
	}
}