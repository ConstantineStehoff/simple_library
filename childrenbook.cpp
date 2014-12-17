#include "childrenbook.h"

//---------------------------------------------------------------------------
// ChildrenBook
// This function is the constuctor for the class.
ChildrenBook::ChildrenBook() :Media(){
    type = "Youth Books:";
    amount = 5;
}

//---------------------------------------------------------------------------
// ~ChildrenBook
// This function is the destructor for the class.
ChildrenBook::~ChildrenBook(){
    
}

//---------------------------------------------------------------------------
// create
// This function returns the children book object.
Media* ChildrenBook::create(){
    return new ChildrenBook();
}

//---------------------------------------------------------------------------
// setData
// This function reads the data about the children book and sets the
// data for the object.
void ChildrenBook::setData(ifstream& infile){
    infile.get();
    getline(infile, author, ',');
    
    infile.get();
    getline(infile, title, ',');
    
    infile >> year;
}

//---------------------------------------------------------------------------
// setData2
// This function reads and sets the data for the children book object
// used inside the setting up a transaction object.
void ChildrenBook::setData2(ifstream& infile){
    infile.get();
    getline(infile, title, ',');
    infile.get();
    getline(infile, author, ',');
}

//---------------------------------------------------------------------------
// display
// This function displays the children book object in the display media
// transaction.
void ChildrenBook::display() const{
    cout << " " << left << setw(2) << amount << "   "
    << setw(25)<< author.substr(0, 20)
    << setw(34)<< title.substr(0, 34) << setw(5)<< year << endl;
}

//---------------------------------------------------------------------------
// partialDisplay
// This function displays children book object in the history of
// transactions for a patron.
void ChildrenBook::partialDisplay() const{
    cout << "  " << left << setw(20)<< author.substr(0, 20) << setw(35)
    << title.substr(0, 34) << setw(5)<< year << endl;
}

//---------------------------------------------------------------------------
// displayHead
// This function displays the header for all of the children book
// objects.
void ChildrenBook::displayHead() const{
    cout << type << endl;
    cout << "AVAIL AUTHOR" << right << setw(24) << "TITLE"
    << setw(33) << "YEAR" << endl;
}

//---------------------------------------------------------------------------
// operator==
// This function compares the children book to the other children book and
// finds out they are equal or not.
bool ChildrenBook::operator==(const NodeData& otherData) const{
    const ChildrenBook& castedData =
        static_cast<const ChildrenBook& >(otherData);
    return(title == castedData.title && author == castedData.author);
}

//---------------------------------------------------------------------------
// operator<
// This function compares the children book to the other children book and
// finds out which one is smaller for the insert tree function.
bool ChildrenBook::operator<(const NodeData& otherData) const{
    const ChildrenBook& castedData =
        static_cast<const ChildrenBook& >(otherData);
    if(title < castedData.title){
        return true;
    } else if (title == castedData.title){
        return author < castedData.author;
    } else {
        return false;
    }
}

//---------------------------------------------------------------------------
// addAvailable
// This function increases the amount of children books by one.
void ChildrenBook::addAvailable(){
    amount += 1;
}

//---------------------------------------------------------------------------
// decreseAvailable
// This function decreses the amount of children books in the library by one.
bool ChildrenBook::decreseAvailable(){
    if (amount > 0) {
        amount -= 1;
        return true;
    } else {
        cout << "There are no " << title << " by " << author
        << " books in the library" << endl << endl;
        return false;
    }
}
