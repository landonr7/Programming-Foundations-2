#include "StudentNode.h"
#include "StudentList.h"
#include "HashTable.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printMenu() { //Print menu function

   cout << "Welcome to the Hash Tabler:" << endl << "-----------------------------------" << endl
   << "1: Insert a node into the hash table." << endl
   << "2: Delete a node from the hash table." << endl
   << "3: Update a node in the hash table." << endl
   << "4: Search a node in the hash table." << endl
   << "5: Print the hash table." << endl
   << "0: Exit the program." << endl
   << "-----------------------------------" << endl;
}

void readFile(string const file, HashTable& bathHouse) {

   string key = "empty";
   string country = "empty";
   string temp2 = "empty";
   string city = "empty";
   string gender1 = "empty";
   float gpa = 0.0;
   string tempg = "empty";

   // to read from file and store to vector
   ifstream filein;
   filein.open(file);

   while (getline(filein, key, ','))
   {
      getline(filein, country, ',');
      getline(filein, city, ',');
      getline(filein, gender1, ',');
      getline(filein, tempg);
      
      bathHouse.insertHT(key, country, city, gender1, stof(tempg));
   }

   // closes file
   filein.close();
}

int main()
{
   HashTable bathHouse(373);
   string file = "student-dataset.txt";
   readFile(file, bathHouse);
   
   int c = 0;
   
   string key = "";
   string tempk = "";
   string country = "";
   string city = "";
   string gender = "";
   float gpa = 0.0;
   
   do {
      

   printMenu();
   cout << "Make a selection" << endl;
   cin >> c;
   
      switch (c) { //Switch case
        
         case 1: //Insert
            cout << "What name would you like to insert? (Use capital letters for each token)" << endl;
            cin.ignore();
            getline(cin, key);
            
            cout << "What country would you like to insert?" << endl;
            cin >> country;
            
            cout << "What city would you like to insert?" << endl;
            cin >> city;            
            
            cout << "What gender would you like to insert?" << endl;
            cin >> gender;            
            
            cout << "What gpa would you like to insert?" << endl;
            cin >> gpa;
            
            bathHouse.insertHT(key, country, city, gender, gpa);
            break;

         case 2: //Delete
            cout << "Enter the full name of the person you would like to delete from the table (First name and last name): " << endl;
            cin.ignore();
            getline(cin, key);
            
            bathHouse.removeHT(key);
    	      break;

         case 3: //Update
            cout << "What name would you like to update? (Use capital letters for each token)" << endl;
            cin >> key;
            getline(cin, tempk);
            key += tempk;
            
            cout << "What  would you like to update the country to?" << endl;
            cin >> country;
            
            cout << "What  would you like to update the city to?" << endl;
            cin >> city;            
            
            cout << "What would you like to update the gender to?" << endl;
            cin >> gender;            
            
            cout << "What  would you like to update the gpa to?" << endl;
            cin >> gpa;
            
            bathHouse.updateHT(key, country, city, gender, gpa);
            break;

         case 4: //Search
            cin.ignore();
            cout << "Enter the full name of the person you would like to search from the table (First name and last name): " << endl;
            getline(cin, key);
            
            bathHouse.searchHT(key)->printN();
    	      break;
    	      
    	   case 5: //Print
    	   
    	      bathHouse.printHT();
    	      break;
    	      
         case 0: //Exits the program
         
            cout << "Size: " << bathHouse.getSize() << endl;
            cout << "Count: " << bathHouse.getCount() << endl;
            cout << "Collisions: " << bathHouse.getColl() << endl;
            cout << "The program ran successfully... now go dig a hole or something." << endl;
            break;
               
         default:
         
            cout << "Enter a valid input." << endl;
            break;
      }      
      
   } while((c != 0) && (c < 6));

   return 0;
}
