// file bintree.cpp
// Member function definitions for class BinTree

#include "bintree.h"
#include <string>
#include <string.h>



// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class BinTree
BinTree::BinTree()
{
	root = NULL;
}

// ---------------------------------------------------------------------------
// Constructor 
// String constructor for class BinTree
BinTree::BinTree(string s)
{
	title = s;
	root = NULL;
}

// ---------------------------------------------------------------------------
// Destructor 
// Destructor for class binTree. Calls the interface makeEmpty().
BinTree::~BinTree()
{
	makeEmpty();
}

// ---------------------------------------------------------------------------
// MakeEmpty()
// calls a helper that Recursively traverses the tree, deleting all the Nodes
void BinTree::makeEmpty()
{
	delete root;
	root = NULL;
}

// ---------------------------------------------------------------------------
// Copy 
// Copy constructor for class BinTree. Calls the copy constructor for Nodes.
BinTree::BinTree(const BinTree &rhs) 
{
	if(rhs.isEmpty())
		root = NULL;
	else root = copyHelper(rhs.root);
}

// ---------------------------------------------------------------------------
//Copy constructor for node struct
//Recursively copies a node and all nodes attached
BinTree::Node* BinTree::copyHelper(const Node* toCopy)
{
    Node* nodePtr;
    if ( toCopy == NULL )
      return NULL;
    else
    {
      nodePtr = new Node;
      nodePtr->data = new NodeData(*toCopy->data);
      nodePtr->left = copyHelper( toCopy->left );
      nodePtr->right = copyHelper( toCopy->right );
      return nodePtr;
	}

}

// ---------------------------------------------------------------------------
// operator= 
// Overloaded assignment operator
// Recursively traverse the tree

BinTree& BinTree::operator=(const BinTree &rhs)
{
	
	if(&rhs == this)
		return *this;
	makeEmpty();
	root = new Node( rhs.root );
	return *this;
}

//Node operator=, helper for BinTree::operator=
BinTree::Node::Node( const Node *rhs ) : data(NULL), left( NULL ), right( NULL )
{
	if( rhs->data )
		data = new NodeData( *rhs->data );
	if( rhs->left )
		left = new Node( rhs->left );
	if( rhs->right )
		right = new Node( rhs->right );
	
}

// --------------------------------------------------------------------------
// operator== 
// Determine if two BinTrees are equal.
bool BinTree::operator==(const BinTree &rhs) const
{
	if(&rhs == this)
		return true;

	return (*root == *rhs.root);
}

// --------------------------------------------------------------------------
// == operator for Nodes
// Is a helper for BinTree:: ==
bool BinTree::Node::operator==( const Node& rhs) const
{
	if( (rhs.left && left == NULL) || (rhs.left == NULL && left) )
		return false;
	if( (rhs.right && right == NULL ) || (right && rhs.right == NULL) )
		return false;
	if( (data && rhs.data == NULL) || (data == NULL && rhs.data) )
		return false;

	if( data != NULL && *data != *rhs.data )
		return false;

	if( right != NULL && *right != *rhs.right )
		return false;

	if( left != NULL && *left != *rhs.left )
		return false;

	return true;
}

// --------------------------------------------------------------------------
// operator!= 
// Determine if two BinTrees are not equal.
bool BinTree::operator!=(const BinTree &rhs) const
{
	return !(*this == rhs);
}
bool BinTree::Node::operator!=(const Node& rhs) const
{
	return !(*this == rhs);
}

// ---------------------------------------------------------------------------
// insert(product*)
bool BinTree::insert(Product* toAdd)
{
	NodeData* toPass = new NodeData(toAdd);
	return insert(toPass);
};
// ---------------------------------------------------------------------------
// insert(NodeData*)
// Creates a Node* and calls insert(Node*), which navigates the bst.
bool BinTree::insert(NodeData* toAdd)
{
	if(isEmpty())
	{
	
		Node* n = new Node;
		n->data = toAdd;
		root = n;
		return true;
	}
	else
	{
		return insert(toAdd, root);
	}
}

// ---------------------------------------------------------------------------
// insert(Node*, Node*)
// Recursive method to navigate the BinTree until toAdd's place is found.
bool BinTree::insert(NodeData* toAdd, Node* current)
{
	if(*toAdd < *current->data) //Working with left side
	{
		if(current->left == NULL)
		{
			Node* n = new Node(toAdd);
			current->left = n;
			return true;
		}
		else return insert(toAdd, current->left);
	}
	else if(*toAdd > *current->data) 	//Right side
	{
		if(current->right == NULL)
		{
			Node* n = new Node(toAdd);
			current->right = n;
			return true;
		}
		else return insert(toAdd, current->right);
	} 
	//toAdd->data was equal to current->data, duplicate not inserted
	return false;
}



// --------------------------------------------------------------------------
// retrieve
// Finds an object with a pass by reference parameter. targetPtr is 
// initially garbage, but will point to actual object in tree if found.
// Returns if the object was found or not.
bool BinTree::retrieve(const NodeData& target, NodeData*& targetPtr) const
{
	if(isEmpty()) return false;

	targetPtr = root->find(target);
	return targetPtr != NULL;
}

// --------------------------------------------------------------------------
// Helper for retrieve, navigates on a node level
NodeData* BinTree::Node::find( const NodeData& target )
{
	NodeData *found = NULL;
	if(*data == target)
		return data;
	

	if( left )
		found = left->find( target );
	if( found == NULL && right )
		found = right->find( target );

	return found;
}

// --------------------------------------------------------------------------
// getDepth
// Finds the depth of a node without using the fact that it's a BST.
// Depth of Node at root is 1. 
// Returns the depth of the node found, or 0 if the target was not found.
int BinTree::getDepth(const NodeData &target) const
{
	if(isEmpty())
		return 0;
	if(target == *root->data)
		return 1;
	Node* current = root;
	int* targetDepth = new int;
	*targetDepth = 0;
	targetDepth = depthHelper(current, 1, targetDepth, target);
	int depth = *targetDepth;
	delete targetDepth;
	return depth;
}

// --------------------------------------------------------------------------
// depthHelper
// Keeps track of how many levels by recursively traversing the tree
int* BinTree::depthHelper(Node* current,  int level, 
	int* targetDepth, const NodeData &target) const
{
	if(*current->data == target)
		*targetDepth = level;

	if(current->left != NULL)
	{
		level++;
		depthHelper(current->left, level, targetDepth, target);
		level--;
	}
	if(current->right != NULL)
	{
		level++;
		depthHelper(current->right, level, targetDepth, target);
		level--;
	}
	return targetDepth;
}

// --------------------------------------------------------------------------
// bstreeToArray
// Fill an array of NodeData* by using inorder traversal of the tree. 
// Assume a statically allocated array of 100 NULL elements.
void BinTree::bstreeToArray(NodeData* toFill[]) const
{
	if(isEmpty())
		return;
	Node* current = root;
	for(int i = 0; i < ARRAY_SIZE; i++)
		toFill[i] = NULL;
	inOrderWalkToArray(current, toFill, 0);
}

//---------------------------------------------------------------------------
// inOrderWalk
// Helper for: bstreeToArray
// Traverses the tree inorder, and stores each Node in the parameter array.
void BinTree::inOrderWalkToArray(Node* current, NodeData* toFill[], int i) const
{
	if(current->left != NULL)
		inOrderWalkToArray(current->left, toFill, i);

	while(toFill[i] != NULL)
		i++;	
	toFill[i] = current->data;

	if(current->right != NULL)
		inOrderWalkToArray(current->right, toFill, i);

}

// --------------------------------------------------------------------------
// arrayToBSTree
// build a balanced BinTree from a sorted(Assumed) array of NodeData*
// Root in the tree is a node built from sortedData[low+high/2]
// NodeDatas are copied into a new array to prevent them from being deleted
// in preparation to balance.
void BinTree::arrayToBSTree(NodeData* sortedData[])
{
	NodeData* tempArr[ARRAY_SIZE];
	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		if(sortedData[i] != NULL)
			tempArr[i] = new NodeData(*sortedData[i]);
		else tempArr[i] = NULL;
	}
	makeEmpty();
	//Find the highest and lowest indices
	int highIndex = -1; 
	int lowIndex = ARRAY_SIZE;
	for(int i = 0; i < ARRAY_SIZE; i++)
		if(tempArr[i] != NULL)
		{
			if(i > highIndex)
				highIndex = i;
			if(i < lowIndex)
				lowIndex = i;
		}
	//If the array was all NULL elements
	if(highIndex == -1 && lowIndex == ARRAY_SIZE)
	{
		root = NULL;
		return;
	}
	arrToTreeHelper(tempArr, lowIndex, highIndex);
}

// --------------------------------------------------------------------------
// arrToTreeHelper
// Recursively inserts nodes at low + high / 2
void BinTree::arrToTreeHelper(NodeData* sortedData[], int start, int end)
{
	if(start > end)
		return;
	int mid = (start + end) / 2;
	if(sortedData[mid] != NULL)
	{
		//If it's already inserted, delete and null the index
		if(!insert(sortedData[mid]))
		{
			delete sortedData[mid];
			sortedData[mid] = NULL;
		}
		arrToTreeHelper(sortedData, start, mid-1);
		arrToTreeHelper(sortedData, mid + 1, end);
	}
}

//---------------------------------------------------------------------------
// displaySideways 
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
void BinTree::sideways(Node* current, int level) const {
   if (current != NULL) {
      level++;
      sideways(current->right, level);

      // indent for readability, 4 spaces per depth level 
      for(int i = level; i >= 0; i--) {
          cout << "    ";
      }

      cout << *current->data << endl;        // display information of object
      sideways(current->left, level);
   }
}

//---------------------------------------------------------------------------
// displaySideways 
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
void BinTree::displaySideways() const {
   sideways(root, 0);
}

//---------------------------------------------------------------------------
// operator<<
// Outputs the stream through an inorder walk
ostream& operator<<(ostream& out, const BinTree& rhs)
{
	if(rhs.isEmpty())
	{
		out << "null" << endl;
		return out;
	}
	else
	{
		cout << "*IN* *OUT*         " << rhs.title << endl;
		cout << "DVD  DVD TITLE                DIRECTOR         YEAR MO  ACTOR" << endl;
		BinTree::Node* current = rhs.root;
		rhs.inOrderWalkOutput(current, out);
		out << endl;
		return out;
	}
}

//---------------------------------------------------------------------------
// inOrderWalk
// Helper for: operator << 
// Traverses the tree, and outputs each node to an ostream
ostream& BinTree::inOrderWalkOutput(Node* current, ostream& out) const
{

	if(current)
	{
		inOrderWalkOutput(current->left, out);
		out << *current->data;
		inOrderWalkOutput(current->right, out);
	}
	return out;

}
//---------------------------------------------------------------------------
// setTitle
void BinTree::setTitle(string s)
{
	title = s;
}
