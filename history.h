//
//  history.h
//  lab4
//
//  Created by Konstantin Stekhov on 3/3/14.
//  Copyright (c) 2014 Konstantin Stekhov. All rights reserved.
//

#ifndef __lab4__history__
#define __lab4__history__

#include <iostream>
#include "transaction.h"

using namespace std;
class Factory;
class Client;

//---------------------------------------------------------------------------
// Histry class represents the history transaction that displays the history
// of transactions for a particular client.
//
// Assumptions: - History transactions are not in the history of the client
//              - Users would not use the copy constructor
//              - If the transaction is not valid it is not going to be
//                executed
//---------------------------------------------------------------------------

class History : public Transaction{
public:
    History(); // constructor
    virtual ~History(); // destructor
    // sets the data for the transaction
    virtual bool setData(ifstream&, BinTree[], Client[], Factory*&);
    virtual void display() const; // displays transaction
    virtual void execute(Transaction*&); // executes transaction
    virtual Transaction* create(); // creates the object
};

#endif /* defined(__lab4__history__) */

