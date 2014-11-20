#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H
// productfactory.h
// productfactory Class
// This class creates movies from text files.
//
// To add additional products to the movie store, all one must do is
// add a call to create at the index hashed to by the product's code. 
// No switches are used (beyond determining that something is a letter). 
// This class takes advantage of the pure virtual functions in product.h
#include "movie.h"
#include "constants.h"
using namespace std;

//Number of types of movies. Genres, formats, etc

class ProductFactory
{
private:
	//C is classic
	//F is comedy
	//D is drama
	int hash(char key) const;
public:
	ProductFactory();
	~ProductFactory();
	Product* createIt(ifstream& infile, int i = 0);
protected:
	Product* prodFact[NUM_TYPES_OF_PRODUCTS];
};
#endif