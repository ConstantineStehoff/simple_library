#ifndef __lab4__nodedata__
#define __lab4__nodedata__

#include <fstream>
#include <list>
using namespace std;

//---------------------------------------------------------------------------
// NodeData is the class that represents the objects that are use by the
// binary tree that goes into the hashmap of media objects. It serves as
// a wrapper around all of the data object that are in the library.
//
//
// Assumptions: - The NodeData objects are going to be stored in the tree
//              - Any classes can overwrite virtual function
//              - Users are not going to use the copy constructor
//              - Patrons would not use operator<=
//              - Patrons would not use operator>=
//---------------------------------------------------------------------------

class NodeData {
    
public:
    NodeData();              // constructor
    virtual ~NodeData() = 0; // destructor
    virtual void setData(ifstream&) = 0; // sets data
    virtual void setData2(ifstream&) = 0; // sets data in transaction
    virtual void display() const = 0; // displays the object
    virtual void partialDisplay() const = 0; // displays in history
    virtual void displayHead() const = 0; // displays the header
    virtual bool operator==(const NodeData&) const = 0; // if equals
    virtual bool operator<(const NodeData&) const = 0; // if less
    virtual NodeData* create() = 0; // creates the objects
    virtual void addAvailable() = 0; // adds data object
    virtual bool decreseAvailable() = 0; // removes data object
    void addOwner(const int); // adds owner to the library item
    void removeOwner(const int); // removes owner from library item
    bool checkOwner(const int); // finds out if it's the owner of an item
    string getTitle() const; // returns the title of the object
protected:
    string title; // title of the library item
    list<int> bookOwnership; // IDs of patrons who hold an item
};

#endif /* defined(__lab4__nodedata__) */

