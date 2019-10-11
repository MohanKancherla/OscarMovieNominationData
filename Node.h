/*
PROJECT Team - Mohan Kancherla & Veena Saraswathy

CSCI 2421 final project -  - Academy Award Movies data manipulation

Project due date May 1,2019

*/


//header file of class Node
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
using namespace std;


//This Structure is for actor-actress database
struct AwardData  //award data of the movie
{
    string year, award, win, name, film;
};

//This Structure is used for pictures database
struct PictureData  //total pictuire data for a movie
{
	string name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis;
};

//Binary Tree Node
template <typename DATATYPE, typename KEYTYPE>
class Node {
private:
    KEYTYPE key; //This should be the datatype of your key...sorted field in tree
    DATATYPE data;
    Node<DATATYPE, KEYTYPE> * left;
    Node<DATATYPE, KEYTYPE> * right;
    Node<DATATYPE, KEYTYPE> * parent;
public:
    Node() { left = nullptr; right = nullptr; parent = nullptr; };
    void setKey(KEYTYPE aKey) { key = aKey; };
    void setData(DATATYPE aData) { data = aData; };
    void setLeft(Node<DATATYPE, KEYTYPE> * aLeft) { left = aLeft; };
    void setRight(Node<DATATYPE, KEYTYPE> * aRight) { right = aRight; };
    void setParent(Node<DATATYPE, KEYTYPE> * aParent) { parent = aParent; };
    KEYTYPE Key() { return key; };
    DATATYPE Data() { return data; };
    Node<DATATYPE, KEYTYPE> * Left() { return left; };
    Node<DATATYPE, KEYTYPE> * Right() { return right; };
    Node<DATATYPE, KEYTYPE> * Parent() { return parent; };
};

#endif
