#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string.h>
#include "media.h"
#include "client.h"
#include "bintree.h"
using namespace std;

class Client;
class Factory;
//---------------------------------------------------------------------------
// Transaction class serves as a parent to all of the transactions in the
// library and holds the data about person who performs transaction,
// information about the item, and the type of the transaction.
//
// Assumptions: - Users would not use the copy constructor
//              - If the transaction is not valid it is not going to be
//                executed
//              - Error will be thrown if a transaction is invalid
//---------------------------------------------------------------------------

class Transaction {
    
public:
    Transaction(); // constructor
    virtual ~Transaction(); // destructor
    // sets the data for a transaction
    virtual bool setData(ifstream&, BinTree[], Client[], Factory*&) = 0;
    virtual void display() const = 0; // displays transaction
    virtual Transaction* create() = 0; // creates an object
    virtual void execute(Transaction*&) = 0; // executes transaction
    string getTransactionType() const; // returns the type of a transaction
    NodeData* getItem() const; // returns the item of a transaction
protected:
    string transType; // type of transaction
    NodeData* item; // item of the transaction
    Client* person; // person who performs
};

#endif
