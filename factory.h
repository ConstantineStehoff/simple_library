#ifndef __lab4__factory__
#define __lab4__factory__

#include <iostream>
#include "fictionbook.h"
#include "childrenbook.h"
#include "periodical.h"
#include "transaction.h"
#include "checkout.h"
#include "history.h"
#include "return.h"
#include "display.h"

//-----------------------------------------------------------------------------
// Factory class holds and creates the hashmap for creation of the media files
// and transactions. It also allows for the factory pattern where objects are
// created without the switch statements and go into the certain indexes in
// corresponding hashmaps.
//
// Assumptions: - Users would not use the copy constructor
//              - Characters that represent data types and transactions
//                are going to be parts of the English alphabet
//              - Media and transaciton objects are going to be stored in
//                binary trees
//-----------------------------------------------------------------------------

using namespace std;
class Media;
class Transaction;
class Checkout;

static const int MAX_COMMANDS = 26;

class Factory{
public:
    Factory(); // constructor
    ~Factory(); // destructor
    NodeData* createMedia(const char, ifstream&); // creates media objects
    // creats transaction objects
    Transaction* createTransaction(const char, ifstream&);
    int getIndex(const char) const; // gets index of the object in the map
    string getBookType(const char) const; // gets the type of media
private:
    int hashIt(const char) const; // gives index in the map
    NodeData* mediaInventory[MAX_COMMANDS]; // array of media data
    Transaction* commandInventory[MAX_COMMANDS]; // array of transactions
};

#endif /* defined(__lab4__factory__) */
