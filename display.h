#ifndef __lab4__display__
#define __lab4__display__

#include <iostream>
#include "transaction.h"

using namespace std;
class Factory;
class Client;

//---------------------------------------------------------------------------
// Display class represent the transaction that shows all of the items
// that are currently in the library and displays the amount of items per
// each type of media.
//
//
// Assumptions: - Users would not use the copy constructor
//              - If the transaction is not valid it is not going to be
//                executed
//              - The initial amount of books in the library that will be
//                displayed if no transactions happened will be 5 for
//                fiction and children book and 1 for periodicals
//---------------------------------------------------------------------------

class Display : public Transaction{
public:
    Display(); // constructor
    virtual ~Display(); // destructor
    // sets the data for transaction
    virtual bool setData(ifstream&, BinTree[], Client[], Factory*&);
    virtual void display() const; // displays transaction
    virtual void execute(Transaction*&); // executes transaction
    virtual Transaction* create(); // creates an object
protected:
    BinTree* hashmapPtr; // pointer to the media hashmap
    static const int MAX_COMMANDS = 26; // all alphabet
};

#endif /* defined(__lab4__display__) */
