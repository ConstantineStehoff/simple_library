#include "nodedata.h"

//---------------------------------------------------------------------------
// NodeData
// This function is the constuctor for the class.
NodeData::NodeData(){
    
}
//---------------------------------------------------------------------------
// ~NodeData
// This function is the destructor for the class.
NodeData::~NodeData(){
    
}

//---------------------------------------------------------------------------
// getTitle
// This function returns the title of the item in the library.
string NodeData::getTitle() const{
    return title;
}

//---------------------------------------------------------------------------
// addOwner
// This function adds an owner with clientID to an item in the library.
void NodeData::addOwner(const int clientID){
    bookOwnership.push_back(clientID);
}

//---------------------------------------------------------------------------
// removeOwner
// This function removes an owner with clientID from an item in the library.
void NodeData::removeOwner(const int clientID){
    bookOwnership.remove(clientID);
}

//---------------------------------------------------------------------------
// checkOwner
// This function checks if the client is the current owner of the item in
// the library.
bool NodeData::checkOwner(const int clientID){
    for(list<int>::iterator list_iter = bookOwnership.begin();
        list_iter != bookOwnership.end(); list_iter++){
        if (*list_iter == clientID) { // if the client is in the book
            return true;              // ownership array
        }
    }
    return false;
}
