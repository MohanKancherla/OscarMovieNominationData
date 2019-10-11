/*
PROJECT Team - Mohan Kancherla & Veena Saraswathy

CSCI 2421 final project -  Academy Award Movies data manipulation

Project due date May 1,2019

*/

//including the header file of binarysearchtree
#include "BinarySearchTree.h"

// default Constructor
template <typename DATATYPE, typename KEYTYPE>
BinarySearchTree<DATATYPE, KEYTYPE>::BinarySearchTree() {
    root = nullptr;
}

// Destructor
template <typename DATATYPE, typename KEYTYPE>
BinarySearchTree<DATATYPE, KEYTYPE>::~BinarySearchTree() {
    if (root != nullptr)
        freeNode(root);
}

// funtion to free the node
template <typename DATATYPE, typename KEYTYPE>
void BinarySearchTree<DATATYPE, KEYTYPE>::freeNode(Node<DATATYPE, KEYTYPE> * leaf)
{
    
	// if the root is leaf, we will delete the leaf else 
	//using recursive call of the leaf's left and right if leaf is not null and delete leaf
    if (Root() == leaf)
        delete leaf;
    else
    {
        if (leaf != nullptr)
        {
            freeNode(leaf->Left());
            freeNode(leaf->Right());
            delete leaf;
        }
    }

}

// funtion defintion to add a node
template <typename DATATYPE, typename KEYTYPE>
void BinarySearchTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, DATATYPE &data)
{
    if (Root() == nullptr)
    {
        Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
        newNodePtr->setKey(key);
        newNodePtr->setData(data);
        root = newNodePtr;
        root->setParent(root);
        setRoot(root);
    }
    else
        addNode(key, root, data);
}

// Add a node (private)
template <typename DATATYPE, typename KEYTYPE>
void BinarySearchTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data) {

    //Otherwise
    //Check to see if the key is < the leaf's key
    // if left is not null then
    //Add the node to the left (recursively)
    // Otherwise make a new node and attach it to the left

    //Check to see if the key >= leaf's key
    // if leaf's right is not null then
    //Add the node to the right (recursively)
    // Otherwise make new node and attach it to the right

    if (key < leaf->Key())
    {

        if (leaf->Left() == nullptr)
        {

            Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
            newNodePtr->setKey(key);
            newNodePtr->setData(data);
            leaf->setParent(newNodePtr);
            leaf->setLeft(newNodePtr);
        }
        else
            addNode(key, leaf->Left(), data);
    }

    else
    {
        if (leaf->Right() != nullptr)
            addNode(key, leaf->Right(), data);
        else
        {
            Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
            newNodePtr->setKey(key);
            newNodePtr->setData(data);
            leaf->setParent(newNodePtr);
            leaf->setRight(newNodePtr);
        }
    }


}

template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BinarySearchTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key)
{
    return findNode(key, root);
}

// funtion to find a node
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BinarySearchTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node)
{
    //Student must fill in
    // trap nullptr first in case we've hit the end unsuccessfully.
    // success base case
    //Greater than (Right), Less than (Left)
    if (node == nullptr)
        return nullptr;
    if (node->Key() == key)
        return node;
    else if (node->Key() < key)
        return findNode(key, node->Right());
    else
        return findNode(key, node->Left());

}

template <typename DATATYPE, typename KEYTYPE>
void BinarySearchTree<DATATYPE, KEYTYPE>::printInorder()
{
    printInorder(root);
}

template <typename DATATYPE, typename KEYTYPE>
void BinarySearchTree<DATATYPE, KEYTYPE>::printInorder(Node<DATATYPE, KEYTYPE> * node)
{
    //Student must fill in.  Use recursive algorithm.
    //Note that this prints using an Inorder, Depth-first search
    //but you may want to do something else when "visiting" the node....
    //like moving visited data to another datastructure
    //Don't forget your base case!
    if (node != nullptr)
    {
        printInorder(node->Left());
        print(cout, node->Data());
        printInorder(node->Right());
    }

}

//printing out the data
template <typename DATATYPE, typename KEYTYPE>
void BinarySearchTree<DATATYPE, KEYTYPE>::print(ostream & out, const DATATYPE & data)
{
    out << data.year << "," << data.award << "," << data.win << "," << data.name << "," << data.film << endl;
}

template <typename DATATYPE, typename KEYTYPE>
void BinarySearchTree<DATATYPE, KEYTYPE>::deleteNode(KEYTYPE key)
{
    setRoot(deleteNode(Root(), key));
}

//deleteNode (Private)
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BinarySearchTree<DATATYPE, KEYTYPE>::deleteNode(Node<DATATYPE, KEYTYPE> * aRoot, KEYTYPE value)
{

    /* Given a binary search tree and a key, this function deletes the key
    and returns the new root */

    // base case
    if (aRoot == nullptr) return aRoot;

    // If the key to be deleted is smaller than the aRoot's key,
    // then it lies in left subtree
    if (value < aRoot->Key())
        aRoot->setLeft(deleteNode(aRoot->Left(), value));

        // If the key to be deleted is greater than the root's key,
        // then it lies in right subtree
    else if (value > aRoot->Key())
        aRoot->setRight(deleteNode(aRoot->Right(), value));

        // if key is same as root's key, then This is the node
        // to be deleted
    else
    {
        // node with only one child or no child
        if (aRoot->Left() == nullptr)
        {
            Node<DATATYPE, KEYTYPE> *temp = aRoot->Right();
            delete aRoot;
            return temp;
        }
        else if (aRoot->Right() == nullptr)
        {
            Node<DATATYPE, KEYTYPE> *temp = aRoot->Left();
            delete aRoot;
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node<DATATYPE, KEYTYPE> * temp = min(aRoot->Right());

        // Copy the inorder successor's content to this node
        aRoot->setKey(temp->Key());
        aRoot->setData(temp->Data());

        // Delete the inorder successor
        aRoot->setRight(deleteNode(aRoot->Right(), temp->Key()));
    }
    return aRoot;
}


// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BinarySearchTree<DATATYPE, KEYTYPE>::min(Node<DATATYPE, KEYTYPE> * node)
{
    Node<DATATYPE, KEYTYPE> * current = node;

    /* loop down to find the leftmost leaf */
    while (current->Left() != nullptr)
        current = current->Left();

    return current;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BinarySearchTree<DATATYPE, KEYTYPE>::max(Node<DATATYPE, KEYTYPE> * node)
{
    Node<DATATYPE, KEYTYPE> * tempNode = node;
    if (node == nullptr) 
        tempNode = nullptr;
    else if (node->Right())
        tempNode = max(node->Right());
    else
        tempNode = node;

    return tempNode;
}