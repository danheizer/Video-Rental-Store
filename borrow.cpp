#include "borrow.h"
//---------------------------------------------------------------------------
//constructor
//intializes members to junk, to be replaced with setData
Borrow::Borrow()
{
	item = NULL;
	clientID = 0;
	code = 'B';
	customer = NULL;
}

//---------------------------------------------------------------------------
//destructor
Borrow::~Borrow()
{

}

//---------------------------------------------------------------------------
//setData
void Borrow::setData(ifstream& infile, Container* inventory)
{
	if(infile.peek() == 10) infile.get();
	code = 'B';
	infile.get();
	infile >> clientID;
	infile >> format;
	infile.get();
	
}

//---------------------------------------------------------------------------
//create
Transaction* Borrow::create()
{
	return new Borrow;
}

//---------------------------------------------------------------------------
//display
void Borrow::display() const
{
	if(item == NULL) return;
	cout << item->getFormat() << " " << setw(8) << left << "Borrow";
	item->displayTransactionData();
};

//---------------------------------------------------------------------------
//requiresproduct
bool Borrow::requiresProduct() const
{
	return true;
}

//---------------------------------------------------------------------------
//requiresCustomer
bool Borrow::requiresCustomer() const
{
	return true;
}