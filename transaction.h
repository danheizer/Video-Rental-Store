#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "product.h"
#include "customer.h"
#include "productfactory.h"
#include <iomanip>
#include <iostream>
#include "store.h"
/*//-------------------------------------------------------------------------
// Transaction is a base class. Any Transaction added to our movie store most be a  
// child of the Transaction class, and provide the required pure virtual        
// functions.                                                               
//                                                                          
//	Assumuptions:                                                            
//   1. There will be at most 52 unique codes that denote type of transaction   
//	 2. Transaction codes must be an english letter, upper or lower case.       
//	 3. The text file used to build products is properly formatted. The     
//	      format can vary depending on the type of product, but this must   
//		  be addressed in setData. The first char on each line must be the  
//		  code for that type of product.                                     
*///-------------------------------------------------------------------------
/*///////////////////////////////////////////
//Parent class of:                         //
//	class Borrow;                          // 
//	class Return;                          //
//	class Show;                            //
//  class History;                         //
*////////////////////////////////////////////
class Container;
class Transaction {
public:
	// An item in the transaction ledger. 
	Transaction();
	// Replace old item with new one
	void updateItem(Product*);
	virtual ~Transaction() = 0;
	// Build transaction from file
	virtual void setData(ifstream&, Container*) = 0;
	// Used for factories, returns a new Transaction
	virtual Transaction* create () = 0;
	virtual void display() const = 0;
	// Returns if(transaction) requires a product. 
	// (ie, a show transaction returns false, borrow returns true)
	virtual bool requiresProduct() const = 0;
	virtual bool requiresCustomer() const = 0;


	// The product that the transction is performed upon
	Product* item;

	// The customer that performed the transaction
	int clientID;
	const Customer* customer;
	char format;

	// A char that denotes which type of transaction
	char code;
};
#endif
