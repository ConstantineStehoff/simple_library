#ifndef CHECKOUT_H
#define CHECKOUT_H

#include"transaction.h"
#include "factory.h"
#include <string>
#include <iostream>
using namespace std;
class Factory;
class Client;

//---------------------------------------------------------------------------
// Checkout class is responsible for the check out of the book transaction
// that is when a patron gets the book from the library. It removes a book
// from the library.
//
//
// Assumptions: - Users would not use the copy constructor
//              - Patrons can't check out the book that is not in
//                the library
//              - Patrons can's check out the book that is not in the
//                book data input file
//              - If the transaction is not valid it is not going to be
//                executed
//---------------------------------------------------------------------------

class Checkout : public Transaction {
    
public:
    Checkout(); // constructor
    virtual ~Checkout(); // destructor
    // sets the data of the transaction
    virtual bool setData(ifstream&, BinTree[], Client[], Factory*&);
    virtual void display() const; // displays the name of transaction
    virtual Transaction* create(); // creates the object
    virtual void execute(Transaction*&); // executes the transaction
};

#endif
