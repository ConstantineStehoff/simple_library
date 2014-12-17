#include "factory.h"

//----------------------------------------------------------------------
// Factory
// This function is the constuctor for the class.
Factory::Factory(){
    for(int i = 0; i < MAX_COMMANDS; i++){
        mediaInventory[i] = NULL;
        commandInventory[i] = NULL;
    }
    // setting up the meida array/hashmap
    mediaInventory[5] = new FictionBook();
    mediaInventory[24] = new ChildrenBook();
    mediaInventory[15] = new Periodical();
    
    // setting up the commands array/hashmap
    commandInventory[2] = new Checkout();
    commandInventory[7] = new History();
    commandInventory[17] = new Return();
    commandInventory[3] = new Display();
}

//----------------------------------------------------------------------
// ~Factory
// This function is the destructor for the class.
Factory::~Factory(){
    for (int i = 0; i < MAX_COMMANDS; i++){
        // deleting the media
        if (mediaInventory[i] != NULL){
            delete mediaInventory[i];
            mediaInventory[i] = NULL;
        }
        // deleting the commands
        if (commandInventory[i] != NULL){
            delete commandInventory[i];
            commandInventory[i] = NULL;
        }
    }
}

//----------------------------------------------------------------------
// createMedia
// This function creates a media object in the corresponding
// idexe in the array.
NodeData* Factory::createMedia(const char type, ifstream& mediaFile){
    int index = hashIt(type);
    string line;
    if(mediaInventory[index] == NULL){ // check if the correct index
        getline(mediaFile, line, '\n');
        return NULL;
    } else {
        return mediaInventory[index]->create();
    }
}

//----------------------------------------------------------------------
// createTransaction
// This function creates a transaction in the corresponding index in
// the array.
Transaction* Factory::createTransaction(const char type, ifstream& transactionFile){
    int index = hashIt(type);
    string line;
    if(commandInventory[index] == NULL){ // check if the correct index
        getline(transactionFile, line, '\n');
        return NULL;
    } else {
        return commandInventory[index]->create();
    }
}

//----------------------------------------------------------------------
// hashIt
// This function returns the number representation of the character
// for the array/hashmap.
int Factory::hashIt(const char type) const{
    return type - 'A';
}

//----------------------------------------------------------------------
// getIndex
// This function returns the index of a given character of a media tree.
int Factory::getIndex(const char type) const{
    return hashIt(type);
}
