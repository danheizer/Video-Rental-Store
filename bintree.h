// file BinTree.h
// Simple binary tree class
#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include "nodedata.h"
#include "product.h"
#include "constants.h"
using namespace std;
//---------------------------------------------------------------------------
// BinTree class:  A binary tree class that stores Node structs
//   -- Allows for comparison of 2 BinTrees
//   -- Allows for insertion of NodeDatas into a tree
//   -- Provides methods to get depth of a Node in the tree
//   -- Provides methods to retrieve a NodeData from the tree
//   -- Provides methods to build a tree from an array and vice versa

// Implementation and assumptions:
//   -- Most methods are implemented through recursive helper methods
//   -- Tree will not exceed 100 elements
//	 -- Lines in the input file must be terminated with "$$".
//   -- A duplicate token will not be inserted into the tree.
//---------------------------------------------------------------------------

class BinTree
{
	friend ostream& operator<<(ostream& out, const BinTree& rhs);

public:
//------------------------Constructors---------------------------------------
	BinTree(); //Creates an empty tree
	BinTree(string s); //Sets title to s
	~BinTree(); //Calls interface makeEmpty()
	BinTree(const BinTree &rhs); //Copy constructor


//---------------------------=, ==, != operators-----------------------------
	BinTree& operator=(const BinTree &rhs);
	bool operator==(const BinTree &rhs) const;
	bool operator!=(const BinTree &rhs) const;

//-------------------------Additional Operations-----------------------------
	void makeEmpty();
	bool insert(NodeData* toAdd); //Insert a node into the tree
	bool insert(Product* toAdd);
	//set pointer to target if found
	bool retrieve(const NodeData&, NodeData*&) const;
	int getDepth(const NodeData &) const; //Return level of NodeData param
	void bstreeToArray(NodeData* []) const; //Build array from tree
	void arrayToBSTree(NodeData* []); //Build tree from sorted array
	void displaySideways() const;
	bool isEmpty() const { return root==NULL; };
	void setTitle(string s);

private:
//---------------------------------------------------------------------------
// Node struct:  A simple Node class that provides some additional 
// functionalities. 
//   -- Contains various methods that act has helper methods for the 
//		BinTree class
//---------------------------------------------------------------------------
	struct Node 
	{
		NodeData* data;
		Node* left;
		Node* right;
		Node()
		{
			data = NULL;
			left = NULL;
			right = NULL;
		}
		Node(NodeData* rhs)
		{
			data = rhs;
			left = NULL;
			right = NULL;
		}
		~Node()
		{
			delete data->getData();
			delete data;
			delete left;
			delete right;
			data = NULL;
			left = NULL;
			right = NULL;
			
		}
		Node( const Node *rhs ); //= operator helper
		NodeData *find( const NodeData& target); //retrieve helper
		bool operator==( const Node& rhs) const; //== helper
		bool operator!=( const Node& rhs) const;
	};
	Node* root;
	string title;

//-------------------------Helper Methods-----------------------------
	void sideways(Node* current, int level) const;
	bool insert(NodeData* toAdd, Node* current); //insert helper
	ostream& inOrderWalkOutput(Node* current, ostream& out) const;
	void inOrderWalkToArray(Node* current, NodeData* [], int i) const;
	bool inOrderWalkEquality(Node* rhsCurrent, Node* current) const;
	Node* copyHelper(const Node* toCopy);
	int* depthHelper(Node* current, int level, 
		int* targetDepth, const NodeData &target) const; 
	NodeData* retrieveHelper(Node* current, 
		const NodeData& target, NodeData* targetPtr) const;
	void arrToTreeHelper(NodeData* sortedData[], int low, int high);
};
#endif