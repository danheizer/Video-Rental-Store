#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"
using namespace std;
/*
The Movie class is a child of the product class, but adds year and director
data members.
*/
class Movie : public Product 
{
protected:
	int year;
	string director;

public:
	Movie( char code );
	~Movie();

};

#endif
