//
//  fictionbook.cpp
//  lab4
//
//  Created by Konstantin Stekhov on 2/27/14.
//  Copyright (c) 2014 Konstantin Stekhov. All rights reserved.
//

#include "fictionbook.h"

//---------------------------------------------------------------------------
// FictionBook
// This function is the constuctor for the class.
FictionBook::FictionBook():Media() {
    type = "Fiction:";
    amount = 5;
}

//---------------------------------------------------------------------------
// ~FictionBook
// This function is the destructor for the class.
FictionBook::~FictionBook(){
    
}

//---------------------------------------------------------------------------
// create
// This function returns the fiction book object.
Media* FictionBook::create(){
    return new FictionBook();
}

//---------------------------------------------------------------------------
// setData
// This function reads the data about the fiction book and sets the data
// for the object
void FictionBook::setData(ifstream& infile){
    infile.get();
    getline(infile, author, ','); // get author
    
    infile.get();
    getline(infile, title, ',');
    
    infile >> year;
}

//---------------------------------------------------------------------------
// setData2
// This function reads and sets the data for the fiction book object used
// inside the setting up a transaction object.
void FictionBook::setData2(ifstream& infile){
    infile.get();
    getline(infile, author, ',');
    
    infile.get();
    getline(infile, title, ',');
}

//---------------------------------------------------------------------------
// display
// This function displays the fiction book object in the display media
// transaction.
void FictionBook::display() const{
    cout << " " << left << setw(2) << amount << "   "
    << setw(25)<< author.substr(0, 20)
    << setw(34)<< title.substr(0, 34) << setw(5)<< year << endl;
}

//---------------------------------------------------------------------------
// partialDisplay
// This function displays children book object in the history of
// transactions for a patron.
void FictionBook::partialDisplay() const{
    cout << "  " << left << setw(20)<< author.substr(0, 20) << setw(35)
    << title.substr(0, 34) << setw(5)<< year << endl;
}

//---------------------------------------------------------------------------
// displayHead
// This function displays the header for all of the fiction book objects.
void FictionBook::displayHead() const{
    cout << type << endl;
    cout << "AVAIL AUTHOR" << right << setw(24) << "TITLE"
    << setw(33) << "YEAR" << endl;
}

//---------------------------------------------------------------------------
// operator==
// This function compares the fiction book to the other fiction book and
// finds out they are equal or not.
bool FictionBook::operator==(const NodeData& otherData) const{
    // casting into the fiction book object
    const FictionBook& castedData =
        static_cast<const FictionBook& >(otherData);
    return(author == castedData.author && title == castedData.title);
}

//---------------------------------------------------------------------------
// operator<
// This function compares the fiction book to the other fiction book and
// finds out which one is smaller for the insert tree function.
bool FictionBook::operator<(const NodeData& otherData) const{
    // casting into the fiction book object
    const FictionBook& castedData =
        static_cast<const FictionBook& >(otherData);
    // compare objects
    if(author < castedData.author){
        return true;
    } else if (author == castedData.author){
        return title < castedData.title;
    } else {
        return false;
    }
}

//---------------------------------------------------------------------------
// addAvailable
// This function increases the amount of fiction books by one.
void FictionBook::addAvailable(){
    amount += 1;
}

//---------------------------------------------------------------------------
// decreseAvailable
// This function decreses the amount of fiction books in the library by one.
bool FictionBook::decreseAvailable(){
    if (amount > 0) {
        amount -= 1;
        return true;
    } else { // error if there are no copies left
        cout << "There are no " << title << " by " << author
        << " books in the library" << endl << endl;
        return false;
    }
}
