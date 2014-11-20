//customer.cpp
//Implementation of class customer
#include "customer.h"
#include "transaction.h"
#include <fstream>
#include <iostream>

//------------------------------------------------
//Default constructor
Customer::Customer()
{
	firstName = "nullF";
	lastName = "nullL";
	pin = 0;
	history = new Transaction*[INITIAL_HISTORY_SIZE];
	for(int i = 0; i < INITIAL_HISTORY_SIZE; i++)
		history[i] = NULL;
	numItems = 0;
	histSize = INITIAL_HISTORY_SIZE;
};

//--------------------------Destructor-------------------
Customer::~Customer()
{
	delete[] history;
	history = NULL;
}

//------------------------------------------------
//setData
//Create customer from text file
void Customer::setData(ifstream& infile)
{
	infile >> pin;
	infile.get();
	infile >> firstName;
	infile.get();
	infile >> lastName;
	infile.get();

};

//------------------------------getName()----------------------------
string Customer::getName() const
{
	string fullName = firstName;
	fullName += " ";
	fullName += lastName;
	return fullName;
};

//-------------------------------Display()-----------------------------
void Customer::display() const
{
	cout << pin << "   " << firstName << " " << lastName << endl;

}

//-------------------------------getPin-----------------------------
int Customer::getPin() const
{
	return pin;
}

//-------------------------------resize-----------------------------
void Customer::resize()
{
	//Add another 100
	Transaction** temp = new Transaction*[histSize + INITIAL_HISTORY_SIZE];
	int tempSize = histSize + INITIAL_HISTORY_SIZE;
	for(int i = 0; i < histSize; i++)
		temp[i] = history[i];

	for(int i = histSize; i < tempSize; i++)
		temp[i] = NULL;

	delete[] history;
	history = NULL;
	history = temp;
	histSize = tempSize;
}

//-------------------------------addItemToHistory------------------------
void Customer::addItemToHistory(Transaction* toAdd)
{
	if(toAdd == NULL) return;
	if(numItems + 1 == histSize)
		resize();
	history[numItems] = toAdd;
	numItems++;
}

//---------------------------------displayHistory------------------------
void Customer::displayHistory(int items) const
{
	cout << "  *** Customer ID = " << pin << "  " 
		<< firstName << " " << lastName << endl;
	if(numItems == 0) 
	{
		cout << endl;
		return;
	}
	if(items == 0)
		for(int i = 0; i <= numItems; i++)
			if(history[i] != NULL)
				history[i]->display();	
	else
		for(int i = 0; i < items; i++)		
			history[i]->display();
	cout << endl;
}

