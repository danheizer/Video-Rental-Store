#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H
// transactionfactory.h
// TransactionFactory Class
// This class creates transactions from text files.
// To add additional transactions to the movie store, all one must do is
// add a call to create at the index hashed to by the transaction's code. 
// No switches are used (beyond determining that something is a letter). 
//
// This class takes advantage of the pure virtual functions in transaction.h

#include "transaction.h"
#include "constants.h"
class Container;
using namespace std;
class TransactionFactory
{
private:
	//B is borrow
	//R is return
	int hash(char key) const;

	 
public:
	TransactionFactory();
	~TransactionFactory();
	bool validateQty(Transaction*, char&);
	bool validateCustomer(Transaction* toAdd, Customer** clients);
	bool validateItem(Transaction* toAdd, Container* inventory);
	Transaction* createIt(ifstream& infile, Container*, Customer**);
private:
	//Each transaction can effect quant differently, and have different format
	Transaction* transFact[NUM_TYPES_OF_TRANSACTIONS];
	int quantity[NUM_TYPES_OF_TRANSACTIONS];
	ProductFactory builder;

};
#endif