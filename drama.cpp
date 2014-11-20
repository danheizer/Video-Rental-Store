#include "drama.h"
using namespace std;

Drama::~Drama()
{
};

//----------------------------------------------------------------
//operator<
//For Dramas we sort by DIRECTOR, then TITLE
bool Drama::operator<(const Product& rhs) const
{
	const Drama& other = static_cast<const Drama&>(rhs);
	//Get both director comparisons out of the way
	int directorDiff = director.compare(other.director);
	if(directorDiff < 0) return true;
	if(directorDiff > 0) return false;
	//Check for title comparison
	int titleDiff = title.compare(other.title);
	if(titleDiff < 0) return true;
	return false;

};

//---------------------- Operator> -----------------------------
bool Drama::operator>(const Product& rhs) const
{
	return !(*this<rhs);
};

//---------------------- Operator== ----------------------------
bool Drama::operator==(const Product& rhs) const
{
	const Drama& other = static_cast<const Drama&>(rhs);
	bool sameDir = (director.compare(other.director) == 0);
	bool sameTitle = (title.compare(other.title) == 0);
	return (sameDir && sameTitle);
};

//---------------------- Operator!= -----------------------------
bool Drama::operator!=(const Product& rhs) const
{
	const Drama& other = static_cast<const Drama&>(rhs);
	return !(*this == other);
};

Product* Drama::create()
{
	return new Drama;
};

//----------------------------------------------------------------
//Display
//sample out: 
//10   0   The Philadelphia Stor George Cukor     1940
void Drama::display() const
{
	displayCopies();
	if(title.compare("null") != 0)
	{
		if(title.length() > 20)
			cout << title.substr(0, 20) << " ";
		else cout << setw(21) << left << title;
	}
	if(director.compare("null") != 0)
	{
		if(director.length() > 16)
			cout << director.substr(0, 16);
		else cout << setw(16) << left << director;
	}
	cout  << " " << year << endl;
};

//----------------------------------------------------------------
//DisplayCopies
//Display amount in, amount out
void Drama::displayCopies() const
{
	if(quantity >= 10)
		cout << quantity;
	else cout << " " << quantity;
	cout << "   ";
	if(NUM_COPIES - quantity >= 10)
		cout << NUM_COPIES - quantity << "  ";
	else cout << NUM_COPIES - quantity<< "   ";
};

//----------------------------------------------------------------
//displayTransactionData
void Drama::displayTransactionData() const
{
	if(title.length() > 20)
		cout << title.substr(0, 20) << " ";
	else cout << setw(21) << left << title;
	if(director.length() > 15)
		cout << director.substr(0, 15) << " ";
	else cout << setw(16) << left << director;
	cout << year << endl;

};

//---------------------------------------------------------------------
//setData
//Assign values to data members from a file
void Drama::setData(ifstream& infile)
{
	totalCopies = NUM_COPIES;
	format = "DVD";
	infile.get();
	getline(infile, director, ',');
	infile.get();
	getline(infile, title, ',');
	infile.get();
	infile >> year;
	infile.get();
};

//---------------------------------------------------------------------
//setData
//Assign values to data members for a transaction
void Drama::setCommandData(ifstream& infile)
{
	infile.get();
	getline(infile, director, ',');
	infile.get();
	getline(infile, title, ',');
	infile.get();
};


