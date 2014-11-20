#include "movie.h"
using namespace std;
/*
This class extends the Movie class, which extends the Product class.
Code: F
Sorting criteria: title, year
*/
class Comedy : public Movie
{
public:
	Comedy() : Movie('F') {};
	virtual ~Comedy();
	virtual bool operator<(const Product& rhs) const;
	virtual bool operator>(const Product& rhs) const;
	virtual bool operator==(const Product& rhs) const;
	virtual bool operator!=(const Product& rhs) const;
	virtual Product* create();
	virtual void display() const;
	virtual void displayCopies() const;
	virtual void displayTransactionData() const;
	virtual void setData(ifstream& infile);
	virtual void setCommandData(ifstream&);

};