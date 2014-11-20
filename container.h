//container.h
//A class to store Products in bintrees.
#include "bintree.h"
#include "product.h"
#include "productfactory.h"
 //Array for hashing
class Container
{
public:
	Container();
	~Container();
	bool insert(Product*);
	void buildContainer(ifstream&);
	void displayAll();
	void display(char itemCode);
	bool retrieve(Product* target, NodeData*&);
private:
	int hash(char itemCode);
	BinTree* arr[NUM_TYPES_OF_PRODUCTS];
	ProductFactory factory;
	char* productTitles[NUM_TYPES_OF_PRODUCTS];
};