#include "show.h"

//---------------------------------------------------------------------------
//constructor
//intializes members to junk, to be replaced with setData
Show::Show()
{
	item = NULL;
	clientID = 0;
	code = 'S';
	customer = NULL;
	inventoryToDisplay = NULL;
}

//---------------------------------------------------------------------------
//destructor
Show::~Show()
{

}

//---------------------------------------------------------------------------
//setData
void Show::setData(ifstream& infile, Container* inventory)
{
	if(infile.eof()) return;
	if(infile.peek() == 10) infile.get();
	code = 'S';
	inventoryToDisplay = inventory;
}

//---------------------------------------------------------------------------
//create
Transaction* Show::create()
{
	return new Show;
}

//---------------------------------------------------------------------------
//display
//Show does not get displayed in histories, and is not required to display
//anything
void Show::display() const
{
	if(inventoryToDisplay != NULL)
		inventoryToDisplay->displayAll();
};

//---------------------------------------------------------------------------
//requiresproduct
bool Show::requiresProduct() const
{
	return false;
}

//---------------------------------------------------------------------------
//requiresCustomer
bool Show::requiresCustomer() const
{
	return false;
}

