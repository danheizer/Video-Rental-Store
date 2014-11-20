//store.cpp
//Implementation of the store class
#include "store.h"

//--------------------------Constructor------------------------------
Store::Store()
{
	customers = new Customer*[MAX_CUSTOMER_ID];
	for(int i = 0; i < MAX_CUSTOMER_ID; i++)
		customers[i] = NULL;
	inventory = new Container;
	transactions = new Transaction*[START_TRANSACTIONS_QUANTITY];
	for(int i = 0; i < START_TRANSACTIONS_QUANTITY; i++)
	{
		transactions[i] = NULL;
	}
	transactionSize = START_TRANSACTIONS_QUANTITY;
	numTransactions = 0;

};

//--------------------------Destructor------------------------------
Store::~Store()
{
	for(int i = 0; i < MAX_CUSTOMER_ID; i++)
	{
		delete customers[i];
		customers[i] = NULL;
	}

	delete[] customers;
	delete inventory;
	for(int i = 0; i < numTransactions; i++)
	{
		delete transactions[i];
		transactions[i] = NULL;
	}

	delete[] transactions;
	customers = NULL;
	inventory = NULL;
	transactions = NULL;	
}
void Store::buildTransactions(ifstream& infile)
{
	TransactionFactory temp;
	while(!infile.eof())
		processTransaction(temp.createIt(infile, inventory, customers));
};

//--------------------------------------------------------------------
//run
void Store::run()
{
	ifstream customerFile("data4customers.txt");
	ifstream commandFile("data4commands.txt");
	ifstream productFile("data4movies.txt");
	buildCustomers(customerFile);
	buildInventory(productFile);
	buildTransactions(commandFile);
};

//-------------------------------------------------------
//processTransaction
//validate information within a transaction
bool Store::processTransaction(Transaction* data)
{

	if(data == NULL) return false;
	
	if(!data->requiresProduct())
	{
		data->display();
		delete data;
		data = NULL;
		return true;
	}
	//Add item to history
	customers[data->clientID]->addItemToHistory(data);
	insertTransaction(data);

	return true;
};

//------------------------------insertTransaction------------------------
//Add a transaction to the store's history
void Store::insertTransaction(Transaction* toAdd)
{
	if(numTransactions + 1 == transactionSize)
		resize();
	transactions[numTransactions] = toAdd;
	numTransactions += 1;
}
//------------------------------ buildCustomers ------------------------
//Create customers from a textfile
void Store::buildCustomers(ifstream& infile)
{
	CustomerFactory temp;
	while(!infile.eof())
	{
		Customer* in = temp.createIt(infile);
		if(in == NULL) return;
		customers[in->getPin()] = in;
	}
};

//------------------------------ DisplayCustomers ------------------------
void Store::displayCustomers() const
{
	cout << "PIN    NAME" << endl;
	for(int i = 0; i < MAX_CUSTOMER_ID; i++)
		if(customers[i] != NULL)
		{
			customers[i]->display();
		}
		cout << endl;
}

//------------------------------ buildInventory ------------------------
//Build an inventory of products from a text file
void Store::buildInventory(ifstream& infile)
{
	ProductFactory builder;
	while(!infile.eof())
	{
		Product* p = builder.createIt(infile);
		if(p != NULL)
			inventory->insert(p);
	}
}

//------------------------------ displayInventory ------------------------
void Store::displayInventory() const
{
	inventory->displayAll();
}

//---------------------------------- resize ------------------------------
void Store::resize()
{
	//Add another 100
	Transaction** temp = new Transaction*[transactionSize + START_TRANSACTIONS_QUANTITY];
	int tempSize = transactionSize + INITIAL_HISTORY_SIZE;
	for(int i = 0; i < transactionSize; i++)
		temp[i] = transactions[i];

	for(int i = transactionSize; i < tempSize; i++)
		temp[i] = NULL;

	delete[] transactions;
	transactions = NULL;
	transactions = temp;
	transactionSize = tempSize;
}

//----------------------------- displayTransactions -----------------------
void Store::displayStoreTransactionHistory()
{
	for(int i = 0; i < numTransactions; i++)
		transactions[i]->display();
}
