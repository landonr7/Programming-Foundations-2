#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "StudentNode.h"

class StudentList {
   
   //Public attributes
   public:
      //Default constructor
      StudentList(); 
      
      //Copy constructor
      StudentList(const StudentList & copy); 
      
      //Destructor
      ~StudentList(); 
      
      //Insert function
      void insertL(string keyIn, string countryIn, string cityIn, string genderIn, float gpaIn); 
      
      //Delete function
      void removeL(string key); 
      
      //Update function
      void updateL(string keyIn, string countryIn, string cityIn, string genderIn, float gpaIn); 
      
      //Search function
      StudentNode* searchL(string key); 
      
      //Print function
      void printL(); 
      
      //Empty function
      bool isEmpty() const;
   
   //Private attributes
   private:
      StudentNode * head; //Declaring head pointer for Student node
};

#endif