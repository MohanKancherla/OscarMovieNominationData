/*
PROJECT Team - Mohan Kancherla & Veena Saraswathy

CSCI 2421 final project -  - Academy Award Movies data manipulation

Project due date May 1,2019

*/

//including the header file of datafunctions
#include "DataFunctions.h"
#include <iostream>

using namespace std;

//gets the data from the following csv files
void DataFunctions::getDatabase()
{
    ifstream File("actor-actress.csv");
    string line, one, two, three, four, five;

    getline(File, line);
    while (getline(File, five, ','))    //gets the year
    {
        getline(File, one, ',');    //gets the award
        getline(File, two, ',');    //gets the winner
        getline(File, three, ',');  //gets the name of the actor
        getline(File, four);    //gets the movie name
//storing them into a Structure of type Awarddata
        tempData.year = five;
        tempData.award = one;
        tempData.win = two;
        tempData.name = three;
        tempData.film = four;
//adding the data into a BST and key is the name of the actor
        actortreeA->addNode(tempData.name, tempData);
    }
    File.close();

    ifstream inFile("pictures.csv");
    string head, a, b, c, d, e, f, g, h, i, j;

    getline(inFile, head);
    while (getline(inFile, a, ','))
    {
        temp.name = a;  //gets the name of the movie
        getline(inFile, b, ',');  temp.year = b;    // gets the year and so...on...
        getline(inFile, c, ',');  temp.nominations = c;
        getline(inFile, d, ',');  temp.rating = d;
        getline(inFile, e, ',');  temp.duration = e;
        getline(inFile, f, ',');  temp.genre1 = f;
        getline(inFile, g, ',');  temp.genre2 = g;
        getline(inFile, h, ',');  temp.release = h;
        getline(inFile, i, ',');  temp.metacritic = i;
        getline(inFile, j);  temp.synopsis = j;
//adding the collected data into BST with key as a movie name
        nametreeC->addNode(temp.name, temp);
    }
    File.close();
}

void DataFunctions:: Search() {
    bool quit = true;
    while (quit) {
        int o;  //for storing the user preference
        string searchWord;  //the word to be searched
        node = actortreeA->Root();  //getting a root node of the tree
        cout << "************************\n";
        cout << "1. Search by Name\n2. Search by Film\n3. Search by Year\n4. Back\n";
        cout << "************************\n";
        cin >> o;
        cin.clear();
        cin.ignore();

        if (o == 1) {
            cout << "Enter the Actor/Actress name to search:\n";
            getline(cin, searchWord);
            ASearch(node,searchWord);   //calling the function
        }
        else if (o == 2) {
            cout << "Enter the Film name to search:\n";
            getline(cin, searchWord);
            ASearch(node,searchWord);
        }
        else if (o == 3)
        {
            cout << "Enter the Year of the Film to search:\n";
            getline(cin, searchWord);
            ASearch(node,searchWord);
        }
        if (o == 4)
            quit = false;
    }
}
void DataFunctions::ASearch(Node<AwardData, string> *l, string w) {
    if (l != nullptr) {
        ASearch(l->Left(), w);  //Inorder search
        g = l->Data();
        if (g.name == w || g.film == w|| g.year == w)   // if the word is present
            cout << g.year << "," << g.award << "," << g.win << "," << g.name << "," << g.film << endl; //shows the data
        ASearch(l->Right(), w);
    }
}

// Same implementation as the Search() function the only difference is it takes pictures database
void DataFunctions::SearchFilm() {
    bool quit = true;
    leaf = nametreeC->Root();
    while (quit) {
        int o;
        string searchWord;
        cout << "************************\n";
        cout << "1. Search by Name\n2. Search by Genre\n3. Search by Year\n4. Back\n";
        cout << "************************\n";
        cin >> o;
        cin.clear();
        cin.ignore();
        if (o == 1)
        {
            BinarySearchTree<PictureData, string> *temptreeC = new BinarySearchTree<PictureData, string>;
            cout << "Enter the word to search:\n";
            getline(cin, searchWord);
            FSearch(leaf,searchWord);
        }
        else if (o == 2)
        {
            BinarySearchTree<PictureData, string> *temptreeC = new BinarySearchTree<PictureData, string>;
            cout << "Enter the word to search:\n";
            getline(cin, searchWord);
            FSearch(leaf,searchWord);
        }
        else if (o == 3)
        {
            BinarySearchTree<PictureData, string> *temptreeC = new BinarySearchTree<PictureData, string>;
            cout << "Enter the year to search:\n";
            getline(cin, searchWord);
            FSearch(leaf,searchWord);
        }
        if (o == 4)
            quit = false;
    }
}

void DataFunctions::FSearch(Node<PictureData, string> *node, string w) {

        if (node != nullptr) {
            FSearch(node->Left(),w);
            a = node->Data();
            if (a.name == " " + w || a.genre1 == w || a.genre2 == w|| a.year == w)
                cout << a.name << ", " << a.year << ", " << a.nominations << ", " << a.rating << ", " << a.duration << ", " << a.genre1 << ", " << a.genre2 << ", " << a.release << ", " << a.metacritic << ", " << a.synopsis <<endl;
            FSearch(node->Right(),w);
        }
}

//This method is used to return a bool variable if a portion of string is present in the string
//Important function for partial searching
bool DataFunctions::findString(string str, string substr){  //takes two string arguments
    int f = str.find(substr);   //if found it is positive
    return (f != -1);
}

//function defintion for partial search
void DataFunctions::partSearch()
{
    bool quit = true;
    while (quit) {

        int o;
        string searchWord;  //word that has to be searched
        node = actortreeA->Root();
        cout << "************************\n";
        cout << "1. Search by Name\n2. Search by Film\n3. Back\n";
        cout << "************************\n";
        cin >> o;
        cin.clear();
        cin.ignore();

        if (o == 1) {
            cout << "Enter the Actor/ Actress name to search:\n";
            getline(cin, searchWord);
            Apart(node,searchWord);
        }
        else if (o == 2) {
            cout << "Enter the Film name to search:\n";
            getline(cin, searchWord);
            Apart(node,searchWord);
        }
        if (o == 3)
            quit = false;
    }

}

void DataFunctions::Apart(Node<AwardData, string> *l, string w)
{  //recursive function uses Inorder transverse
    if (l != nullptr) {
        Apart(l->Left(), w);
        g = l->Data();
        if (findString(g.name,w) || findString(g.film,w))
            cout << g.year << "," << g.award << "," << g.win << "," << g.name << "," << g.film << endl;
        Apart(l->Right(), w);
    }
}

//Same as the partSearch() but this function goes through the pictures database
void DataFunctions::partSearchFilm() {
    bool quit = true;
    leaf = nametreeC->Root();
    while (quit) {
        int o;
        string searchWord;
        cout << "************************\n";
        cout << "1. Search by Name\n2. Search by Genre\n3. Back\n";
        cout << "************************\n";
        cin >> o;
        cin.clear();
        cin.ignore();
        if (o == 1) {
            BinarySearchTree<PictureData, string> *temptreeC = new BinarySearchTree<PictureData, string>;
            cout << "Enter the word to search:\n";
            getline(cin, searchWord);
            Fpart(leaf, searchWord);
        } else if (o == 2) {
            BinarySearchTree<PictureData, string> *temptreeC = new BinarySearchTree<PictureData, string>;
            cout << "Enter the word to search:\n";
            getline(cin, searchWord);
            Fpart(leaf, searchWord);
         
        }
        if (o == 3)
            quit = false;
    }
}

void DataFunctions::Fpart(Node<PictureData, string> *node, string w){

    if (node != nullptr) {
        Fpart(node->Left(),w);
        a = node->Data();
        if (findString(a.name,w) || findString(a.genre1,w) || findString(a.genre2,w))
            cout << a.name << ", " << a.year << ", " << a.nominations << ", " << a.rating << ", " << a.duration << ", " << a.genre1 << ", " << a.genre2 << ", " << a.release << ", " << a.metacritic << ", " << a.synopsis <<endl;
        Fpart(node->Right(),w);
    }
}

//This function is called if any modifications has to be done like, adding, deleting, modifying a particular field.
void DataFunctions::modify()
{
    bool end = true;
    while (end){
        int q;
        string one,two,three,four,five,name,data;
        cout << "************************\n";
        cout << "1. Add\n2. Delete\n3. Modify\n4. Back\n";
        cout << "************************\n";
        cin >> q;
        cin.clear();
        cin.ignore();
        if (q == 1) //for adding the new data
        {
            cout << "Enter the data as follows:Year,Award,Winner,Name,Film.\n";
            getline(cin,one); tempData.year = one;
            getline(cin,two); tempData.award = two;
            getline(cin,three);   tempData.win = three;
            getline(cin,four);    tempData.name = four;
            getline(cin,five);    tempData.film = five;
            actortreeA->addNode(tempData.name,tempData);
            node = actortreeA->findNode(four);
            g = node->Data();
            cout << "Added Data\n";
            cout << g.year << ", " << g.award << ", " << g.win << ", " << g.name << ", " << g.film << endl;
        }
        if (q == 2) //deleting the data
        {
            cout << "Enter the name of the actor you want to delete.\n";
            getline(cin,name);
            actortreeA->deleteNode(name);   //calling deleteNode from BinarySearchTree class
            cout << "Entered Data has been Deleted\n";
        }
        if (q == 3)
        {
            string datam,data;
            cout << "Enter the exact name of the actor that you want to modify:\n";
            getline(cin,data);
            node = actortreeA->findNode(data);
            g = node->Data();
            u = g;
            cout << g.year << ", " << g.award << ", " << g.win << ", " << g.name << ", " << g.film << endl;
            cout << "Enter the field that you want to modify.\n1. Year\n2. Award\n3. Winner\n4. Name\n5. Film\n";
            cin >> q;
            cin.clear();
            cin.ignore();
            cout << "Enter the new data:\n";
            getline(cin,datam);
            if (q == 1)
                u.year = datam;
            else if (q == 2)
                u.award = datam;
            else if (q == 3)
                u.win = datam;
            else if (q == 4)
                u.name = datam;
            else
                u.film = datam;

            cout << "The Data has been Modified.\n";
            actortreeA->deleteNode(g.name); //deleting the old data
            actortreeA->addNode(u.name,u);  //uploading the new data
            cout << g.year << ", " << g.award << ", " << g.win << ", " << g.name << ", " << g.film << endl;
        }
        if (q == 4)
        {
            end = false;
        }
    }
}

//Same as the function modify but for pictures database.
void DataFunctions::modifyFilm()
{
    bool end = true;
    while (end){
        int q;
        string one,two,three,four,five,six,seven,eight,nine,ten,name,data;
        cout << "************************\n";
        cout << "1. Add\n2. Delete\n3. Modify\n4. Back\n";
        cout << "************************\n";
        cin >> q;
        cin.clear();
        cin.ignore();
        if (q == 1)
        {
            cout << "Enter the data as follows:Name,Year,Nominations,Rating,Duration,Genre1,Genre2,Release,Metacritic,Synopsis.\n";
            getline(cin,one); temp.name = " "+one;
            getline(cin,two); temp.year = two;
            getline(cin,three);   temp.nominations = three;
            getline(cin,four);    temp.rating = four;
            getline(cin,five);    temp.duration = five;
            getline(cin,six);    temp.genre1 = six;
            getline(cin,seven);    temp.genre2 = seven;
            getline(cin,eight);    temp.release = eight;
            getline(cin,nine);    temp.metacritic = nine;
            getline(cin,ten);    temp.synopsis = ten;
            nametreeC->addNode(temp.name,temp);
            leaf = nametreeC->findNode(one);
            a = leaf->Data();
            cout << "Added Data\n";
            cout << a.name << ", " << a.year << ", " << a.nominations << ", " << a.rating << ", " << a.duration << ", " << a.genre1 << ", " << a.genre2 << ", " << a.release << ", " << a.metacritic << ", " << a.synopsis <<endl;
        }
        if (q == 2)
        {
            cout << "Enter the name of the movie you want to delete.\n";
            getline(cin,name);
            nametreeC->deleteNode(" "+name);
            cout << "Entered Data has been Deleted\n";
        }
        if (q == 3)
        {
            string datam,data;
            cout << "Enter the exact name of the movie that you want to modify:\n";
            getline(cin,data);
            leaf = nametreeC->findNode(" "+data);
            a = leaf->Data();
            b = a;
            cout << a.name << ", " << a.year << ", " << a.nominations << ", " << a.rating << ", " << a.duration << ", " << a.genre1 << ", " << a.genre2 << ", " << a.release << ", " << a.metacritic << ", " << a.synopsis <<endl;
            cout << "Enter the field that you want to modify.\n1. Name\n2. Year\n3. Nominations\n4. Rating\n5. Duration\n6. Genre1\n7. Genre2\n8. Release\n9. Metacritic\n10. Synopsis\n";
            cin >> q;
            cin.clear();
            cin.ignore();
            cout << "Enter the new data:\n";
            getline(cin,datam);
            if (q == 1)
                b.name = " "+datam;
            else if (q == 2)
                b.year = datam;
            else if (q == 3)
                b.nominations = datam;
            else if (q == 4)
                b.rating = datam;
            else if (q ==5)
                b.duration = datam;
            else if (q == 6)
                b.genre1 = datam;
            else if (q == 7)
                b.genre2 = datam;
            else if (q == 8)
                b.release= datam;
            else if (q == 9)
                b.metacritic = datam;
            else
                b.synopsis = datam;

            cout << "The Data has been Modified.\n";
            nametreeC->deleteNode(a.name);
            nametreeC->addNode(b.name,b);
            cout << a.name << ", " << a.year << ", " << a.nominations << ", " << a.rating << ", " << a.duration << ", " << a.genre1 << ", " << a.genre2 << ", " << a.release << ", " << a.metacritic << ", " << a.synopsis <<endl;
        }
        if (q == 4)
        {
            end = false;
        }
    }
}

//This method is used for sorting the data and saving it into a *.csv file.
void DataFunctions::sortData()
{
    node = actortreeA->Root();
    int r;
    cout << "************************\n";
    cout << "1. Sort by Year\n2. Sort by film\n";
    cout << "************************\n";
    cin >> r;
    cin.clear();
    cin.ignore();
    string filename = "Actors_Modified.csv";
    outfile.open(filename);
    outfile << "Year,Award,Winner,Name,Film"<<endl;
    if (r == 1){
        dataSort(node,r);   //calling a function called dataSort which takes node as an argument
        save(yeartreeA->Root());    //function for saving the data into a *.csv file
        cout << "File has been saved"<<endl;
    }
    if (r == 2){
        dataSort(node,r);
        save(filmtreeA->Root());
        cout << "File has been saved"<<endl;
    }
}

//uses a inorder search
void DataFunctions::dataSort(Node<AwardData, string> *node, int r) {

    if(r == 1){
        if (node != nullptr)
        {
            dataSort(node->Left(),1);
            g = node->Data();
            yeartreeA->addNode(g.year,g);
            dataSort(node->Right(),1);
        }
        return;
    }
    if (r == 2){
        if (node != nullptr)
        {
            dataSort(node->Left(),2);
            g = node->Data();
            filmtreeA->addNode(g.film,g);
            dataSort(node->Right(),2);
        }
        return;
    }
}

// the function is taking the root as a data that has to be sorted.
void DataFunctions::save(Node<AwardData, string> *node) {
    if (node != nullptr) {
        save(node->Left());
        g = node->Data();
        //writing into a file
        outfile << g.year << ", " << g.award << ", " << g.win << ", " << g.name << ", " << ", " << g.film << endl;
        save(node->Right());
    }
}

//Same as te sortData but uses the pictures database
void DataFunctions::sortDataFilm()
{
    leaf = nametreeC->Root();
    int r;
    cout << "************************\n";
    cout << "1. Sort by Year\n2. Sort by Rating\n3. Sort by Nominations\n";
    cout << "************************\n";
    cin >> r;
    cin.clear();
    cin.ignore();
    file.open("Pictures_Modified.csv");
    file << "name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis"<<endl;
    if (r == 1)
    {
        dataSortFilm(leaf,r);
        saveFilm(yeartreeC->Root());
    }
    if (r == 2)
    {
        dataSortFilm(leaf,r);
        saveFilm(ratetreeC->Root());
    }
    if (r == 3)
    {
        dataSortFilm(leaf,r);
        saveFilm(nomitreeC->Root());
    }
}

void DataFunctions::dataSortFilm(Node<PictureData, string> *node, int r) {
    if(r == 1){

        if (node != nullptr)
        {
            dataSortFilm(node->Left(),1);
            a = node->Data();
            yeartreeC->addNode(a.year,a);
            dataSortFilm(node->Right(),1);
        }
        return;
    }
    if (r == 2){
        if (node != nullptr)
        {
            dataSortFilm(node->Left(),2);
            a = node->Data();
            ratetreeC->addNode(a.rating,a);
            dataSortFilm(node->Right(),2);
        }
        return;
    }
    if(r == 3){
        if (node != nullptr)
        {
            dataSortFilm(node->Left(),3);
            a = node->Data();
            nomitreeC->addNode(a.nominations,a);
            dataSortFilm(node->Right(),3);
        }
        return;
    }
}

void DataFunctions::saveFilm(Node<PictureData, string> *leaf)
{
    if (leaf != nullptr) {
        saveFilm(leaf->Left());
        a = leaf->Data();
        file << a.name << ", " << a.year << ", " << a.nominations << ", " << a.rating << ", " << a.duration << ", " << a.genre1 << ", " << a.genre2 << ", " << a.release << ", " << a.metacritic << ", " << a.synopsis <<endl;
        saveFilm(leaf->Right());
    }

}