#ifndef CHILDRENBOOK_H
#define CHILDRENBOOK_H

#include"media.h"
using namespace std;

//---------------------------------------------------------------------------
// ChildrenBook class represents type of media which is youth books. It has
// a parent classes of Media and NodeData and holds the information about
// an author.
//
//
// Assumptions: - Users would not use the copy constructor
//              - operator<= is not going to be used
//              - operator>= is not going to be used
//              - Error will be thrown if there is no children book in
//                the library
//---------------------------------------------------------------------------

class ChildrenBook : public Media {
    
public:
    ChildrenBook();	// constructor
    virtual ~ChildrenBook(); // destructor
    virtual void setData(ifstream&); // sets the data for the book
    virtual void setData2(ifstream&); // sets the data in transaction
    virtual bool operator==(const NodeData&) const; // checks if equal
    virtual bool operator<(const NodeData&) const; // checks if smaller
    virtual void display() const; // displays the book
    virtual void partialDisplay() const; // display for history
    virtual void displayHead() const; // displays the header for all books
    virtual Media* create(); // creates the object
    virtual void addAvailable(); // adds the book to the library
    virtual bool decreseAvailable(); // removes the book to the library
protected:
    string author; // self-explanatory
};

#endif
