#include "movie.h"
Movie::Movie( char code ) : Product( code )
{
	year = 0;
	title = "null";
	director = "null";
	quantity = NUM_COPIES;
	//code = '0';
};
Movie::~Movie()
{


};