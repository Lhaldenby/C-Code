#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <iosfwd>
#include <vector>

// In this exercise you will implement a simple hierarchy of people
// using inheritance. The hierarchy consists of a base class Person,
// the classes Customer and Employee, which are derived from Person,
// and two other classes, Manager and Consultant, which are derived
// from the class Employee.
// Each person supports two functions: toString and type.
// The function type should return the name of that class.
// The toString function should print the information of the instance
// as explained below.
//
// You should add the virtual keyword where appropriate and then
// implement the functions where they are most appropriate.
// Person and Employee could be abstract classes, but 
// Customer, Manager and Consultant should be concrete classes.
//
// Customer has an additional feature to place an order.
// Every employee has the additional feature to get their
// salary increased.
// Consultant has a manager, which is implemented by a pointer to 
// and object of type Manager. Notice that many consultants will 
// share the pointer to the same Manager, and that the Consultant 
// objects do not own the corresponding Manager object.
//
// Each class has some extra functions, declared below.

class Person {
public:
	// No need to implement copy and move constructors
	Person() = delete;
	Person(const Person&) = delete;
	Person(Person&&) = delete;

	// Constructs a Person with a given name
	Person(const char* name);
	Person(const std::string& name);

	virtual ~Person();

	// Returns the name of the Person.
	// Should be supported by all Persons.
	std::string name() const;

	// Returns a string containing all the information of a Person
	// represented in the following format.
	//
	// For a Customer with name John Smith, customer ID 42 and no orders:
	// [John Smith, 42]
	//
	// For a Customer with name John Smith, customer ID 42 and 
	// orders with numbers 123 and 456:
	// [John Smith, 42, 123, 456]
	//
	// For a Manager with name Alice Jones and salary 50000.5:
	// [Alice Jones, earns: 50000.5]
	//     
	// For a Consultant Bob Lewis with salary 30000 and manager Alice Jones:
	// [Bob Lewis, earns: 30000, manager: Alice Jones]
	virtual std::string toString() const=0;

	// Should return Customer for Customer, Manager for Manager, and
	// Consultant for Consultant 
	virtual std::string type() const=0;

	// Override the redirection. Should work for all
	// references to Persons by outputting the toString method
	friend std::ostream& operator<<(std::ostream& o, const Person& p);

  // TODO:
  // Add data members and functions you need.
private:
  // TODO:
  // Add data members and functions you need.
protected:
  // TODO:
  // Add data members and functions you need.
	std::string name_;
};

class Customer : public Person {
public:
	// No need to implement copy and move constructors
	Customer() = delete;
	Customer(const Customer&) = delete;
	Customer(Customer&&) = delete;

	// Constructors and destructor
	Customer(const char* name,unsigned int customerId);
	Customer(const std::string& name, unsigned int customerId);
	~Customer();

	// Add an order to the customer. If the order number is 0,
	// the function should have no effect.
	void addOrder(unsigned int order);

	// Return the i-th order of a customer.
	// If i is out of bounds return 0.
	unsigned int getOrder(unsigned int i);

	// Return the customer's ID
	unsigned int id() const;
	
	std::string toString() const override;
	std::string type() const override;
	
	std::string printOrderNums() const;
  // TODO:
  // Add data members and functions you need.
private:
  // TODO:
  // Add data members and functions you need.
protected:
  // TODO:
  // Add data members and functions you need.
	int customerId_;
	std::vector<int> orderNumber_;
};

class Employee : public Person {
public:
	// No need to implement copy and move constructors
	Employee() = delete;
	Employee(const Employee&) = delete;
	Employee(Employee&&) = delete;

	// Constructors and destructor
	Employee(const char* name, double salary);
	Employee(const std::string& name, double salary);
	virtual ~Employee();


	// Adds amount to the Employee's salary.
	// If amount <= 0,the function has no effect.
	void increaseSalaryBy(double amount);

	// Returns the employee's salary.
	double salary() const;

  // TODO:
  // Add data members and functions you need.
private:
  // TODO:
  // Add data members and functions you need.
protected:
  // TODO:
  // Add data members and functions you need.
	int salary_;
};

class Manager : public Employee {
public:
	// No need to implement copy and move constructors
	Manager() = delete;
	Manager(const Manager&) = delete;
	Manager(Manager&&) = delete;

	// Constructors and destructor
	Manager(const char* name, double salary);
	Manager(const std::string& name, double salary);
	~Manager();

	std::string toString() const override;
	std::string type() const override;

  // TODO:
  // Add data members and functions you need.
private:
  // TODO:
  // Add data members and functions you need.
protected:
  // TODO:
  // Add data members and functions you need.
};

class Consultant : public Employee {
public:
	// No need to implement copy and move constructors
	Consultant() = delete;
	Consultant(const Consultant&) = delete;
	Consultant(Consultant&&) = delete;

	// Constructors and destructor
	Consultant(const char* name, double salary);
	Consultant(const std::string& name, double salary);
	~Consultant();


	// Sets the manager of the consultant.
	void setManager(Manager* manager);

	// Returns manager's name. 
	// If there is no manager, returns the empty string.
	std::string getManagerName() const;
		

	std::string toString() const override;
	std::string type() const override;
  // TODO:
  // Add data members and functions you need.
private:
  // TODO:
  // Add data members and functions you need.
protected:
  // TODO:
  // Add data members and functions you need.
	Manager* manager_;
};



#endif /* PERSON_H_ */
