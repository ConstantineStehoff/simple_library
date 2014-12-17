#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include "bintree.h"
#include "client.h"
#include "factory.h"

using namespace std;
const int MAX_CLIENTS = 10000;
//---------------------------------------------------------------------------
// LibraryManager class serves as the processing class that creates media
// objects, creates clients, and creates transaction objects. It has the
// hashmap for clients, hashmap of trees of media objects, and has the list
// of all valid transactions.
//
// Assumptions: - Text files have no spaces
//              - Input files are the text files
//              - The ids of the clients are no more than 5 digits long
//              - Users would not use the copy constructor
//---------------------------------------------------------------------------

class LibraryManager {
    
public:
    LibraryManager(); // constructor
    ~LibraryManager(); // destructor
    void buildClients(ifstream&); // builds client objects
    void buildMedia(ifstream&); // builds media objects
    void buildTransactions(ifstream&); // builds and processes transactions
    void registerClient(const Client&); // adds a client to the library
private:
    Client clients[MAX_CLIENTS]; // array of clients
    Factory* factory; // factory that creates hashmaps
    BinTree mediaMap[MAX_COMMANDS]; // hashmap for media
    list<Transaction*> transactionList; // hashmap for transactions
};

#endif

