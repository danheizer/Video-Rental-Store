#ifndef BORROW_H
#define BORROW_H
#include "transaction.h"
class Borrow : public Transaction
{
/*
This class extends the Transaction class.
Code: B
Requires: An item, a customer
*/
public:
	Borrow();
	virtual ~Borrow();
	virtual void setData(ifstream& infile, Container*);
	virtual Transaction* create();
	virtual void display() const;
	virtual bool requiresProduct() const;
	virtual bool requiresCustomer() const;
};
#endif