#include "comedy.h"
using namespace std;

//---------------------------Destructor-------------------------
Comedy::~Comedy()
{

};
//----------------------------------------------------------------
//operator<
//For Comedys we sort by TITLE, then DATE
bool Comedy::operator<(const Product& rhs) const
{
	const Comedy& other = static_cast<const Comedy&>(rhs);
	//title comparison
	int titleDiff = title.compare(other.title);
	if(titleDiff < 0) return true;
	if(titleDiff > 0) return false;
	//year comparison
	if(year < other.year) return true;

	return false;

};

//---------------------- Operator> -----------------------------
bool Comedy::operator>(const Product& rhs) const
{
	return !(*this<rhs);
};

//---------------------- Operator== ----------------------------
bool Comedy::operator==(const Product& rhs) const
{
	const Comedy& other = static_cast<const Comedy&>(rhs);
	return (year == other.year && title.compare(other.title) == 0);
};

//---------------------- Operator!= -----------------------------
bool Comedy:: operator!=(const Product& rhs) const
{
	const Comedy& other = static_cast<const Comedy&>(rhs);
	return !(*this == rhs);
};

//--------------------------create-------------------------------
Product* Comedy::create()
{
	return new Comedy;
};
//----------------------------------------------------------------
//Display
//sample out: 
//10   0   The Philadelphia Stor George Cukor     1940
void Comedy::display() const
{
	displayCopies();
	if(title.compare("null") != 0)
	{
		if(title.length() > MAX_TITLE_DISPLAY_WIDTH)
			cout << title.substr(0, MAX_TITLE_DISPLAY_WIDTH) << " ";
		else cout << setw(MAX_TITLE_DISPLAY_WIDTH + 1) << left << title;
	}
	if(director.length() > MAX_DIRECTOR_DISPLAY_WIDTH)
		cout << director.substr(0, MAX_DIRECTOR_DISPLAY_WIDTH);
	else cout << setw(MAX_DIRECTOR_DISPLAY_WIDTH) << left << director;
	cout  << " " << year << endl;
};


//----------------------------------------------------------------
//DisplayCopies
//Display amount in, out
void Comedy::displayCopies() const
{
	if(quantity >= 10)
		cout << quantity;
	else cout << " " << quantity;
	cout << "   ";
	if(NUM_COPIES - quantity >= 10)
		cout << NUM_COPIES - quantity << "  ";
	else cout << NUM_COPIES - quantity<< "   ";
}

//-------------------------displayTransactionData----------------------
void Comedy::displayTransactionData()  const
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
void Comedy::setData(ifstream& infile)
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

//---------------------------------------------------------------
void Comedy::setCommandData(ifstream& infile)
{
	infile.get();
	getline(infile, title, ',');
	infile.get();
	infile >> year;
	infile.get();
};



