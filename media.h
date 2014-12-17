#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include "nodedata.h"
#include "transaction.h"
using namespace std;

class Transaction;

//---------------------------------------------------------------------------
// Media class is the pure virtual class that represents all media objects
// in the library that are currently books but can be anything else really.
//
// Assumptions: - Media objects are the going to be stored in trees
//              - Patrons would not use operator<=
//              - Patrons would not use operator>=
//              - Any classes can overwrite virtual function
//              - Users are not going to use the copy constructor
//              - Users would not use the copy constructor
//---------------------------------------------------------------------------

class Media : public NodeData {
    
public:
    Media(); // constructor
    virtual ~Media(); // destructor
    virtual void setData(ifstream&) = 0; // sets the data for media
    virtual void setData2(ifstream&) = 0; // sets data for history
    virtual void display() const = 0; // displays media object
    virtual void partialDisplay() const = 0; // displays in transaction
    virtual void displayHead() const = 0; // displays header for all media
    virtual bool operator==(const NodeData&) const = 0; // checks if equals
    virtual bool operator<(const NodeData&) const = 0; // checks if less
    virtual void addAvailable() = 0; // adds media object to the library
    virtual bool decreseAvailable() = 0; // remove media object
    virtual NodeData* create() = 0; // creates media object
    
protected:
    char bookCode; // type of book or media in transaction
    int year, amount; // year of a book and amount of books
    string type; // name of the media object
};

#endif

