#include "display.h"

//---------------------------------------------------------------------------
// Display
// This function is the constuctor for the class.
Display::Display() : Transaction(){
    transType = "Display";
}

//---------------------------------------------------------------------------
// ~Display
// This function is the destructor for the class.
Display::~Display(){
    
}

//---------------------------------------------------------------------------
// setData
// This function sets the data for the display transaction and validates the
// transaction. It sets the pointer to the media hashmap.
bool Display::setData(ifstream& infile, BinTree hashmap[],
                      Client clients[], Factory*& factoryPtr){
    hashmapPtr = hashmap;
    return true;
}

//---------------------------------------------------------------------------
// display
// This function prints out the type of the transaction.
void Display::display() const{
    cout << transType << " ";
}

//---------------------------------------------------------------------------
// create
// This function return the display object.
Transaction* Display::create(){
    return new Display();
}

//---------------------------------------------------------------------------
// execute
// This function executes the transaction and prints out all of the data
// about the media in the library.
void Display::execute(Transaction*& newTran){
    cout << "-------------------------------------" <<
    "--------------------------------------" << endl;
    for(int i = 0; i < MAX_COMMANDS; i++){
        if (!hashmapPtr[i].isEmpty()) {
            cout << hashmapPtr[i];
        }
    }
}
