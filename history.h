#ifndef HISTORY_H
#define HISTORY_H
#include "transaction.h"
class History : public Transaction
{
/*
This class extends the Transaction class.
Code: H
Requires: a customer
*/
public:
	History();
	virtual ~History();
	virtual void display() const;
	virtual void setData(ifstream& infile, Container*);
	virtual Transaction* create();
	virtual bool requiresProduct() const;
	virtual bool requiresCustomer() const;
};

#endif