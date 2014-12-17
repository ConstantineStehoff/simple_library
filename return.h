#ifndef __lab4__return__
#define __lab4__return__

#include <iostream>
#include "transaction.h"
#include "factory.h"

using namespace std;
class Factory;
class Client;

//---------------------------------------------------------------------------
// Return class represents the return transaction when a patron returns
// the item back to the library it checks if the client that returns it
// actually holds an item in order to return.
//
//
// Assumptions: - Patron can't return a book that he or she doesn't own
//              - Users are not going to use the copy constructor
//              - If the transaction is not valid it is not going to be
//                executed
//---------------------------------------------------------------------------

class Return : public Transaction{
public:
    Return(); // constructor
    virtual ~Return(); // destructor
    // sets the data for the transaction and validates
    virtual bool setData(ifstream&, BinTree[], Client[], Factory*&);
    virtual void display() const; // displays transaction
    virtual void execute(Transaction*&); // executes transaction
    virtual Transaction* create(); // creates an object
};

#endif /* defined(__lab4__return__) */


