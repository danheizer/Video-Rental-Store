#include "history.h"
//---------------------------------------------------------------------------
//constructor
//intializes members to junk, to be replaced with setData
History::History()
{
	code = 'H';
	clientID = 0;
	item = NULL;
	customer = NULL;
	format = '0';
}

//---------------------------------------------------------------------------
//destructor
History::~History()
{

}

//---------------------------------------------------------------------------
//display
//Because a history object itself is not inserted into a customer's history,
//it does not display.
void History::display() const
{
	if(customer != NULL)
		customer->displayHistory();
}

//---------------------------------------------------------------------------
//setData
void History::setData(ifstream& infile, Container* inventory)
{
	if(infile.eof()) return;
	infile.get();
	infile >> clientID;
	infile.get();
};

//---------------------------------------------------------------------------
//create
Transaction* History::create()
{
	return new History;
};

//---------------------------------------------------------------------------
//requiresproduct
bool History::requiresProduct() const
{
	return false;
}

//---------------------------------------------------------------------------
//requiresCustomer
bool History::requiresCustomer() const
{
	return true;
}