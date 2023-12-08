#include <stdio.h>
#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include <time.h>

using namespace std;

//Run queue function
void rnQueue(const int iterations, Queue& queue) {
   // Get start time
   clock_t time1 = clock();
   
   for (int i = 0; i < iterations; i++) {
      if (queue.isEmpty()) {
         
         queue.insert(rand() % 100 + 1);
      }
      else if (rand() % 1000 + 1 >= 500) {
         
         queue.insert(rand() % 100 + 1);
      }
      else {
         
         queue.remove();
      }
   }
   
   queue.print();
   
   // Get end time
   clock_t time2 = clock();
   double run_time = (time2-time1) / (double)CLOCKS_PER_SEC;
   cout << "Run time: " << run_time << " seconds\n";

}

//Run stack function
void rnStack(const int iterations, Stack& stack) {
   
   // Get start time
   clock_t time1=clock();
   
   for (int i = 0; i < iterations; i++) {
      if (stack.isEmpty()) {
         
         stack.push(rand() % 100 + 1);
      }
      else if (rand() % 1000 + 1 >= 500) {
         
         stack.push(rand() % 100 + 1);
      }
      else {
         stack.pop();
      }
   }
   
   stack.print();
   
   // Get end time
   clock_t time2=clock();
   double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
   cout << "Run time: " << run_time << " seconds\n";

}

void printMenu() { //Print menu function

   cout << "Pick an option:" << endl << "----------------------------------------------------------------------------" << endl
     << "1.) Queue: 1000 iterations" << endl
     << "2.) Queue: 10000 iterations" << endl
     << "3.) Queue: 100000 iterations" << endl
     << "4.) Stack: 1000 iterations" << endl
     << "5.) Stack: 10000 iterations" << endl
     << "6.) Stack: 100000 iterations" << endl
     << "7.) Exit the program" << endl << "----------------------------------------------------------------------------" << endl;
}

//Switch input
char getChoice() {
    char c = ' ';
    while (cout << "Enter menu selection:\n" && cin >> c && (c < '1' || c > '7'))
        cout << "Error: invalid input. Please try again.\n";
    return c;
}

int main() {
   
   //Objects
   Queue queue;
   Stack stack;
   
   char c = '0';
   do { //Do while function for input
   
   //Seeding random
   srand(time(0));
   
     printMenu();
   
     c = getChoice();
   
     switch (c)
     {
   
      case '1': //Queue iterations 1000
         rnQueue(1000, queue);
      
         break;
   
      case '2': //Queue iterations 10000
         rnQueue(10000, queue);
   
         break;
   
      case '3': //Queue iterations 100000
         rnQueue(100000, queue);
   
         break;
   
      case '4': //Stack iterations 1000
         rnStack(1000, stack);
   
         break;
   
      case '5': //Stack iterations 10000
         rnStack(10000, stack);
   
         break;
   
      case '6': //Stack iterations 100000
         rnStack(100000, stack);
   
         break;
         
      case '7': //Closes the program
         
         return 0;
   
      default:
   
         cout << "Enter a valid input." << endl;
     }
   
   } while (c != 7);

 cout << "The program ran successfully, have a nice night." << endl;
 
   return 0;
}
