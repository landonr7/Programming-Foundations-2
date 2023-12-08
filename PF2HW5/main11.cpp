#include "Book.h"
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

void printMenu() { //Print menu function

   cout << "Welcome to the Sortatron 9000:" << endl << "-----------------------------------" << endl
   << "1: Insertion sort" << endl
   << "2: Selection sort" << endl
   << "3: Merge sort" << endl
   << "4: Quick sort" << endl
   << "5: Exit the program" << endl 
   << "-----------------------------------" << endl;
}

char getUserChoice() { //Switch function

  char userChoice = '\0';

  do
   {
      cout << "Enter menu selection: " << endl;
      cin >> userChoice;
      if (userChoice < '1' || userChoice > '5')
	    cout << "Error: invalid input. Please try again." << endl;
   }
  while (userChoice < '1' || userChoice > '5');

  return userChoice;
}

void readFile(string const file, vector<Book>& list) {

    string lName = "empty";
    string fName = "empty";
    string tempy = "empty";
    string tempr = "empty";
    string title1 = "empty";
    string genre1 = "empty";

    // to read from file and store to vector
    ifstream filein;
    filein.open(file);

    while (getline(filein, tempy, ','))
    {
        getline(filein, title1, ',');
        getline(filein, lName, ',');
        getline(filein, fName, ',');
        getline(filein, genre1, ',');
        getline(filein, tempr, ',');

        // creates book object from data read from file
        Book checkout(stoi(tempy), title1, lName, fName, genre1, stof(tempr));
        list.push_back(checkout);
    }

    // closes file
    filein.close();
}
//Insertion sort
void insertionSort(vector<Book>& list, int lo) {
    
   for (int i = lo + 1; i < list.size(); i++) {
       
      float fix = list.at(i).getRating();
      Book key = list.at(i);
      float j = i;
        
      while ((j >= 0) && (list.at(j).getRating()) > fix) {
           
         list.at(j) = list.at(j - 1);
         j = j - 1;
      }
        
      list.at(j) = key;
   }
}

//Selection sort
void selectionSort(vector<Book>& list) {
   
   int sizeSelection = list.size();
    
   for (int i = 0; i < sizeSelection - 1; i++) {
      
      int minIndex = i;
      
      for (int j = i + 1; j < sizeSelection; j++) {
           
         if (list[j].getRating() < list[minIndex].getRating()) {
               
            minIndex = j;
         }
      }
        
      if (minIndex != i) {
           
         swap(list[i], list[minIndex]);
      }
   }
}

//Quick sort
int partition(vector<Book>& list, int lo, int hi) {
   
   string pivot = list[hi].getGenre(); // pivot
   
   int i = lo - 1; // Index of smaller element

   for (int j = lo; j <= hi - 1; j++) {
      // If current element is greater than or equal to pivot
      if (list[j].getGenre() >= pivot) {
           
         i++; // increment index of smaller element
         swap(list[i], list[j]);
      }
   }
    
   swap(list[i + 1], list[hi]);
   return (i + 1);
}

void quickSort(vector<Book>& list, int lo, int hi) {
   
   if (lo < hi) {
      int part = partition(list, lo, hi);

      quickSort(list, lo, part - 1); // Sort elements before partition
      quickSort(list, part + 1, hi); // Sort elements after partition
   }
}

//Merge sort
void mergeMini(vector<Book>& list, vector<Book>& left, vector<Book>& right) {
   
   int leftI = 0;
   int rightI = 0;
   int index = 0;
    
   while ((leftI < left.size()) && (rightI < right.size())) {
       
      if (left[leftI].getFirstName() < right[rightI].getFirstName()) {
           
         list[index] = left[leftI];
         leftI++;
      } else {
           
         list[index] = right[rightI];
         rightI++;
      }
        
      index++;
   }

   while (leftI < left.size()) {
       
      list[index] = left[leftI];
      leftI++;
      index++;
   }

   while (rightI < right.size()) {
       
      list[index] = right[rightI];
      rightI++;
      index++;
   }
}

void mergeSort(vector<Book>& list) {
   
   if (list.size() < 2) {
      
      return;
   }

   int mid = list.size() / 2;
   vector<Book> left(list.begin(), list.begin() + mid);
   vector<Book> right(list.begin() + mid, list.end());

   mergeSort(left);
   mergeSort(right);
   mergeMini(list, left, right);
}

void writeFile(const string filename, vector<Book>& list, Book & object) { //Write function
   ofstream dout;
   dout.open (filename);
    
   if (dout.fail ()) {
        
      cout << "Error opening file" << endl;
      return;
   }
    
   for(int i = 0; i < list.size(); i++) {
      Book thing = list.at(i);
         if(list.at(i).getYear() != 0) {
            dout << thing.getYear() << "," <<thing.getTitle() << "," << thing.getFirstName() << "," 
            <<thing.getLastName() << "," << thing.getGenre() << "," <<thing.getRating() << endl;
         }
         else {
            dout.close();
         }
   }

}

int main()
{
   
   string file = "books.txt";
   
   string insertFile = "insertFile.csv";
   string selectFile = "selectFile.csv";
   string quickFile = "quickFile.csv";
   string mergeFile = "mergeFile.csv";
   
   vector<Book> list; //Book object
   
   Book object1;
   Book object2;
   Book object3;
   Book object4;
   
   clock_t start = clock();
   // call to sorting algorithm method
   clock_t end = clock();
   double runtime = (end - start) / double(CLOCKS_PER_SEC);
   
   char c = '0';
   
   do { //Do while function for input
      list.clear();
      readFile(file, list);

      printMenu();
      c = getUserChoice();
    
      switch (c) { //Switch case
        
         case '1': //Insertion sort
        
            start = clock();
            // call to sorting algorithm method
            end = clock();
            runtime = (end - start) / double(CLOCKS_PER_SEC);
            cout << "Insertion sort runtime in seconds :" << runtime << endl;
            writeFile(insertFile, list, object1);
            break;

         case '2': //Selection sort

            start = clock();
            // call to sorting algorithm method
            end = clock();
            runtime = (end - start) / double(CLOCKS_PER_SEC);
            cout << "Selection sort runtime in seconds :" << runtime << endl;
            writeFile(selectFile, list, object2);
    	      break;

         case '3': //Merge sort
    
            start = clock();
            // call to sorting algorithm method
            end = clock();
            runtime = (end - start) / double(CLOCKS_PER_SEC);
            cout << "Merge sort runtime in seconds :" << runtime << endl;
            writeFile(mergeFile, list, object3);    
            break;

         case '4': //Quick sort
         
            start = clock();
            // call to sorting algorithm method
            end = clock();
            runtime = (end - start) / double(CLOCKS_PER_SEC);
            cout << "Quick sort runtime in seconds :" << runtime << endl;
            writeFile(quickFile, list, object4);
            break;

         case '5': //Exits the program
         
            return 0;
            break;
         default:
         
    	    cout << "Enter a valid input." << endl;
        }
        
    }while ((c >= '1') && (c < '5'));

   cout << "The code has finished executing or something..." << endl;
   return 0;
}
