#include "RestaurantNode.h"
#include "RestaurantList.h"
#include <stdio.h>

void printMenu() { //Print menu function

  cout << "Welcome to the Best Restaurant in the World or Something:" << endl << "-----------------------------------" << endl
    << "1: Add a meal" << endl
    << "2: Search for the highest priced meal" << endl
    << "3: Change the price of a meal" << endl
    << "4: Print out existing meals" << endl
    << "5: Exit the program" << endl << "-----------------------------------" << endl;
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

int main()
{
    
    RestaurantList * foodList = new RestaurantList(); //Restaurant list object

    char c = '0';
    do { //Do while function for input
    
    printMenu();
    
    c = getUserChoice();
    
    switch (c) { //Switch case
        
        case '1': //Adds a meal to the menu
            
            foodList->addMeal();
            break;

        case '2': //Searches for the highest priced meal
    	    
    	    foodList->highestPrice();
    	break;

        case '3': //Changes the price of a meal
    	
    	    foodList->changePrice();
            break;

        case '4': //Prints out existing meals
        
            foodList->printL();
    	    break;
    	    
    	case '5': //Exits program
    	   
            cout << "The program ran successfully, have a nice night." << endl;
            
            return 0;
        
        default:
    	    cout << "Enter a valid input." << endl;
        }
    }while (c != 5);
    
    return 0;
}
