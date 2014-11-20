#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>
#include "product.h"
#include <iostream>
#include <fstream>
using namespace std;

// simple class containing one string to use for testing
// not necessary to comment further

class NodeData {
   friend ostream & operator<<(ostream &, const NodeData &);

public:
   NodeData();          // default constructor, data is set to an empty string
   ~NodeData();          
   NodeData(Product*);      // data is set equal to parameter
   NodeData& operator=(const NodeData&);

   // set class data from data file
   Product* getData() const;

   bool operator==(const NodeData &) const;
   bool operator!=(const NodeData &) const;
   bool operator<(const NodeData &) const;
   bool operator>(const NodeData &) const;
   bool operator<=(const NodeData &) const;
   bool operator>=(const NodeData &) const;

private:
   Product* data;          
};

#endif

