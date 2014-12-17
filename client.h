#ifndef CLIENT_H
#define CLIENT_H

#include <list>
#include <string>
#include <iostream>
#include "transaction.h"
using namespace std;

//-----------------------------------------------------------------------------
// Client class represents a client in the system, stores the clients
// first and last name and id along with the clients transaction history.
//
//
// Assumptions: - Users would not use the copy constructor
//              - all clients have first names, last names, and ids
//              - history transactions are not going to be printed
//                in the client history
//              - operator<= is not going to be used
//              - operator>= is not going to be used
//-----------------------------------------------------------------------------
class Transaction;
class ClientManager;

class Client {
public:
    Client(int = 0, string = "", string = "");  // constructor
    Client(ifstream&); // another constructor
    ~Client(); //destructor
    int getID() const; // returns id of a client
    string getFirstName() const; // returns first name
    string getLastName() const; // returns last name
    void printHistory(); // prints the transaction history
    void addTransaction(Transaction*&); // adds transaction to history
    void setData(ifstream&); // sets the data for a client
    bool operator==(const Client&) const; // checks if equal
    bool operator!=(const Client&) const; // checks if not equal
    
private:
    list<Transaction*> history; //running record of customer transactions
    int clientID;
    string firstName;
    string lastName;
};

#endif
