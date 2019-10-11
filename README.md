# OscarMovieNominationData

This project mainly deals with the storing the data from the given two input files (actor_actress.csv and pictures.csv) 
and then displaying the movie information by the search key either by actor name or by movie name.

It also has the option of adding the record, search through the records, modify and deletion of records as well.

First, we will read the actor_actress data and picture information from the provided csv files and then by using binary search tree, 
we will search and sort through the data.

In binary search tree, I am implementing in the depth-first tranversal, Inorder(left child, parent, right child) and 
it will called recursively through their left and right leaves. We will be using DataFunctions class which consists of functions 
which do partial search, search, adding the data, manipulating the data. For this, we will use binary search tree operations

Important member functions present in DataFunctions class are:
Void GetDatabase()	
  - This function is for opening the respective CSV files(actor_actress, pictures) and store them into BinarySearch tree. 
    Both the data are sorted with the name of actor in actor_actress csv file and by name of movie from pictures csv file
Void search()
  -	It is function to search the data by using the user selected option.
Void partialSearch()
  -	This function is to do partial search with the user entered keyword against the complete databases and to display the results
Void Modify()
  -	This function is for adding, updating and deletion of records from the databases
Void save(node)
  -	This function is to write the data into .csv file
Void Sortdata()
  -	This function is used to sort the whole database. 
bool findString()
  -	To check for the substring present in a string
  
For Pictures database,
void sortDataFilm()
  -	This function is used to sort in pictures database. 
void SearchFilm()
  -	This function is used to search in the pictures database.
void partSearchFilm()
  -	This function is used to partially search in the pictures database.
void modifyFilm()
  -	    This function is used to partially search in the pictures database.

