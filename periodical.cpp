#include "periodical.h"

//---------------------------------------------------------------------------
// Periodical
// This function is the constuctor for the class.
Periodical::Periodical() :Media(){
    type = "Periodicals:";
    amount = 1;
}

//---------------------------------------------------------------------------
// ~Periodical
// This function is the destructor for the class.
Periodical::~Periodical(){
    
}

//---------------------------------------------------------------------------
// create
// This function returns the periodical object.
Media* Periodical::create(){
    return new Periodical();
}

//---------------------------------------------------------------------------
// setData
// This function reads the data about the periodical and sets the data
// for the object
void Periodical::setData(ifstream& infile){
    infile.get();
    getline(infile, title, ',');
    infile >> month;
    infile >> year;
}

//---------------------------------------------------------------------------
// setData2
// This function reads and sets the data for the periodical object used
// inside the setting up a transaction object.
void Periodical::setData2(ifstream& infile){
    infile >> year;
    infile >> month;
    infile.get();
    getline(infile, title, ',');
}

//---------------------------------------------------------------------------
// display
// This function displays the periodical object in the display media
// transaction.
void Periodical::display() const{
    cout << " " << left << setw(2) << amount << "   " <<
    setw(6) << year << setw(3)
    << month << title << endl;
}

//---------------------------------------------------------------------------
// partialDisplay
// This function displays periodical object in the history of transactions
// for a patron.
void Periodical::partialDisplay() const{
    cout << "  " << year << "  " << month << " " << title << endl;
}

//---------------------------------------------------------------------------
// displayHead
// This function displays the header for all of the periodical objects.
void Periodical::displayHead() const{
    cout << type << endl;
    cout << "AVAIL YEAR MO  TITLE" << endl;
}

//---------------------------------------------------------------------------
// operator==
// This function compares the periodical to the other periodical and
// finds out they are equal or not.
bool Periodical::operator==(const NodeData& otherData) const{
    const Periodical& castedData = static_cast<const Periodical& >(otherData);
    return(year == castedData.year && month == castedData.month
           && title == castedData.title);
}

//---------------------------------------------------------------------------
// operator<
// This function compares the periodical to the other periodical and finds
// out which one is smaller for the insert tree function.
bool Periodical::operator<(const NodeData& otherData) const{
    const Periodical& castedData = static_cast<const Periodical& >(otherData);
    if(year < castedData.year){
        return true;
    } else if (year == castedData.year){
        if(month == castedData.month){
            return title == castedData.title;
        } else {
            return month < castedData.month;
        }
    } else {
        return false;
    }
    return true;
}

//---------------------------------------------------------------------------
// addAvailable
// This function increases the amount of periodicals by one.
void Periodical::addAvailable(){
    amount += 1;
}

//---------------------------------------------------------------------------
// decreseAvailable
// This function decreses the amount of periodicals in the library by one.
bool Periodical::decreseAvailable(){
    if (amount > 0) {
        amount -= 1;
        return true;
    } else {
        cout << "There are no periodicals " << title
        << " in the library" << endl << endl;
        return false;
    }
}
