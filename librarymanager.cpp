#include "librarymanager.h"

//----------------------------------------------------------------------
// LibraryManager
// This function is the constuctor for the class.
LibraryManager::LibraryManager(){
    // initiating the clients hashmap with the empty clients
    for(int i = 0; i < MAX_CLIENTS; i++){
        clients[i] = Client();
    }
    factory = new Factory(); // creating factory
}

//----------------------------------------------------------------------
// ~LibraryManager
// This function is the destructor for the class.
LibraryManager::~LibraryManager(){
    // delete all of the transactions from the transaction queue
    for(list<Transaction*>::iterator list_iter = transactionList.begin();
        list_iter != transactionList.end(); list_iter++){
        delete *list_iter;
        *list_iter = NULL;
    }
    // deletes the factory object
    delete factory;
    factory = NULL;
}

//----------------------------------------------------------------------
// buildClients
// This function reads the clients from the patron data text file
// then creates the clients and adds them to the hashmap of clients.
void LibraryManager::buildClients(ifstream& infilePatrons){
    if (!infilePatrons) {
        cout << "Patrons file could not be opened." << endl;
        return;
    }
    string firstName, lastName;
    int id;
    infilePatrons >> id; // reading id
    // check if the file is empty
    if(infilePatrons.peek() == ifstream::traits_type::eof()){
        cout << "The patrons file is empty" << endl;
        return;
    }
    // reading the rest of the client data then creating
    // clients and adding to the hashmap
    while (!infilePatrons.eof()) {
        infilePatrons >> lastName;
        infilePatrons >> firstName;
        registerClient(Client(id, lastName, firstName));
        infilePatrons >> id;
    }
    infilePatrons.close();
}

//----------------------------------------------------------------------
// registerClient
// This function adds a single client into the clients' hashmap.
void LibraryManager::registerClient(const Client& newPatron){
    clients[newPatron.getID()] = newPatron;
}

//----------------------------------------------------------------------
// buildMedia
// This function reads the media data text file then creates media
// objects and adds them into the media hashmap.
void LibraryManager::buildMedia(ifstream& infileBooks){
    // check if the file exists or empty
    if (!infileBooks) {
        cout << "The books file could not be opened." << endl;
        return;
    }
    if(infileBooks.peek() == ifstream::traits_type::eof()){
        cout << "The books file is empty" << endl;
        return;
    }
    char bookCode = ' ';
    // reading the file for the rest of the media data
    infileBooks >> bookCode;
    while (!infileBooks.eof()) {
        // create a media object depending on the bookCode
        NodeData* newBook = factory->createMedia(bookCode, infileBooks);
        if(newBook != NULL){
            // setting the book object
            newBook->setData(infileBooks);
            // inserting in the map and the corresponding bintree
            bool suc = mediaMap[factory->
                                getIndex(bookCode)].insert(newBook);
            if(!suc){
                cout << "Can't insert a new book" << endl;
                delete newBook;
            }
        }
        infileBooks >> bookCode;
    }
    infileBooks.close();
}

//---------------------------------------------------------------------------
// buildTransactions
// This function reads the transactions text file then creates transactons,
// validates them, adds to the transaction queue, and finally reads the
// transactions queue and executes the transactions.
void LibraryManager::buildTransactions(ifstream& infileCommands){
    // check if the file exists or empty
    if (!infileCommands) {
        cout << "Command file could not be opened." << endl;
        return;
    }
    if(infileCommands.peek() == ifstream::traits_type::eof()){
        cout << "The command file is empty" << endl;
        return;
    }
    char commandCode;
    string dummyString;
    // reading the data for the transactions
    infileCommands >> commandCode;
    while (!infileCommands.eof()) {
        // creating the transaction
        Transaction* newTran = factory->createTransaction(commandCode, infileCommands);
        // if transaction exists then set it up
        if(newTran != NULL){
            if(newTran->setData(infileCommands, mediaMap, clients, factory)){
                transactionList.push_back(newTran);
            // if not a valid transaction throw the error
            } else {
                cout << "Not a valid transaction ";
                newTran->display();
                cout << endl;
                delete newTran;
                newTran = NULL;
            }
        }
        infileCommands >> commandCode;
    }
    infileCommands.close();
    // read the transactions from the transaction queue and execute them
    for(list<Transaction*>::iterator list_iter = transactionList.begin();
        list_iter != transactionList.end(); list_iter++){
        (*list_iter)->execute((*list_iter));
    }
}

