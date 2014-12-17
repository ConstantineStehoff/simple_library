#include <iomanip>
#include "librarymanager.h"
using namespace std;

//---------------------------------------------------------------------------
// Lab4.cpp creates the library management class and runs the whole
// library.
//---------------------------------------------------------------------------

int main() {
    // Create a library
    LibraryManager shhh;
    
    // read in data from file
    ifstream infileBooks("data4books.txt");
    ifstream infilePatrons("data4patrons.txt");
    ifstream infileCommands("data4commands.txt");
    
    // build data and run the transactions
    shhh.buildClients(infilePatrons);
    shhh.buildMedia(infileBooks);
    shhh.buildTransactions(infileCommands);
    
    return 0;
}

