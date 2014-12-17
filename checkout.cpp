//
//  checkout.cpp
//  lab4
//
//  Created by Konstantin Stekhov on 2/27/14.
//  Copyright (c) 2014 Konstantin Stekhov. All rights reserved.
//

#include "checkout.h"

//---------------------------------------------------------------------------
// Checkout
// This function is the constuctor for the class.
Checkout::Checkout() : Transaction(){
    transType = "Checkout";
}

//---------------------------------------------------------------------------
// ~Checkout
// This function is the destructor for the class.
Checkout::~Checkout(){}

//---------------------------------------------------------------------------
// This function sets the data for the display transaction and validates the
// transaction.
bool Checkout::setData(ifstream& infile, BinTree hashmap[],
                       Client clients[], Factory*& factoryPtr){
    int clientID;
    char bookCode = ' ', mediaCode = ' ';
    string dummyString;
    NodeData* tempBook = NULL; // book for comaprison
    NodeData* compareBookPtr = NULL; // book that's from the tree
    infile >> clientID;
    if (infile.eof()) { // check if end of file
        cout << "Error: End of file" << endl;
        return false;
    }
    if(clients[clientID].getID() != 0){ // find a client
        person = &clients[clientID];
        infile >> bookCode;
        if (infile.eof()) {
            cout << "Error: End of file" << endl;
            return false;
        }
        infile >> mediaCode;
        if (mediaCode != 'H') { // check if it's a hard copy
            cout << "Error this is not a hard copy" << endl;
            getline(infile, dummyString); // skip the line
            return false;
        } else {
            // create a book for comparison
            tempBook = factoryPtr->createMedia(bookCode, infile);
            if (tempBook != NULL) { // if exists
                tempBook->setData2(infile);
                int num = (*factoryPtr).getIndex(bookCode);
                // find the book in the media tree
                hashmap[num].retrieve(*tempBook, compareBookPtr);
            } else { // wrong book code
                cout << "Error: The book code is not valid" << endl;
                return false;
            }
        }
        // if the book in the library
        if (compareBookPtr != NULL) {
            item = compareBookPtr; // assign the item
            delete tempBook;
            tempBook = NULL;
            return true;
        } else {
            // no book in the library
            cout << "Error: No book in the library" << endl;
            getline(infile, dummyString);
            if (tempBook != NULL) { // delete the comparison book
                delete tempBook;
                tempBook = NULL;
            }
            return false;
        }
    } else { // no such patron
        cout << "No client with ID: " << clientID << endl;
        getline(infile, dummyString);
        return false;
    }
}

//---------------------------------------------------------------------------
// display
// This function prints out the type of the transaction.
void Checkout::display() const{
    cout << left << setw(8) << transType;
}

//---------------------------------------------------------------------------
// create
// This function return the history object.
Transaction* Checkout::create(){
    return new Checkout();
}

void Checkout::execute(Transaction*& newTran){
    person->addTransaction(newTran); // add to the transaction history
    item->decreseAvailable(); // remove the book from the library
    item->addOwner(person->getID()); // add the owner to the book
}
