//
//  client.cpp
//  lab4
//
//  Created by Konstantin Stekhov on 2/27/14.
//  Copyright (c) 2014 Konstantin Stekhov. All rights reserved.
//

#include "client.h"
#include <fstream>

//----------------------------------------------------------------------
// Client
// This function is the constuctor for the class.
Client::Client(ifstream& input){
    setData(input);
}

//----------------------------------------------------------------------
// Client
// This function is the destructor for the class.
Client::Client(int clientID, string lastName, string firstName){
    this->clientID = clientID;
    this->firstName = firstName;
    this->lastName = lastName;
}

//----------------------------------------------------------------------
// ~Client
// This function is the destructor for the client class.
Client::~Client(){}

//----------------------------------------------------------------------
// setData
// This function sets the data for the
void Client::setData(ifstream& infile){
    infile >> clientID;
    if(infile.eof()) return;
    infile.get();
    infile >> lastName;
    infile.get();
    infile >> firstName;
}

//----------------------------------------------------------------------
// getID
//
int Client::getID() const{
    return clientID;
}

//----------------------------------------------------------------------
// getFirstName
//
string Client::getFirstName() const{
    return firstName;
}

//----------------------------------------------------------------------
// getLastName
//
string Client::getLastName() const{
    return lastName;
}

//----------------------------------------------------------------------
// printHistory
// This function prints out the transaction history for a client.
void Client::printHistory(){
    // header for the history
    cout << "*** " << "Patron ID = " << clientID << "  " << lastName << " "
    << firstName << endl;
    // list of transactions
    if(history.size() > 0){
        for(list<Transaction*>::iterator list_iter = history.begin();
            list_iter != history.end(); list_iter++){
            (*list_iter)->display();
            (*list_iter)->getItem()->partialDisplay();
        }
    } else {
        cout << "No transaction history " << endl;
    }
    cout << endl;
}

//----------------------------------------------------------------------
// addTransaction
// This function add a single transaction to a client history.
void Client::addTransaction(Transaction*& tran){
    this->history.push_back(tran);
}


//----------------------------------------------------------------------
// operator==
// This function compares the clients to the other client and see if
// they are equal or not.
bool Client::operator==(const Client& otherClient) const{
    return clientID == otherClient.clientID;
}


//----------------------------------------------------------------------
// operator!=
// This function compares the clients to the other client and see if
// they are not equal.
bool Client::operator!=(const Client& otherClient) const{
    return clientID != otherClient.clientID;
}
