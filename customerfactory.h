#ifndef CUSTOMERFACTORY_H
#define CUSTOMERFACTORY_H
// customerfactory.h
// CustomerFactory Class
// This class creates customers from text files.

#include "customer.h"
using namespace std;

class CustomerFactory
{
public:
	CustomerFactory();
	~CustomerFactory();
	Customer* createIt(ifstream& infile);
private:
	Customer* custFact;
};
#endif