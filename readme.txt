1. To my knowledge, my program is fully functional. It does not crash with the provided text files, and I believe it will work with any text files that are properly formatted. There are no memory leaks.

2. Hashtables:
	in TransactionFactory:
		int quantity[]           - For hashing 'B' to -1, 'R' to positive 1, used to adjust product quantities
		Transaction* transFact[] - For hashing 'B' to create a Borrow etc
	
	in ProductFactory:
		Product* prodFact[]      - For hashing 'C' to create a Classic etc

	in Container:
		BinTree* arr[]           - For hashing the 'F' of a comedy to the appropriate tree for storage / retrieval

3. Reading movies starts in class Store with: Store::buildInventory(productFile).
	Build Inventory calls: ProductFactory.createIt() until EOF, doing error checking etc
	If createIt returns a valid product, it is inserted into: Store::Container* inventory


		Add retVal of ProductFactory.createIt() to Product Container in store class (Container* inventory).
			ProductFactory::createIt() uses the virtual setData to process a single line of text.

4. Reading Transactions starts in class Store with: Store::buildTransactions(transactionFile)
	Store::buildTransaction(commandFile).
		Add retVal of TransactionFactory.createIt() to Transaction** transactions in store class.
			TransactionFactory::createIt().
				Is passed the store's container, in order to find the real product from the transaction info. 
				Uses the virtual setData to process a single line of text.
				Does error checking for junk customer number, junk movie info, junk first char on line.

5. I feel like passing a container and a customer array into createIt for my transactionFactory is sloppy.

6. Honestly, just that the entire thing is working without memory leaks. Setting multiple pointers to the same object and making sure everything is deleted properly proved more difficult than I anticipated. Additionally, I thought that using a hashtable of ints that specify how to modify the quantity was reasonably clever. 