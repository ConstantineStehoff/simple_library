#include "bintree.h"

//---------------------------------------------------------------------------
// BinTree
// This is a constructor.
BinTree::BinTree(){
    root = NULL;
}

//---------------------------------------------------------------------------
// ~BinTree
// This is a destructor.
BinTree::~BinTree(){
    makeEmpty();
}

//---------------------------------------------------------------------------
// operator<<
// This function displays the tree in inorder traversal.
ostream& operator<<(ostream &output, const BinTree &otherTree){
	otherTree.printHelper(otherTree.root);
    output << endl;
	return output;
}


//---------------------------------------------------------------------------
// printHelper
// This is the helper recursive function for displaying the tree in inorder
// traversal.
void BinTree::printHelper(const Node *ptr) const {
	if(ptr == root){
        ptr->data->displayHead();
    }
    if (ptr != NULL) {
		printHelper (ptr->left);
		ptr->data->display();
		printHelper (ptr->right);
	}
}

//----------------------------------------------------------------------------
// isEmpty
// This function checks if the tree is empty.
bool BinTree::isEmpty() const{
    return root == NULL;
}

//----------------------------------------------------------------------------
// makeEmpty
// This function removes all data and all nodes from the tree.
void BinTree::makeEmpty(){
    makeEmptyHelper(root);
}

//----------------------------------------------------------------------------
// makeEmptyHelper
// This is a helper function that deletes nodes and data.
void BinTree::makeEmptyHelper(Node*& head){
    if(head != NULL){
        // going through the tree
        makeEmptyHelper(head->left);
        makeEmptyHelper(head->right);
        
        // deleting the stuff
        delete head->data;
        head->data = NULL;
        delete head;
        head = NULL;
    }
}

//----------------------------------------------------------------------------
// insert
// This function inserts the nodes into the tree.
bool BinTree::insert(NodeData* dataptr) {
    if (isEmpty()) {
        Node* ptr = new Node;
        if (ptr == NULL) return false;       // out of memory
        ptr->data = dataptr;
        ptr->left = ptr->right = NULL;
        root = ptr;
    } else {
        Node* current = root;                // walking pointer
        bool inserted = false;               // whether inserted yet
        
        // if item is less than current item, insert in left subtree,
        // otherwise insert in right subtree
        while (!inserted) {
            if (*dataptr < *current->data) {
                if (current->left == NULL) {          // insert left
                    Node* ptr = new Node;
                    if (ptr == NULL) return false;    // out of memory
                    ptr->data = dataptr;
                    ptr->left = ptr->right = NULL;
                    current->left = ptr;
                    inserted = true;
                } else {
                    current = current->left;          // one step left
                }
            } else if (*dataptr == *current->data) {
                return false; // inserting the duplican thus false
            } else {
                if (current->right == NULL) {         // insert right
                    Node* ptr = new Node;
                    if (ptr == NULL) return false;    // out of memory
                    ptr->data = dataptr;
                    ptr->left = ptr->right = NULL;
                    current->right = ptr;
                    inserted = true;
                } else {
                    current = current->right;         // one step right
                }
            }
        }
    }
    return true;
}

//---------------------------------------------------------------------------
// retrieve
// This function finds and retrives the object by assigning the objPtr to it.
bool BinTree::retrieve(const NodeData &obj, NodeData*& objPtr) const{
    Node* head = root;
    Node* nodePtr = NULL;
    findNode(head, obj, nodePtr);
    if(nodePtr != NULL){
        objPtr = nodePtr->data;
        return true;
    }
    return false;
}

//---------------------------------------------------------------------------
// findNode
// This function finds the node into the tree that points to the object
// passed into the function. Also, it assigns the pointer to the node,
// that was found, to the nodePtr paramenter.
void BinTree::findNode(Node*& head, const NodeData &obj,
                       Node* &nodePtr) const{
    if (head != NULL) {
        if (*head->data == obj){
            nodePtr = head;
        }
        findNode(head->left, obj, nodePtr);
        findNode(head->right, obj, nodePtr);
    }
}
