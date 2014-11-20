#ifndef RETURN_H
#define RETURN_H
#include "transaction.h"
class Return: public Transaction
{
/*
This class extends the Transaction class.
Code: R
Requires: An item, a customer
*/
public:
	Return();
	virtual ~Return();
	virtual void setData(ifstream& infile, Container*);
	virtual Transaction* create();
	virtual void display() const;
	virtual bool requiresProduct() const;
	virtual bool requiresCustomer() const;
	
};
#endif