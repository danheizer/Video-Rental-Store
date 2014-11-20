#include "comedy.h"
#include "store.h"
#include <fstream>
#include "productfactory.h"
#include "customerfactory.h"
#include "transactionfactory.h"

int main()
{
	// store.displayCustomers()
	// store.displayTransactions() (Shows rental / return history)
	// store.displayInventory() (A manual 'S' command)
	// Create ifstreams
	ifstream movieFile("data4movies.txt");
	ifstream commandFile("data4commands.txt");
	ifstream customerFile("data4customers.txt");

	// Create store
	Store ManyOverzealousVideosIgniteAndEntertain;

	//Calls the various build functions, then processes commands
	ManyOverzealousVideosIgniteAndEntertain.run();


	movieFile.close();
	commandFile.close();
	customerFile.close();
	return 1;
}