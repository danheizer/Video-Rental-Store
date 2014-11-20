#include "nodedata.h"

//------------------- constructors/destructor  -------------------------------
NodeData::NodeData() { data = NULL; }                         // default

NodeData::~NodeData() { }            // needed so strings are deleted properly


NodeData::NodeData(Product* s)
{ 
	data = s;
}    // cast string to NodeData

//------------------------- operator= ----------------------------------------
NodeData& NodeData::operator=(const NodeData& rhs) {
	if(rhs.data != NULL)
	{
		if (this != &rhs) 
		{
			data = rhs.data;
   		}
	}
	else data = NULL;
	return *this;
}

//------------------------- operator==,!= ------------------------------------
bool NodeData::operator==(const NodeData& rhs) const {
   return *data == *rhs.data;
}

bool NodeData::operator!=(const NodeData& rhs) const {

   return *data != *rhs.data;
}

//------------------------ operator<,> ---------------------------------
bool NodeData::operator<(const NodeData& rhs) const {
   return *data < *rhs.data;
}

bool NodeData::operator>(const NodeData& rhs) const {
   return *data > *rhs.data;
}

//------------------------------ getData -------------------
Product* NodeData::getData() const
{
	return data;
}

//-------------------------- operator<< --------------------------------------
ostream& operator<<(ostream& output, const NodeData& nd) {
   nd.data->display();
   return output;
}

