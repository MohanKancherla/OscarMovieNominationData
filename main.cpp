/*

PROJECT Team - Mohan Kancherla & Veena Saraswathy

CSCI 2421 final project -  - Academy Award Movies data manipulation

Project due date May 1,2019

*/

//including the headerfiles of binarysearchtree and datafunctions
#include "BinarySearchTree.h"
#include "BinarySearchTree.hpp"
#include "DataFunctions.h"
#include "DataFunctions.hpp"
#include <fstream>
#include <string>

using namespace std;

int main() {

    DataFunctions f;//creating object to data function class
    int a;
    f.getDatabase();// calling respective database
    cout << "Select the Database:\n1. Actor-Actress\n2. Pictures\n";
    cout << "************************\n";
	//user will select which database he/she need to work on
    cin >> a;
    cin.clear();
    cin.ignore();
    bool asd = true;
    while(asd){
        if (a == 1)
        {
			//displaying the possible menu options for the actor-actress database
			/*
			 1. Search
			 2. Partial Search
			 3. Add,delete and Modify the record
			 4. sort the reports and save them into a file
			 5. Exit
			*/
            int t;
            cout << "************************\n";
            cout << "1. Search\n2. Partial Search\n3. Add, Delete, Modify the record\n4. Sort the Reports and Save into a file\n5. Exit\n";
            cout << "************************\n";
            cin >> t;
            cin.clear();
            cin.ignore();
            if (t == 1)
                f.Search();
            else if (t == 2)
                f.partSearch();
            else if (t == 3)
                f.modify();
            else if (t == 4)
                f.sortData();
            if (t == 5)
                asd = false;
        }
        else if (a == 2) {
            int t;
			//displaying the possible menu options for the pictures database
			/*
			 1. Search
			 2. Partial Search
			 3. Add,delete and Modify the record
			 4. sort the reports and save them into a file
			 5. Exit
			*/
            cout << "************************\n";
            cout << "1. Search\n2. Partial Search\n3. Add, Delete, Modify\n4. Sort the Reports and Save into a file\n5. Exit\n";
            cout << "************************\n";
            cin >> t;
            cin.clear();
            cin.ignore();
            if (t == 1)
                f.SearchFilm();
            else if (t == 2)
                f.partSearchFilm();
            else if (t == 3)
                f.modifyFilm();
            else if (t == 4)
                f.sortDataFilm();
            if (t == 5)
                asd = false;
        }
    }
    return 0;
}