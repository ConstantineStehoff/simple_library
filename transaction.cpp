#include "transaction.h"

//---------------------------------------------------------------------------
// Transaction
// This function is the constuctor for the class.
Transaction::Transaction(){
    item = NULL;
    transType = "";
}

//---------------------------------------------------------------------------
// ~Transaction
// This function is the destructor for the class.
Transaction::~Transaction(){}

//---------------------------------------------------------------------------
// getItem
// This function returns the item of the transaction.
NodeData* Transaction::getItem() const{
    return item;
}

//---------------------------------------------------------------------------
// getTransactionType
// This function return the transaction type.
string Transaction::getTransactionType() const{
    return transType;
}


