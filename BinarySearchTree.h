/*
PROJECT Team - Mohan Kancherla & Veena Saraswathy

CSCI 2421 final project -  - Academy Award Movies data manipulation

Project due date May 1,2019

*/

//including the header file of node class
#ifndef BinarySearchTREEINT_H
#define BinarySearchTREEINT_H
#include <iostream>
using namespace std;
#include "Node.h"

// Binary Search Tree class
template <typename DATATYPE, typename KEYTYPE>
class BinarySearchTree {
private:
    Node<DATATYPE, KEYTYPE> * root;
    void addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data);
    Node<DATATYPE, KEYTYPE> * deleteNode(Node<DATATYPE, KEYTYPE> * node, KEYTYPE key);
    void freeNode(Node<DATATYPE, KEYTYPE> * leaf);
    void printInorder(Node<DATATYPE, KEYTYPE> * node);
    Node<DATATYPE, KEYTYPE> * findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node);

public:
	BinarySearchTree<DATATYPE, KEYTYPE>();//constructor
    ~BinarySearchTree<DATATYPE, KEYTYPE>();//destructor
    Node<DATATYPE, KEYTYPE> * Root() { return root; }
    void setRoot(Node<DATATYPE, KEYTYPE> * _root) { root = _root; }
    void addNode(KEYTYPE key, DATATYPE &data);
    Node<DATATYPE, KEYTYPE> * findNode(KEYTYPE key);
    void printInorder();
    void print(ostream & out, const DATATYPE & data);
    void deleteNode(KEYTYPE key);
    Node<DATATYPE, KEYTYPE> * min(Node<DATATYPE, KEYTYPE> * node);
    Node<DATATYPE, KEYTYPE> * max(Node<DATATYPE, KEYTYPE> * node);
};
#endif  
//BST
