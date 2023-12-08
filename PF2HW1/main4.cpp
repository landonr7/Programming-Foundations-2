///////////////////////////////////////////////////////////////////////
//Landon Reynolds
//PF2
///////////////////////////////////////////////////////////////////////


#include "pinball.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

const int SIZE = 10;

Pinball machines[SIZE];

void printMenu() { //Print menu function

  cout << "Welcome to Pee Wee's Pinball Database:" << endl << "-----------------------------------" << endl
    << "1: Read the machines from an ASCII file." << endl
    << "2: Add a machine to the database" << endl
    << "3: Search machines by year" << endl
    << "4: Print out existing machines to ASCII file and exit the program." << endl << "-----------------------------------" << endl;
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

void readFile(const string filename, Pinball &ball) { //Read function

    ifstream din;
    din.open(filename);
    
    string machineName = "";
    string temp = "";
    int yearProduced = 0;
    string manufacturer = "";
    float funRating = 0.0;
    string theme = "";
    int num = 0;
    
    if (din.fail()) {
    
        cout << "Error opening file" << endl;
        return;
    }
    
    while(!din.eof()) {
        
        //Delimited getlines
        getline(din, machineName, ',');
        
        getline(din, temp, ',');
        yearProduced = stoi(temp);
        
        getline(din, manufacturer, ',');
    
        getline(din, temp, ',');
        funRating = stof(temp);
        
        getline(din, theme);
        
        Pinball pin = Pinball(machineName, yearProduced, manufacturer, funRating, theme);
        machines[num] = pin;
        num++;
    }
    
    din.close();
}

void print(Pinball machines[]) { //Print function
    
    for (int i = 0; i < SIZE; i++) {
        if (machines[i].getMachineName() == "") {
            break;    
        }
        machines[i].print();
    }
}

void writeFile(const string filename1, Pinball ball) { //Write function
    ofstream dout;
    dout.open ("pinball1.txt");
    
    if (dout.fail ()) {
        
        cout << "Error opening file" << endl;
        return;
    }
    
    for(int i = 0; i < SIZE; i++) {
        Pinball pin1 = machines[i];
            if(machines[i].getYearProduced() != 0) {
                dout << pin1.getMachineName() << "," << pin1.getYearProduced() << "," <<  pin1.getManufacturer() << "," 
                << pin1.getFunRating() << "," << pin1.getTheme() << "," << endl;
            }
            else {
                dout.close();
            }
    }

}

int main() {

    string filename = "pinball.txt";
    string filename1= "pinball1.txt";
    
    Pinball ball; //Objects
    Pinball pin;
    
    string nameIn = ""; //Declaring setter values
    int yearIn = 0;
    string manufacturerIn = "";
    float ratingIn = 0.0;
    string themeIn = "";
    int year = 0;
    
    readFile(filename, ball); //Read file function

    char c = '0';
    do { //Do while function for input
        printMenu ();
        
    c = getUserChoice();
    
    switch (c) { //Switch case
        
        case '1': //Reads pinball.txt file
        
            readFile(filename, ball);
            break;

        case '2': //Adds a machine to array 
    	
        //User inputs
	    cout << "What is the name of your machine?" << endl;
    	cin >> nameIn;
    	
    	cout << "What is the Year Produced of your machine?" << endl;
    	cin >> yearIn;
    	
    	cout << "What is the Manufacturer of your machine?" << endl;
    	cin >> manufacturerIn;
    	
    	cout << "What is the Average fun rating of your machine?" << endl;
    	cin >> ratingIn;
    	
    	cout << "What is the theme of your machine?" << endl;
    	cin >> themeIn;
    	
    	pin.setMachineName(nameIn); //Setters are used
    	pin.setYearProduced(yearIn);
    	pin.setManufacturer(manufacturerIn);
    	pin.setFunRating(ratingIn);
    	pin.setTheme(themeIn);
    	
    	for (int i = 0; i < SIZE; i++) { //Adds inputs to array
    	    if (machines[i].getYearProduced() == 0) {
    	        machines[i] = pin;
    	        break;
    	    }

    	}
    	break;

        case '3': //Searches machines by year
    	
    	    cout << "Enter a year to see which machines were manufactured during that year." << endl;
    	    cin >> year;
    	    
    	    for (int i = 0; i < SIZE; i++) {
    	        if (machines[i].getYearProduced() == year) {
    	            machines[i].print();
    	        }
    	   }
            break;

        case '4':
            
            print(machines);
            writeFile(filename1, ball);
    	    break;
    	    
        default:
    	    cout << "Enter a valid input." << endl;
        }
    }while ((c >= '1') && (c < '4'));
    
    return 0;
}
