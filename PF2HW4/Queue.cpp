#include "Queue.h"

//Constructor
Queue::Queue() {
   
   for(int i = 0; i < count; i++) {
      data[i] = 0;
   }
   
}

//Copy constructor
Queue::Queue(const Queue& copy) {
   
   for(int i = 0; i < copy.count; i++) {
      data[i] = copy.data[i];
   }
   
   count = copy.count;
}

//Destructor
Queue::~Queue() {
   
}

//Insert method
void Queue::insert(const int number) {
   
   if(isFull()) {
      return;
   }
    
   data.insert(data.end(), number);
   count++;
}

//Remove method
void Queue::remove() {
   
   if(isEmpty()) {
      
      cout << "Queue is empty" << endl;
      return ;        
   }
   
   data.erase(data.begin());
   count--;
}

//Full method
bool Queue::isFull() const {
   
   return false;
}

//Empty method
bool Queue::isEmpty() const {
   
   return count == 0;
}

//Getter
int Queue::getCount() const {
   
   return count;
}

int Queue::getFront() const {
 
 return data.front();  
}

//Print method
void Queue::print() const {
   
   if (isEmpty()) {
      
      cout << "Queue is empty I guess" << endl;
      return;
   }
   
   cout << "Printing the queue like right now: " << endl;
   
   for(int i = 0; i < count; i++) {
      
     cout << i << ". " << data[i] << "\n";
   }
   
   cout << endl << "Finished printing the queue or something." << endl;

}