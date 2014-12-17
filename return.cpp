#include "return.h"

//---------------------------------------------------------------------------
// Return
// This function is the constuctor for the class.
Return::Return() : Transaction(){
    transType = "Return";
}

//---------------------------------------------------------------------------
// ~Return
// This function is the destructor for the class.
Return::~Return(){}

//---------------------------------------------------------------------------
// setData
// This function sets the data for the return transaction and validates the
// transaction. It reads the data about the transaction and throws error
// if the input in text file is incorrect.
bool Return::setData(ifstream& infile, BinTree hashmap[],
                     Client clients[], Factory*& factoryPtr){
    int clientID;
    char bookCode = ' ', mediaCode = ' ';
    string dummyString; // string for skipping lines
    NodeData* tempBook = NULL;
    NodeData* compareBookPtr = NULL;
    
    infile >> clientID;
    if (infile.eof()) { // if end of file
        cout << "Error: End of file" << endl;
        return false;
    }
    // checking if the client exists
    if(clients[clientID].getID() != 0){
        person = &clients[clientID]; // set the person
        infile >> bookCode; // reading the type of book
        if (infile.eof()) {
            cout << "Error: End of file" << endl;
            return false;
        }
        
        infile >> mediaCode; // checking if the hard copy or not
        if (mediaCode != 'H') {
            cout << "Error this is not a hard copy" << endl;
            getline(infile, dummyString); // skip the line
            return false;
        } else {
            // creating the book object
            tempBook = factoryPtr->createMedia(bookCode, infile);
            if (tempBook != NULL) { // if the book created
                tempBook->setData2(infile); // setting up the book
                int num = (*factoryPtr).getIndex(bookCode);
                // checking if it's part of the library
                hashmap[num].retrieve(*tempBook, compareBookPtr);
            } else {
                // code is not valid
                cout << "Error: The book code is not valid" << endl;
                return false;
            }
        }
        // if part of library
        if (compareBookPtr != NULL) {
            item = compareBookPtr; // setting up the item
            delete tempBook; // deleting the book for comparison
            tempBook = NULL;
            return true;
        } else {
            // book is not the part of the library
            cout << "Error: No book in the library" << endl;
            getline(infile, dummyString);
            if (tempBook != NULL) {
                delete tempBook;
                tempBook = NULL;
            }
            return false;
        }
    } else {
        // no such client
        cout << "No client with ID: " << clientID << endl;
        getline(infile, dummyString);
        return false;
    }
    return true;
}

//---------------------------------------------------------------------------
// display
// This function prints out the type of the transaction.
void Return::display() const{
    cout << left << setw(8) << transType;
}

//---------------------------------------------------------------------------
// create
// This function return the return object.
Transaction* Return::create(){
    return new Return();
}

//---------------------------------------------------------------------------
// execute
// This function executes the return transaction. It checks if the person
// owns the item that they try to return and if not prints the error.
void Return::execute(Transaction*& newTran){
    if (item->checkOwner(person->getID())) {
        person->addTransaction(newTran); // add to the history
        item->addAvailable(); // add item to the library
        item->removeOwner(person->getID()); // removes owner from media
    } else {
        cout << "Error: Patron with id: " << person->getID()
        << " can't return " << item->getTitle() << endl << endl;
    }
}
