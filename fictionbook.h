//
//  fictionbook.h
//  lab4
//
//  Created by Konstantin Stekhov on 2/27/14.
//  Copyright (c) 2014 Konstantin Stekhov. All rights reserved.
//

#ifndef FICTIONBOOK_H
#define FICTIONBOOK_H

#include "media.h"
using namespace std;

//---------------------------------------------------------------------------
// FictionBook class represents fictions in the library and holds the
// data about the author of the book.
//
// Assumptions: - Users would not use the copy constructor
//              - Error will be thrown if there is no fiction book in
//                the library
//              - Patrons would not use operator<=
//              - Patrons would not use operator>=
//---------------------------------------------------------------------------


class FictionBook : public Media {
    
public:
    FictionBook();  // constructor
    virtual ~FictionBook(); // destructor
    virtual void setData(ifstream&); // sets the data for a book
    virtual void setData2(ifstream&); // sets data in transaction
    virtual bool operator==(const NodeData&) const; // checks if equals
    virtual bool operator<(const NodeData&) const; // checks if less
    virtual void display() const; // displays a book
    virtual void partialDisplay() const; // displays for history
    virtual void displayHead() const; // displays the header for all books
    virtual void addAvailable(); // adds book to the library
    virtual bool decreseAvailable(); // removes a book from the library
    virtual Media* create(); // creates the object
protected:
    string author;
};

#endif
