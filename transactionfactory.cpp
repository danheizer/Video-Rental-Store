#include "transactionfactory.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "borrow.h"
#include "return.h"
#include "history.h"
#include "show.h"
#include "store.h"
using namespace std;

//---------------------------------------------------------------------------
//Constructor
TransactionFactory::TransactionFactory()
{
	for(int i = 0; i < NUM_TYPES_OF_TRANSACTIONS; i++)
	{
		transFact[i] = NULL;
		quantity[i] = 0;
	}
	transFact[hash('B')] = new Borrow;
	quantity[hash('B')] = -1;
	transFact[hash('R')] = new Return;
	quantity[hash('R')] = 1;
	transFact[hash('H')] = new History;
	transFact[hash('S')] = new Show;
};

//---------------------------------------------------------------------------
//Destructor
TransactionFactory::~TransactionFactory()
{
	for(int i = 0; i < NUM_TYPES_OF_TRANSACTIONS; i++)
	{
		delete transFact[i];
		transFact[i] = NULL;
	}
}

//---------------------------------------------------------------------------
//Creates a transaction
//Uses the truncated data from the data4commands file to create a junk product
//Searches through the param container to find the appropriate product
//Searches through the param Customer** to find the appropriate customer
Transaction* TransactionFactory::createIt(ifstream& infile,  Container* inventory, Customer** clients)
{
	if(infile.eof()) return NULL;
	while(infile.peek() == 10){ infile.get(); }
	char key = infile.get();
	if(transFact[hash(key)] == NULL) //Bad Transaction code
	{
		while(!infile.eof() && infile.get() != '\n'){}
		return NULL;
	}
	//Make a new object at the index
	Transaction* toAdd = transFact[hash(key)]->create();
	toAdd->setData(infile, inventory);

	//If transaction doesnt need to find a customer or an item
	if(!toAdd->requiresCustomer() && !toAdd->requiresProduct())
		return toAdd;

	if(!validateCustomer(toAdd, clients)) return NULL;

	//If I don't need to retrieve an item
	if(!toAdd->requiresProduct()) return toAdd;

	toAdd->item = builder.createIt(infile, 1);
	//Ensure the product is in inventory
	if(!validateItem(toAdd, inventory)) return NULL;
	if(!validateQty(toAdd, key)) return NULL;
	
	toAdd->item->setQuantity(toAdd->item->getQuantity() + quantity[hash(key)]);
	return toAdd;
};

//---------------------------------------------------------------------------
//hash
//A is index 0, Z is 25, a 26, z 51
int TransactionFactory::hash(char itemCode) const
{
	if(itemCode >= 'A'&& itemCode <= 'Z')
		return (itemCode - 'A') % NUM_TYPES_OF_TRANSACTIONS;
	
	else if(itemCode >= 'a' && itemCode <= 'z')
		return (itemCode - 'a' + 26) % NUM_TYPES_OF_TRANSACTIONS;
	

	else return 0;
}

//---------------------------------------------------------------------------
//validateQty
//Returns true if we have copies to rent out
bool TransactionFactory::validateQty(Transaction* toAdd, char& key)
{
	int currentStock = toAdd->item->getQuantity();
	int newStock = currentStock + quantity[hash(key)];
	if(newStock < 0 || newStock > toAdd->item->getTotalCopies())
	{	
		delete toAdd;
		toAdd = NULL;
		return false;
	}	
	return true;
}

//---------------------------------------------------------------------------
//validateCustomer
//returns true if the customer is found
bool TransactionFactory::validateCustomer(Transaction* toAdd, Customer** clients)
{
	//Find customer
	if(clients[toAdd->clientID] == NULL)
	{
		delete toAdd;
		return false;
	}
	toAdd->customer = clients[toAdd->clientID];
	return true;
}

//---------------------------------------------------------------------------
//returns true if the item is found. toAdd's pointer is set to the item
//in the inventory
bool TransactionFactory::validateItem(Transaction* toAdd, Container* inventory)
{
	NodeData* storedItem = NULL;
	if(!inventory->retrieve(toAdd->item, storedItem))
	{
		//object created with an item not in inventory
		delete toAdd->item;
		toAdd->item = NULL;
		delete toAdd;
		toAdd= NULL;
		return false;
	}
	toAdd->updateItem(storedItem->getData());
	return true;
}