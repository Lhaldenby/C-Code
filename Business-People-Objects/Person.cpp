#include "Person.h"

using std::string;
using std::stringstream;

Person::Person(const char* name)
	:name_(name){
	// IMPLEMENT ME DONE
}

Person::Person(const std::string& name)
	:name_(name){
	// IMPLEMENT ME DONE
}

Person::~Person(){
	// IMPLEMENT ME DONE
	
}

std::string Person::name() const{
	// IMPLEMENT ME DONE
	return name_;

}

std::ostream& operator<<(std::ostream& o, const Person& p){
	// IMPLEMENT ME DONE
	o << p.toString();
	return o;
}






Customer::Customer(const char* name, unsigned int customerId)
	:Person(name),customerId_(customerId){
	// IMPLEMENT ME DONE
}

Customer::Customer(const std::string& name, unsigned int customerId)
	:Person(name),customerId_(customerId){
	// IMPLEMENT ME DONE
}

Customer::~Customer(){
	// IMPLEMENT ME
}

void Customer::addOrder(unsigned int order){
	// IMPLEMENT ME
	orderNumber_.push_back(order);
}

unsigned int Customer::getOrder(unsigned int i){
	// IMPLEMENT ME 
	if (i >= orderNumber_.size())
		return 0;
	
	
	for (int j = 0; j < orderNumber_.size(); j++){
		if (i == ( j+1))
			return orderNumber_[j];
		
	}
}

unsigned int Customer::id() const{
	// IMPLEMENT ME DONE
	return customerId_;
}

std::string Customer::printOrderNums() const{
	std::string s;
	
	for (int j = 0; j < orderNumber_.size(); j++){
			s = s +", " + std::to_string(orderNumber_[j]);
		
	}
	
	return s;
}

std::string Customer::toString() const{
	std::string s = printOrderNums();
	return "[" + name() + ", " + std::to_string(customerId_) + s + "]" ;
}

std::string Customer::type() const{
	// DONE
	return "Customer";
}



Employee::Employee(const char* name, double salary)
	:Person(name),salary_(salary){
	// IMPLEMENT ME DONE
}

Employee::Employee(const std::string& name, double salary)
	:Person(name),salary_(salary){
	// IMPLEMENT ME DONE
}

Employee::~Employee(){
	// IMPLEMENT ME DONE
}

void Employee::increaseSalaryBy(double amount){
	// IMPLEMENT ME DONE
	if (!(amount <= 0)){
		salary_ = salary_ + amount;
	}
}

double Employee::salary()const{
	// IMPLEMENT ME DONE
	return salary_;
}






Manager::Manager(const char* name, double salary)
	:Employee(name, salary){
	// IMPLEMENT ME DONe
}

Manager::Manager(const std::string& name, double salary)
	:Employee(name, salary){
	// IMPLEMENT ME DONE
}

Manager::~Manager(){
	// IMPLEMENT ME DONE
}

std::string Manager::toString() const{
	
	return "[" + name() + ", earns: " + std::to_string(salary_) + "]";
}

std::string Manager::type() const{
	//DONE
	return "Manager";
}



Consultant::Consultant(const char* name, double salary)
	:Employee(name, salary){
	// IMPLEMENT ME DONE
}

Consultant::Consultant(const std::string& name, double salary)
	:Employee(name, salary){
	// IMPLEMENT ME DONE
}

Consultant::~Consultant(){
	// IMPLEMENT ME DONE
}

void Consultant::setManager(Manager* manager){
	// IMPLEMENT ME DONE
	manager_ = manager;
}

std::string Consultant::getManagerName() const{
	// IMPLEMENT ME DONE
	return manager_->name();
}

std::string Consultant::toString() const{

	return "[" + name() + ", earns: " + std::to_string(salary()) +", manager: " + getManagerName() + "]";
}

std::string Consultant::type() const{
	//DONE
	return "Consultant";
}

// TODO:
// Add missing functions implementations.

