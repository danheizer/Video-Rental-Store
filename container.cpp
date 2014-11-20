#include "container.h"

//----------------------------Constructor----------------------------
Container::Container()
{
	for(int i = 0; i < NUM_TYPES_OF_PRODUCTS; i++)
		arr[i] = new BinTree;
	arr[hash('C')]->setTitle("CLASSICS");
	arr[hash('D')]->setTitle("DRAMAS");
	arr[hash('F')]->setTitle("COMEDIES");
}

//----------------------------Destructor----------------------------
Container::~Container()
{
	for(int i = 0; i < NUM_TYPES_OF_PRODUCTS; i++)
	{
		delete arr[i];
		arr[i] = NULL;
	}
}

//-------------------------------Insert------------------------------
bool Container::insert(Product* toAdd)
{
	if(hash(toAdd->getCode()) >= NUM_TYPES_OF_PRODUCTS) return false;
	if(hash(toAdd->getCode()) < 0)
	{
		cout << "Item Code Invalid: " << toAdd->getCode() << endl;
		return false;
	}

	arr[hash(toAdd->getCode())]->insert(toAdd);
	return true;

}

//-------------------------------buildContainer------------------------------
void Container::buildContainer(ifstream& infile)
{
	ProductFactory builder;
	while(!infile.eof())
	{
		Product* p = builder.createIt(infile);
		if(p != NULL)
			insert(p);
		
	}
};

//-------------------------------displayAll------------------------------
void Container::displayAll()
{
	for(int i = 0; i < NUM_TYPES_OF_PRODUCTS; i++)
		if(!arr[i]->isEmpty())
				cout << *arr[i];
}

//-------------------------------display------------------------------
void Container::display(char itemCode)
{
	if(!arr[hash(itemCode)]->isEmpty())
		cout << *arr[hash(itemCode)];
}

//-------------------------------hash------------------------------
//A is index 0, Z is 25, a 26, z 51
int Container::hash(char itemCode)
{
	if(itemCode >= 'A'&& itemCode <= 'Z')
		return (itemCode - 'A') % NUM_TYPES_OF_PRODUCTS;
	
	else if(itemCode >= 'a' && itemCode <= 'z')
		return (itemCode - 'a' + 26) % NUM_TYPES_OF_PRODUCTS;

	else return -1;
}

//-------------------------------retrieve------------------------------
bool Container::retrieve(Product* target, NodeData*& ptr)
{

	if(target == NULL) return false;
	NodeData temp(target);
	int index = hash(target->getCode());
	bool retVal = arr[index]->retrieve(temp, ptr);
	return retVal;
};