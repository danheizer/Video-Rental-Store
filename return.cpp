#include "return.h"
//---------------------------------------------------------------------------
//constructor
//intializes members to junk, to be replaced with setData
Return::Return()
{
	code = 'R';
	clientID = 0;
	item = NULL;
	customer = NULL;
}

//---------------------------------------------------------------------------
//destructor
Return::~Return()
{

};

//---------------------------------------------------------------------------
//setData
void Return::setData(ifstream& infile, Container* inventory)
{
	if(infile.peek() == 10) infile.get();
	code = 'R';
	infile >> clientID;
		//Find customer
	infile >> format;
	ProductFactory temp;
	infile.get();
};

//---------------------------------------------------------------------------
//create
Transaction* Return::create()
{
	return new Return;
};

//---------------------------------------------------------------------------
//display
void Return::display() const
{
	if(item == NULL) return;
	cout << item->getFormat() << setw(8) << left << " Return  ";
	item->displayTransactionData();
};

//---------------------------------------------------------------------------
//requiresproduct
bool Return::requiresProduct() const
{
	return true;
}

//---------------------------------------------------------------------------
//requiresCustomer
bool Return::requiresCustomer() const
{
	return true;
}