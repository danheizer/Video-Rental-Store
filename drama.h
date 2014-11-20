#include "movie.h"
class Drama : public Movie
{
/*
This class extends the Movie class, which extends the Product class.
Code: D
Sorting criteria: director, title
*/
public:
	Drama() : Movie( 'D' ){};
	virtual ~Drama();
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