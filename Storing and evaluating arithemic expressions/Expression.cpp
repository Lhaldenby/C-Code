#include <string>
#include "Expression.h"

Expression::Expression(){
	// IMPLEMENT ME
}
Expression::~Expression(){
	// IMPLEMENT ME
}




BinaryExpression::BinaryExpression(Expression* subexp1, Expression* subexp2){
	// IMPLEMENT ME
	subExp1_ = subexp1;
	subExp2_ = subexp2;
}
BinaryExpression::~BinaryExpression(){
	// IMPLEMENT ME
}

std::string BinaryExpression::print() const{
	return "Binary Expression";
}

std::string BinaryExpression::type() const{
	// DONE
	return "BinaryExpression";
}



UnaryExpression::UnaryExpression(Expression* subexp){
	// IMPLEMENT ME
	subExp_ = subexp;
}
UnaryExpression::~UnaryExpression(){
	// IMPLEMENT ME
}

std::string UnaryExpression::print() const{
	return "UnaryExpression";
}

std::string UnaryExpression::type() const{
	// DONE
	return "UnaryExpression";
}


Number::Number(int n){
	// IMPLEMENT ME
	num_ = n;
}
Number::~Number(){
	// IMPLEMENT ME
}

std::string Number::print() const{
	return std::to_string(num_);
}

std::string Number::type() const{
	// DONE
	return "Number";
}

int Number::evaluate() const{
	return num_;
}




Multiply::Multiply(Expression* subexp1, Expression* subexp2)
	:BinaryExpression(subexp1, subexp2){
	// IMPLEMENT ME
}
Multiply::~Multiply(){
	// IMPLEMENT ME
}

std::string Multiply::print() const{
	return "("+subExp1_->print()+"*"+subExp2_->print()+")";
}

std::string Multiply::type() const{
	// DONE
	return "Multiply";
}

int Multiply::evaluate() const{
	return subExp1_->evaluate() * subExp2_->evaluate();
}




Add::Add(Expression* subexp1, Expression* subexp2)
	:BinaryExpression(subexp1, subexp2){
	// IMPLEMENT ME
}
Add::~Add(){
	// IMPLEMENT ME
}

std::string Add::print() const{
	return "(" + subExp1_->print() + "+" + subExp2_->print() + ")";
}

std::string Add::type() const{
	// DONE
	return "Add";
}

int Add::evaluate() const{
	return subExp1_->evaluate() + subExp2_->evaluate();
}





Abs::Abs(Expression* subexp)
	:UnaryExpression(subexp){
	// IMPLEMENT ME
}
Abs::~Abs(){
	// IMPLEMENT ME
}

std::string Abs::print() const{
	
	return "Abs("+subExp_->print()+")";
}

std::string Abs::type() const{
	// DONE
	return "Abs";
}

int Abs::evaluate() const{
	if (subExp_->evaluate()>0){
		return subExp_->evaluate();
	} else {
		return -(subExp_->evaluate());
	}
}




Square::Square(Expression* subexp)
	:UnaryExpression(subexp){
	// IMPLEMENT ME
}
Square::~Square(){
	// IMPLEMENT ME
}

std::string Square::print() const{
	return "Square(" + subExp_->print() +")";
}

std::string Square::type() const{
	// DONE
	return "Square";
}

int Square::evaluate() const{
	return subExp_->evaluate() * subExp_->evaluate();
}

// TODO:
// Add missing functions implementations.

