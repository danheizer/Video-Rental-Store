

#ifndef FACTORY_H
#define FACTORY_H
#include "product.h"
#include "customer.h"
#include "transaction.h"
const int maxMovies = 100;
const int maxCustomers = 100;
const int maxTransactions = 1000;
const int NUM_TYPES_OF_PRODUCTS = 8;
class Factory
{
private:
	Product* productFact[NUM_TYPES_OF_PRODUCTS];
	Customer* customerFact;



	//Genres
	//C is classic
	//D is drama
	//F is comedy


	//Customers
	//#### is customer



/*
	// ----- CLASS Factory -------------------------------------------------------
class Factory {
private:
    Stuff* objFactory[5];              // in general, do not hard code numbers
    int hash(char ch) const { return ch-'A'; }

public:
    Factory() {
       objFactory[0] = new AObject();
       objFactory[1] = new BObject();
       objFactory[2] = new CObject();
       objFactory[3] = new DObject();
       objFactory[4] = new EObject();
    }

    ~Factory() {
       for (int i = 0; i < 5; i++) {
          delete objFactory[i];
          objFactory[i] = NULL;
       }
    }

    Stuff* createIt(char ch) const {
       int subscript = hash(ch);             // would do error checking
       return objFactory[subscript]->create();
    }
};
*/

};

#endif