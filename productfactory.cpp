#include "productfactory.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "movie.h"
#include "comedy.h"
#include "classic.h"
#include "drama.h"
using namespace std;

ProductFactory::ProductFactory()
{
	for(int i = 0; i < NUM_TYPES_OF_PRODUCTS; i++)
		prodFact[i] = NULL;
	prodFact[hash('F')] = new Comedy;
	prodFact[hash('C')] = new Classic;
	prodFact[hash('D')] = new Drama;
	 
};

ProductFactory::~ProductFactory()
{
	for(int i = 0; i < NUM_TYPES_OF_PRODUCTS; i++)
	{
		delete prodFact[i];
		prodFact[i] = NULL;
	}

};

//--------------------------------------------------
//hash
//A is index 0, Z is 25, a 26, z 51
int ProductFactory::hash(char itemCode) const
{
	if(itemCode >= 'A'&& itemCode <= 'Z')
		return (itemCode - 'A') % NUM_TYPES_OF_PRODUCTS;
	
	else if(itemCode >= 'a' && itemCode <= 'z')
		return (itemCode - 'a' + 26) % NUM_TYPES_OF_PRODUCTS;
	

	else return 0;
}

//------------------------------------------------------------------
//createIt
//Creates a product
//i == 0 specifies that a product is being created for storage
//i != 0 specifies that a product is being created for a transaction
Product* ProductFactory::createIt(ifstream& infile, int i)
{
	while(infile.peek() == 10) infile.get();
	char key = infile.get();
	if(prodFact[hash(key)] == NULL || hash(key) == -1) //Bad product code
	{
		while(!infile.eof() && infile.get() != '\n'){}
		return NULL;
	}
	//Make a new object at the index
	Product* toAdd = prodFact[hash(key)]->create();
	if(i == 0)
		toAdd->setData(infile);
		
	else toAdd->setCommandData(infile);
	return toAdd;
	

};