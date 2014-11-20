//customerfactory.cpp
//implementation of customerFactory class
#include "customerfactory.h"
#include <iostream>
#include <fstream>
//--------------------------------------------------
//Default constructor
CustomerFactory::CustomerFactory()
{
	custFact = new Customer();
};
//--------------------------------------------------
//Destructor
CustomerFactory::~CustomerFactory()
{
	delete custFact;
	custFact = NULL;
}

//--------------------------------------------------
//createIt
//uses setData to build a customer from a text file
Customer* CustomerFactory::createIt(ifstream& infile)
{
	if(!infile.eof())
	{
		Customer* toAdd = new Customer;
		toAdd->setData(infile); 

		return toAdd;
	}
	return NULL;
};