#ifndef PERIODICAL_H
#define PERIODICAL_H

#include"media.h"
using namespace std;

//---------------------------------------------------------------------------
// Periodical class represent periodical data objects in the library it holds
// the information about the month of the object in addition to the data in
// NodeData and Media.
//
// Assumptions: - Patrons would not use operator<=
//              - Patrons would not use operator>=
//              - Users would not use the copy constructor
//              - Error will be thrown if there is no children book in
//                the library
//---------------------------------------------------------------------------

class Periodical : public Media {
    
public:
    Periodical(); // constructor
    ~Periodical(); // destructor
    virtual void setData(ifstream&); // sets data for periodical
    virtual void setData2(ifstream&); // sets data in transaction
    virtual bool operator==(const NodeData&) const; // checks if equal
    virtual bool operator<(const NodeData&) const; // checks if less
    virtual void display() const; // displays the object
    virtual void partialDisplay() const; // displays in history
    virtual void displayHead() const; // displays the header for all obj
    virtual Media* create(); // creates periodical obj
    virtual void addAvailable(); // adds item to the library
    virtual bool decreseAvailable(); // removes item from library
protected:
    int month; // month of periodical
};

#endif

