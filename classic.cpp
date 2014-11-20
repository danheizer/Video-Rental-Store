#include "classic.h"
using namespace std;

//----------------------------------------------------------------
//Default constructor
//init additional members to 0 / null
Classic::Classic() : Movie('C')
{
	month = 0;
	actorFirst = "null";
	actorLast = "null";
	format = "DVD";
};
//---------------------------Destructor-------------------------
Classic::~Classic()
{

};
//----------------------------------------------------------------
//operator<
//For classics we sort by year, then month, then famous actor
bool Classic::operator<(const Product& rhs)  const
{
	const Classic& other = static_cast<const Classic&>(rhs);
	//year comparisons
	if(year < other.year) return true;
	if(year > other.year) return false;
	//Years are equal

	//month comparisons
	if(month < other.month) return true;
	if(month > other.month) return false;

	//Months are equal, compare actorfirst
	int actorFirstDiff = actorFirst.compare(other.actorFirst);
	if(actorFirstDiff < 0) return true;
	if(actorFirstDiff > 0) return false;

	int actorLastDiff = actorLast.compare(other.actorLast);
	if(actorLastDiff < 0) return true;

	//year, month, actor first, and actor last are equal
	return false;

};

//----------------------- Operator> -----------------------------
bool Classic::operator>(const Product& rhs)  const
{
	return !(*this<rhs);
};

//---------------------- Operator== -----------------------------
bool Classic::operator==(const Product& rhs)  const
{
	const Classic& other = static_cast<const Classic&>(rhs);
	return (year == other.year && month == other.month && 
		actorFirst.compare(other.actorFirst) == 0 
		&& actorLast.compare(other.actorLast) == 0);
};

//---------------------- Operator!= -----------------------------
bool Classic::operator!=(const Product& rhs) const
{
	const Classic& other = static_cast<const Classic&>(rhs);
	return !(*this == other);
};

//----------------------------create-----------------------------
Product* Classic::create()
{
	return new Classic;
};

//----------------------------------------------------------------
//Display
//sample out: 
//10   0   The Philadelphia Stor George Cukor     1940  5  Katherine Hepburn
void Classic::display()  const
{
	displayCopies();
	if(title.compare("null") != 0)
	{
		if(title.length() > MAX_TITLE_DISPLAY_WIDTH)
			cout << title.substr(0, MAX_TITLE_DISPLAY_WIDTH) << " ";
		else cout << setw(21) << left << title;
	}
	if(director.length() > MAX_DIRECTOR_DISPLAY_WIDTH)
		cout << director.substr(0, MAX_DIRECTOR_DISPLAY_WIDTH);
	else cout << setw(MAX_DIRECTOR_DISPLAY_WIDTH) << left << director;
	
	cout  << " " << year << " ";
	if(month < 10) cout << month << "   ";
	else cout << month << "  ";
	cout << actorFirst << "  " << actorLast << endl;
};

//-------------------------------------------------------------------
//displayCopies
//display amount in, amount out
void Classic::displayCopies()  const
{
	if(quantity >= 10)
		cout << quantity;
	else cout << " " << quantity;
	cout << "   ";
	if(NUM_COPIES - quantity >= 10)
		cout << NUM_COPIES - quantity << "  ";
	else cout << NUM_COPIES - quantity<< "   ";
};

//-------------------------displayTransactionData----------------------
void Classic::displayTransactionData()  const
{
	if(title.length() > MAX_TITLE_DISPLAY_WIDTH)
		cout << title.substr(0, MAX_TITLE_DISPLAY_WIDTH) << " ";
	else cout << setw(21) << left << title;
	if(director.length() > 15)
		cout << director.substr(0, 15) << " ";
	else cout << setw(MAX_DIRECTOR_DISPLAY_WIDTH) << left << director;
	cout << year << " " << setw(3) << month;
	cout << actorFirst << " " << actorLast << endl;

};


//---------------------------------------------------------------------
//setData
//Assign values to data members from a file
void Classic::setData(ifstream& infile)
{
	totalCopies = NUM_COPIES;
	format = "DVD";
	infile.get();
	getline(infile, director, ',');
	infile.get();
	getline(infile, title, ',');
	infile.get();
	infile >> actorFirst >> actorLast;
	infile >> month >> year;
	infile.get();
};
//---------------------------setCommandData----------------------------
void Classic::setCommandData(ifstream& infile) 
{
	infile >> month >> year;
	infile.get();
	infile >> actorFirst >> actorLast;
}


