#include "movie.h"
class Classic : public Movie
{
/*
This class extends the Movie class, which extends the Product class.
Code: C
Sorting criteria:  year, month, famous actor
*/

public:
	//initialize additional members to null
	Classic();
	virtual ~Classic();
	//Sort by year, month, actor first, actor last
	virtual bool operator<(const Product& rhs) const;
	virtual bool operator>(const Product& rhs) const;
	virtual bool operator==(const Product& rhs) const;
	virtual bool operator!=(const Product& rhs) const;
	virtual Product* create();
	//virtual Movie& operator=(const Movie& rhs);
	virtual void display() const;
	virtual void displayCopies() const;
	virtual void displayTransactionData() const;
	virtual void setData(ifstream& infile);
	virtual void setCommandData(ifstream&);

protected:
	//Data members that only exist for Classics
	string actorFirst;
	string actorLast;
	int month;
};