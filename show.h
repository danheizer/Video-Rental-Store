#ifndef SHOW_H
#define SHOW_H
#include "transaction.h"
class Show : public Transaction
{
public:
	Show();
	virtual ~Show();
	virtual void setData(ifstream& infile, Container*);
	virtual Transaction* create();
	virtual void display() const;
	virtual bool requiresProduct() const;
	virtual bool requiresCustomer() const;
private:
	Container* inventoryToDisplay;
};
#endif