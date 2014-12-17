
#ifndef __Lab2__bintree__
#define __Lab2__bintree__

#include <iostream>
#include "nodedata.h"

//---------------------------------------------------------------------------
// Binary trees: a tree data structure in which each node has at most two
//      children In a binary tree, the degree of each node can be at most
//      two. Binary trees are used to implement the binary search trees.
//
//
// Assumptions:
//   -- The left subtree of a node contains only nodes with keys less than
//      the node's key
//   -- The right subtree of a node contains only nodes with keys greater
//      than the node's key
//   -- The left and right subtree each must also be a binary search tree
//   -- There must be no duplicate nodes
//---------------------------------------------------------------------------

using namespace std;

class BinTree{
    // prints the tree in inorder traversal
    friend ostream& operator<<(ostream &, const BinTree &);
    
public:
    BinTree();                              // constructor
    ~BinTree();                             // destructor
    bool insert(NodeData*);                 // inserts a node into a tree
    bool retrieve(const NodeData &, NodeData*&) const; // retrives the obj
    bool isEmpty() const;              // if the tree is empty
    void makeEmpty();                  // deletes the tree
    
private:
    
    struct Node {
        NodeData* data;        // pointer to actual data stored
        Node* left;            // pointer to left child Node, left subtree
        Node* right;           // pointer to right child Node, right subtree
    };
    Node *root;                // The root of this BSTree.
    
    // utility functions

    // helper for deleting the tree
    void makeEmptyHelper(Node*&);
    // finds the node with data that was passed into function
    void findNode(Node*&, const NodeData &, Node*&) const;
    // helper for the displaying the tree in inorder traversal
    void printHelper(const Node*) const;
    };

#endif /* defined(__Lab2__bintree__) */
