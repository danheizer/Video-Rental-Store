#ifndef STORE_H
#define STORE_H
#include "customer.h"
#include "product.h"
#include "transaction.h"
#include "bintree.h"
#include "container.h"
#include "customerfactory.h"
#include "transactionfactory.h"
#include "productfactory.h"
#include "constants.h"
// This is my manager class for lab 4. It has datamembers for all customers, transactions
// and products. Products are stored in BinTrees, but everything else is stored in arrays.
// This class contains methods for building (transactions/customers/products) through 
// factory classes. Store uses a factory to process the data from the text files. 
// the run() method processes all three files.

// Additional display methods are included as well.
class Store 
{
public:
	Store();
	~Store();

	//Processes the textfiles, builds inventory etc
	void run();
	//Creates a customerFactory and populates customer array
	void buildCustomers(ifstream&);
	//Displays all customers
	void displayCustomers() const;

	//Check for valid customer ID, valid product
	bool processTransaction(Transaction* data);
	//Populates transactions array from file
	void buildTransactions(ifstream&);
	//Display every customers transaction history
	//or a single history of pin from param
	void displayStoreTransactionHistory();

	//Creates a product factory and populates container
	void buildInventory(ifstream&);
	void displayInventory() const;

private:
	//Array of all customers active at the store
	Customer** customers;

	//Record of all the store's transactions
	Transaction** transactions;

	//Container Object that holds products
	Container* inventory;

	void insertTransaction(Transaction*);
	//Add 100 spaces to transactions[]
	void resize();
	int transactionSize;
	int numTransactions;
};

#endif
