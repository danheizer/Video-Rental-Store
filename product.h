#ifndef PRODUCT_H
#define PRODUCT_H
using namespace std;
#include <string>
#include <fstream>
#include <iostream>
#include "constants.h"
#include <iomanip>

/*//-------------------------------------------------------------------------
// Product is a base class. Any product added to our movie store most be a  
// child of the Product class, and provide the required pure virtual        
// functions.                                                               
//                                                                          
//	Assumuptions:                                                            
//   1. There will be at most 52 unique codes that denote type of product   
//	 2. Product codes must be an english letter, upper or lower case.       
//	 3. The text file used to build products is properly formatted. The     
//	      format can vary depending on the type of product, but this must   
//		  be addressed in setData. The first char on each line must be the  
//		  code for that type of product.                                     
*///-------------------------------------------------------------------------

/*///////////////////////////////////////////
//Parent class of:                         //
//	class Classic;                         // 
//	class Comedy;                          //
//	class Drama;                           //
*////////////////////////////////////////////
class Product 
{
private:
	char code;
public:
	Product( char c );
	virtual ~Product() = 0;
	

	//Operators for sorting
	virtual bool operator<(const Product& rhs) const = 0;
	virtual bool operator>(const Product& rhs) const = 0;
	virtual bool operator==(const Product& rhs) const = 0;
	virtual bool operator!=(const Product& rhs) const = 0;
	//Returns a new product
	virtual Product* create() = 0;

	// Display product-specific information
	virtual void display() const = 0;
	// Display the amount of copies in stock, then out
	virtual void displayCopies() const = 0;
	// Display data in transaction format
	virtual void displayTransactionData() const = 0;
	
	//Build product from a file
	virtual void setData(ifstream&) = 0;
	//Build a product using only what's provided by a transaction
	virtual void setCommandData(ifstream&) = 0;

	int getTotalCopies() const;
	int getQuantity() const;
	void setQuantity(int quant);
	char getCode() const;
	string getFormat() const;
	string getTitle() const;

protected:
	string title;
	int quantity;
	int totalCopies;
	string format;
};
#endif
