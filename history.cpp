#include "history.h"

//---------------------------------------------------------------------------
// History
// This function is the constuctor for the class.
History::History() : Transaction(){
    transType = "History";
}

//---------------------------------------------------------------------------
// ~History
// This function is the destructor for the class.
History::~History(){
    
}

//---------------------------------------------------------------------------
// This function sets the data for the history transaction and validates the
// transaction.
bool History::setData(ifstream& infile, BinTree hashmap[],
                      Client clients[], Factory*& factoryPtr){
    int clientID;
    infile >> clientID; // read the client id
    if (infile.eof()) { // error if the end of file
        cout << "Error: End of file" << endl;
        return false;
    }
    // check if the client is in the clients hashmap
    if(clients[clientID].getID() != 0){
        person = &clients[clientID];
        return true;
    } else {
        cout << "No client with ID: " << clientID << endl;
        return false;
    }
}

//---------------------------------------------------------------------------
// display
// This function prints out the type of the transaction.
void History::display() const{
    cout << transType << " ";
}

//---------------------------------------------------------------------------
// create
// This function return the history object.
Transaction* History::create(){
    return new History();
}

//---------------------------------------------------------------------------
// execute
//
void History::execute(Transaction*& newTran){
    person->printHistory();
}
