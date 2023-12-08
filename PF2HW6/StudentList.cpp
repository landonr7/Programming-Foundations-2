#include "StudentList.h"

// Default constructor
StudentList::StudentList() {
   head = NULL;
}

// Copy constructor
StudentList::StudentList(const StudentList& copy) {
   
   head = copy.head;

}

// Destructor
StudentList::~StudentList()
{
   // Iterate over the nodes and delete them one by one
   StudentNode* temp = head;
   while(temp != NULL) {
     
      temp = temp->getNext();
      delete temp;
      temp = head;
   }
}

// Insert a node at the end of the list
void StudentList::insertL(string keyIn, string countryIn, string cityIn, string genderIn, float gpaIn)
{
   StudentNode* newNode = new StudentNode(keyIn, countryIn, cityIn, genderIn, gpaIn);
   
   if (head == nullptr) {
      
      head = newNode;
   } else {
      
      StudentNode* temp = head;
      
      while (temp->getNext() != nullptr) {
            
         temp = temp->getNext();
        
      }
      
      head->setNext(newNode);
   }
}

// Delete a node from the list
void StudentList::removeL(string key)
{
   if (head == NULL) {
      
      cout << "List is empty" << endl;
      return;
   }
   if (head->getKey() == key) {
        
        StudentNode* temp = head;
        head = head->getNext();
        delete temp;
        return;
   }
    
   StudentNode* temp = head;
    
   //Loop
   while (temp->getNext() != nullptr && temp->getNext()->getKey() != key) {
        
      temp = temp->getNext();
    
   }
   //Remove
   if (temp->getNext() != nullptr) {
        
      StudentNode* temp = temp->getNext();
      temp->setNext(temp->getNext());
      delete temp;
    
   }
}

// Update a node in the list
void StudentList::updateL(string key, string country, string city, string gender, float gpa)
{
   StudentNode * temp = head;
   //Loop
   while (temp != nullptr && temp->getKey() != key) {
        
      temp = temp->getNext();
      
   }
   
   //Node is found
   if (temp != nullptr) {
        
      temp->setCountry(country);
      temp->setCity(city);
      temp->setGender(gender);
      temp->setGpa(gpa);
    
   }
}

//Searchh function
StudentNode* StudentList::searchL(string key) {
   
   StudentNode * temp = head;
   
   //Loop
   while (temp != NULL && temp->getKey() != key) {

      temp = temp->getNext();
   }

   return temp;
}

//Print function
void StudentList::printL() { 
    
   StudentNode * temp = head;
    
   while (temp != NULL) {
        
      temp->printN();
      temp = temp->getNext();
   }
}

//Empty function
bool StudentList::isEmpty() const {
   
   return head == nullptr;
}
