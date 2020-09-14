#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include <string>

// In this exercise you will implement storing and evaluation 
// of simple arithmetic expressions using inheritance.
// 
// The hierarchy of expressions is:
//
//                  				Expression
//                       				 |
//             --------------------------------------------------
//             |                         |                      |
//        BinaryExpression              Number              UnaryExpression
//             |                                                |
//  ------------------------                            ----------------
//  |                      |                            |              |
// Multiply               Add                          Square         Abs
//
//
// Number represents expressions that are integer values,
// Multiply represents multiplication of two Expressions,
// Add represents sum of two Expressions, and
// Abs represents the absolute value of an Expression.         
// All expressions should support functions:
// type : return the name of the class
// print : return a string version of the entire expression
//         more details below
// evaluate : return the result of evaluating the expression
// The result of evaluating an expression is an integer.
//
// As in Part 1, you should add the virtual keyword where appropriate
// and then implement the functions where they are most appropriate.
// Expression, BinaryExpression, and UnaryExpression could be  abstract 
// classes but all other classes should be concrete classes.



class Expression {
public:
	Expression();
	virtual ~Expression();

	// Functions supported by all types of Expression:
	
	// Returns the result of evaluating the expression.
	virtual int evaluate() const = 0;
	
	// Prints the expression.
	// You should NOT introduce extra spaces or new lines.
	// The brackets and the corresponding operator are part
	// of the output format and do not depend on the 
	// contents of the expression. Required format:
	//
	// Multiply: 
	// (subexp*subexp)
	//           
	// Add:
	// (subexp+subexp)
	//     
	// Abs:
	// Abs(subexp)
	//    
	// Square:
	// Square(subexp)
	//	
	// Number, where n is its value:
	// n
	virtual std::string print() const=0;

	// Returns the name of the class:
	// Multiply, Add, Number, Square or Abs
	virtual std::string type() const=0;
	
	// TODO:
  	// Add data members and functions you need.

protected:
	// TODO:
  	// Add data members and functions you need.
	Expression * subExp_;

private:
	// TODO:
  	// Add data members and functions you need.

};


class BinaryExpression : public Expression {
public:
	BinaryExpression() = delete;
	BinaryExpression(Expression* subexp1, Expression* subexp2);
	virtual ~BinaryExpression();

	// TODO:
  	// Add data members and functions you need.
	std::string print() const override;
	std::string type() const override;
	int evaluate() const override = 0;
protected:
	// TODO:
  	// Add data members and functions you need.
	Expression * subExp1_;
	Expression * subExp2_;

private:
	// TODO:
	// Add data members and functions you need.
};

class UnaryExpression : public Expression {
public:
	UnaryExpression() = delete;
	UnaryExpression(Expression* subexp);
	virtual ~UnaryExpression();

	// TODO:
  	// Add data members and functions you need.
	std::string print() const override;
	std::string type() const override;
	int evaluate() const override = 0;

protected:
	// TODO:
  	// Add data members and functions you need.
	Expression * subExp3_;

private:
	// TODO:
	// Add data members and functions you need.
};


class Number : public Expression {
public:
	Number() = delete;
	Number(int n);
	~Number();

	// TODO:
  	// Add data members and functions you need.
	
	std::string print() const override;
	std::string type() const override;
	int evaluate() const override;
protected:
	// TODO:
  	// Add data members and functions you need.
	int num_;

private:
	// TODO:
	// Add data members and functions you need.
};


class Multiply : public BinaryExpression {
public:
	Multiply() = delete;
	Multiply(Expression* subexp1,Expression* subexp2);
	~Multiply();

	// TODO:
  	// Add data members and functions you need.
	std::string print() const override;
	std::string type() const override;
	int evaluate() const override;
protected:
	// TODO:
  	// Add data members and functions you need.

private:
	// TODO:
	// Add data members and functions you need.
};


class Add : public BinaryExpression{
public:
	Add() = delete;
	Add(Expression* subexp1,Expression* subexp2);
	~Add();

	// TODO:
  	// Add data members and functions you need.
	std::string print() const override;
	std::string type() const override;
	int evaluate() const override;
protected:
	// TODO:
  	// Add data members and functions you need.

private:
	// TODO:
	// Add data members and functions you need.
};


class Abs : public UnaryExpression {
public:
	Abs() = delete;
	Abs(Expression* subexp);
	~Abs();

	// TODO:
  	// Add data members and functions you need.
	std::string print() const override;
	std::string type() const override;
	int evaluate() const override;
protected:
	// TODO:
  	// Add data members and functions you need.

private:
	// TODO:
	// Add data members and functions you need.
};

class Square : public UnaryExpression {
public:
	Square() = delete;
	Square(Expression* subexp);
	~Square();

	// TODO:
  	// Add data members and functions you need.
	std::string print() const override;
	std::string type() const override;
	int evaluate() const override;
protected:
	// TODO:
  	// Add data members and functions you need.
	
private:
	// TODO:
	// Add data members and functions you need.
};

#endif /* EXPRESSION_H_ */
