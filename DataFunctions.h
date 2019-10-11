
/*
PROJECT Team - Mohan Kancherla & Veena Saraswathy

CSCI 2421 final project -  - Academy Award Movies data manipulation

Project due date May 1,2019

*/

#ifndef DATAFUNCTIONSMAN
#define DATAFUNCTIONSMAN

#include "Node.h"
#include "BinarySearchTree.h"
#include <string>
#include <fstream>

using namespace std;

class DataFunctions
{
private:
    BinarySearchTree<AwardData, string> *actortreeA = new BinarySearchTree<AwardData, string>;
	BinarySearchTree<AwardData, string> *filmtreeA = new BinarySearchTree<AwardData, string>;
	BinarySearchTree<AwardData, string> *yeartreeA = new BinarySearchTree<AwardData, string>;
    Node<AwardData, string> * node;
	AwardData g,u;
	AwardData tempData;

    Node<PictureData, string> * leaf;
	PictureData a,b;
	PictureData temp;
	BinarySearchTree<PictureData, string> *nametreeC = new BinarySearchTree<PictureData, string>;
	BinarySearchTree<PictureData, string> *yeartreeC = new BinarySearchTree<PictureData, string>;
	BinarySearchTree<PictureData, string> *ratetreeC = new BinarySearchTree<PictureData, string>;
	BinarySearchTree<PictureData, string> *nomitreeC = new BinarySearchTree<PictureData, string>;

    ofstream outfile;
    ofstream file;

    void dataSort(Node<AwardData, string> * node, int r);
    void dataSortFilm(Node<PictureData, string> * node, int r);

    void ASearch(Node<AwardData, string> *node, string w);
    void FSearch(Node<PictureData, string> *node, string w);


    void Apart(Node<AwardData, string> *l, string w);
    void Fpart(Node<PictureData, string> *l, string w);

    void save(Node<AwardData, string> *node);
    void saveFilm(Node<PictureData, string> *leaf);

public:
    //This function is used to get the data from a *.csv file into a tree
    void getDatabase();

	//This function is used to sort the whole database
	//This function is called from the main function
	//This function is called as per the user preference
	void sortData();

	//All this function works after choosing the database which is either actor-actress or pictures
	//Searching the data as per user request
	void Search();

    //This function prints the data that has the sub-string that was given by the user
	void partSearch();

	//It's functionality is to add, delete or modify the required data.
    void modify();

    //To check for the substring present in a string
    bool findString(string str, string substr);


    //for pictures database
    void sortDataFilm();
    void SearchFilm();
    void partSearchFilm();
    void modifyFilm();

};
#endif