//-------------------------------------------
// customer.h
// Customer Class
// Used in: Transaction, Factory, Store
//
// Each customer object has a name and PIN, as 
// well as a transaction / rental history
//-------------------------------------------
#include <string>
#ifndef CUSTOMER_H
#define CUSTOMER_H

class Transaction;
using namespace std;
class Customer {
public:
	Customer();
	~Customer();
	Customer(string name, int pin);

	// Returns the customer's name
	string getName() const;
	void setData(ifstream& infile);

	// Displays the specified number of items in history, or all if items is not
	// specified or set to 0
	void displayHistory(int items = 0) const;
	void display() const;
	void addItemToHistory(Transaction*);
	int getPin() const;
	Customer* create();

private:
	string firstName;      // The customer's name
	string lastName;
	int pin;          // The customer's PIN (4 digit)
	Transaction** history;
	int histSize;
	int numItems;
	void resize();
};

#endif
