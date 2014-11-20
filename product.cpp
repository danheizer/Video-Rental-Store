//product.cpp
#include "product.h"
#include <iostream>
#include <iomanip>
using namespace std;

//-----------------------Constructor-------------------------
Product::Product( char c )
{
	code = c;
	quantity = 0;
	format = "bad";
};

//-----------------------Destructor-------------------------
Product::~Product()
{

};

//-----------------------getTotalCopies-----------------------
int Product::getTotalCopies() const
{
	return totalCopies;
};

//-----------------------getQuantity-------------------------
int Product::getQuantity() const
{
	return quantity;
};

//------------------------setQuantity-------------------------
void Product::setQuantity(int quant)
{
	quantity = quant;
};

//-------------------------getFormat-------------------------
string Product::getFormat() const
{
	return format;
};

//-------------------------getTitle-------------------------
string Product::getTitle() const
{
	return title;
};

//-------------------------getCode---------------------------
char Product::getCode() const
{
	return code;
};