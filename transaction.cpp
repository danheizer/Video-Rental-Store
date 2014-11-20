#include "transaction.h"


//---------------------Default Construcotr------------------
Transaction::Transaction()
{
	item = NULL;
	clientID = 0;
	code = '0';
}
//------------------------Destructor----------------------------
Transaction::~Transaction()
{

};

//------------------------updateItem-------------------------
//Replace old item from command file with new data from product
//container. Delete old item.
void Transaction::updateItem(Product* replacement)
{
	delete item;
	item = NULL;
	item = replacement;
};
